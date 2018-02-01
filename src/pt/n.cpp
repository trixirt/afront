/*
 * Copyright (c) 2017 Tom Rix
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
#include "n.h"
#include "e.h"
#include "l/location.h"

n::n() : m() {}
n::n(lex::token a) : m() { lt = a; }
class lex::location &n::here() {
  return lt.here();
}
signed n::what() { return lt.what(); }

std::string n::where() {
  if (what() != -1) {
    class lex::location l = here();
    if (l.begin.filename != nullptr) {
      std::string r = *l.begin.filename;
      r += ':';
      r += std::to_string(l.begin.line);
      r += ':';
      r += std::to_string(l.begin.column);
      return r;
    } else {
      return "";
    }
  } else {
    return "";
  }
}

std::string n::who() {
  if (what() != -1)
    return lt.text();
  else
    return "";
}

std::string n::classname() { return "n"; };

// add child, back
class n &n::operator+=(const std::shared_ptr<n> &rhs) {
  std::shared_ptr<m> mrhs = rhs;
  m::operator+=(mrhs);
  // the parent loction expands to cover child
  lt += rhs->lt;
  return *this;
}

// add child, front
class n &n::operator*=(const std::shared_ptr<n> &rhs) {
  std::shared_ptr<m> mrhs = rhs;
  m::operator*=(mrhs);
  // the parent loction expands to cover child
  lt += rhs->lt;
  return *this;
}
