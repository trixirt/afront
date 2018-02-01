/*
 * Copyright (c) 2017 Tom Rix
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
#ifndef NADA_C_PT_VIS_VISITOR_H
#define NADA_C_PT_VIS_VISITOR_H

class abstract_array_declarator;
class abstract_declarator;
class abstract_function_declarator;
class additive_expr;
class and_expr;
class argument_expr_list;
class array_declarator;
class assignment_expr;
class assignment_operator;
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
class enumerator;
class enumerator_list;
class enum_specifier;
class equality_expr;
class exclusive_or_expr;
class expr;
class expression_statement;
class external_definition;
class translation_unit;
class function_body;
class function_declarator;
class function_definition;
class function_specifier;
class identifier;
class identifier_list;
class inclusive_or_expr;
class init_declarator;
class init_declarator_list;
class initializer;
class initializer_list;
class iteration_statement;
class jump_statement;
class labeled_statement;
class logical_and_expr;
class logical_or_expr;
class m;
class multiplicative_expr;
class n;
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
class type_specifier;
class typedef_name;
class unary_expr;
class unary_operator;

class visitor {
public:
  visitor(){};
  virtual ~visitor(){};

  virtual void descend() { }
  virtual void ascend() { }

  virtual void v(abstract_array_declarator *a) = 0;
  virtual void v(abstract_declarator *a) = 0;
  virtual void v(abstract_function_declarator *a) = 0;
  virtual void v(additive_expr *a) = 0;
  virtual void v(and_expr *a) = 0;
  virtual void v(argument_expr_list *a) = 0;
  virtual void v(array_declarator *a) = 0;
  virtual void v(assignment_expr *a) = 0;
  virtual void v(assignment_operator *a) = 0;
  virtual void v(cast_expr *a) = 0;
  virtual void v(compound_statement *a) = 0;
  virtual void v(conditional_expr *a) = 0;
  virtual void v(constant_expr *a) = 0;
  virtual void v(declaration *a) = 0;
  virtual void v(declaration_list *a) = 0;
  virtual void v(declaration_specifiers *a) = 0;
  virtual void v(declarator *a) = 0;
  virtual void v(direct_abstract_declarator *a) = 0;
  virtual void v(direct_declarator *a) = 0;
  virtual void v(enumerator *a) = 0;
  virtual void v(enumerator_list *a) = 0;
  virtual void v(enum_specifier *a) = 0;
  virtual void v(equality_expr *a) = 0;
  virtual void v(exclusive_or_expr *a) = 0;
  virtual void v(expr *a) = 0;
  virtual void v(expression_statement *a) = 0;
  virtual void v(external_definition *a) = 0;
  virtual void v(function_body *a) = 0;
  virtual void v(function_declarator *a) = 0;
  virtual void v(function_definition *a) = 0;
  virtual void v(function_specifier *a) = 0;
  virtual void v(identifier *a) = 0;
  virtual void v(identifier_list *a) = 0;
  virtual void v(inclusive_or_expr *a) = 0;
  virtual void v(init_declarator *a) = 0;
  virtual void v(init_declarator_list *a) = 0;
  virtual void v(initializer *a) = 0;
  virtual void v(initializer_list *a) = 0;
  virtual void v(iteration_statement *a) = 0;
  virtual void v(jump_statement *a) = 0;
  virtual void v(labeled_statement *a) = 0;
  virtual void v(logical_and_expr *a) = 0;
  virtual void v(logical_or_expr *a) = 0;
  virtual void v(multiplicative_expr *a) = 0;
  virtual void v(m *a) = 0;
  virtual void v(n *a) = 0;
  virtual void v(parameter_declaration *a) = 0;
  virtual void v(parameter_list *a) = 0;
  virtual void v(parameter_type_list *a) = 0;
  virtual void v(pointer *a) = 0;
  virtual void v(postfix_expr *a) = 0;
  virtual void v(primary_expr *a) = 0;
  virtual void v(relation_expr *a) = 0;
  virtual void v(selection_statement *a) = 0;
  virtual void v(shift_expr *a) = 0;
  virtual void v(specifier_qualifier_list *a) = 0;
  virtual void v(statement *a) = 0;
  virtual void v(statement_list *a) = 0;
  virtual void v(storage_class_specifier *a) = 0;
  virtual void v(struct_declaration *a) = 0;
  virtual void v(struct_declaration_list *a) = 0;
  virtual void v(struct_declarator *a) = 0;
  virtual void v(struct_declarator_list *a) = 0;
  virtual void v(struct_or_union *a) = 0;
  virtual void v(struct_or_union_specifier *a) = 0;
  virtual void v(translation_unit *a) = 0;
  virtual void v(type_name *a) = 0;
  virtual void v(type_qualifier *a) = 0;
  virtual void v(type_qualifier_list *a) = 0;
  virtual void v(type_specifier *a) = 0;
  virtual void v(typedef_name *a) = 0;
  virtual void v(unary_expr *a) = 0;
  virtual void v(unary_operator *a) = 0;
};

#endif
