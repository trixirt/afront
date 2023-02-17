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
#include "at.h"
#include "pt.h"

scope::scope() {}

scope::scope(location &l, scope *p, std::string name) {
  _location = l;
  _super = p;
  _name = name;
  if (_super != nullptr)
    _super->_sub.push_back(this);
}

std::string scope::classname() { return "scope"; }

void scope::notify() {}

std::string scope::name() { return _name; }
size_t scope::subscopes() { return _sub.size(); }

//
// Add an enum tag to map
//
// Returns nullptr on failure, that tag is already defined
// Returns the contents of the map for the input on success
enum_specifier *scope::enum_tag(enum_specifier *a) {
  enum_specifier *ret = nullptr;
  auto c = a->children();
  // expecting { identifier, enumeration_list }
  // expecting { identifier }
  identifier *i = dynamic_cast<identifier *>(c[0].get());
  if (i != nullptr) {
    std::string s = i->id();
    // not already a struct/union
    if (_struct_or_union_tag_map.find(s) == _struct_or_union_tag_map.end()) {
      auto e = _enum_tag_map.find(s);
      if (e == _enum_tag_map.end()) {
        // easy, first time
        _enum_tag_map[s] = a;
        ret = a;
      } else {
        if (a->children().size() == 1) {
          // redundant incomplete enum
          // do not save
          // return current contents
          ret = e->second;
        } else {
          // an enum definition
          if (e->second->children().size() == 1) {
            // replace existing incomplete with complete
            _enum_tag_map[s] = a;
            ret = a;
          } else {
            // both existing and input have an enumeration_list
            // let redef check catch this
            // return current;
            ret = e->second;
          }
        }
      }
    }
  }
  return ret;
}

//
// Add a struct/union tag to map
//
// Returns nullptr on failure, that tag is already defined
// Returns the contents of the map for the input on success
struct_or_union_specifier *
scope::struct_or_union_tag(struct_or_union_specifier *a) {
  struct_or_union_specifier *ret = nullptr;
  auto c = a->children();
  // expecting { struct_or_union, identifier, struct_declaration_list }
  // expecting { struct_or_union, struct_declaration_list }
  // expecting { struct_or_union, identifier }
  identifier *i = dynamic_cast<identifier *>(c[1].get());
  if (i != nullptr) {
    std::string s = i->id();
    // not already an enum
    if (_enum_tag_map.find(s) == _enum_tag_map.end()) {
      auto sou = _struct_or_union_tag_map.find(s);
      if (sou == _struct_or_union_tag_map.end()) {
        // easy, first time..
        _struct_or_union_tag_map[s] = a;
        ret = a;
      } else {
        // previous
        if ((a->is_struct() == sou->second->is_struct()) ||
            (a->is_union() == sou->second->is_union())) {
          // make sure struct/union matches
          if (a->children().size() == 2) {
            // redundant incomplete
            // do not save
            // return current contents
            ret = sou->second;
          } else {
            // 'a' size == 3
            if (sou->second->children().size() == 2) {
              // replace existing incomplete with complete
              _struct_or_union_tag_map[s] = a;
              ret = a;
            } else {
              // both existing and input have struct_declaration_list
              // let type redef checker catch this
              // return current
              ret = sou->second;
            }
          }
        }
      }
    }
  }
  return ret;
}

//
// Add a user type to map
//
// Returns nullptr on failure, that type is already defined
// Returns input on success
class n *scope::user_type(std::string a, class n *b) {
  class n *ret = nullptr;
  if (_user_type_map.find(a) == _user_type_map.end()) {
    _user_type_map[a] = b;
    ret = b;
  }
  return ret;
}

bool scope::has_declaration(std::string a) {
  bool ret = false;
  if (_declaration_specifiers_map.find(a) != _declaration_specifiers_map.end())
    ret = true;
  return ret;
}
declaration_specifiers * scope::get_declaration(std::string a) {
  declaration_specifiers *ret = nullptr;
  if (has_declaration(a)) {
    ret = _declaration_specifiers_map[a];
  }
  return ret;
}
void scope::set_declaration(std::string a, declaration_specifiers *b) {
  if (!has_declaration(a)) {
    _declaration_specifiers_map[a] = b;
  }
}
