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

#include "typedefs.h"
#include "e.h"
#include "pt.h"

typedefs::typedefs() { seen_typedef = false; }
typedefs::~typedefs() {}

std::vector<identifier *> &typedefs::get() { return i; }
bool typedefs::is() { return seen_typedef; }

void typedefs::v(declaration *a) { a->caccept(this); }
void typedefs::v(declaration_specifiers *a) { a->caccept(this); }
void typedefs::v(storage_class_specifier *a) {
  if (a->what() == nada::parser::token::TYPEDEF)
    seen_typedef = true;
  /* terminal */
}
void typedefs::v(init_declarator_list *a) { a->caccept(this); }
void typedefs::v(init_declarator *a) { a->caccept(this); }
void typedefs::v(declarator *a) { a->caccept(this); }
void typedefs::v(direct_declarator *a) { a->caccept(this); }
void typedefs::v(identifier *a) {
    if (a->parent() != nullptr) {
	if (dynamic_cast<direct_declarator *>(a->parent())) {
	    i.push_back(a);
	    if (i.empty()) {
		throw(ice_exception(__FILE__, __LINE__, "empty identifier list"));
	    }
	}
    }
    /* terminal */
}


void typedefs::v(abstract_array_declarator *a) { /* skip */ }
void typedefs::v(abstract_declarator *a) { /* skip */ }
void typedefs::v(abstract_function_declarator *a) { /* skip */ }
void typedefs::v(additive_expr *a) { /* skip */ }
void typedefs::v(and_expr *a) { /* skip */ }
void typedefs::v(argument_expr_list *a) { /* skip */ }
void typedefs::v(array_declarator *a) { /* skip */ }
void typedefs::v(assignment_expr *a) { /* skip */ }
void typedefs::v(assignment_operator *a) { /* skip */ }
void typedefs::v(cast_expr *a) { /* skip */ }
void typedefs::v(compound_statement *a) { /* skip */ }
void typedefs::v(conditional_expr *a) { /* skip */ }
void typedefs::v(constant_expr *a) { /* skip */ }
void typedefs::v(declaration_list *a) { /* skip */ }
void typedefs::v(direct_abstract_declarator *a) { /* skip */ }
void typedefs::v(enumerator *a) { /* skip */ }
void typedefs::v(enumerator_list *a) { /* skip */ }
void typedefs::v(enum_specifier *a) { /* skip */ }
void typedefs::v(equality_expr *a) { /* skip */ }
void typedefs::v(exclusive_or_expr *a) { /* skip */ }
void typedefs::v(expr *a) { /* skip */ }
void typedefs::v(expression_statement *a) { /* skip */ }
void typedefs::v(external_definition *a) { /* skip */ }
void typedefs::v(function_body *a) { /* skip */ }
void typedefs::v(function_declarator *a) { /* skip */ }
void typedefs::v(function_definition *a) { /* skip */ }
void typedefs::v(function_specifier *a) { /* skip */ }
void typedefs::v(generic_association *a) { /* skip */ }
void typedefs::v(generic_assoc_list *a) { /* skip */ }
void typedefs::v(generic_selection *a) { /* skip */ }
void typedefs::v(identifier_list *a) { /* skip */ }
void typedefs::v(inclusive_or_expr *a) { /* skip */ }
void typedefs::v(initializer *a) { /* skip */ }
void typedefs::v(initializer_list *a) { /* skip */ }
void typedefs::v(iteration_statement *a) { /* skip */ }
void typedefs::v(jump_statement *a) { /* skip */ }
void typedefs::v(labeled_statement *a) { /* skip */ }
void typedefs::v(logical_and_expr *a) { /* skip */ }
void typedefs::v(logical_or_expr *a) { /* skip */ }
void typedefs::v(multiplicative_expr *a) { /* skip */ }
void typedefs::v(m *a) { /* skip */ }
void typedefs::v(n *a) { /* skip */ }
void typedefs::v(parameter_declaration *a) { /* skip */ }
void typedefs::v(parameter_list *a) { /* skip */ }
void typedefs::v(parameter_type_list *a) { /* skip */ }
void typedefs::v(pointer *a) { /* skip */ }
void typedefs::v(postfix_expr *a) { /* skip */ }
void typedefs::v(primary_expr *a) { /* skip */ }
void typedefs::v(relation_expr *a) { /* skip */ }
void typedefs::v(selection_statement *a) { /* skip */ }
void typedefs::v(shift_expr *a) { /* skip */ }
void typedefs::v(specifier_qualifier_list *a) { /* skip */ }
void typedefs::v(statement *a) { /* skip */ }
void typedefs::v(statement_list *a) { /* skip */ }
void typedefs::v(struct_declaration *a) { /* skip */ }
void typedefs::v(struct_declaration_list *a) { /* skip */ }
void typedefs::v(struct_declarator *a) { /* skip */ }
void typedefs::v(struct_declarator_list *a) { /* skip */ }
void typedefs::v(struct_or_union *a) { /* terminal */ }
void typedefs::v(struct_or_union_specifier *a) { /* skip */ }
void typedefs::v(translation_unit *a) { /* no possible */ }
void typedefs::v(type_name *a) { /* skip */ }
void typedefs::v(type_qualifier *a) { /* skip */ }
void typedefs::v(type_qualifier_list *a) { /* skip */ }
void typedefs::v(type_specifier *a) { /* skip */ }
void typedefs::v(typedef_name *a) { /* skip */ }
void typedefs::v(unary_expr *a) { /* skip */ }
void typedefs::v(unary_operator *a) { /* terminal */ }
