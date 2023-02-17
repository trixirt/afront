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
#ifndef AFRONT_AT_SCOPE_H
#define AFRONT_AT_SCOPE_H

#include "ast.h"
#include "l/lex_token.h"
#include "pt/pt_classes.h"
#include <map>
#include <vector>

class enum_specifier;
class n;
class struct_or_union_specifier;

class scope : public ast {
public:
  scope();
  scope(location &loc, scope *parent = nullptr, std::string name = "");
  virtual ~scope(){};
  virtual void notify();
  virtual std::string classname();
  std::string name();
  size_t subscopes();
  enum_specifier *enum_tag(enum_specifier *a);
  bool has_tag(std::string a);
  struct_or_union_specifier *struct_or_union_tag(struct_or_union_specifier *a);
  n *user_type(std::string a, n *b);
  // check if a declaration has already been made at this scope
  bool has_declaration(std::string a);
  // get the scope's declaration
  declaration_specifiers *get_declaration(std::string a);
  // set declaration to this scope
  void set_declaration(std::string a, declaration_specifiers *b);

private:
  location _location;
  std::string _name;
  scope *_super;
  std::vector<scope *> _sub;
  std::map<std::string, enum_specifier *> _enum_tag_map;
  std::map<std::string, struct_or_union_specifier *> _struct_or_union_tag_map;
  std::map<std::string, class n *> _user_type_map;
  std::map<std::string, declaration_specifiers *> _declaration_specifiers_map;
};

#endif
