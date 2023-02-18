/*
 * Copyright (c) 2017-2023 Tom Rix
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
#include <sstream>
#include <stdio.h>
#include <string.h>

#include "parser.tab.hh"

// #define WARNING_TRAINING
// #define ABORT_TRAINING
//
// The training of syntax errors idea comes from
// Clinton Jeffery, jeffery@cs.uidaho.edu
// http://www.unicon.org/merr/

oparser::oparser(lang_driver *drv) : parser(drv) {
#include "oparser_warn.h"
}

static location override_loc;

void oparser::error(const class location &loc, const std::string &msg) {
#ifndef WARNING_TRAINING
  const location *lloc = &loc;
  if (override_loc.begin.line >= loc.begin.line &&
      override_loc.begin.column > loc.begin.column)
    lloc = &override_loc;

  str_error = drv->Filename;
  str_error += ':';
  str_error += std::to_string(lloc->begin.line);
  str_error += ':';
  str_error += std::to_string(lloc->begin.column);
  str_error += " Error: ";
  str_error += msg;
  str_error += '\n';

  unsigned l = lloc->begin.line;
  std::shared_ptr<std::string> s = drv->Scanner->get_line(l);
  if (s != nullptr) {
    const char *cs = s->c_str();
    size_t l = strlen(cs);
    for (size_t i = 0; i < l; i++) {
      std::stringstream con;
      if ((cs[i] >= 0x20 && cs[i] < 0x7f) || cs[i] == '\n' || cs[i] == '\r' ||
          cs[i] == '\t' || cs[i] == '\v' || cs[i] == '\f') {
        con << cs[i];
      } else {
        con << std::oct << cs[i];
        str_error += "0";
      }
      str_error += con.str();
    }
    if (s->back() != '\n')
      str_error += '\n';

    for (size_t i = 0; i < l; i++) {
      if (i + 1 < lloc->begin.column)
        str_error += " ";
      else if ((i + 1 < lloc->end.column) ||
               (lloc->begin.line != lloc->end.line))
        str_error += "^";
      else
        break;
    }
    str_error += '\n';
  }
#endif
}

template <typename Base>
oparser::symbol_kind_type
oparser::basic_symbol<Base>::type_get() const YY_NOEXCEPT {
  return this->kind();
}

std::string oparser::yysyntax_error_(const context &yyctx) const {

  state_type yystate = yystack_[0].state;
  const symbol_type &yyla = yyctx.lookahead();

  if (!yyla.empty()) {
    int ty = yyla.type_get();
    if (ty == yytranslate_(afront::parser::token::UNSUPPORTED_INPUT_CHAR)) {
      const afront::parser::semantic_type *val = &yyla.value;
      lex_token t = val->as<lex_token>();
      override_loc = t.here();
      std::string r = "Unsupported input char";
      return r;
    }
  }

  std::string r = afront::parser::yysyntax_error_(yyctx);
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

std::string oparser::error() { return str_error; }
