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
#ifndef NADA_LEX_LOCATION_H
#define NADA_LEX_LOCATION_H
#include <iostream>
#include <string>
namespace lex {
class pos {
public:
  pos() : line(1), column(1){};
  std::string *filename;
  unsigned int line;
  unsigned int column;

  class pos &operator=(const class pos &rhs) {
    filename = rhs.filename;
    line = rhs.line;
    column = rhs.column;
    return *this;
  }

  class pos &operator<<=(const class pos &rhs) {
    if (filename == nullptr) {
      *this = rhs;
    } else {
      if (rhs.line < line) {
        line = rhs.line;
        column = rhs.column;
      } else if ((rhs.line == line) && (rhs.column < column)) {
        column = rhs.column;
      }
    }
    return *this;
  }
  class pos &operator>>=(const class pos &rhs) {
    if (filename == nullptr) {
      *this = rhs;
    } else {
      if (rhs.line > line) {
        line = rhs.line;
        column = rhs.column;
      } else if ((rhs.line == line) && (rhs.column > column)) {
        column = rhs.column;
      }
    }
    return *this;
  }
};

class location {
public:
  location() {}
  void step() { begin = end; }
  void columns(int a = 1) { end.column += a; }
  void lines() {
    end.line += 1;
    end.column = 1;
  }

  class location &operator+=(const class location &rhs) {
    if ((rhs.begin.filename != nullptr) && (rhs.end.filename != nullptr)) {
      begin <<= rhs.begin;
      end >>= rhs.end;
    }
    return *this;
  }
  class pos begin;
  class pos end;
};

//
// Necessary when %debug or similar directive is used
static inline std::ostream &operator<<(std::ostream &o,
                                       const class location &l) {
  if (l.begin.filename != nullptr) {
    o << *l.begin.filename;
    o << " ";
    o << l.begin.line << ':' << l.begin.column;
    o << " - ";
    o << l.end.line << ':' << l.end.column;
  }
  return o;
}
} // namespace lex
#endif
