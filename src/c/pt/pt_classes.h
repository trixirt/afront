/*
 * Copyright (c) 2017-2019 Tom Rix
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

/* multiple includes is ok */

// Define PT_CLASS(classname) to do something
#ifndef PT_CLASS
// If you did not, then it is foreward decl of the class
#define PT_CLASS(C) class C;
#endif

PT_CLASS(abstract_array_declarator)
PT_CLASS(abstract_declarator)
PT_CLASS(abstract_function_declarator)
PT_CLASS(additive_expr)
PT_CLASS(alignment_specifier)
PT_CLASS(and_expr)
PT_CLASS(argument_expr_list)
PT_CLASS(array_declarator)
PT_CLASS(assignment_expr)
PT_CLASS(assignment_operator)
PT_CLASS(atomic_type_specifier)
PT_CLASS(block_item)
PT_CLASS(block_item_list)
PT_CLASS(cast_expr)
PT_CLASS(character_constant)
PT_CLASS(compound_statement)
PT_CLASS(conditional_expr)
PT_CLASS(constant)
PT_CLASS(constant_expr)
PT_CLASS(declaration)
PT_CLASS(declaration_list)
PT_CLASS(declaration_specifiers)
PT_CLASS(declarator)
PT_CLASS(direct_abstract_declarator)
PT_CLASS(direct_declarator)
PT_CLASS(enumeration_constant)
PT_CLASS(enumerator)
PT_CLASS(enumerator_list)
PT_CLASS(enum_specifier)
PT_CLASS(equality_expr)
PT_CLASS(exclusive_or_expr)
PT_CLASS(expr)
PT_CLASS(expression_statement)
PT_CLASS(external_definition)
PT_CLASS(floating_constant)
PT_CLASS(function_body)
PT_CLASS(function_declarator)
PT_CLASS(function_definition)
PT_CLASS(function_specifier)
PT_CLASS(generic_association)
PT_CLASS(generic_assoc_list)
PT_CLASS(generic_selection)
PT_CLASS(identifier)
PT_CLASS(identifier_list)
PT_CLASS(inclusive_or_expr)
PT_CLASS(init_declarator)
PT_CLASS(init_declarator_list)
PT_CLASS(initializer)
PT_CLASS(initializer_list)
PT_CLASS(integer_constant)
PT_CLASS(iteration_statement)
PT_CLASS(jump_statement)
PT_CLASS(labeled_statement)
PT_CLASS(logical_and_expr)
PT_CLASS(logical_or_expr)
PT_CLASS(m)
PT_CLASS(multiplicative_expr)
PT_CLASS(n)
PT_CLASS(parameter_declaration)
PT_CLASS(parameter_list)
PT_CLASS(parameter_type_list)
PT_CLASS(pointer)
PT_CLASS(postfix_expr)
PT_CLASS(primary_expr)
PT_CLASS(relation_expr)
PT_CLASS(selection_statement)
PT_CLASS(shift_expr)
PT_CLASS(specifier_qualifier_list)
PT_CLASS(statement)
PT_CLASS(statement_list)
PT_CLASS(static_assert_declaration)
PT_CLASS(storage_class_specifier)
PT_CLASS(string_literal)
PT_CLASS(struct_declaration)
PT_CLASS(struct_declaration_list)
PT_CLASS(struct_declarator)
PT_CLASS(struct_declarator_list)
PT_CLASS(struct_or_union)
PT_CLASS(struct_or_union_specifier)
PT_CLASS(translation_unit)
PT_CLASS(type_name)
PT_CLASS(type_qualifier)
PT_CLASS(type_qualifier_list)
PT_CLASS(type_specifier)
PT_CLASS(typedef_name)
PT_CLASS(unary_expr)
PT_CLASS(unary_operator)

#undef PT_CLASS
