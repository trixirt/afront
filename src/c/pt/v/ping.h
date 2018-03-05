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

#ifndef NADA_C_PT_VIS_PING_H
#define NADA_C_PT_VIS_PING_H
#include "visitor.h"
#include "parser.tab.hh"
class ping : public visitor {
public:
  ping(bool pre = true);
  virtual ~ping();
  virtual void v(abstract_array_declarator *a);
  virtual void v(abstract_declarator *a);
  virtual void v(abstract_function_declarator *a);
  virtual void v(additive_expr *a);
  virtual void v(alignment_specifier *a);
  virtual void v(and_expr *a);
  virtual void v(argument_expr_list *a);
  virtual void v(array_declarator *a);
  virtual void v(assignment_expr *a);
  virtual void v(assignment_operator *a);
  virtual void v(atomic_type_specifier *a);
  virtual void v(block_item *a);
  virtual void v(block_item_list *a);
  virtual void v(cast_expr *a);
  virtual void v(compound_statement *a);
  virtual void v(conditional_expr *a);
  virtual void v(constant_expr *a);
  virtual void v(declaration *a);
  virtual void v(declaration_list *a);
  virtual void v(declaration_specifiers *a);
  virtual void v(declarator *a);
  virtual void v(direct_abstract_declarator *a);
  virtual void v(direct_declarator *a);
  virtual void v(enumeration_constant *a);
  virtual void v(enumerator *a);
  virtual void v(enumerator_list *a);
  virtual void v(enum_specifier *a);
  virtual void v(equality_expr *a);
  virtual void v(exclusive_or_expr *a);
  virtual void v(expr *a);
  virtual void v(expression_statement *a);
  virtual void v(external_definition *a);
  virtual void v(function_body *a);
  virtual void v(function_declarator *a);
  virtual void v(function_definition *a);
  virtual void v(function_specifier *a);
  virtual void v(generic_association *a);
  virtual void v(generic_assoc_list *a);
  virtual void v(generic_selection *a);
  virtual void v(identifier *a);
  virtual void v(identifier_list *a);
  virtual void v(inclusive_or_expr *a);
  virtual void v(init_declarator *a);
  virtual void v(init_declarator_list *a);
  virtual void v(initializer *a);
  virtual void v(initializer_list *a);
  virtual void v(iteration_statement *a);
  virtual void v(jump_statement *a);
  virtual void v(labeled_statement *a);
  virtual void v(logical_and_expr *a);
  virtual void v(logical_or_expr *a);
  virtual void v(multiplicative_expr *a);
  virtual void v(m *a);
  virtual void v(n *a);
  virtual void v(parameter_declaration *a);
  virtual void v(parameter_list *a);
  virtual void v(parameter_type_list *a);
  virtual void v(pointer *a);
  virtual void v(postfix_expr *a);
  virtual void v(primary_expr *a);
  virtual void v(relation_expr *a);
  virtual void v(selection_statement *a);
  virtual void v(shift_expr *a);
  virtual void v(specifier_qualifier_list *a);
  virtual void v(statement *a);
  virtual void v(statement_list *a);
  virtual void v(static_assert_declaration *a);
  virtual void v(storage_class_specifier *a);
  virtual void v(struct_declaration *a);
  virtual void v(struct_declaration_list *a);
  virtual void v(struct_declarator *a);
  virtual void v(struct_declarator_list *a);
  virtual void v(struct_or_union *a);
  virtual void v(struct_or_union_specifier *a);
  virtual void v(translation_unit *a);
  virtual void v(type_name *a);
  virtual void v(type_qualifier *a);
  virtual void v(type_qualifier_list *a);
  virtual void v(type_specifier *a);
  virtual void v(typedef_name *a);
  virtual void v(unary_expr *a);
  virtual void v(unary_operator *a);

private:
  bool preorder;
};
#endif
