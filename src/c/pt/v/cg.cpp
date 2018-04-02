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
#include "cc1.h"
#include "e.h"
#include "fig.h"
#include "pt.h"

#define V(C)                                                                   \
  void cg::v(C *a) { a->caccept(this); }

cg::cg() {
  config = nullptr;

  if (opt.fig_filename.size()) {
    config = new llvm_configuration(opt.fig_filename);
    if (config->has_triple()) {
      if (opt.flag_verbose)
        std::cout << "Triple : " << config->triple() << std::endl;
    }
  }
}
cg::~cg() {}

V(abstract_array_declarator)
V(abstract_declarator)
V(abstract_function_declarator)
V(additive_expr)
V(alignment_specifier)
V(and_expr)
V(argument_expr_list)
V(array_declarator)
V(assignment_expr)
V(assignment_operator)
V(atomic_type_specifier)
V(block_item)
V(block_item_list)
V(cast_expr)
V(character_constant)
V(compound_statement)
V(conditional_expr)
V(constant)
V(constant_expr)
V(declaration)
V(declaration_list)
V(declaration_specifiers)
V(declarator)
V(direct_abstract_declarator)
V(direct_declarator)
V(enumeration_constant)
V(enumerator)
V(enumerator_list)
V(enum_specifier)
V(equality_expr)
V(exclusive_or_expr)
V(expr)
V(expression_statement)
V(external_definition)
V(floating_constant)
V(function_body)
V(function_declarator)
V(function_definition)
V(function_specifier)
V(generic_association)
V(generic_assoc_list)
V(generic_selection)
V(identifier)
V(identifier_list)
V(inclusive_or_expr)
V(init_declarator)
V(init_declarator_list)
V(initializer)
V(initializer_list)
V(integer_constant)
V(iteration_statement)
V(jump_statement)
V(labeled_statement)
V(logical_and_expr)
V(logical_or_expr)
V(multiplicative_expr)
V(m)
V(n)
V(parameter_declaration)
V(parameter_list)
V(parameter_type_list)
V(pointer)
V(postfix_expr)
V(primary_expr)
V(relation_expr)
V(selection_statement)
V(shift_expr)
V(specifier_qualifier_list)
V(statement)
V(statement_list)
V(static_assert_declaration)
V(storage_class_specifier)
V(string_literal)
V(struct_declaration)
V(struct_declaration_list)
V(struct_declarator)
V(struct_declarator_list)
V(struct_or_union)
V(struct_or_union_specifier)
V(translation_unit)
V(type_name)
V(type_qualifier)
V(type_qualifier_list)
V(type_specifier)
V(typedef_name)
V(unary_expr)
V(unary_operator)
