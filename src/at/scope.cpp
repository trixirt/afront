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
#include "at.h"
#include "pt.h"

scope::scope() {}

scope::scope(location &l, scope *p, std::string name) {
  loc = l;
  super = p;
  n = name;
  if (super != nullptr)
    super->sub.push_back(this);
}

std::string scope::classname() { return "scope"; }

void scope::notify() {}

std::string scope::name() { return n; }
size_t scope::subscopes() { return sub.size(); }

enum_specifier *scope::enum_tag(enum_specifier *a) {
  enum_specifier *ret = nullptr;
  auto c = a->children();
  // expecting { identifier, enumerator_list }
  if (c.size() == 2) {
    identifier *i = dynamic_cast<identifier *>(c.front().get());
    if (i != nullptr) {
      std::string s = i->id();
      if (!has_tag(s)) {
        enum_tag_map[s] = a;
        ret = a;
      }
    }
  }
  return ret;
}

struct_or_union_specifier *
scope::struct_or_union_tag(struct_or_union_specifier *a) {
  struct_or_union_specifier *ret = nullptr;
  auto c = a->children();
  // expecting { struct_or_union, identifier, struct_declaration_list }
  if (c.size() == 3) {
    identifier *i = dynamic_cast<identifier *>(c[1].get());
    if (i != nullptr) {
      std::string s = i->id();
      if (!has_tag(s)) {
        struct_or_union_tag_map[s] = a;
        ret = a;
      }
    }
  }
  return ret;
}

bool scope::has_tag(std::string a) {
  bool ret = false;
  if (enum_tag_map.find(a) != enum_tag_map.end())
    ret = true;
  else if (struct_or_union_tag_map.find(a) != struct_or_union_tag_map.end())
    ret = true;
  return ret;
}
