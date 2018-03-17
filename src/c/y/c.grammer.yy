/* Copyright (c) 2017-2018 Tom Rix
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
%include c.grammer.primary_expr.yy
%include c.grammer.postfix_expr.yy
%include c.grammer.argument_expr_list.yy
%include c.grammer.unary_expr.yy
%include c.grammer.unary_operator.yy
%include c.grammer.cast_expr.yy
%include c.grammer.multiplicative_expr.yy
%include c.grammer.additive_expr.yy
%include c.grammer.shift_expr.yy
%include c.grammer.relation_expr.yy
%include c.grammer.equality_expr.yy
%include c.grammer.and_expr.yy
%include c.grammer.exclusive_or_expr.yy
%include c.grammer.inclusive_or_expr.yy
%include c.grammer.logical_and_expr.yy
%include c.grammer.logical_or_expr.yy
%include c.grammer.conditional_expr.yy
%include c.grammer.assignment_expr.yy
%include c.grammer.assignment_operator.yy
%include c.grammer.expr.yy
%include c.grammer.character_constant.yy
%include c.grammer.integer_constant.yy
%include c.grammer.floating_constant.yy
%include c.grammer.constant.yy
%include c.grammer.constant_expr.yy
%include c.grammer.declaration.yy
%include c.grammer.declaration_specifiers.yy
%include c.grammer.init_declarator_list.yy
%include c.grammer.init_declarator.yy
%include c.grammer.storage_class_specifier.yy
%include c.grammer.typedef_name.yy
%include c.grammer.type_specifier.yy
%include c.grammer.type_qualifier.yy
%include c.grammer.struct_or_union_specifier.yy
%include c.grammer.struct_or_union.yy
%include c.grammer.struct_declaration_list.yy
%include c.grammer.specifier_qualifier_list.yy
%include c.grammer.struct_declaration.yy
%include c.grammer.struct_declarator_list.yy
%include c.grammer.struct_declarator.yy
%include c.grammer.enum_specifier.yy
%include c.grammer.enumeration_constant.yy
%include c.grammer.enumerator.yy
%include c.grammer.enumerator_list.yy
%include c.grammer.declarator.yy
%include c.grammer.direct_declarator.yy
%include c.grammer.array_declarator.yy
%include c.grammer.function_declarator.yy
%include c.grammer.type_qualifier_list.yy
%include c.grammer.pointer.yy
%include c.grammer.identifier_list.yy
%include c.grammer.parameter_type_list.yy
%include c.grammer.parameter_list.yy
%include c.grammer.parameter_declaration.yy
%include c.grammer.type_name.yy
%include c.grammer.abstract_declarator.yy
%include c.grammer.direct_abstract_declarator.yy
%include c.grammer.abstract_array_declarator.yy
%include c.grammer.abstract_function_declarator.yy
%include c.grammer.initializer.yy
%include c.grammer.initializer_list.yy
%include c.grammer.statement.yy
%include c.grammer.labeled_statement.yy
%include c.grammer.compound_statement.yy
%include c.grammer.declaration_list.yy
%include c.grammer.statement_list.yy
%include c.grammer.expression_statement.yy
%include c.grammer.selection_statement.yy
%include c.grammer.iteration_statement.yy
%include c.grammer.jump_statement.yy
%include c.grammer.translation_unit.yy
%include c.grammer.external_definition.yy
%include c.grammer.function_definition.yy
%include c.grammer.function_body.yy
%include c.grammer.identifier.yy
%ifdef c99
%include c.grammer.block_item.yy
%include c.grammer.block_item_list.yy
%include c.grammer.function_specifier.yy
%endif
%ifdef c11
%include c.grammer.alignment_specifier.yy
%include c.grammer.atomic_type_specifier.yy
%include c.grammer.generic_association.yy
%include c.grammer.generic_assoc_list.yy
%include c.grammer.generic_selection.yy
%include c.grammer.static_assert_declaration.yy
%endif
