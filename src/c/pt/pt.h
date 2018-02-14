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
#ifndef AFRONT_C_PT_PT_H
#define AFRONT_C_PT_PT_H

#include "n.h"
#include <vector>

class abstract_array_declarator;
class abstract_declarator;
class abstract_function_declarator;
class additive_expr;
class alignment_specifier;
class and_expr;
class argument_expr_list;
class array_declarator;
class assignment_expr;
class assignment_operator;
class atomic_type_specifier;
class block_item;
class block_item_list;
class cast_expr;
class compound_statement;
class conditional_expr;
class constant_expr;
class declaration;
class declaration_list;
class declaration_specifiers;
class declarator;
class direct_abstract_declarator;
class direct_declarator;
class enum_specifier;
class enumerator;
class enumerator_list;
class equality_expr;
class exclusive_or_expr;
class expr;
class expression_statement;
class external_definition;
class function_body;
class function_declarator;
class function_definition;
class function_specifier;
class generic_association;
class generic_assoc_list;
class generic_selection;
class identifier;
class identifier_list;
class inclusive_or_expr;
class init_declaration;
class init_declarator;
class init_declarator_list;
class initializer;
class initializer_list;
class iteration_statement;
class jump_statement;
class labeled_statement;
class logical_and_expr;
class logical_or_expr;
class multiplicative_expr;
class parameter_declaration;
class parameter_list;
class parameter_type_list;
class pointer;
class postfix_expr;
class primary_expr;
class relation_expr;
class selection_statement;
class shift_expr;
class specifier_qualifier_list;
class statement;
class statement_list;
class static_assert_declaration;
class storage_class_specifier;
class struct_declaration;
class struct_declaration_list;
class struct_declarator;
class struct_declarator_list;
class struct_or_union;
class struct_or_union_specifier;
class translation_unit;
class type_name;
class type_qualifier;
class type_qualifier_list;
class typedef_name;
class type_specifier;
class unary_expr;
class unary_operator;

