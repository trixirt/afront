/* Copyright (c) 2019 Tom Rix
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

%type <std::shared_ptr<abstract_array_declarator>> abstract_array_declarator;
%type <std::shared_ptr<abstract_declarator>> abstract_declarator;
%type <std::shared_ptr<abstract_function_declarator>> abstract_function_declarator;
%type <std::shared_ptr<additive_expr>> additive_expr;
%type <std::shared_ptr<alignment_specifier>> alignment_specifier;
%type <std::shared_ptr<and_expr>> and_expr;
%type <std::shared_ptr<argument_expr_list>> argument_expr_list;
%type <std::shared_ptr<array_declarator>> array_declarator;
%type <std::shared_ptr<assignment_expr>> assignment_expr;
%type <std::shared_ptr<assignment_operator>> assignment_operator;
%type <std::shared_ptr<atomic_type_specifier>> atomic_type_specifier;
%type <std::shared_ptr<cast_expr>> cast_expr;
%type <std::shared_ptr<character_constant>> character_constant;
%type <std::shared_ptr<conditional_expr>> conditional_expr;
%type <std::shared_ptr<constant>> constant;
%type <std::shared_ptr<constant_expr>> constant_expr;
%type <std::shared_ptr<control_line>> control_line;
%type <std::shared_ptr<cpp_primary_expr>> primary_expr;
%type <std::shared_ptr<cpp_va_arg>> va_arg;
%type <std::shared_ptr<declaration_specifiers>> declaration_specifiers;
%type <std::shared_ptr<declarator>> declarator;
%type <std::shared_ptr<defined>> defined;
%type <std::shared_ptr<direct_abstract_declarator>> direct_abstract_declarator;
%type <std::shared_ptr<direct_declarator>> direct_declarator;
%type <std::shared_ptr<elif_group>> elif_group;
%type <std::shared_ptr<elif_groups>> elif_groups;
%type <std::shared_ptr<else_group>> else_group;
%type <std::shared_ptr<enumeration_constant>> enumeration_constant;
%type <std::shared_ptr<enumerator>> enumerator;
%type <std::shared_ptr<enumerator_list>> enumerator_list;
%type <std::shared_ptr<enum_specifier>> enum_specifier;
%type <std::shared_ptr<equality_expr>> equality_expr;
%type <std::shared_ptr<exclusive_or_expr>> exclusive_or_expr;
%type <std::shared_ptr<expr>> expr;
%type <std::shared_ptr<floating_constant>> floating_constant;
%type <std::shared_ptr<function_declarator>> function_declarator;
%type <std::shared_ptr<function_specifier>> function_specifier;
%type <std::shared_ptr<generic_association>> generic_association;
%type <std::shared_ptr<generic_assoc_list>> generic_assoc_list;
%type <std::shared_ptr<generic_selection>> generic_selection;
%type <std::shared_ptr<group>> group;
%type <std::shared_ptr<group_part>> group_part;
%type <std::shared_ptr<identifier>> identifier;
%type <std::shared_ptr<identifier>> identifier_lparen;
%type <std::shared_ptr<identifier>> typename_identifier;
%type <std::shared_ptr<identifier_list>> identifier_list;
%type <std::shared_ptr<if_group>> if_group;
%type <std::shared_ptr<if_section>> if_section;
%type <std::shared_ptr<inclusive_or_expr>> inclusive_or_expr;
%type <std::shared_ptr<integer_constant>> integer_constant;
%type <std::shared_ptr<logical_and_expr>> logical_and_expr;
%type <std::shared_ptr<logical_or_expr>> logical_or_expr;
%type <std::shared_ptr<multiplicative_expr>> multiplicative_expr;
%type <std::shared_ptr<non_directive>> non_directive;
%type <std::shared_ptr<parameter_declaration>> parameter_declaration;
%type <std::shared_ptr<parameter_list>> parameter_list;
%type <std::shared_ptr<parameter_type_list>> parameter_type_list;
%type <std::shared_ptr<pointer>> pointer;
%type <std::shared_ptr<postfix_expr>> postfix_expr;
%type <std::shared_ptr<pp_tokens>> pp_tokens;
%type <std::shared_ptr<preprocessing_file>> preprocessing_file;
%type <std::shared_ptr<preprocessing_token>> preprocessing_token;
%type <std::shared_ptr<relation_expr>> relation_expr;
%type <std::shared_ptr<replacement_list>> replacement_list;
%type <std::shared_ptr<shift_expr>> shift_expr;
%type <std::shared_ptr<specifier_qualifier_list>> specifier_qualifier_list;
%type <std::shared_ptr<static_assert_declaration>> static_assert_declaration;
%type <std::shared_ptr<storage_class_specifier>> storage_class_specifier;
%type <std::shared_ptr<string_literal>> string_literal;
%type <std::shared_ptr<struct_declaration_list>> struct_declaration_list;
%type <std::shared_ptr<struct_declaration>> struct_declaration;
%type <std::shared_ptr<struct_declarator_list>> struct_declarator_list;
%type <std::shared_ptr<struct_declarator>> struct_declarator;
%type <std::shared_ptr<struct_or_union_specifier>> struct_or_union_specifier;
%type <std::shared_ptr<struct_or_union>> struct_or_union;
%type <std::shared_ptr<text_line>> text_line;
%type <std::shared_ptr<typedef_name>> typedef_name;
%type <std::shared_ptr<type_name>> type_name;
%type <std::shared_ptr<type_qualifier_list>> type_qualifier_list;
%type <std::shared_ptr<type_qualifier>> type_qualifier;
%type <std::shared_ptr<type_specifier>> type_specifier;
%type <std::shared_ptr<unary_expr>> unary_expr;
%type <std::shared_ptr<unary_operator>> unary_operator;

