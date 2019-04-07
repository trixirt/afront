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
%ifdef debug.all
%def   debug.grammer.class_head
%endif

class_head
	: class_key class_head_name                                                                { $$ = std::shared_ptr<class_head> (new class_head($1, $2));             }
	| class_key attribute_specifier_seq class_head_name                                        { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3));         }
	| class_key attribute_specifier_seq class_head_name class_virt_specifier                   { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3, $4));     }
	| class_key attribute_specifier_seq class_head_name class_base_clause                      { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3, $4));     }
	| class_key attribute_specifier_seq class_head_name class_virt_specifier class_base_clause { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3, $4, $5)); }
	| class_key class_head_name class_virt_specifier                                           { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3));         }
	| class_key class_head_name class_virt_specifier base_clause                               { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3, $4));     }
	| class_key class_head_name base_clause                                                    { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3));         }
	| class_key                                                                                { $$ = std::shared_ptr<class_head> (new class_head($1));                 }
	| class_key attribute_specifier_seq                                                        { $$ = std::shared_ptr<class_head> (new class_head($1, $2));             }
	| class_key attribute_specifier_seq base_clause                                            { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3));         }
	| class_key base_clause                                                                    { $$ = std::shared_ptr<class_head> (new class_head($1, $2, $3));         }
	;



