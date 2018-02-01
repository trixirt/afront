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

#include "driver.h"
#include "oparser.h"
#include "scanner.h"
#include <fstream>

static const char *default_filename = "stdin";

namespace c {
driver::~driver() {
  if (scanner)
    delete (scanner);
  if (parser)
    delete (parser);
}

bool driver::parse(const char *const filename) {
  bool ret = false;
  std::ifstream *ifs = nullptr;

  if (filename != nullptr) {
    ifs = new std::ifstream(filename);
    std::ifstream *ifs = new std::ifstream(filename);
    if (ifs->good()) {
      this->filename = filename; // needed for location
    }
  } else {
    this->filename = default_filename;
  }
  std::istream *i = (ifs != nullptr && ifs->good()) ? ifs : &std::cin;

  scanner = new lex::scanner(i, &this->filename);
  /* Additional builtin types */
  /* XXX this should be common */
  const char *builtin_types[] = {
      "__builtin_va_list",
      "",
  };
  for (const char **c = builtin_types; **c != '\0'; c++) {
    scanner->add_typename(*c);
  }

  parser = new nada::oparser(this);
  // yyresult :
  // 0 on success
  // 1 on failure
  ret = parser->parse() ? false : true;

end:
  return ret;
}

std::string driver::result() { return "" /* Add something here */; }
std::shared_ptr<translation_unit> driver::get() { return tu; }
void driver::set(std::shared_ptr<translation_unit> a) { tu = a; }

void driver::error(const class lex::location &loc, const std::string &msg) {
  parser->error(loc, msg);
}
void driver::ice(const char *a, unsigned b, const std::string &c) {
  fprintf(stderr, "Internal Error: %s %d %s\n", a, b, c.c_str());
}

void driver::add_typedefs(std::vector<identifier *> a) {
  for (auto i : a) {
    scanner->add_typename(i->who());
  }
}
} /* namespace c */
