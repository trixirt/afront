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

void abstract_array_declarator::accept(visitor *a) { a->v(this); };
std::string abstract_array_declarator::classname() {
  return "abstract_array_declarator";
};

abstract_array_declarator::abstract_array_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<type_qualifier_list> b, lex_token c,
    std::shared_ptr<assignment_expr> d)
    : n(c) {
  *this += a;
  *this += b;
  *this += d;
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
void additive_expr::accept(visitor *a) { a->v(this); };
std::string additive_expr::classname() { return "additive_expr"; };

// Alignment Specifier 6.7.5
alignment_specifier::alignment_specifier(std::shared_ptr<type_name> a) {
  *this += a;
}
alignment_specifier::alignment_specifier(std::shared_ptr<constant_expr> a) {
  *this += a;
}
void alignment_specifier::accept(visitor *a) { a->v(this); };
std::string alignment_specifier::classname() { return "alignment_specifier"; };

and_expr::and_expr(std::shared_ptr<equality_expr> a) { *this += a; }
and_expr::and_expr(std::shared_ptr<and_expr> a, lex_token b,
                   std::shared_ptr<equality_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void and_expr::accept(visitor *a) { a->v(this); };
std::string and_expr::classname() { return "and_expr"; };

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
void array_declarator::accept(visitor *a) { a->v(this); };
std::string array_declarator::classname() { return "array_declarator"; };

assignment_operator::assignment_operator(lex_token a) : n(a){};
void assignment_operator::accept(visitor *a) { a->v(this); };
std::string assignment_operator::classname() { return "assignment_operator"; };

equality_expr::equality_expr(std::shared_ptr<relation_expr> a) { *this += a; }
equality_expr::equality_expr(std::shared_ptr<equality_expr> a, lex_token b,
                             std::shared_ptr<relation_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void equality_expr::accept(visitor *a) { a->v(this); };
std::string equality_expr::classname() { return "equality_expr"; };

exclusive_or_expr::exclusive_or_expr(std::shared_ptr<and_expr> a) {
  *this += a;
}
exclusive_or_expr::exclusive_or_expr(std::shared_ptr<exclusive_or_expr> a,
                                     lex_token b, std::shared_ptr<and_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void exclusive_or_expr::accept(visitor *a) { a->v(this); };
std::string exclusive_or_expr::classname() { return "exclusive_or_expr"; };

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
void declaration_specifiers::accept(visitor *a) { a->v(this); };
std::string declaration_specifiers::classname() {
  return "declaration_specifiers";
};

function_specifier::function_specifier(lex_token a) : n(a) {}
void function_specifier::accept(visitor *a) { a->v(this); };
std::string function_specifier::classname() { return "function_specifier"; };

identifier::identifier(lex_token a) : n(a){};
void identifier::accept(visitor *a) { a->v(this); };
std::string identifier::classname() { return "identifier"; };

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
void inclusive_or_expr::accept(visitor *a) { a->v(this); };
std::string inclusive_or_expr::classname() { return "inclusive_or_expr"; };

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
void iteration_statement::accept(visitor *a) { a->v(this); };
std::string iteration_statement::classname() { return "iteration_statement"; };

jump_statement::jump_statement(lex_token a) : n(a){};
jump_statement::jump_statement(lex_token a, std::shared_ptr<identifier> b)
    : n(a) {

  *this += b;
};
jump_statement::jump_statement(lex_token a, std::shared_ptr<expr> b) : n(a) {
  *this += b;
};
void jump_statement::accept(visitor *a) { a->v(this); };
std::string jump_statement::classname() { return "jump_statement"; };

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
void labeled_statement::accept(visitor *a) { a->v(this); };
std::string labeled_statement::classname() { return "labeled_statement"; };

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
void logical_and_expr::accept(visitor *a) { a->v(this); };
std::string logical_and_expr::classname() { return "logical_and_expr"; };

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
void logical_or_expr::accept(visitor *a) { a->v(this); };
std::string logical_or_expr::classname() { return "logical_or_expr"; };

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
void multiplicative_expr::accept(visitor *a) { a->v(this); };
std::string multiplicative_expr::classname() { return "multiplicative_expr"; };

parameter_type_list::parameter_type_list(std::shared_ptr<parameter_list> a) {
  *this += a;
}
parameter_type_list::parameter_type_list(std::shared_ptr<parameter_list> a,
                                         lex_token b)
    : n(b) {
  *this += a;
}

void parameter_type_list::accept(visitor *a) { a->v(this); };
std::string parameter_type_list::classname() { return "parameter_type_list"; };

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
void postfix_expr::accept(visitor *a) { a->v(this); };
std::string postfix_expr::classname() { return "postfix_expr"; };

primary_expr::primary_expr(lex_token a) : n(a) {}
primary_expr::primary_expr(std::shared_ptr<identifier> a) { *this += a; }
primary_expr::primary_expr(std::shared_ptr<expr> a) { *this += a; }
primary_expr::primary_expr(std::shared_ptr<generic_selection> a) { *this += a; }
void primary_expr::accept(visitor *a) { a->v(this); }
std::string primary_expr::classname() { return "primary_expr"; };

relation_expr::relation_expr(std::shared_ptr<shift_expr> a) { *this += a; }
relation_expr::relation_expr(std::shared_ptr<relation_expr> a, lex_token b,
                             std::shared_ptr<shift_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void relation_expr::accept(visitor *a) { a->v(this); };
std::string relation_expr::classname() { return "relation_expr"; };

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
void selection_statement::accept(visitor *a) { a->v(this); };
std::string selection_statement::classname() { return "selection_statement"; };

shift_expr::shift_expr(std::shared_ptr<additive_expr> a) { *this += a; }
shift_expr::shift_expr(std::shared_ptr<shift_expr> a, lex_token b,
                       std::shared_ptr<additive_expr> c)
    : n(b) {
  *this += a;
  *this += c;
}
void shift_expr::accept(visitor *a) { a->v(this); };
std::string shift_expr::classname() { return "shift_expr"; };

storage_class_specifier::storage_class_specifier(lex_token a) : n(a) {}
void storage_class_specifier::accept(visitor *a) { a->v(this); };
std::string storage_class_specifier::classname() {
  return "storage_class_specifier";
};

struct_or_union::struct_or_union(lex_token a) : n(a) {}
void struct_or_union::accept(visitor *a) { a->v(this); };
std::string struct_or_union::classname() { return "struct_or_union"; };

type_qualifier::type_qualifier(lex_token a) : n(a) {}
void type_qualifier::accept(visitor *a) { a->v(this); };
std::string type_qualifier::classname() { return "type_qualifier"; };

type_specifier::type_specifier(lex_token a) : n(a) {}
type_specifier::type_specifier(std::shared_ptr<struct_or_union_specifier> a) {
  *this += a;
}
type_specifier::type_specifier(std::shared_ptr<enum_specifier> a) {
  *this += a;
}
type_specifier::type_specifier(std::shared_ptr<typedef_name> a) { *this += a; }
void type_specifier::accept(visitor *a) { a->v(this); };
std::string type_specifier::classname() { return "type_specifier"; };

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
void unary_expr::accept(visitor *a) { a->v(this); };
std::string unary_expr::classname() { return "unary_expr"; };

unary_operator::unary_operator(lex_token a) : n(a) {}
void unary_operator::accept(visitor *a) { a->v(this); }
std::string unary_operator::classname() { return "unary_operator"; };
