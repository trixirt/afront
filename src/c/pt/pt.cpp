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
#include "pt.h"
#include "e.h"
#include "v/observers.h"
#include "v/ping.h"
#include "v/typedefs.h"

abstract_array_declarator::abstract_array_declarator() {}
abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a) {
  *this += a;
}
abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<constant_expr> a) {
  *this += a;
}
abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<constant_expr> b) {
  *this += a;
  *this += b;
}

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<assignment_expr> a) {
  *this += a;
}
abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<assignment_expr> b) {
  *this += a;
  *this += b;
}

abstract_array_declarator::abstract_array_declarator(lex_token a) : n(a) {}
abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a, lex_token b)
    : n(b) {
  *this += a;
}

abstract_array_declarator::abstract_array_declarator(
    lex_token a, std::shared_ptr<assignment_expr> b)
    : n(a) {
  *this += b;
}

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a, lex_token b,
    std::shared_ptr<assignment_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}

abstract_array_declarator::abstract_array_declarator(
    lex_token a, std::shared_ptr<type_qualifier_list> b,
    std::shared_ptr<assignment_expr> c)
    : n(a) {
  *this += b;
  *this += c;
}

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a, lex_token b,
    std::shared_ptr<type_qualifier_list> c, std::shared_ptr<assignment_expr> d)
    : n(b) {
  *this += a;
  *this += c;
  *this += d;
}

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<type_qualifier_list> a, lex_token b,
    std::shared_ptr<assignment_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}

void abstract_array_declarator::accept(visitor *a) { a->v(this); }
void abstract_array_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string abstract_array_declarator::classname() {
  return "abstract_array_declarator";
}

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<type_qualifier_list> b, lex_token c,
    std::shared_ptr<assignment_expr> d)
    : n(c) {
  *this += a;
  *this += b;
  *this += d;
}

abstract_declarator::abstract_declarator(std::shared_ptr<pointer> a) {
  *this += a;
}
abstract_declarator::abstract_declarator(
    std::shared_ptr<direct_abstract_declarator> a) {
  *this += a;
}
abstract_declarator::abstract_declarator(
    std::shared_ptr<pointer> a, std::shared_ptr<direct_abstract_declarator> b) {
  *this += a;
  *this += b;
}

void abstract_declarator::accept(visitor *a) { a->v(this); }
void abstract_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string abstract_declarator::classname() { return "abstract_declarator"; }
bool abstract_declarator::has_pointer() {
  bool ret = false;
  auto c = children();
  // expecting { pointer }
  // expecting { pointer direct_abstract_declarator }
  // expecting { direct_abstract_declarator }
  pointer *p = dynamic_cast<pointer *>(c[0].get());
  if (p != nullptr)
    ret = true;
  return ret;
}

abstract_function_declarator::abstract_function_declarator() {}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<parameter_type_list> a) {
  *this += a;
}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<direct_abstract_declarator> a) {
  *this += a;
}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<parameter_type_list> b) {
  *this += a;
  *this += b;
}

void abstract_function_declarator::accept(visitor *a) { a->v(this); }
void abstract_function_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string abstract_function_declarator::classname() {
  return "abstract_function_declarator";
}

