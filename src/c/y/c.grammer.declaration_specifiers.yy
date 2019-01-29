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
%ifdef debug.all
%def   debug.grammer.declaration_specifiers
%endif

declaration_specifiers
	: storage_class_specifier                        { $$ = std::shared_ptr<declaration_specifiers> (new declaration_specifiers($1)); } 
	| storage_class_specifier declaration_specifiers { *$2 *= $1; $$ = $2; } 
	| type_specifier                                 { $$ = std::shared_ptr<declaration_specifiers> (new declaration_specifiers($1)); } 
	| type_specifier declaration_specifiers          { *$2 *= $1; $$ = $2; }
	| type_qualifier                                 { $$ = std::shared_ptr<declaration_specifiers> (new declaration_specifiers($1)); } 
	| type_qualifier declaration_specifiers          { *$2 *= $1; $$ = $2; }
%ifdef c99
	| function_specifier                             { $$ = std::shared_ptr<declaration_specifiers> (new declaration_specifiers($1)); } 
	| function_specifier declaration_specifiers      { *$2 *= $1; $$ = $2; }
%endif
%ifdef c11
	| alignment_specifier                             { $$ = std::shared_ptr<declaration_specifiers> (new declaration_specifiers($1)); } 
	| alignment_specifier declaration_specifiers      { *$2 *= $1; $$ = $2; }
%endif
	;
