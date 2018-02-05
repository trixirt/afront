/*
 * Copyright (c) 2018 Tom Rix
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
#ifndef AFRONT_FIG_PT_PT_H
#define AFRONT_FIG_PT_PT_H

#include "n.h"

class abi;
class configuration;
class constant;
class data_layout;
class endian;
class identifier;
class language_type;
class layout_option_list;
class layout_option;
class mangle;
class object_class;
class object_list;
class object;
class stack;
class string_constant;
class triple;

class abi : public n {
  abi(std::shared_ptr<string_constant> a);
  virtual ~abi(){};
  virtual void accept(visitor *a);
};

class configuration : public n {
  configuration(std::shared_ptr<data_layout> a,
                std::shared_ptr<language_type_list> b);
  configuration(std::shared_ptr<triple> a, std::shared_ptr<data_layout> b,
                std::shared_ptr<language_type_list> c);
  virtual ~configuration(){};
  virtual void accept(visitor *a);
};

class constant : public n {
  constant(lex::token a);
  virtual ~constant(){};
  virtual void accept(visitor *a);
};

class data_layout : public n {
  data_layout(std::shared_ptr<endian> a, std::shared_ptr<object_list> b);
  data_layout(std::shared_ptr<endian> a, std::shared_ptr<layout_option_list> b,
              std::shared_ptr<object_list> c);
  virtual ~data_layout(){};
  virtual void accept(visitor *a);
};

class endian : public n {
  endian(lex::token a);
  virtual ~endian(){};
  virtual void accept(visitor *a);
};

class identifier : public n {
  identifier(lex::token a);
  virtual ~identifier(){};
  virtual void accept(visitor *a);
};

class language_type : public n {
  language_type(std::shared_ptr<string_literal> a,
                std::shared_ptr<object_class> b, std::shared_ptr<constant> c);
  language_type(std::shared_ptr<string_literal> a,
                std::shared_ptr<object_class> b, std::shared_ptr<constant> c,
                std::shared_ptr<constant> d);
  virtual ~language_type(){};
  virtual void accept(visitor *a);
};

class layout_option_list : public n {
  layout_option_list(std::shared_ptr<layout_option> a);
  virtual ~layout_option_list(){};
  virtual void accept(visitor *a);
};

class layout_option : public n {
  layout_option(std::shared_ptr<stack> a);
  layout_option(std::shared_ptr<mangle> a);
  layout_option(std::shared_ptr<abi> a);
  virtual ~layout_option(){};
  virtual void accept(visitor *a);
};

class mangle : public n {
  mangle(std::shared_ptr<string_constant> a);
  virtual ~mangle(){};
  virtual void accept(visitor *a);
};

class object_class : public n {
  object_class(lex::token a);
  virtual ~object_class(){};
  virtual void accept(visitor *a);
};

class object_list : public n {
  object_list(std::shared_ptr<object> a);
  virtual ~object_list(){};
  virtual void accept(visitor *a);
};

class object : public n {
  object(std::shared_ptr<object_class> a, std::shared_ptr<constant> b);
  object(std::shared_ptr<object_class> a, std::shared_ptr<constant> b,
         std::shared_ptr<constant> c);
  virtual ~object(){};
  virtual void accept(visitor *a);
};

class stack : public n {
  stack(std::shared_ptr<constant> a);
  virtual ~stack(){};
  virtual void accept(visitor *a);
};

class string_constant : public n {
  string_constant(lex::token a);
  virtual ~string_constant(){};
  virtual void accept(visitor *a);
};

class triple : public n {
  triple(std::shared_ptr<string_constant> a);
  virtual ~triple(){};
  virtual void accept(visitor *a);
};

#endif