additive_expr::additive_expr(std::shared_ptr<multiplicative_expr> a) {
  *this += a;
}
additive_expr::additive_expr(std::shared_ptr<additive_expr> a, lex_token b,
                             std::shared_ptr<multiplicative_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void additive_expr::accept(visitor *a) { a->v(this); }
void additive_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string additive_expr::classname() { return "additive_expr"; }

// Alignment Specifier 6.7.5
alignment_specifier::alignment_specifier(std::shared_ptr<type_name> a) {
  *this += a;
}
alignment_specifier::alignment_specifier(std::shared_ptr<constant_expr> a) {
  *this += a;
}
void alignment_specifier::accept(visitor *a) { a->v(this); }
void alignment_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string alignment_specifier::classname() { return "alignment_specifier"; }

and_expr::and_expr(std::shared_ptr<equality_expr> a) { *this += a; }
and_expr::and_expr(std::shared_ptr<and_expr> a, lex_token b,
                   std::shared_ptr<equality_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void and_expr::accept(visitor *a) { a->v(this); }
void and_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string and_expr::classname() { return "and_expr"; }

argument_expr_list::argument_expr_list(std::shared_ptr<assignment_expr> a) {
  *this += a;
}
void argument_expr_list::accept(visitor *a) { a->v(this); }
void argument_expr_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string argument_expr_list::classname() { return "argument_expr_list"; }

array_declarator::array_declarator(std::shared_ptr<direct_declarator> a) {
  *this += a;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   std::shared_ptr<constant_expr> b) {
  *this += a;
  *this += b;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   std::shared_ptr<assignment_expr> b) {
  *this += a;
  *this += b;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   std::shared_ptr<type_qualifier_list> b) {
  *this += a;
  *this += b;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   lex_token b,
                                   std::shared_ptr<assignment_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   lex_token b,
                                   std::shared_ptr<type_qualifier_list> c,
                                   std::shared_ptr<assignment_expr> d)
    : n(b) {
  *this += a;
  *this += c;
  *this += d;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   std::shared_ptr<type_qualifier_list> b,
                                   lex_token c,
                                   std::shared_ptr<assignment_expr> d)
    : n(c) {
  *this += a;
  *this += b;
  *this += d;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   lex_token b)
    : n(b) {
  *this += a;
}
array_declarator::array_declarator(std::shared_ptr<direct_declarator> a,
                                   std::shared_ptr<type_qualifier_list> b,
                                   lex_token c)
    : n(c) {
  *this += a;
  *this += b;
}
void array_declarator::accept(visitor *a) { a->v(this); }
void array_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string array_declarator::classname() { return "array_declarator"; }

assignment_expr::assignment_expr(std::shared_ptr<conditional_expr> a) {
  *this += a;
}
assignment_expr::assignment_expr(std::shared_ptr<unary_expr> _a,
                                 std::shared_ptr<assignment_operator> _b,
                                 std::shared_ptr<assignment_expr> _c) {
  *this += _a;
  *this += _b;
  *this += _c;
}
void assignment_expr::accept(visitor *a) { a->v(this); }
void assignment_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string assignment_expr::classname() { return "assignment_expr"; }

assignment_operator::assignment_operator(lex_token a) : n(a) {}
void assignment_operator::accept(visitor *a) { a->v(this); }
void assignment_operator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string assignment_operator::classname() { return "assignment_operator"; }

atomic_type_specifier::atomic_type_specifier(std::shared_ptr<type_name> a) {
  *this += a;
}
void atomic_type_specifier::accept(visitor *a) { a->v(this); }
void atomic_type_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string atomic_type_specifier::classname() {
  return "atomic_type_specifier";
}

block_item::block_item(std::shared_ptr<declaration> a) { *this += a; }
block_item::block_item(std::shared_ptr<statement> a) { *this += a; }
void block_item::accept(visitor *a) { a->v(this); }
void block_item::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string block_item::classname() { return "block_item"; }

block_item_list::block_item_list(std::shared_ptr<block_item> a) { *this += a; }
void block_item_list::accept(visitor *a) { a->v(this); }
void block_item_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string block_item_list::classname() { return "block_item_list"; }

cast_expr::cast_expr(std::shared_ptr<unary_expr> a) { *this += a; }
cast_expr::cast_expr(std::shared_ptr<type_name> a,
                     std::shared_ptr<cast_expr> b) {
  *this += a;
  *this += b;
}
void cast_expr::accept(visitor *a) { a->v(this); }
void cast_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string cast_expr::classname() { return "cast_expr"; }

compound_statement::compound_statement() {}
compound_statement::compound_statement(std::shared_ptr<statement_list> a) {
  *this += a;
}
compound_statement::compound_statement(std::shared_ptr<declaration_list> a) {
  *this += a;
}
compound_statement::compound_statement(std::shared_ptr<declaration_list> a,
                                       std::shared_ptr<statement_list> b) {
  *this += a;
  *this += b;
}
compound_statement::compound_statement(std::shared_ptr<block_item_list> a) {
  *this += a;
}
void compound_statement::accept(visitor *a) { a->v(this); }
void compound_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string compound_statement::classname() { return "compound_statement"; }

conditional_expr::conditional_expr(std::shared_ptr<logical_or_expr> a) {
  *this += a;
}
conditional_expr::conditional_expr(std::shared_ptr<logical_or_expr> _a,
                                   std::shared_ptr<logical_or_expr> _b,
                                   std::shared_ptr<conditional_expr> _c) {
  *this += _a;
  *this += _b;
  *this += _c;
}
void conditional_expr::accept(visitor *a) { a->v(this); }
void conditional_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string conditional_expr::classname() { return "conditional_expr"; }

constant_expr::constant_expr(std::shared_ptr<conditional_expr> a) {
  *this += a;
}
void constant_expr::accept(visitor *a) { a->v(this); }
void constant_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string constant_expr::classname() { return "constant_expr"; }

declaration::declaration(std::shared_ptr<declaration_specifiers> a) {
  *this += a;
}
declaration::declaration(std::shared_ptr<declaration_specifiers> a,
                         std::shared_ptr<init_declarator_list> b) {
  *this += a;
  *this += b;
}
declaration::declaration(std::shared_ptr<static_assert_declaration> a) {
  *this += a;
}
void declaration::accept(visitor *a) { a->v(this); }
void declaration::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string declaration::classname() { return "declaration"; }
bool declaration::find_typedefs(std::vector<identifier *> &a) {
  bool ret = false;
  if (!a.empty())
    throw(ice_exception(__FILE__, __LINE__, "identifier list should be empty"));

  class typedefs *v = new typedefs();
  if (v) {
    this->accept(v);
    if (v->is()) {
      a = v->get();
      if (!a.empty())
        ret = true;
    }
    delete (v);
    v = nullptr;
  } else {
    throw(ice_exception(__FILE__, __LINE__, "allocating typedef visitor"));
  }
  return ret;
}

declaration_list::declaration_list(std::shared_ptr<declaration> a) {
  *this += a;
}
void declaration_list::accept(visitor *a) { a->v(this); }
void declaration_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string declaration_list::classname() { return "declaration_list"; }

//
// 6.7.6 Declarators
declarator::declarator(std::shared_ptr<direct_declarator> a) { *this += a; }
declarator::declarator(std::shared_ptr<pointer> a,
                       std::shared_ptr<direct_declarator> b) {
  *this += a;
  *this += b;
}
void declarator::accept(visitor *a) { a->v(this); }
void declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string declarator::classname() { return "declarator"; }
identifier *declarator::identifier() {
  class identifier *ret = nullptr;
  std::shared_ptr<single_fetch_observer<class identifier>> o =
      std::shared_ptr<single_fetch_observer<class identifier>>(
          new single_fetch_observer<class identifier>());
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    ret = o->get();
    delete v;
    v = nullptr;
  }
  m::clear();
  return ret;
}

bool declarator::has_pointer() {
  bool ret = false;
  auto c = children(); // expecting { direct_declarator }
  // expecting { pointer direct_declarator }
  pointer *p = dynamic_cast<pointer *>(c[0].get());
  if (p != nullptr)
    ret = true;
  return ret;
}

enumeration_constant::enumeration_constant(std::shared_ptr<identifier> a) {
  *this += a;
}
void enumeration_constant::accept(visitor *a) { a->v(this); }
void enumeration_constant::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string enumeration_constant::classname() { return "enumeration_constant"; }

enumerator::enumerator(std::shared_ptr<enumeration_constant> a) { *this += a; }
enumerator::enumerator(std::shared_ptr<enumeration_constant> a,
                       std::shared_ptr<constant_expr> b) {
  *this += a;
  *this += b;
}
void enumerator::accept(visitor *a) { a->v(this); }
void enumerator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string enumerator::classname() { return "enumerator"; }

enumerator_list::enumerator_list(std::shared_ptr<enumerator> a) { *this += a; }
void enumerator_list::accept(visitor *a) { a->v(this); }
void enumerator_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string enumerator_list::classname() { return "enumerator_list"; }
//
// Add enumerator to map
//
// Returns nullptr on failure, that enumerator is already defined
// Returns input on success
enumerator *enumerator_list::update_map(enumerator *a) {
  enumerator *ret = nullptr;
  auto c = a->children();
  // expecting { enumeration-constant }
  // expecting { enumeration-constant constant-expression }
  enumeration_constant *ec = dynamic_cast<enumeration_constant *>(c[0].get());
  if (ec != nullptr) {
    auto c = ec->children();
    // expecting { identifier }
    identifier *i = dynamic_cast<identifier *>(c[0].get());
    if (i != nullptr) {
      std::string s = i->id();
      if (enumerator_map.find(s) == enumerator_map.end()) {
        enumerator_map[s] = a;
        ret = a;
      } else {
        // identifier is already in the map
        // the input is a redefinition of an existing
        // enumerator.
        //
        // return nullptr
      }

    } else {
      throw(
          ice_exception(__FILE__, __LINE__, "malformed enumeration constant"));
    }
  } else {
    throw(ice_exception(__FILE__, __LINE__, "malformed enumerator"));
  }
  return ret;
}

equality_expr::equality_expr(std::shared_ptr<relation_expr> a) { *this += a; }
equality_expr::equality_expr(std::shared_ptr<equality_expr> a, lex_token b,
                             std::shared_ptr<relation_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void equality_expr::accept(visitor *a) { a->v(this); }
void equality_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string equality_expr::classname() { return "equality_expr"; }

exclusive_or_expr::exclusive_or_expr(std::shared_ptr<and_expr> a) {
  *this += a;
}
exclusive_or_expr::exclusive_or_expr(std::shared_ptr<exclusive_or_expr> a,
                                     lex_token b, std::shared_ptr<and_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void exclusive_or_expr::accept(visitor *a) { a->v(this); }
void exclusive_or_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string exclusive_or_expr::classname() { return "exclusive_or_expr"; }

declaration_specifiers::declaration_specifiers(
    std::shared_ptr<storage_class_specifier> a) {
  *this += a;
}

declaration_specifiers::declaration_specifiers(
    std::shared_ptr<type_specifier> a) {
  *this += a;
}
declaration_specifiers::declaration_specifiers(
    std::shared_ptr<type_qualifier> a) {
  *this += a;
}

declaration_specifiers::declaration_specifiers(
    std::shared_ptr<function_specifier> a) {
  *this += a;
}

declaration_specifiers::declaration_specifiers(
    std::shared_ptr<alignment_specifier> a) {
  *this += a;
}
void declaration_specifiers::accept(visitor *a) { a->v(this); }
void declaration_specifiers::notify() {
  for (auto i : observers)
    i->update(this);
}

std::string declaration_specifiers::classname() {
  return "declaration_specifiers";
}

void declaration_specifiers::storage_class_specifiers(
    std::vector<storage_class_specifier *> *a) {
  std::shared_ptr<fetch_observer<class storage_class_specifier>> o =
      std::shared_ptr<fetch_observer<class storage_class_specifier>>(
          new fetch_observer<class storage_class_specifier>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

void declaration_specifiers::type_specifiers(std::vector<type_specifier *> *a) {
  std::shared_ptr<fetch_observer<class type_specifier>> o =
      std::shared_ptr<fetch_observer<class type_specifier>>(
          new fetch_observer<class type_specifier>(a));
  m::attach(o);
  // type-specifier is recursive
  // so limit ping to a depth of 1
  class ping *v = new ping(true /* preorder */, 1 /* depth */);
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

void declaration_specifiers::type_qualifiers(std::vector<type_qualifier *> *a) {
  std::shared_ptr<fetch_observer<class type_qualifier>> o =
      std::shared_ptr<fetch_observer<class type_qualifier>>(
          new fetch_observer<class type_qualifier>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

void declaration_specifiers::function_specifiers(
    std::vector<function_specifier *> *a) {
  std::shared_ptr<fetch_observer<class function_specifier>> o =
      std::shared_ptr<fetch_observer<class function_specifier>>(
          new fetch_observer<class function_specifier>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

void declaration_specifiers::alignment_specifiers(
    std::vector<alignment_specifier *> *a) {
  std::shared_ptr<fetch_observer<class alignment_specifier>> o =
      std::shared_ptr<fetch_observer<class alignment_specifier>>(
          new fetch_observer<class alignment_specifier>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

direct_abstract_declarator::direct_abstract_declarator(
    std::shared_ptr<abstract_declarator> a) {
  *this += a;
}
direct_abstract_declarator::direct_abstract_declarator(
    std::shared_ptr<abstract_array_declarator> a) {
  *this += a;
}
direct_abstract_declarator::direct_abstract_declarator(
    std::shared_ptr<abstract_function_declarator> a) {
  *this += a;
}

void direct_abstract_declarator::accept(visitor *a) { a->v(this); }
void direct_abstract_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string direct_abstract_declarator::classname() {
  return "direct_abstract_declarator";
}

direct_declarator::direct_declarator(std::shared_ptr<identifier> a) {
  *this += a;
}
direct_declarator::direct_declarator(std::shared_ptr<declarator> a) {
  *this += a;
}
direct_declarator::direct_declarator(std::shared_ptr<array_declarator> a) {
  *this += a;
}
direct_declarator::direct_declarator(std::shared_ptr<function_declarator> a) {
  *this += a;
}

void direct_declarator::accept(visitor *a) { a->v(this); }
void direct_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string direct_declarator::classname() { return "direct_declarator"; }

enum_specifier::enum_specifier(std::shared_ptr<enumerator_list> a) {
  *this += a;
}
enum_specifier::enum_specifier(std::shared_ptr<identifier> a,
                               std::shared_ptr<enumerator_list> b) {
  *this += a;
  *this += b;
}
enum_specifier::enum_specifier(std::shared_ptr<identifier> a) { *this += a; }
void enum_specifier::accept(visitor *a) { a->v(this); }
void enum_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string enum_specifier::classname() { return "enum_specifier"; }

expr::expr(std::shared_ptr<assignment_expr> a) { *this += a; }
expr::expr(std::shared_ptr<expr> a, std::shared_ptr<assignment_expr> b) {
  *this += a;
  *this += b;
}
void expr::accept(visitor *a) { a->v(this); }
void expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string expr::classname() { return "expr"; }

expression_statement::expression_statement() {}
expression_statement::expression_statement(std::shared_ptr<expr> a) {
  *this += a;
}
void expression_statement::accept(visitor *a) { a->v(this); }
void expression_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string expression_statement::classname() { return "expression_statement"; }

external_definition::external_definition(
    std::shared_ptr<function_definition> a) {
  *this += a;
}
external_definition::external_definition(std::shared_ptr<declaration> a) {
  *this += a;
}
void external_definition::accept(visitor *a) { a->v(this); }
void external_definition::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string external_definition::classname() { return "external_definition"; }

function_body::function_body(std::shared_ptr<compound_statement> a) {
  *this += a;
}
function_body::function_body(std::shared_ptr<declaration_list> a,
                             std::shared_ptr<compound_statement> b) {
  *this += a;
  *this += b;
}
void function_body::accept(visitor *a) { a->v(this); }
void function_body::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string function_body::classname() { return "function_body"; }

function_declarator::function_declarator(std::shared_ptr<direct_declarator> a) {
  *this += a;
}
function_declarator::function_declarator(
    std::shared_ptr<direct_declarator> a,
    std::shared_ptr<parameter_type_list> b) {
  *this += a;
  *this += b;
}
function_declarator::function_declarator(std::shared_ptr<direct_declarator> a,
                                         std::shared_ptr<identifier_list> b) {
  *this += a;
  *this += b;
}

void function_declarator::accept(visitor *a) { a->v(this); }
void function_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string function_declarator::classname() { return "function_declarator"; }

//
// 6.9.1 Function Definition
function_definition::function_definition(std::shared_ptr<declarator> a,
                                         std::shared_ptr<function_body> b) {
  *this += a;
  *this += b;
}
function_definition::function_definition(
    std::shared_ptr<declaration_specifiers> a, std::shared_ptr<declarator> b,
    std::shared_ptr<function_body> c) {
  *this += a;
  *this += b;
  *this += c;
}
void function_definition::accept(visitor *a) { a->v(this); }
void function_definition::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string function_definition::classname() { return "function_definition"; }
std::string function_definition::functionname() {
  std::string ret = "";
  for (auto c : children()) {
    declarator *d = dynamic_cast<declarator *>(c.get());
    if (d != nullptr) {
      identifier *i = d->identifier();
      if (i != nullptr) {
        ret = i->id();
      }
      break;
    }
  }
  return ret;
}
labeled_statement *function_definition::label(labeled_statement *a) {
  labeled_statement *ret = nullptr;
  auto c = a->children();
  // expecting { identifier, statement }
  if (c.size() == 2) {
    identifier *i = dynamic_cast<identifier *>(c[0].get());
    if (i != nullptr) {
      std::string s = i->id();
      auto itr = label_map.find(s);
      if (itr == label_map.end()) {
        label_map[s] = a;
        ret = a;
      } else {
        ret = itr->second;
      }
    }
  }
  return ret;
}

function_specifier::function_specifier(lex_token a) : n(a) {}
void function_specifier::accept(visitor *a) { a->v(this); }
void function_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string function_specifier::classname() { return "function_specifier"; }

generic_assoc_list::generic_assoc_list(std::shared_ptr<generic_association> a) {
  *this += a;
}
void generic_assoc_list::accept(visitor *a) { a->v(this); }
void generic_assoc_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string generic_assoc_list::classname() { return "generic_assoc_list"; }

generic_association::generic_association(std::shared_ptr<assignment_expr> a) {
  *this += a;
}
generic_association::generic_association(std::shared_ptr<type_name> a,
                                         std::shared_ptr<assignment_expr> b) {
  *this += a;
  *this += b;
}
void generic_association::accept(visitor *a) { a->v(this); }
void generic_association::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string generic_association::classname() { return "generic_association"; }

generic_selection::generic_selection(std::shared_ptr<assignment_expr> a,
                                     std::shared_ptr<generic_assoc_list> b) {
  *this += a;
  *this += b;
}
void generic_selection::accept(visitor *_a) { _a->v(this); }
void generic_selection::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string generic_selection::classname() { return "generic_selection"; }

//
// 6.4.2 Identifiers
identifier::identifier(lex_token a) : n(a) {}
void identifier::accept(visitor *a) { a->v(this); }
void identifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string identifier::classname() { return "identifier"; }
std::string identifier::id() { return who(); }

identifier_list::identifier_list(std::shared_ptr<identifier> a) { *this += a; }
void identifier_list::accept(visitor *a) { a->v(this); }
void identifier_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string identifier_list::classname() { return "identifier_list"; }

inclusive_or_expr::inclusive_or_expr(std::shared_ptr<exclusive_or_expr> a) {
  *this += a;
}
inclusive_or_expr::inclusive_or_expr(std::shared_ptr<inclusive_or_expr> a,
                                     lex_token b,
                                     std::shared_ptr<exclusive_or_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void inclusive_or_expr::accept(visitor *a) { a->v(this); }
void inclusive_or_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string inclusive_or_expr::classname() { return "inclusive_or_expr"; }

iteration_statement::iteration_statement(lex_token a, std::shared_ptr<expr> b,
                                         std::shared_ptr<statement> c)
    : n(a) {
  *this += b;
  *this += c;
}
iteration_statement::iteration_statement(lex_token a,
                                         std::shared_ptr<statement> b,
                                         lex_token c, std::shared_ptr<expr> d)
    : n(a) {
  *this += b;
  *this += d;
}

iteration_statement::iteration_statement(lex_token a, std::shared_ptr<expr> b,
                                         std::shared_ptr<expr> c,
                                         std::shared_ptr<expr> d,
                                         std::shared_ptr<statement> e)
    : n(a) {
  *this += b;
  *this += c;
  *this += d;
  *this += e;
}
iteration_statement::iteration_statement(lex_token a,
                                         std::shared_ptr<declaration> b,
                                         std::shared_ptr<expr> c,
                                         std::shared_ptr<expr> d,
                                         std::shared_ptr<statement> e)
    : n(a) {
  *this += b;
  *this += c;
  *this += d;
  *this += e;
}
void iteration_statement::accept(visitor *a) { a->v(this); }
void iteration_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string iteration_statement::classname() { return "iteration_statement"; }

init_declarator::init_declarator(std::shared_ptr<declarator> a) { *this += a; }
init_declarator::init_declarator(std::shared_ptr<declarator> a,
                                 std::shared_ptr<initializer> b) {
  *this += a;
  *this += b;
}
void init_declarator::accept(visitor *a) { a->v(this); }
void init_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string init_declarator::classname() { return "init_declarator"; }

init_declarator_list::init_declarator_list(std::shared_ptr<init_declarator> a) {
  *this += a;
}
void init_declarator_list::accept(visitor *a) { a->v(this); }
void init_declarator_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string init_declarator_list::classname() { return "init_declarator_list"; }
void init_declarator_list::declarators(std::vector<declarator *> *a) {
  std::shared_ptr<fetch_observer<class declarator>> o =
      std::shared_ptr<fetch_observer<class declarator>>(
          new fetch_observer<class declarator>(a));
  m::attach(o);
  // declarators are recursive
  // the list itself is depth 1
  // to get to the contents of the list is depth 2
  class ping *v = new ping(true /* preorder */, 2 /* depth */);
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

initializer::initializer(std::shared_ptr<assignment_expr> a) { *this += a; }
initializer::initializer(std::shared_ptr<initializer_list> a) { *this += a; }
void initializer::accept(visitor *a) { a->v(this); }
void initializer::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string initializer::classname() { return "initializer"; }

initializer_list::initializer_list(std::shared_ptr<initializer> a) {
  *this += a;
}
void initializer_list::accept(visitor *a) { a->v(this); }
void initializer_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string initializer_list::classname() { return "initializer_list"; }

jump_statement::jump_statement(lex_token a) : n(a) {}
jump_statement::jump_statement(lex_token a, std::shared_ptr<identifier> b)
    : n(a) {

  *this += b;
}
jump_statement::jump_statement(lex_token a, std::shared_ptr<expr> b) : n(a) {
  *this += b;
}
void jump_statement::accept(visitor *a) { a->v(this); }
void jump_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string jump_statement::classname() { return "jump_statement"; }

labeled_statement::labeled_statement(std::shared_ptr<identifier> a,
                                     std::shared_ptr<statement> b) {
  *this += a;
  *this += b;
}
labeled_statement::labeled_statement(lex_token a,
                                     std::shared_ptr<constant_expr> b,
                                     std::shared_ptr<statement> c)
    : n(a) {
  *this += b;
  *this += c;
}
labeled_statement::labeled_statement(lex_token a, std::shared_ptr<statement> b)
    : n(a) {
  *this += b;
}
void labeled_statement::accept(visitor *a) { a->v(this); }
void labeled_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string labeled_statement::classname() { return "labeled_statement"; }

logical_and_expr::logical_and_expr(std::shared_ptr<inclusive_or_expr> a) {
  *this += a;
}
logical_and_expr::logical_and_expr(std::shared_ptr<logical_and_expr> a,
                                   lex_token b,
                                   std::shared_ptr<inclusive_or_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void logical_and_expr::accept(visitor *a) { a->v(this); }
void logical_and_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string logical_and_expr::classname() { return "logical_and_expr"; }

logical_or_expr::logical_or_expr(std::shared_ptr<logical_and_expr> a) {
  *this += a;
}
logical_or_expr::logical_or_expr(std::shared_ptr<logical_or_expr> a,
                                 lex_token b,
                                 std::shared_ptr<logical_and_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void logical_or_expr::accept(visitor *a) { a->v(this); }
void logical_or_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string logical_or_expr::classname() { return "logical_or_expr"; }

multiplicative_expr::multiplicative_expr(std::shared_ptr<cast_expr> a) {
  *this += a;
}
multiplicative_expr::multiplicative_expr(std::shared_ptr<multiplicative_expr> a,
                                         lex_token b,
                                         std::shared_ptr<cast_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void multiplicative_expr::accept(visitor *a) { a->v(this); }
void multiplicative_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string multiplicative_expr::classname() { return "multiplicative_expr"; }

parameter_declaration::parameter_declaration(
    std::shared_ptr<declaration_specifiers> _a,
    std::shared_ptr<declarator> _b) {
  *this += _a;
  *this += _b;
}
parameter_declaration::parameter_declaration(
    std::shared_ptr<declaration_specifiers> _a,
    std::shared_ptr<abstract_declarator> _b) {
  *this += _a;
  *this += _b;
}

parameter_declaration::parameter_declaration(
    std::shared_ptr<declaration_specifiers> _a) {
  *this += _a;
}

void parameter_declaration::accept(visitor *a) { a->v(this); }
void parameter_declaration::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string parameter_declaration::classname() {
  return "parameter_declaration";
}

parameter_list::parameter_list(std::shared_ptr<parameter_declaration> a) {
  *this += a;
}
void parameter_list::accept(visitor *a) { a->v(this); }
void parameter_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string parameter_list::classname() { return "parameter_list"; }

parameter_type_list::parameter_type_list(std::shared_ptr<parameter_list> a) {
  *this += a;
}
parameter_type_list::parameter_type_list(std::shared_ptr<parameter_list> a,
                                         lex_token b)
    : n(b) {
  *this += a;
}

void parameter_type_list::accept(visitor *a) { a->v(this); }
void parameter_type_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string parameter_type_list::classname() { return "parameter_type_list"; }
bool parameter_type_list::has_vararg() {
  bool ret = false;
  if (what() == afront::parser::token::ELIPSIS)
    ret = true;
  return ret;
}

pointer::pointer() {}
pointer::pointer(std::shared_ptr<type_qualifier_list> a) { *this += a; }
pointer::pointer(std::shared_ptr<pointer> a) { *this += a; }
pointer::pointer(std::shared_ptr<type_qualifier_list> a,
                 std::shared_ptr<pointer> b) {
  *this += a;
  *this += b;
}

void pointer::accept(visitor *a) { a->v(this); }
void pointer::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string pointer::classname() { return "pointer"; }

postfix_expr::postfix_expr(std::shared_ptr<primary_expr> a) { *this += a; }
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a,
                           std::shared_ptr<expr> b) {
  *this += a;
  *this += b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a) { *this += a; }
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a,
                           std::shared_ptr<argument_expr_list> b) {
  *this += a;
  *this += b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a,
                           std::shared_ptr<identifier> b) {
  *this += a;
  *this += b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a, lex_token b,
                           std::shared_ptr<identifier> c)
    : n(b) {
  *this += a;
  *this += c;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> a, lex_token b)
    : n(b) {
  *this += a;
}
postfix_expr::postfix_expr(std::shared_ptr<type_name> a,
                           std::shared_ptr<identifier_list> b) {
  *this += a;
  *this += b;
}
void postfix_expr::accept(visitor *a) { a->v(this); }
void postfix_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string postfix_expr::classname() { return "postfix_expr"; }

primary_expr::primary_expr(lex_token a) : n(a) {}
primary_expr::primary_expr(std::shared_ptr<identifier> a) { *this += a; }
primary_expr::primary_expr(std::shared_ptr<expr> a) { *this += a; }
primary_expr::primary_expr(std::shared_ptr<generic_selection> a) { *this += a; }
void primary_expr::accept(visitor *a) { a->v(this); }
void primary_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string primary_expr::classname() { return "primary_expr"; }

relation_expr::relation_expr(std::shared_ptr<shift_expr> a) { *this += a; }
relation_expr::relation_expr(std::shared_ptr<relation_expr> a, lex_token b,
                             std::shared_ptr<shift_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void relation_expr::accept(visitor *a) { a->v(this); }
void relation_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string relation_expr::classname() { return "relation_expr"; }

selection_statement::selection_statement(lex_token a, std::shared_ptr<expr> b,
                                         std::shared_ptr<statement> c)
    : n(a) {
  *this += b;
  *this += c;
}
selection_statement::selection_statement(lex_token a, std::shared_ptr<expr> b,
                                         std::shared_ptr<statement> c,
                                         lex_token d,
                                         std::shared_ptr<statement> e) {
  elt = d;
  *this += b;
  *this += c;
  *this += e;
}
void selection_statement::accept(visitor *a) { a->v(this); }
void selection_statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string selection_statement::classname() { return "selection_statement"; }

shift_expr::shift_expr(std::shared_ptr<additive_expr> a) { *this += a; }
shift_expr::shift_expr(std::shared_ptr<shift_expr> a, lex_token b,
                       std::shared_ptr<additive_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void shift_expr::accept(visitor *a) { a->v(this); }
void shift_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string shift_expr::classname() { return "shift_expr"; }

specifier_qualifier_list::specifier_qualifier_list(
    std::shared_ptr<type_specifier> a) {
  *this += a;
}
specifier_qualifier_list::specifier_qualifier_list(
    std::shared_ptr<type_qualifier> a) {
  *this += a;
}
void specifier_qualifier_list::accept(visitor *a) { a->v(this); }
void specifier_qualifier_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string specifier_qualifier_list::classname() {
  return "specifier_qualifier_list";
}

void specifier_qualifier_list::type_specifiers(
    std::vector<type_specifier *> *a) {
  std::shared_ptr<fetch_observer<class type_specifier>> o =
      std::shared_ptr<fetch_observer<class type_specifier>>(
          new fetch_observer<class type_specifier>(a));
  m::attach(o);
  // type-specifier is recursive
  // so limit ping to a depth of 1
  class ping *v = new ping(true /* preorder */, 1 /* depth */);
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

void specifier_qualifier_list::type_qualifiers(
    std::vector<type_qualifier *> *a) {
  std::shared_ptr<fetch_observer<class type_qualifier>> o =
      std::shared_ptr<fetch_observer<class type_qualifier>>(
          new fetch_observer<class type_qualifier>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

statement::statement(std::shared_ptr<labeled_statement> a) { *this += a; }
statement::statement(std::shared_ptr<compound_statement> a) { *this += a; }
statement::statement(std::shared_ptr<expression_statement> a) { *this += a; }
statement::statement(std::shared_ptr<selection_statement> a) { *this += a; }
statement::statement(std::shared_ptr<iteration_statement> a) { *this += a; }
statement::statement(std::shared_ptr<jump_statement> a) { *this += a; }

void statement::accept(visitor *a) { a->v(this); }
void statement::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string statement::classname() { return "statement"; }

statement_list::statement_list(std::shared_ptr<statement> a) { *this += a; }
void statement_list::accept(visitor *a) { a->v(this); }
void statement_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string statement_list::classname() { return "statement_list"; }

//
// 6.7.10 Static Assertions
static_assert_declaration::static_assert_declaration(
    std::shared_ptr<constant_expr> a, lex_token b)
    : n(b) {
  *this += a;
}
void static_assert_declaration::accept(visitor *a) { a->v(this); }
void static_assert_declaration::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string static_assert_declaration::classname() {
  return "static_assert_declaration";
}

storage_class_specifier::storage_class_specifier(lex_token a) : n(a) {}
void storage_class_specifier::accept(visitor *a) { a->v(this); }
void storage_class_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string storage_class_specifier::classname() {
  return "storage_class_specifier";
}

struct_declaration::struct_declaration(
    std::shared_ptr<specifier_qualifier_list> a) {
  *this += a;
}

struct_declaration::struct_declaration(
    std::shared_ptr<specifier_qualifier_list> a,
    std::shared_ptr<struct_declarator_list> b) {
  *this += a;
  *this += b;
}
struct_declaration::struct_declaration(
    std::shared_ptr<static_assert_declaration> a) {
  *this += a;
}
void struct_declaration::accept(visitor *a) { a->v(this); }
void struct_declaration::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_declaration::classname() { return "struct_declaration"; }

struct_declaration_list::struct_declaration_list(
    std::shared_ptr<struct_declaration> a) {
  *this += a;
}
void struct_declaration_list::accept(visitor *a) { a->v(this); }
void struct_declaration_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_declaration_list::classname() {
  return "struct_declaration_list";
}

struct_declarator::struct_declarator(std::shared_ptr<declarator> a) {
  *this += a;
}
struct_declarator::struct_declarator(std::shared_ptr<constant_expr> a) {
  *this += a;
}
struct_declarator::struct_declarator(std::shared_ptr<declarator> a,
                                     std::shared_ptr<constant_expr> b) {
  *this += a;
  *this += b;
}

void struct_declarator::accept(visitor *a) { a->v(this); }
void struct_declarator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_declarator::classname() { return "struct_declarator"; }

struct_declarator_list::struct_declarator_list(
    std::shared_ptr<struct_declarator> a) {
  *this += a;
}
void struct_declarator_list::accept(visitor *a) { a->v(this); }
void struct_declarator_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_declarator_list::classname() {
  return "struct_declarator_list";
}
void struct_declarator_list::declarators(std::vector<declarator *> *a) {
  std::shared_ptr<fetch_observer<class declarator>> o =
      std::shared_ptr<fetch_observer<class declarator>>(
          new fetch_observer<class declarator>(a));
  m::attach(o);
  // declarators are recursive
  // the list itself is depth 1
  // to get to the contents of the list is depth 2
  class ping *v = new ping(true /* preorder */, 2 /* depth */);
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

struct_or_union::struct_or_union(lex_token a) : n(a) {}
void struct_or_union::accept(visitor *a) { a->v(this); }
void struct_or_union::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_or_union::classname() { return "struct_or_union"; }

//
// 6.7.2.1 Structure or Union Specifier
//
struct_or_union_specifier::struct_or_union_specifier(
    std::shared_ptr<struct_or_union> a, std::shared_ptr<identifier> b,
    std::shared_ptr<struct_declaration_list> c) {
  *this += a;
  *this += b;
  *this += c;
}
struct_or_union_specifier::struct_or_union_specifier(
    std::shared_ptr<struct_or_union> a,
    std::shared_ptr<struct_declaration_list> b) {
  *this += a;
  *this += b;
}
struct_or_union_specifier::struct_or_union_specifier(
    std::shared_ptr<struct_or_union> a, std::shared_ptr<identifier> b) {
  *this += a;
  *this += b;
}
void struct_or_union_specifier::accept(visitor *a) { a->v(this); }
void struct_or_union_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string struct_or_union_specifier::classname() {
  return "struct_or_union_specifier";
}
bool struct_or_union_specifier::is_union() {
  bool ret = false;
  auto c = children();
  // expecting { struct_or_union, identifier, struct_declaration_list }
  // expecting { struct_or_union, struct_declaration_list }
  // expecting { struct_or_union, identifier }
  struct_or_union *sou = dynamic_cast<struct_or_union *>(c[0].get());
  if (sou && sou->what() == afront::parser::token::UNION)
    ret = true;
  return ret;
}
bool struct_or_union_specifier::is_struct() {
  bool ret = false;
  auto c = children();
  // expecting { struct_or_union, identifier, struct_declaration_list }
  // expecting { struct_or_union, struct_declaration_list }
  // expecting { struct_or_union, identifier }
  struct_or_union *sou = dynamic_cast<struct_or_union *>(c[0].get());
  if (sou && sou->what() == afront::parser::token::STRUCT)
    ret = true;
  return ret;
}

//
// Add declarator to map
//
// Returns nullptr on failure, that declarator's identifier is already defined
// Returns input on success
declarator *struct_or_union_specifier::update_map(declarator *a) {
  declarator *ret = nullptr;
  identifier *i = a->identifier();
  if (i != nullptr) {
    std::string s = i->id();
    if (declarator_map.find(s) == declarator_map.end()) {
      declarator_map[s] = a;
      ret = a;
    } else {
      // identifier is already in the map
      // the input is a redefinition of an existing
      // declarator's identifier.
      //
      // return nullptr
    }
  } else {
    throw(ice_exception(__FILE__, __LINE__, "malformed declarator"));
  }
  return ret;
}

//
// Fetch all of the declarators
void struct_or_union_specifier::declarators(std::vector<declarator *> *a) {
  std::shared_ptr<fetch_observer<class declarator>> o =
      std::shared_ptr<fetch_observer<class declarator>>(
          new fetch_observer<class declarator>(a));
  m::attach(o);
  class ping *v = new ping();
  if (v) {
    this->accept(v);
    delete v;
    v = nullptr;
  }
  m::clear();
}

//
// 6.9 translation-unit
//
translation_unit::translation_unit(std::shared_ptr<external_definition> a) {
  *this += a;
}
void translation_unit::accept(visitor *a) { a->v(this); }
void translation_unit::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string translation_unit::classname() { return "translation_unit"; }
std::string translation_unit::filename() {
  std::string ret = "";
  class location l = here();
  if (l.begin.filename != nullptr)
    ret = *l.begin.filename;
  return ret;
}

type_name::type_name(std::shared_ptr<specifier_qualifier_list> a) {
  *this += a;
}
type_name::type_name(std::shared_ptr<specifier_qualifier_list> a,
                     std::shared_ptr<abstract_declarator> b) {
  *this += a;
  *this += b;
}

void type_name::accept(visitor *a) { a->v(this); }
void type_name::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string type_name::classname() { return "type_name"; }

type_qualifier::type_qualifier(lex_token a) : n(a) {}
void type_qualifier::accept(visitor *a) { a->v(this); }
void type_qualifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string type_qualifier::classname() { return "type_qualifier"; }

type_qualifier_list::type_qualifier_list(std::shared_ptr<type_qualifier> a) {
  *this += a;
}
void type_qualifier_list::accept(visitor *a) { a->v(this); }
void type_qualifier_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string type_qualifier_list::classname() { return "type_qualifier_list"; }

type_specifier::type_specifier(lex_token a) : n(a) {}
type_specifier::type_specifier(std::shared_ptr<struct_or_union_specifier> a) {
  *this += a;
}
type_specifier::type_specifier(std::shared_ptr<enum_specifier> a) {
  *this += a;
}
type_specifier::type_specifier(std::shared_ptr<typedef_name> a) { *this += a; }
type_specifier::type_specifier(std::shared_ptr<atomic_type_specifier> a) {
  *this += a;
}
void type_specifier::accept(visitor *a) { a->v(this); }
void type_specifier::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string type_specifier::classname() { return "type_specifier"; }
bool type_specifier::is_void() {
  bool ret = false;
  if (what() == afront::parser::token::VOID)
    ret = true;
  return ret;
}

typedef_name::typedef_name(std::shared_ptr<identifier> _a) { *this += _a; }
void typedef_name::accept(visitor *_a) { _a->v(this); }
void typedef_name::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string typedef_name::classname() { return "typedef_name"; }

unary_expr::unary_expr(std::shared_ptr<postfix_expr> a) { *this += a; }
unary_expr::unary_expr(lex_token a, std::shared_ptr<unary_expr> b) : n(a) {
  *this += b;
}
unary_expr::unary_expr(std::shared_ptr<unary_operator> a,
                       std::shared_ptr<cast_expr> b) {
  *this += a;
  *this += b;
}
unary_expr::unary_expr(std::shared_ptr<unary_expr> a,
                       std::shared_ptr<identifier> b) {
  *this += a;
  *this += b;
}
unary_expr::unary_expr(lex_token a, std::shared_ptr<type_name> b) : n(a) {
  *this += b;
}
void unary_expr::accept(visitor *a) { a->v(this); }
void unary_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string unary_expr::classname() { return "unary_expr"; }

unary_operator::unary_operator(lex_token a) : n(a) {}
void unary_operator::accept(visitor *a) { a->v(this); }
void unary_operator::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string unary_operator::classname() { return "unary_operator"; }