class abstract_array_declarator : public n {
public:
  abstract_array_declarator();
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a);
  abstract_array_declarator(std::shared_ptr<constant_expr> a);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            std::shared_ptr<constant_expr> b);
  /* changed to assignment expression in c99 */
  abstract_array_declarator(std::shared_ptr<assignment_expr> a);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            std::shared_ptr<assignment_expr> b);
  /* c99 variable length array */
  abstract_array_declarator(lex_token a);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            lex_token b);
  /* c11 type qualifier attrib */
  abstract_array_declarator(lex_token a, std::shared_ptr<assignment_expr> b);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            lex_token b, std::shared_ptr<assignment_expr> c);
  abstract_array_declarator(lex_token a, std::shared_ptr<type_qualifier_list> b,
                            std::shared_ptr<assignment_expr> c);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            lex_token b, std::shared_ptr<type_qualifier_list> c,
                            std::shared_ptr<assignment_expr> d);
  abstract_array_declarator(std::shared_ptr<type_qualifier_list> a, lex_token b,
                            std::shared_ptr<assignment_expr> c);
  abstract_array_declarator(std::shared_ptr<direct_abstract_declarator> a,
                            std::shared_ptr<type_qualifier_list> b, lex_token c,
                            std::shared_ptr<assignment_expr> d);

  virtual ~abstract_array_declarator(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "abstract_declarator.h"
#include "abstract_function_declarator.h"

class additive_expr : public n {
public:
  additive_expr(std::shared_ptr<multiplicative_expr> a);
  additive_expr(std::shared_ptr<additive_expr> a, lex_token b,
                std::shared_ptr<multiplicative_expr> c);

  virtual ~additive_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class alignment_specifier : public n {
public:
  alignment_specifier(std::shared_ptr<type_name> a);
  alignment_specifier(std::shared_ptr<constant_expr> a);
  virtual ~alignment_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class and_expr : public n {
public:
  and_expr(std::shared_ptr<equality_expr> a);
  and_expr(std::shared_ptr<and_expr> a, lex_token b,
           std::shared_ptr<equality_expr> c);

  virtual ~and_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "argument_expr_list.h"

class array_declarator : public n {
public:
  array_declarator(std::shared_ptr<direct_declarator> a);
  array_declarator(std::shared_ptr<direct_declarator> a,
                   std::shared_ptr<constant_expr> b);
  array_declarator(std::shared_ptr<direct_declarator> a,
                   std::shared_ptr<assignment_expr> b);
  array_declarator(std::shared_ptr<direct_declarator> a,
                   std::shared_ptr<type_qualifier_list> b);
  array_declarator(std::shared_ptr<direct_declarator> a, lex_token b,
                   std::shared_ptr<assignment_expr> c);
  array_declarator(std::shared_ptr<direct_declarator> a, lex_token b,
                   std::shared_ptr<type_qualifier_list> c,
                   std::shared_ptr<assignment_expr> d);
  array_declarator(std::shared_ptr<direct_declarator> a,
                   std::shared_ptr<type_qualifier_list> b, lex_token c,
                   std::shared_ptr<assignment_expr> d);
  array_declarator(std::shared_ptr<direct_declarator> a, lex_token b);
  array_declarator(std::shared_ptr<direct_declarator> a,
                   std::shared_ptr<type_qualifier_list> b, lex_token c);

  virtual ~array_declarator(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "assignment_expr.h"

class assignment_operator : public n {
public:
  assignment_operator(lex_token a);
  virtual ~assignment_operator(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class atomic_type_specifier : public n {
public:
  atomic_type_specifier(std::shared_ptr<type_name> a);
  virtual ~atomic_type_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class block_item : public n {
public:
  block_item(std::shared_ptr<declaration> a);
  block_item(std::shared_ptr<statement> a);
  virtual ~block_item(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class block_item_list : public n {
public:
  block_item_list(std::shared_ptr<block_item> a);
  virtual ~block_item_list(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "cast_expr.h"

class compound_statement : public n {
public:
  compound_statement();
  compound_statement(std::shared_ptr<statement_list> a);
  compound_statement(std::shared_ptr<declaration_list> a);
  compound_statement(std::shared_ptr<declaration_list> a,
                     std::shared_ptr<statement_list> b);
  compound_statement(std::shared_ptr<block_item_list> a);
  virtual ~compound_statement(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "conditional_expr.h"
#include "constant_expr.h"

class declaration : public n {
public:
  declaration(std::shared_ptr<declaration_specifiers> a);
  declaration(std::shared_ptr<declaration_specifiers> a,
              std::shared_ptr<init_declarator_list> b);
  declaration(std::shared_ptr<static_assert_declaration> a);
  virtual ~declaration(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
  bool find_typedefs(std::vector<identifier *> &a);
};

class declaration_list : public n {
public:
  declaration_list(std::shared_ptr<declaration> a);
  virtual ~declaration_list(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class declaration_specifiers : public n {
public:
  declaration_specifiers(std::shared_ptr<storage_class_specifier> a);
  declaration_specifiers(std::shared_ptr<type_specifier> a);
  declaration_specifiers(std::shared_ptr<type_qualifier> a);
  /* c99 */
  declaration_specifiers(std::shared_ptr<function_specifier> a);
  /* c11 */
  declaration_specifiers(std::shared_ptr<alignment_specifier> a);
  virtual ~declaration_specifiers(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "declarator.h"
#include "direct_abstract_declarator.h"
#include "direct_declarator.h"
#include "enum_specifier.h"
#include "enumerator.h"
#include "enumerator_list.h"

class equality_expr : public n {
public:
  equality_expr(std::shared_ptr<relation_expr> a);
  equality_expr(std::shared_ptr<equality_expr> a, lex_token b,
                std::shared_ptr<relation_expr> c);

  virtual ~equality_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class exclusive_or_expr : public n {
public:
  exclusive_or_expr(std::shared_ptr<and_expr> a);
  exclusive_or_expr(std::shared_ptr<exclusive_or_expr> a, lex_token b,
                    std::shared_ptr<and_expr> c);

  virtual ~exclusive_or_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "expr.h"
#include "expression_statement.h"
#include "external_definition.h"
#include "function_body.h"
#include "function_declarator.h"
#include "function_definition.h"

class function_specifier : public n {
public:
  function_specifier(lex_token a);

  virtual ~function_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "generic_assoc_list.h"
#include "generic_association.h"
#include "generic_selection.h"

class identifier : public n {
public:
  identifier(lex_token a);
  virtual ~identifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "identifier_list.h"

class inclusive_or_expr : public n {
public:
  inclusive_or_expr(std::shared_ptr<exclusive_or_expr> a);
  inclusive_or_expr(std::shared_ptr<inclusive_or_expr> a, lex_token b,
                    std::shared_ptr<exclusive_or_expr> c);

  virtual ~inclusive_or_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "init_declarator.h"
#include "init_declarator_list.h"
#include "initializer.h"
#include "initializer_list.h"
class iteration_statement : public n {
public:
  iteration_statement(lex_token a, std::shared_ptr<expr> b,
                      std::shared_ptr<statement> c);
  iteration_statement(lex_token a, std::shared_ptr<statement> b, lex_token c,
                      std::shared_ptr<expr> d);
  iteration_statement(lex_token a, std::shared_ptr<expr> b,
                      std::shared_ptr<expr> c, std::shared_ptr<expr> d,
                      std::shared_ptr<statement> e);
  iteration_statement(lex_token a, std::shared_ptr<declaration> b,
                      std::shared_ptr<expr> c, std::shared_ptr<expr> d,
                      std::shared_ptr<statement> e);

  virtual ~iteration_statement(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class jump_statement : public n {
public:
  jump_statement(lex_token a);
  jump_statement(lex_token a, std::shared_ptr<identifier> b);
  jump_statement(lex_token a, std::shared_ptr<expr> b);
  virtual ~jump_statement(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class labeled_statement : public n {
public:
  labeled_statement(std::shared_ptr<identifier> a,
                    std::shared_ptr<statement> b);
  labeled_statement(lex_token a, std::shared_ptr<constant_expr> b,
                    std::shared_ptr<statement> c);
  labeled_statement(lex_token a, std::shared_ptr<statement> b);

  virtual ~labeled_statement(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class logical_and_expr : public n {
public:
  logical_and_expr(std::shared_ptr<inclusive_or_expr> a);
  logical_and_expr(std::shared_ptr<logical_and_expr> a, lex_token b,
                   std::shared_ptr<inclusive_or_expr> c);

  virtual ~logical_and_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class logical_or_expr : public n {
public:
  logical_or_expr(std::shared_ptr<logical_and_expr> a);
  logical_or_expr(std::shared_ptr<logical_or_expr> a, lex_token b,
                  std::shared_ptr<logical_and_expr> c);

  virtual ~logical_or_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class multiplicative_expr : public n {
public:
  multiplicative_expr(std::shared_ptr<cast_expr> a);
  multiplicative_expr(std::shared_ptr<multiplicative_expr> a, lex_token b,
                      std::shared_ptr<cast_expr> c);

  virtual ~multiplicative_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "parameter_declaration.h"
#include "parameter_list.h"

class parameter_type_list : public n {
public:
  parameter_type_list(std::shared_ptr<parameter_list> a);
  parameter_type_list(std::shared_ptr<parameter_list> a, lex_token b);

  virtual ~parameter_type_list(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "pointer.h"

class postfix_expr : public n {
public:
  postfix_expr(std::shared_ptr<primary_expr> a);
  postfix_expr(std::shared_ptr<postfix_expr> a, std::shared_ptr<expr> b);
  postfix_expr(std::shared_ptr<postfix_expr> a);
  postfix_expr(std::shared_ptr<postfix_expr> a,
               std::shared_ptr<argument_expr_list> b);
  postfix_expr(std::shared_ptr<postfix_expr> a, std::shared_ptr<identifier> b);
  postfix_expr(std::shared_ptr<postfix_expr> a, lex_token b,
               std::shared_ptr<identifier> c);
  postfix_expr(std::shared_ptr<postfix_expr> a, lex_token b);
  postfix_expr(std::shared_ptr<type_name> a,
               std::shared_ptr<identifier_list> b);

  virtual ~postfix_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class primary_expr : public n {
public:
  primary_expr(lex_token a);
  primary_expr(std::shared_ptr<identifier> a);
  primary_expr(std::shared_ptr<expr> a);
  primary_expr(std::shared_ptr<generic_selection> a);
  virtual ~primary_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class relation_expr : public n {
public:
  relation_expr(std::shared_ptr<shift_expr> a);
  relation_expr(std::shared_ptr<relation_expr> a, lex_token b,
                std::shared_ptr<shift_expr> c);

  virtual ~relation_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class selection_statement : public n {
public:
  selection_statement(lex_token a, std::shared_ptr<expr> b,
                      std::shared_ptr<statement> c);
  selection_statement(lex_token a, std::shared_ptr<expr> b,
                      std::shared_ptr<statement> c, lex_token d,
                      std::shared_ptr<statement> e);
  virtual ~selection_statement(){};
  virtual void accept(visitor *a);
  virtual std::string classname();

private:
  lex_token elt;
};

class shift_expr : public n {
public:
  shift_expr(std::shared_ptr<additive_expr> a);
  shift_expr(std::shared_ptr<shift_expr> a, lex_token b,
             std::shared_ptr<additive_expr> c);

  virtual ~shift_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "specifier_qualifier_list.h"
#include "statement.h"
#include "statement_list.h"

class static_assert_declaration : public n {
public:
  static_assert_declaration(std::shared_ptr<constant_expr> a, lex_token b);
  virtual ~static_assert_declaration(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class storage_class_specifier : public n {
public:
  storage_class_specifier(lex_token a);
  virtual ~storage_class_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class struct_declaration : public n {
public:
  struct_declaration(std::shared_ptr<specifier_qualifier_list> a,
                     std::shared_ptr<struct_declarator_list> b);
  struct_declaration(std::shared_ptr<static_assert_declaration> a);
  virtual ~struct_declaration(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "struct_declaration_list.h"
#include "struct_declarator.h"
#include "struct_declarator_list.h"

class struct_or_union : public n {
public:
  struct_or_union(lex_token a);
  virtual ~struct_or_union(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class struct_or_union_specifier : public n {
public:
  struct_or_union_specifier(std::shared_ptr<struct_or_union> a,
                            std::shared_ptr<identifier> b,
                            std::shared_ptr<struct_declaration_list> c);

  struct_or_union_specifier(std::shared_ptr<struct_or_union> a,
                            std::shared_ptr<struct_declaration_list> b);

  struct_or_union_specifier(std::shared_ptr<struct_or_union> a,
                            std::shared_ptr<identifier> b);

  virtual ~struct_or_union_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "translation_unit.h"
#include "type_name.h"

class type_qualifier : public n {
public:
  type_qualifier(lex_token a);

  virtual ~type_qualifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class type_qualifier_list : public n {
public:
  type_qualifier_list(std::shared_ptr<type_qualifier> a);
  virtual ~type_qualifier_list(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "typedef_name.h"

class type_specifier : public n {
public:
  type_specifier(lex_token a);
  type_specifier(std::shared_ptr<struct_or_union_specifier> a);
  type_specifier(std::shared_ptr<enum_specifier> a);
  type_specifier(std::shared_ptr<typedef_name> a);
  type_specifier(std::shared_ptr<atomic_type_specifier> a);

  virtual ~type_specifier(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class unary_expr : public n {
public:
  unary_expr(std::shared_ptr<postfix_expr> a);
  unary_expr(lex_token a, std::shared_ptr<unary_expr> b);
  unary_expr(std::shared_ptr<unary_operator> a, std::shared_ptr<cast_expr> b);
  unary_expr(std::shared_ptr<unary_expr> a, std::shared_ptr<identifier> b);
  unary_expr(lex_token a, std::shared_ptr<type_name> b);

  virtual ~unary_expr(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

class unary_operator : public n {
public:
  unary_operator(lex_token a);
  virtual ~unary_operator(){};
  virtual void accept(visitor *a);
  virtual std::string classname();
};

#include "v/visitor.h"
#endif
