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

%token <class lex_token> ADD_ASSIGN
%token <class lex_token> ANDAND
%token <class lex_token> AND_ASSIGN
%token <class lex_token> AUTO
%token <class lex_token> CHAR
%token <class lex_token> CONST
%token <class lex_token> DEC
%token <class lex_token> DEFAULT
%token <class lex_token> DEFINE
%token <class lex_token> DIV_ASSIGN
%token <class lex_token> DOUBLE
%token <class lex_token> ELIF
%token <class lex_token> ELLIPSIS
%token <class lex_token> ELSE
%token <class lex_token> ENDIF
%token <class lex_token> ENUM
%token <class lex_token> ERROR
%token <class lex_token> EXTERN
%token <class lex_token> FLOAT
%token <class lex_token> HASH
%token <class lex_token> IF
%token <class lex_token> IFDEF
%token <class lex_token> IFNDEF
%token <class lex_token> INC
%token <class lex_token> INCLUDE
%token <class lex_token> INLINE
%token <class lex_token> INT
%token <class lex_token> LEFT_ASSIGN
%token <class lex_token> LINE
%token <class lex_token> LONG
%token <class lex_token> MOD_ASSIGN
%token <class lex_token> MUL_ASSIGN
%token <class lex_token> NE
%token <class lex_token> NL
%token <class lex_token> OR_ASSIGN
%token <class lex_token> OROR
%token <class lex_token> PRAGMA
%token <class lex_token> PTR
%token <class lex_token> REGISTER
%token <class lex_token> RESTRICT
%token <class lex_token> RIGHT_ASSIGN
%token <class lex_token> SHORT
%token <class lex_token> SIGNED
%token <class lex_token> SIZEOF
%token <class lex_token> STATIC
%token <class lex_token> STRUCT
%token <class lex_token> SUB_ASSIGN
%token <class lex_token> TOKEN
%token <class lex_token> TYPEDEF
%token <class lex_token> TYPENAME_IDENTIFIER
%token <class lex_token> UNDEF
%token <class lex_token> UNION
%token <class lex_token> UNSIGNED
%token <class lex_token> VOID
%token <class lex_token> VOLATILE
%token <class lex_token> WS
%token <class lex_token> XOR_ASSIGN
%token <class lex_token> IDENTIFIER_LPAREN

%token <class lex_token> _ALIGNAS
%token <class lex_token> _ATOMIC
%token <class lex_token> _BOOL
%token <class lex_token> _COMPLEX
%token <class lex_token> _GENERIC
%token <class lex_token> _NORETURN
%token <class lex_token> _STATIC_ASSERT
