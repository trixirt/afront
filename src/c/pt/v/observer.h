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
#ifndef AFRONT_C_PT_V_OBSERVER_H
#define AFRONT_C_PT_V_OBSERVER_H

class observer {
public:
  observer() {}
  virtual ~observer() {}

  virtual void update(abstract_array_declarator *a) {}
  virtual void update(abstract_declarator *a) {}
  virtual void update(abstract_function_declarator *a) {}
  virtual void update(additive_expr *a) {}
  virtual void update(alignment_specifier *a) {}
  virtual void update(and_expr *a) {}
  virtual void update(argument_expr_list *a) {}
  virtual void update(array_declarator *a) {}
  virtual void update(assignment_expr *a) {}
  virtual void update(assignment_operator *a) {}
  virtual void update(atomic_type_specifier *a) {}
  virtual void update(block_item *a) {}
  virtual void update(block_item_list *a) {}
  virtual void update(cast_expr *a) {}
  virtual void update(compound_statement *a) {}
  virtual void update(conditional_expr *a) {}
  virtual void update(constant_expr *a) {}
  virtual void update(declaration *a) {}
  virtual void update(declaration_list *a) {}
  virtual void update(declaration_specifiers *a) {}
  virtual void update(declarator *a) {}
  virtual void update(direct_abstract_declarator *a) {}
  virtual void update(direct_declarator *a) {}
  virtual void update(enumerator *a) {}
  virtual void update(enumerator_list *a) {}
  virtual void update(enum_specifier *a) {}
  virtual void update(equality_expr *a) {}
  virtual void update(exclusive_or_expr *a) {}
  virtual void update(expr *a) {}
  virtual void update(expression_statement *a) {}
  virtual void update(external_definition *a) {}
  virtual void update(function_body *a) {}
  virtual void update(function_declarator *a) {}
  virtual void update(function_definition *a) {}
  virtual void update(function_specifier *a) {}
  virtual void update(generic_association *a) {}
  virtual void update(generic_assoc_list *a) {}
  virtual void update(generic_selection *a) {}
  virtual void update(identifier *a) {}
  virtual void update(identifier_list *a) {}
  virtual void update(inclusive_or_expr *a) {}
  virtual void update(init_declarator *a) {}
  virtual void update(init_declarator_list *a) {}
  virtual void update(initializer *a) {}
  virtual void update(initializer_list *a) {}
  virtual void update(iteration_statement *a) {}
  virtual void update(jump_statement *a) {}
  virtual void update(labeled_statement *a) {}
  virtual void update(logical_and_expr *a) {}
  virtual void update(logical_or_expr *a) {}
  virtual void update(multiplicative_expr *a) {}
  virtual void update(m *a) {}
  virtual void update(n *a) {}
  virtual void update(parameter_declaration *a) {}
  virtual void update(parameter_list *a) {}
  virtual void update(parameter_type_list *a) {}
  virtual void update(pointer *a) {}
  virtual void update(postfix_expr *a) {}
  virtual void update(primary_expr *a) {}
  virtual void update(relation_expr *a) {}
  virtual void update(selection_statement *a) {}
  virtual void update(shift_expr *a) {}
  virtual void update(specifier_qualifier_list *a) {}
  virtual void update(statement *a) {}
  virtual void update(statement_list *a) {}
  virtual void update(static_assert_declaration *a) {}
  virtual void update(storage_class_specifier *a) {}
  virtual void update(struct_declaration *a) {}
  virtual void update(struct_declaration_list *a) {}
  virtual void update(struct_declarator *a) {}
  virtual void update(struct_declarator_list *a) {}
  virtual void update(struct_or_union *a) {}
  virtual void update(struct_or_union_specifier *a) {}
  virtual void update(translation_unit *a) {}
  virtual void update(type_name *a) {}
  virtual void update(type_qualifier *a) {}
  virtual void update(type_qualifier_list *a) {}
  virtual void update(type_specifier *a) {}
  virtual void update(typedef_name *a) {}
  virtual void update(unary_expr *a) {}
  virtual void update(unary_operator *a) {}
};

#endif
