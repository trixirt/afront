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

#include "cg.h"
#include "e.h"
#include "pt.h"
cg::cg() {}
cg::~cg() {}
void cg::v(abstract_array_declarator *a) { a->caccept(this); }

void cg::v(abstract_declarator *a) { a->caccept(this); }

void cg::v(abstract_function_declarator *a) { a->caccept(this); }

void cg::v(additive_expr *a) { a->caccept(this); }

void cg::v(alignment_specifier *a) { a->caccept(this); }

void cg::v(and_expr *a) { a->caccept(this); }

void cg::v(argument_expr_list *a) { a->caccept(this); }

void cg::v(array_declarator *a) { a->caccept(this); }

void cg::v(assignment_expr *a) { a->caccept(this); }

void cg::v(assignment_operator *a) { a->caccept(this); }

void cg::v(atomic_type_specifier *a) { a->caccept(this); }

void cg::v(block_item *a) { a->caccept(this); }

void cg::v(block_item_list *a) { a->caccept(this); }

void cg::v(cast_expr *a) { a->caccept(this); }

void cg::v(compound_statement *a) { a->caccept(this); }

void cg::v(conditional_expr *a) { a->caccept(this); }

void cg::v(constant_expr *a) { a->caccept(this); }

void cg::v(declaration *a) { a->caccept(this); }

void cg::v(declaration_list *a) { a->caccept(this); }

void cg::v(declaration_specifiers *a) { a->caccept(this); }

void cg::v(declarator *a) { a->caccept(this); }

void cg::v(direct_abstract_declarator *a) { a->caccept(this); }

void cg::v(direct_declarator *a) { a->caccept(this); }

void cg::v(enumerator *a) { a->caccept(this); }

void cg::v(enumerator_list *a) { a->caccept(this); }

void cg::v(enum_specifier *a) { a->caccept(this); }

void cg::v(equality_expr *a) { a->caccept(this); }

void cg::v(exclusive_or_expr *a) { a->caccept(this); }

void cg::v(expr *a) { a->caccept(this); }

void cg::v(expression_statement *a) { a->caccept(this); }

void cg::v(external_definition *a) { a->caccept(this); }

void cg::v(function_body *a) { a->caccept(this); }

void cg::v(function_declarator *a) { a->caccept(this); }

void cg::v(function_definition *a) { a->caccept(this); }

void cg::v(function_specifier *a) { a->caccept(this); }

void cg::v(generic_association *a) { a->caccept(this); }

void cg::v(generic_assoc_list *a) { a->caccept(this); }

void cg::v(generic_selection *a) { a->caccept(this); }

void cg::v(identifier *a) {}

void cg::v(identifier_list *a) { a->caccept(this); }

void cg::v(inclusive_or_expr *a) { a->caccept(this); }

void cg::v(init_declarator *a) { a->caccept(this); }

void cg::v(init_declarator_list *a) { a->caccept(this); }

void cg::v(initializer *a) { a->caccept(this); }

void cg::v(initializer_list *a) { a->caccept(this); }

void cg::v(iteration_statement *a) { a->caccept(this); }

void cg::v(jump_statement *a) { a->caccept(this); }

void cg::v(labeled_statement *a) { a->caccept(this); }

void cg::v(logical_and_expr *a) { a->caccept(this); }

void cg::v(logical_or_expr *a) { a->caccept(this); }

void cg::v(multiplicative_expr *a) { a->caccept(this); }

void cg::v(m *a) { a->caccept(this); }

void cg::v(n *a) { a->caccept(this); }

void cg::v(parameter_declaration *a) { a->caccept(this); }

void cg::v(parameter_list *a) { a->caccept(this); }

void cg::v(parameter_type_list *a) { a->caccept(this); }

void cg::v(pointer *a) { a->caccept(this); }

void cg::v(postfix_expr *a) { a->caccept(this); }

void cg::v(primary_expr *a) { a->caccept(this); }

void cg::v(relation_expr *a) { a->caccept(this); }

void cg::v(selection_statement *a) { a->caccept(this); }

void cg::v(shift_expr *a) { a->caccept(this); }

void cg::v(specifier_qualifier_list *a) { a->caccept(this); }

void cg::v(statement *a) { a->caccept(this); }

void cg::v(statement_list *a) { a->caccept(this); }

void cg::v(static_assert_declaration *a) { a->caccept(this); }

void cg::v(storage_class_specifier *a) { a->caccept(this); }

void cg::v(struct_declaration *a) { a->caccept(this); }

void cg::v(struct_declaration_list *a) { a->caccept(this); }

void cg::v(struct_declarator *a) { a->caccept(this); }

void cg::v(struct_declarator_list *a) { a->caccept(this); }

void cg::v(struct_or_union *a) {}

void cg::v(struct_or_union_specifier *a) { a->caccept(this); }

void cg::v(translation_unit *a) { a->caccept(this); }

void cg::v(type_name *a) { a->caccept(this); }

void cg::v(type_qualifier *a) { a->caccept(this); }

void cg::v(type_qualifier_list *a) { a->caccept(this); }

void cg::v(type_specifier *a) { a->caccept(this); }

void cg::v(typedef_name *a) { a->caccept(this); }

void cg::v(unary_expr *a) { a->caccept(this); }

void cg::v(unary_operator *a) {}
