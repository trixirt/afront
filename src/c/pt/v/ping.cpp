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

#include "ping.h"
#include "e.h"
#include "pt.h"
ping::ping(bool pre) { preorder = pre; }
ping::~ping() {}
void ping::v(abstract_array_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(abstract_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(abstract_function_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(additive_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(alignment_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(and_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(argument_expr_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(array_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(assignment_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(assignment_operator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(atomic_type_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(block_item *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(block_item_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(cast_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(compound_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(conditional_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(constant_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(declaration *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(declaration_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(declaration_specifiers *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(direct_abstract_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(direct_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(enumerator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(enumerator_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(enum_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(equality_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(exclusive_or_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(expression_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(external_definition *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(function_body *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(function_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(function_definition *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(function_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(generic_association *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(generic_assoc_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(generic_selection *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(identifier *a) {
  if (preorder)
    a->notify();
  if (!preorder)
    a->notify();
}

void ping::v(identifier_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(inclusive_or_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(init_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(init_declarator_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(initializer *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(initializer_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(iteration_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(jump_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(labeled_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(logical_and_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(logical_or_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(multiplicative_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(m *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(n *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(parameter_declaration *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(parameter_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(parameter_type_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(pointer *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(postfix_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(primary_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(relation_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(selection_statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(shift_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(specifier_qualifier_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(statement *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(statement_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(static_assert_declaration *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(storage_class_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(struct_declaration *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(struct_declaration_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(struct_declarator *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(struct_declarator_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(struct_or_union *a) {
  if (preorder)
    a->notify();
  if (!preorder)
    a->notify();
}

void ping::v(struct_or_union_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(translation_unit *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(type_name *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(type_qualifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(type_qualifier_list *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(type_specifier *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(typedef_name *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(unary_expr *a) {
  if (preorder)
    a->notify();
  a->caccept(this);
  if (!preorder)
    a->notify();
}

void ping::v(unary_operator *a) {
  if (preorder)
    a->notify();
  if (!preorder)
    a->notify();
}
