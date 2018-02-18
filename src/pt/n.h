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
#ifndef AFRONT_C_PT_N_H
#define AFRONT_C_PT_N_H

#include "con/m.h"
#include "l/lex_token.h"
#include <exception>
#include <string>

class n : public m {
public:
  n();
  n(lex_token a);
  virtual ~n(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  /* add to children, back */
  class n &operator+=(const std::shared_ptr<n> &rhs);
  /* add to children, front */
  class n &operator*=(const std::shared_ptr<n> &rhs);
  class location &here();
  std::string where();
  signed what();
  std::string who();

private:
  lex_token lt;
};

class visitor_exception : public std::exception {
public:
  visitor_exception(std::string a, class m *b) : exception() {
    s = a;
    e = dynamic_cast<n *>(b);
  };
  ~visitor_exception() {}
  virtual const char *what() { return s.c_str(); }
  virtual class n *who() { return e; }

private:
  std::string s;
  class n *e;
};

#endif
