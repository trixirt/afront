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
#include "pt_classes.h"
#include <map>
#include <vector>

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
  virtual void notify();
  virtual std::string classname();
};

class abstract_declarator : public n {
public:
  abstract_declarator(std::shared_ptr<pointer>);
  abstract_declarator(std::shared_ptr<direct_abstract_declarator>);
  abstract_declarator(std::shared_ptr<pointer>,
                      std::shared_ptr<direct_abstract_declarator>);

  virtual ~abstract_declarator(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
  bool has_pointer();
};

class abstract_function_declarator : public n {
public:
  abstract_function_declarator();
  abstract_function_declarator(std::shared_ptr<parameter_type_list> a);
  abstract_function_declarator(std::shared_ptr<direct_abstract_declarator> a);
  abstract_function_declarator(std::shared_ptr<direct_abstract_declarator> a,
                               std::shared_ptr<parameter_type_list> b);

  virtual ~abstract_function_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class additive_expr : public n {
public:
  additive_expr(std::shared_ptr<multiplicative_expr> a);
  additive_expr(std::shared_ptr<additive_expr> a, lex_token b,
                std::shared_ptr<multiplicative_expr> c);

  virtual ~additive_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class alignment_specifier : public n {
public:
  alignment_specifier(std::shared_ptr<type_name> a);
  alignment_specifier(std::shared_ptr<constant_expr> a);
  virtual ~alignment_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class and_expr : public n {
public:
  and_expr(std::shared_ptr<equality_expr> a);
  and_expr(std::shared_ptr<and_expr> a, lex_token b,
           std::shared_ptr<equality_expr> c);

  virtual ~and_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class argument_expr_list : public n {
public:
  argument_expr_list(std::shared_ptr<assignment_expr> a);
  virtual ~argument_expr_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

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
  virtual void notify();
  virtual std::string classname();
};

class assignment_expr : public n {
public:
  assignment_expr(std::shared_ptr<conditional_expr> a);
  assignment_expr(std::shared_ptr<unary_expr> a,
                  std::shared_ptr<assignment_operator> b,
                  std::shared_ptr<assignment_expr> c);

  virtual ~assignment_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class assignment_operator : public n {
public:
  assignment_operator(lex_token a);
  virtual ~assignment_operator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class atomic_type_specifier : public n {
public:
  atomic_type_specifier(std::shared_ptr<type_name> a);
  virtual ~atomic_type_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class block_item : public n {
public:
  block_item(std::shared_ptr<declaration> a);
  block_item(std::shared_ptr<statement> a);
  virtual ~block_item(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class block_item_list : public n {
public:
  block_item_list(std::shared_ptr<block_item> a);
  virtual ~block_item_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class cast_expr : public n {
public:
  cast_expr(std::shared_ptr<unary_expr> a);
  cast_expr(std::shared_ptr<type_name> a, std::shared_ptr<cast_expr> b);

  virtual ~cast_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class character_constant : public n {
public:
  character_constant(lex_token);

  virtual ~character_constant(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
};

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
  virtual void notify();
  virtual std::string classname();
};

class conditional_expr : public n {
public:
  conditional_expr(std::shared_ptr<logical_or_expr> a);
  conditional_expr(std::shared_ptr<logical_or_expr> a,
                   std::shared_ptr<logical_or_expr> c,
                   std::shared_ptr<conditional_expr> e);

  virtual ~conditional_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class constant : public n {
public:
  constant(std::shared_ptr<character_constant>);
  constant(std::shared_ptr<enumeration_constant>);
  constant(std::shared_ptr<floating_constant>);
  constant(std::shared_ptr<integer_constant>);

  virtual ~constant(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
};
class constant_expr : public n {
public:
  constant_expr(std::shared_ptr<conditional_expr> a);

  virtual ~constant_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class declaration : public n {
public:
  declaration(std::shared_ptr<declaration_specifiers> a);
  declaration(std::shared_ptr<declaration_specifiers> a,
              std::shared_ptr<init_declarator_list> b);
  declaration(std::shared_ptr<static_assert_declaration> a);
  virtual ~declaration(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  bool find_typedefs(std::vector<identifier *> &a);
};

class declaration_list : public n {
public:
  declaration_list(std::shared_ptr<declaration> a);
  virtual ~declaration_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class declaration_specifiers : public n {
public:
  declaration_specifiers(std::shared_ptr<storage_class_specifier>);
  declaration_specifiers(std::shared_ptr<type_specifier>);
  declaration_specifiers(std::shared_ptr<type_qualifier>);
  /* c99 */
  declaration_specifiers(std::shared_ptr<function_specifier>);
  /* c11 */
  declaration_specifiers(std::shared_ptr<alignment_specifier>);
  virtual ~declaration_specifiers(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
  void storage_class_specifiers(std::vector<storage_class_specifier *> *);
  void type_specifiers(std::vector<type_specifier *> *);
  void type_qualifiers(std::vector<type_qualifier *> *);
  void function_specifiers(std::vector<function_specifier *> *);
  void alignment_specifiers(std::vector<alignment_specifier *> *);
};

class declarator : public n {
public:
  declarator(std::shared_ptr<direct_declarator> a);
  declarator(std::shared_ptr<pointer> a, std::shared_ptr<direct_declarator> b);

  virtual ~declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  identifier *identifier();
  bool has_pointer();
};

class direct_abstract_declarator : public n {
public:
  direct_abstract_declarator(std::shared_ptr<abstract_declarator> a);
  direct_abstract_declarator(std::shared_ptr<abstract_array_declarator> a);
  direct_abstract_declarator(std::shared_ptr<abstract_function_declarator> a);

  virtual ~direct_abstract_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class direct_declarator : public n {
public:
  direct_declarator(std::shared_ptr<identifier> a);
  direct_declarator(std::shared_ptr<declarator> a);
  direct_declarator(std::shared_ptr<array_declarator> a);
  direct_declarator(std::shared_ptr<function_declarator> a);

  virtual ~direct_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class enum_specifier : public n {
public:
  enum_specifier(std::shared_ptr<enumerator_list> a);
  enum_specifier(std::shared_ptr<identifier> a,
                 std::shared_ptr<enumerator_list> b);
  enum_specifier(std::shared_ptr<identifier> a);

  virtual ~enum_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class enumeration_constant : public n {
public:
  enumeration_constant(std::shared_ptr<identifier> a);

  virtual ~enumeration_constant(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class enumerator : public n {
public:
  enumerator(std::shared_ptr<enumeration_constant> a);
  enumerator(std::shared_ptr<enumeration_constant> a,
             std::shared_ptr<constant_expr> b);

  virtual ~enumerator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class enumerator_list : public n {
public:
  enumerator_list(std::shared_ptr<enumerator> a);
  virtual ~enumerator_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  //
  // Add an enumerator to map
  //
  // Returns nullptr on failure, that enumerator is already defined
  // Returns input on success
  enumerator *update_map(enumerator *);

private:
  std::map<std::string, enumerator *> enumerator_map;
};

class equality_expr : public n {
public:
  equality_expr(std::shared_ptr<relation_expr> a);
  equality_expr(std::shared_ptr<equality_expr> a, lex_token b,
                std::shared_ptr<relation_expr> c);

  virtual ~equality_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class exclusive_or_expr : public n {
public:
  exclusive_or_expr(std::shared_ptr<and_expr> a);
  exclusive_or_expr(std::shared_ptr<exclusive_or_expr> a, lex_token b,
                    std::shared_ptr<and_expr> c);

  virtual ~exclusive_or_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class expr : public n {
public:
  expr(std::shared_ptr<assignment_expr> a);
  expr(std::shared_ptr<expr> a, std::shared_ptr<assignment_expr> b);

  virtual ~expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class expression_statement : public n {
public:
  expression_statement();
  expression_statement(std::shared_ptr<expr> a);
  virtual ~expression_statement(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class external_definition : public n {
public:
  external_definition(std::shared_ptr<function_definition> a);
  external_definition(std::shared_ptr<declaration> a);
  virtual ~external_definition(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class floating_constant : public n {
public:
  floating_constant(lex_token);

  virtual ~floating_constant(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
};

class function_body : public n {
public:
  function_body(std::shared_ptr<compound_statement> a);
  function_body(std::shared_ptr<declaration_list> a,
                std::shared_ptr<compound_statement> b);
  virtual ~function_body(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class function_declarator : public n {
public:
  function_declarator(std::shared_ptr<direct_declarator> a);
  function_declarator(std::shared_ptr<direct_declarator> a,
                      std::shared_ptr<parameter_type_list> b);
  function_declarator(std::shared_ptr<direct_declarator> a,
                      std::shared_ptr<identifier_list> b);

  virtual ~function_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class function_definition : public n {
public:
  function_definition(std::shared_ptr<declarator> a,
                      std::shared_ptr<function_body> b);
  function_definition(std::shared_ptr<declaration_specifiers> a,
                      std::shared_ptr<declarator> b,
                      std::shared_ptr<function_body> c);
  virtual ~function_definition(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  std::string functionname();
  labeled_statement *label(labeled_statement *a);

private:
  std::map<std::string, labeled_statement *> label_map;
};

class function_specifier : public n {
public:
  function_specifier(lex_token a);

  virtual ~function_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class generic_assoc_list : public n {
public:
  generic_assoc_list(std::shared_ptr<generic_association> a);
  virtual ~generic_assoc_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class generic_association : public n {
public:
  generic_association(std::shared_ptr<assignment_expr> a);
  generic_association(std::shared_ptr<type_name> a,
                      std::shared_ptr<assignment_expr> b);

  virtual ~generic_association(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class generic_selection : public n {
public:
  generic_selection(std::shared_ptr<assignment_expr> a,
                    std::shared_ptr<generic_assoc_list> b);

  virtual ~generic_selection(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class identifier : public n {
public:
  identifier(lex_token a);
  virtual ~identifier(){};
  virtual void accept(visitor *a);

  virtual void notify();
  virtual std::string classname();
  std::string id();
};

class identifier_list : public n {
public:
  identifier_list(std::shared_ptr<identifier> a);
  virtual ~identifier_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class inclusive_or_expr : public n {
public:
  inclusive_or_expr(std::shared_ptr<exclusive_or_expr> a);
  inclusive_or_expr(std::shared_ptr<inclusive_or_expr> a, lex_token b,
                    std::shared_ptr<exclusive_or_expr> c);

  virtual ~inclusive_or_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class init_declarator : public n {
public:
  init_declarator(std::shared_ptr<declarator> a);
  init_declarator(std::shared_ptr<declarator> a,
                  std::shared_ptr<initializer> b);

  virtual ~init_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class init_declarator_list : public n {
public:
  init_declarator_list(std::shared_ptr<init_declarator>);
  virtual ~init_declarator_list(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
  void declarators(std::vector<declarator *> *);
};

class initializer : public n {
public:
  initializer(std::shared_ptr<assignment_expr> a);
  initializer(std::shared_ptr<initializer_list> a);
  virtual ~initializer(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class initializer_list : public n {
public:
  initializer_list(std::shared_ptr<initializer> a);
  virtual ~initializer_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class integer_constant : public n {
public:
  integer_constant(lex_token);

  virtual ~integer_constant(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
};

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
  virtual void notify();
  virtual std::string classname();
};

class jump_statement : public n {
public:
  jump_statement(lex_token a);
  jump_statement(lex_token a, std::shared_ptr<identifier> b);
  jump_statement(lex_token a, std::shared_ptr<expr> b);
  virtual ~jump_statement(){};
  virtual void accept(visitor *a);
  virtual void notify();
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
  virtual void notify();
  virtual std::string classname();
};

class logical_and_expr : public n {
public:
  logical_and_expr(std::shared_ptr<inclusive_or_expr> a);
  logical_and_expr(std::shared_ptr<logical_and_expr> a, lex_token b,
                   std::shared_ptr<inclusive_or_expr> c);

  virtual ~logical_and_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class logical_or_expr : public n {
public:
  logical_or_expr(std::shared_ptr<logical_and_expr> a);
  logical_or_expr(std::shared_ptr<logical_or_expr> a, lex_token b,
                  std::shared_ptr<logical_and_expr> c);

  virtual ~logical_or_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class multiplicative_expr : public n {
public:
  multiplicative_expr(std::shared_ptr<cast_expr> a);
  multiplicative_expr(std::shared_ptr<multiplicative_expr> a, lex_token b,
                      std::shared_ptr<cast_expr> c);

  virtual ~multiplicative_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class parameter_declaration : public n {
public:
  parameter_declaration(std::shared_ptr<declaration_specifiers> a,
                        std::shared_ptr<declarator> b);
  parameter_declaration(std::shared_ptr<declaration_specifiers> a,
                        std::shared_ptr<abstract_declarator> b);
  parameter_declaration(std::shared_ptr<declaration_specifiers> a);

  virtual ~parameter_declaration(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class parameter_list : public n {
public:
  parameter_list(std::shared_ptr<parameter_declaration> a);
  virtual ~parameter_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class parameter_type_list : public n {
public:
  parameter_type_list(std::shared_ptr<parameter_list> a);
  parameter_type_list(std::shared_ptr<parameter_list> a, lex_token b);

  virtual ~parameter_type_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  bool has_vararg();
};

class pointer : public n {
public:
  pointer();
  pointer(std::shared_ptr<type_qualifier_list> a);
  pointer(std::shared_ptr<pointer> a);
  pointer(std::shared_ptr<type_qualifier_list> a, std::shared_ptr<pointer> b);

  virtual ~pointer(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

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
  virtual void notify();
  virtual std::string classname();
};

class primary_expr : public n {
public:
  primary_expr(lex_token a);
  primary_expr(std::shared_ptr<constant> a);
  primary_expr(std::shared_ptr<identifier> a);
  primary_expr(std::shared_ptr<expr> a);
  primary_expr(std::shared_ptr<generic_selection> a);
  virtual ~primary_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class relation_expr : public n {
public:
  relation_expr(std::shared_ptr<shift_expr> a);
  relation_expr(std::shared_ptr<relation_expr> a, lex_token b,
                std::shared_ptr<shift_expr> c);

  virtual ~relation_expr(){};
  virtual void accept(visitor *a);
  virtual void notify();
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
  virtual void notify();
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
  virtual void notify();
  virtual std::string classname();
};

class specifier_qualifier_list : public n {
public:
  specifier_qualifier_list(std::shared_ptr<type_specifier> a);
  specifier_qualifier_list(std::shared_ptr<type_qualifier> a);
  virtual ~specifier_qualifier_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  void type_specifiers(std::vector<type_specifier *> *);
  void type_qualifiers(std::vector<type_qualifier *> *);
};

class statement : public n {
public:
  statement(std::shared_ptr<labeled_statement> a);
  statement(std::shared_ptr<compound_statement> a);
  statement(std::shared_ptr<expression_statement> a);
  statement(std::shared_ptr<selection_statement> a);
  statement(std::shared_ptr<iteration_statement> a);
  statement(std::shared_ptr<jump_statement> a);

  virtual ~statement(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class statement_list : public n {
public:
  statement_list(std::shared_ptr<statement> a);
  virtual ~statement_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class static_assert_declaration : public n {
public:
  static_assert_declaration(std::shared_ptr<constant_expr> a, lex_token b);
  virtual ~static_assert_declaration(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class storage_class_specifier : public n {
public:
  storage_class_specifier(lex_token a);
  virtual ~storage_class_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class struct_declaration : public n {
public:
  struct_declaration(std::shared_ptr<specifier_qualifier_list>);
  struct_declaration(std::shared_ptr<specifier_qualifier_list>,
                     std::shared_ptr<struct_declarator_list>);
  struct_declaration(std::shared_ptr<static_assert_declaration>);
  virtual ~struct_declaration(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
};

class struct_declaration_list : public n {
public:
  struct_declaration_list(std::shared_ptr<struct_declaration> a);
  virtual ~struct_declaration_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class struct_declarator : public n {
public:
  struct_declarator(std::shared_ptr<declarator> a);
  struct_declarator(std::shared_ptr<constant_expr> a);
  struct_declarator(std::shared_ptr<declarator> a,
                    std::shared_ptr<constant_expr> b);

  virtual ~struct_declarator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class struct_declarator_list : public n {
public:
  struct_declarator_list(std::shared_ptr<struct_declarator>);
  virtual ~struct_declarator_list(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
  void declarators(std::vector<declarator *> *);
};

class struct_or_union : public n {
public:
  struct_or_union(lex_token a);
  virtual ~struct_or_union(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class struct_or_union_specifier : public n {
public:
  struct_or_union_specifier(std::shared_ptr<struct_or_union>,
                            std::shared_ptr<identifier>,
                            std::shared_ptr<struct_declaration_list>);

  struct_or_union_specifier(std::shared_ptr<struct_or_union>,
                            std::shared_ptr<struct_declaration_list>);

  struct_or_union_specifier(std::shared_ptr<struct_or_union>,
                            std::shared_ptr<identifier>);

  virtual ~struct_or_union_specifier(){};
  virtual void accept(visitor *);
  virtual void notify();
  virtual std::string classname();
  bool is_union();
  bool is_struct();
  //
  // Add a declarator to map
  //
  // Returns nullptr on failure, that declarator's identifier is already defined
  // Returns input on success
  declarator *update_map(declarator *);
  //
  // Fetch all of the declarators
  void declarators(std::vector<declarator *> *);

private:
  std::map<std::string, declarator *> declarator_map;
};

class translation_unit : public n {
public:
  translation_unit(std::shared_ptr<external_definition> a);
  virtual ~translation_unit(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  std::string filename();
};

class type_name : public n {
public:
  type_name(std::shared_ptr<specifier_qualifier_list> a);
  type_name(std::shared_ptr<specifier_qualifier_list> a,
            std::shared_ptr<abstract_declarator> b);

  virtual ~type_name(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class type_qualifier : public n {
public:
  type_qualifier(lex_token a);

  virtual ~type_qualifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class type_qualifier_list : public n {
public:
  type_qualifier_list(std::shared_ptr<type_qualifier> a);
  virtual ~type_qualifier_list(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class typedef_name : public n {
public:
  typedef_name(std::shared_ptr<identifier> a);

  virtual ~typedef_name(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

class type_specifier : public n {
public:
  type_specifier(lex_token a);
  type_specifier(std::shared_ptr<struct_or_union_specifier> a);
  type_specifier(std::shared_ptr<enum_specifier> a);
  type_specifier(std::shared_ptr<typedef_name> a);
  type_specifier(std::shared_ptr<atomic_type_specifier> a);

  virtual ~type_specifier(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
  bool is_void();
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
  virtual void notify();
  virtual std::string classname();
};

class unary_operator : public n {
public:
  unary_operator(lex_token a);
  virtual ~unary_operator(){};
  virtual void accept(visitor *a);
  virtual void notify();
  virtual std::string classname();
};

#include "v/visitor.h"

#endif
