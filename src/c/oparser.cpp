/*
 * Copyright (c) 2017-2018 Tom Rix
 * All rights reserved.
 *
 * You may distribute under the terms of :
 *
 * the BSD 2-Clause license
 *
 * Any patches released for this software are to be released under these
 * same license terms.
 *
 * BSD 2-Clause license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "oparser.h"
#include "scanner.h"
#include <iostream>
#include <stdio.h>

// #define WARNING_TRAINING
// #define ABORT_TRAINING
//
// The training of syntax errors idea comes from
// Clinton Jeffery, jeffery@cs.uidaho.edu
// http://www.unicon.org/merr/

oparser::oparser(c_driver *drv) : parser(drv) {
#include "oparser_warn.h"
}
void oparser::error(const class location &loc, const std::string &msg) {
#ifndef WARNING_TRAINING
  fprintf(stderr, "%s:%u:%u Error: %s\n", drv->Filename.c_str(), loc.begin.line,
          loc.begin.column, msg.c_str());
  unsigned l = loc.begin.line;
  std::shared_ptr<std::string> s = drv->Scanner->get_line(l);
  if (s != nullptr) {
    const char *cs = s->c_str();
    fprintf(stderr, "%s", s->c_str());
    if (s->back() != '\n')
      fprintf(stderr, "\n");

    size_t l = strlen(cs);
    for (size_t i = 0; i < l; i++) {
      if (i + 1 < loc.begin.column)
        fprintf(stderr, " ");
      else if ((i + 1 < loc.end.column) || (loc.begin.line != loc.end.line))
        fprintf(stderr, "^");
      else
        break;
    }
    fprintf(stderr, "\n");
  }
#endif
}
std::string oparser::yysyntax_error_(state_type yystate,
                                     const symbol_type &yyla) const {
  std::string r = afront::parser::yysyntax_error_(yystate, yyla);
  std::hash<std::string> shash;
  std::size_t h = shash(r);
  auto si = syntax_error_map.find((int)yystate);
  if (si != syntax_error_map.end()) {
    std::shared_ptr<hs_map> hs = si->second;
    auto hi = hs->find(h);
    if (hi != hs->end()) {
      return hi->second;
    } else {
#ifdef WARNING_TRAINING
      fprintf(stdout, "/* %d %20lld */ (*syntax_error_map[%d])[%lld] = %s;\n",
              (int)yystate, (long long)h, (int)yystate, (long long)h,
              r.c_str());
#ifdef ABORT_TRAINING
      abort();
#endif
#endif
    }
  } else {
#ifdef WARNING_TRAINING
    fprintf(stdout,
            "/* %d 0                    */ syntax_error_map[%d] = "
            "std::shared_ptr<hs_map> "
            "(new hs_map());\n",
            (int)yystate, (int)yystate);
    fprintf(stdout, "/* %d %20lld */ (*syntax_error_map[%d])[%lld] = \"%s\";\n",
            (int)yystate, (long long)h, (int)yystate, (long long)h, r.c_str());
#ifdef ABORT_TRAINING
    abort();
#endif
#endif
  }
  return r;
}
