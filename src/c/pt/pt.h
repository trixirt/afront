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
#ifndef NADA_C_PT_PT_H
#define NADA_C_PT_PT_H

#include "abstract_array_declarator.h"
#include "abstract_declarator.h"
#include "abstract_function_declarator.h"
#include "additive_expr.h"
#include "and_expr.h"
#include "argument_expr_list.h"
#include "array_declarator.h"
#include "assignment_expr.h"
#include "assignment_operator.h"
#include "cast_expr.h"
#include "compound_statement.h"
#include "conditional_expr.h"
#include "constant_expr.h"
#include "declaration.h"
#include "declaration_list.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "direct_abstract_declarator.h"
#include "direct_declarator.h"
#include "enum_specifier.h"
#include "enumerator.h"
#include "enumerator_list.h"
#include "equality_expr.h"
#include "exclusive_or_expr.h"
#include "expr.h"
#include "expression_statement.h"
#include "external_definition.h"
#include "function_body.h"
#include "function_declarator.h"
#include "function_definition.h"
#include "function_specifier.h"
#include "generic_association.h"
#include "generic_assoc_list.h"
#include "generic_selection.h"
#include "identifier.h"
#include "identifier_list.h"
#include "inclusive_or_expr.h"
#include "init_declaration.h"
#include "init_declarator.h"
#include "init_declarator_list.h"
#include "initializer.h"
#include "initializer_list.h"
#include "iteration_statement.h"
#include "jump_statement.h"
#include "labeled_statement.h"
#include "logical_and_expr.h"
#include "logical_or_expr.h"
#include "multiplicative_expr.h"
#include "parameter_declaration.h"
#include "parameter_list.h"
#include "parameter_type_list.h"
#include "pointer.h"
#include "postfix_expr.h"
#include "primary_expr.h"
#include "relation_expr.h"
#include "selection_statement.h"
#include "shift_expr.h"
#include "specifier_qualifier_list.h"
#include "statement.h"
#include "statement_list.h"
#include "storage_class_specifier.h"
#include "struct_declaration.h"
#include "struct_declaration_list.h"
#include "struct_declarator.h"
#include "struct_declarator_list.h"
#include "struct_or_union.h"
#include "struct_or_union_specifier.h"
#include "translation_unit.h"
#include "type_name.h"
#include "type_qualifier.h"
#include "type_qualifier_list.h"
#include "typedef_name.h"
#include "type_specifier.h"
#include "unary_expr.h"
#include "unary_operator.h"

#include "v/visitor.h"
#endif
