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

/* multiple includes is ok */

#ifdef C_PT_VISITOR_METHOD
#undef C_PT_VISITOR_METHOD
#endif

#ifdef C_PT_VISITOR_METHODS
#undef C_PT_VISITOR_METHODS
#endif

#ifdef VISITOR_ABSTRACT_CLASS
#define C_PT_VISITOR_METHOD(C) virtual void v(C *) = 0
#else
#define C_PT_VISITOR_METHOD(C) virtual void v(C *)
#endif

#define C_PT_VISITOR_METHODS()                                                 \
  C_PT_VISITOR_METHOD(abstract_array_declarator);                              \
  C_PT_VISITOR_METHOD(abstract_declarator);                                    \
  C_PT_VISITOR_METHOD(abstract_function_declarator);                           \
  C_PT_VISITOR_METHOD(additive_expr);                                          \
  C_PT_VISITOR_METHOD(alignment_specifier);                                    \
  C_PT_VISITOR_METHOD(and_expr);                                               \
  C_PT_VISITOR_METHOD(argument_expr_list);                                     \
  C_PT_VISITOR_METHOD(array_declarator);                                       \
  C_PT_VISITOR_METHOD(assignment_expr);                                        \
  C_PT_VISITOR_METHOD(assignment_operator);                                    \
  C_PT_VISITOR_METHOD(atomic_type_specifier);                                  \
  C_PT_VISITOR_METHOD(block_item);                                             \
  C_PT_VISITOR_METHOD(block_item_list);                                        \
  C_PT_VISITOR_METHOD(cast_expr);                                              \
  C_PT_VISITOR_METHOD(character_constant);                                     \
  C_PT_VISITOR_METHOD(compound_statement);                                     \
  C_PT_VISITOR_METHOD(conditional_expr);                                       \
  C_PT_VISITOR_METHOD(constant);                                               \
  C_PT_VISITOR_METHOD(constant_expr);                                          \
  C_PT_VISITOR_METHOD(declaration);                                            \
  C_PT_VISITOR_METHOD(declaration_list);                                       \
  C_PT_VISITOR_METHOD(declaration_specifiers);                                 \
  C_PT_VISITOR_METHOD(declarator);                                             \
  C_PT_VISITOR_METHOD(direct_abstract_declarator);                             \
  C_PT_VISITOR_METHOD(direct_declarator);                                      \
  C_PT_VISITOR_METHOD(enumeration_constant);                                   \
  C_PT_VISITOR_METHOD(enumerator);                                             \
  C_PT_VISITOR_METHOD(enumerator_list);                                        \
  C_PT_VISITOR_METHOD(enum_specifier);                                         \
  C_PT_VISITOR_METHOD(equality_expr);                                          \
  C_PT_VISITOR_METHOD(exclusive_or_expr);                                      \
  C_PT_VISITOR_METHOD(expr);                                                   \
  C_PT_VISITOR_METHOD(expression_statement);                                   \
  C_PT_VISITOR_METHOD(external_definition);                                    \
  C_PT_VISITOR_METHOD(floating_constant);                                      \
  C_PT_VISITOR_METHOD(function_body);                                          \
  C_PT_VISITOR_METHOD(function_declarator);                                    \
  C_PT_VISITOR_METHOD(function_definition);                                    \
  C_PT_VISITOR_METHOD(function_specifier);                                     \
  C_PT_VISITOR_METHOD(generic_association);                                    \
  C_PT_VISITOR_METHOD(generic_assoc_list);                                     \
  C_PT_VISITOR_METHOD(generic_selection);                                      \
  C_PT_VISITOR_METHOD(identifier);                                             \
  C_PT_VISITOR_METHOD(identifier_list);                                        \
  C_PT_VISITOR_METHOD(inclusive_or_expr);                                      \
  C_PT_VISITOR_METHOD(init_declarator);                                        \
  C_PT_VISITOR_METHOD(init_declarator_list);                                   \
  C_PT_VISITOR_METHOD(initializer);                                            \
  C_PT_VISITOR_METHOD(initializer_list);                                       \
  C_PT_VISITOR_METHOD(integer_constant);                                       \
  C_PT_VISITOR_METHOD(iteration_statement);                                    \
  C_PT_VISITOR_METHOD(jump_statement);                                         \
  C_PT_VISITOR_METHOD(labeled_statement);                                      \
  C_PT_VISITOR_METHOD(logical_and_expr);                                       \
  C_PT_VISITOR_METHOD(logical_or_expr);                                        \
  C_PT_VISITOR_METHOD(multiplicative_expr);                                    \
  C_PT_VISITOR_METHOD(m);                                                      \
  C_PT_VISITOR_METHOD(n);                                                      \
  C_PT_VISITOR_METHOD(parameter_declaration);                                  \
  C_PT_VISITOR_METHOD(parameter_list);                                         \
  C_PT_VISITOR_METHOD(parameter_type_list);                                    \
  C_PT_VISITOR_METHOD(pointer);                                                \
  C_PT_VISITOR_METHOD(postfix_expr);                                           \
  C_PT_VISITOR_METHOD(primary_expr);                                           \
  C_PT_VISITOR_METHOD(relation_expr);                                          \
  C_PT_VISITOR_METHOD(selection_statement);                                    \
  C_PT_VISITOR_METHOD(shift_expr);                                             \
  C_PT_VISITOR_METHOD(specifier_qualifier_list);                               \
  C_PT_VISITOR_METHOD(statement);                                              \
  C_PT_VISITOR_METHOD(statement_list);                                         \
  C_PT_VISITOR_METHOD(static_assert_declaration);                              \
  C_PT_VISITOR_METHOD(storage_class_specifier);                                \
  C_PT_VISITOR_METHOD(string_literal);                                         \
  C_PT_VISITOR_METHOD(struct_declaration);                                     \
  C_PT_VISITOR_METHOD(struct_declaration_list);                                \
  C_PT_VISITOR_METHOD(struct_declarator);                                      \
  C_PT_VISITOR_METHOD(struct_declarator_list);                                 \
  C_PT_VISITOR_METHOD(struct_or_union);                                        \
  C_PT_VISITOR_METHOD(struct_or_union_specifier);                              \
  C_PT_VISITOR_METHOD(translation_unit);                                       \
  C_PT_VISITOR_METHOD(type_name);                                              \
  C_PT_VISITOR_METHOD(type_qualifier);                                         \
  C_PT_VISITOR_METHOD(type_qualifier_list);                                    \
  C_PT_VISITOR_METHOD(type_specifier);                                         \
  C_PT_VISITOR_METHOD(typedef_name);                                           \
  C_PT_VISITOR_METHOD(unary_expr);                                             \
  C_PT_VISITOR_METHOD(unary_operator)

C_PT_VISITOR_METHODS();
