/* Copyright (c) 2018 Tom Rix
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
%def   debug.grammer.control_line
%control

control_line
	: HASH INCLUDE pp_tokens NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3)); }
	| HASH DEFINE identifier replacement_list NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3, $4)); }
	| HASH DEFINE identifier LPAREN CPA replacement_list NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3, $6)); }
	| HASH DEFINE identifier LPAREN identifier_list CPA replacement_list NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3, $5, $7)); }
	| HASH DEFINE identifier LPAREN ELIPSIS CPA replacement_list NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3, $5, $6)); }
	| HASH DEFINE identifier LPAREN identifier_list COM ELIPSIS CPA replacement_list NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3, $5, $7, $9)); }
	| HASH UNDEF identifier NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3)); }
	| HASH LINE pp_tokens NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3)); }
	| HASH ERROR NL { $$ = std::shared_ptr<control_line> (new control_line($2)); }
	| HASH ERROR pp_tokens NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3)); }
	| HASH PRAGMA NL { $$ = std::shared_ptr<control_line> (new control_line($2)); }	   
	| HASH PRAGMA pp_tokens NL { $$ = std::shared_ptr<control_line> (new control_line($2, $3)); }
	| HASH NL { $$ = std::shared_ptr<control_line> (new control_line()); }
	;