/* Copyright (c) 2017 Tom Rix
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
%ifdef debug.all
%def   debug.grammer.abstract_array_declarator
%endif

abstract_array_declarator
	: OBK CBK                                                                      { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator()); }
        | direct_abstract_declarator OBK CBK                                           { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1)); }
%ifdef c99
	| OBK assignment_expr CBK                                                      { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2)); }
	| direct_abstract_declarator OBK assignment_expr CBK                           { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1,$3)); }
%else
	| OBK constant_expr CBK                                                        { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2)); }
	| direct_abstract_declarator OBK constant_expr CBK                             { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1,$3)); }
%endif
%ifdef c99
	| direct_abstract_declarator OBK MUL CBK                                       { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1,$3)); }
	| OBK MUL CBK                                                                  { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2)); }
%endif
%ifdef c11
       | OBK STATIC assignment_expr CBK                                                { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2, $3)); }
       | direct_abstract_declarator OBK STATIC assignment_expr CBK                     { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1, $3, $4)); }
       | OBK STATIC type_qualifier_list assignment_expr CBK                            { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2, $3, $4)); }
       | direct_abstract_declarator OBK STATIC type_qualifier_list assignment_expr CBK { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1, $3, $4, $5)); }
       | OBK type_qualifier_list STATIC assignment_expr CBK                            { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($2, $3, $4)); }
       | direct_abstract_declarator OBK type_qualifier_list STATIC assignment_expr CBK { $$ = std::shared_ptr<abstract_array_declarator> (new abstract_array_declarator($1, $3, $4, $5)); }
%endif
	;
 
