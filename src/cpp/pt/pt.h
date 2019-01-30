/*
 * Copyright (c) 2019 Tom Rix
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
#ifndef AFRONT_CPP_PT_PT_H
#define AFRONT_CPP_PT_PT_H

#include "c/pt/pt.h"
#include "n.h"
#include "pt_classes.h"

class control_line : public n {
public:
  control_line();
  control_line(lex_token a, std::shared_ptr<pp_tokens> b);
  control_line(lex_token a, std::shared_ptr<identifier> b,
               std::shared_ptr<replacement_list> c);
  control_line(lex_token a, std::shared_ptr<identifier> b,
               std::shared_ptr<identifier_list> c,
               std::shared_ptr<replacement_list> d);
  control_line(lex_token a, std::shared_ptr<identifier> b, lex_token c,
               std::shared_ptr<replacement_list> d);
  control_line(lex_token a, std::shared_ptr<identifier> b,
               std::shared_ptr<identifier_list> c, lex_token d,
               std::shared_ptr<replacement_list> e);
  control_line(lex_token a, std::shared_ptr<identifier> b);
  control_line(lex_token a);

  virtual ~control_line(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class elif_group : public n {
public:
  elif_group(std::shared_ptr<constant_expr> a);
  elif_group(std::shared_ptr<constant_expr> a, std::shared_ptr<group> b);

  virtual ~elif_group(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class elif_groups : public n {
public:
  elif_groups(std::shared_ptr<elif_group> a);

  virtual ~elif_groups(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class else_group : public n {
public:
  else_group();
  else_group(std::shared_ptr<group> a);

  virtual ~else_group(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class endif_line : public n {
public:
  endif_line();

  virtual ~endif_line(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class group : public n {
public:
  group(std::shared_ptr<group_part> a);

  virtual ~group(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class group_part : public n {
public:
  group_part(std::shared_ptr<if_section> a);
  group_part(std::shared_ptr<control_line> a);
  group_part(std::shared_ptr<text_line> a);
  group_part(std::shared_ptr<non_directive> a);

  virtual ~group_part(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class if_group : public n {
public:
  if_group(lex_token a, std::shared_ptr<constant_expr> b);
  if_group(lex_token a, std::shared_ptr<constant_expr> b,
           std::shared_ptr<group> c);
  if_group(lex_token a, std::shared_ptr<identifier> b);
  if_group(lex_token a, std::shared_ptr<identifier> b,
           std::shared_ptr<group> c);

  virtual ~if_group(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class if_section : public n {
public:
  if_section(std::shared_ptr<if_group> a, std::shared_ptr<endif_line> b);
  if_section(std::shared_ptr<if_group> a, std::shared_ptr<else_group> b,
             std::shared_ptr<endif_line> c);
  if_section(std::shared_ptr<if_group> a, std::shared_ptr<elif_groups> b,
             std::shared_ptr<endif_line> c);
  if_section(std::shared_ptr<if_group> a, std::shared_ptr<elif_groups> b,
             std::shared_ptr<else_group> c, std::shared_ptr<endif_line> d);

  virtual ~if_section(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class non_directive : public n {
public:
  non_directive(std::shared_ptr<pp_tokens> a);

  virtual ~non_directive(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class pp_tokens : public n {
public:
  pp_tokens(std::shared_ptr<preprocessing_token> a);

  virtual ~pp_tokens(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class preprocessing_file : public n {
public:
  preprocessing_file();
  preprocessing_file(std::shared_ptr<group> a);

  virtual ~preprocessing_file(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class preprocessing_token : public n {
public:
  preprocessing_token(lex_token a);

  virtual ~preprocessing_token(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class replacement_list : public n {
public:
  replacement_list();
  replacement_list(std::shared_ptr<pp_tokens> a);

  virtual ~replacement_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class text_line : public n {
public:
  text_line();
  text_line(std::shared_ptr<pp_tokens> a);

  virtual ~text_line(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

#endif
