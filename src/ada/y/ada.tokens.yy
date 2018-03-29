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

%token END 0
%token <class lex_token> ABORT
%token <class lex_token> ABS
%token <class lex_token> ACCEPT
%token <class lex_token> ACCESS
%token <class lex_token> ALL
%token <class lex_token> AMP
%token <class lex_token> AND
%token <class lex_token> ARRAY
%token <class lex_token> ARROW
%token <class lex_token> ASSIGN
%token <class lex_token> AT
%token <class lex_token> KEYWORD_BEGIN
%token <class lex_token> BODY
%token <class lex_token> BOX
%token <class lex_token> CASE
%token <class lex_token> CHARACTER_LITERAL
%token <class lex_token> COL
%token <class lex_token> COM
%token <class lex_token> CONSTANT
%token <class lex_token> CBK
%token <class lex_token> CPA
%token <class lex_token> DECLARE
%token <class lex_token> DELAY
%token <class lex_token> DELTA
%token <class lex_token> DIGITS
%token <class lex_token> DO
%token <class lex_token> DOT
%token <class lex_token> DOTDOT
%token <class lex_token> ELSE
%token <class lex_token> ELSIF
%token <class lex_token> END
%token <class lex_token> ENTRY
%token <class lex_token> EQ
%token <class lex_token> EXCEPTION
%token <class lex_token> EXIT
%token <class lex_token> FOR
%token <class lex_token> FUNCTION
%token <class lex_token> GENERIC
%token <class lex_token> GOTO
%token <class lex_token> GT
%token <class lex_token> GTGT
%token <class lex_token> GTE
%token <class lex_token> IDENTIFIER
%token <class lex_token> IS
%token <class lex_token> IF
%token <class lex_token> IN
%token <class lex_token> LIMITED
%token <class lex_token> LOOP
%token <class lex_token> LT
%token <class lex_token> LTLT
%token <class lex_token> LTE
%token <class lex_token> MIN
%token <class lex_token> MOD
%token <class lex_token> MUL
%token <class lex_token> MULMUL
%token <class lex_token> NEW
%token <class lex_token> NOT
%token <class lex_token> NEQ
%token <class lex_token> KEYWORD_NULL
%token <class lex_token> NUMERIC_LITERAL
%token <class lex_token> OF
%token <class lex_token> OBR
%token <class lex_token> OPA
%token <class lex_token> OR
%token <class lex_token> OTHERS
%token <class lex_token> OUT
%token <class lex_token> PACKAGE
%token <class lex_token> PLU
%token <class lex_token> PRAGMA
%token <class lex_token> PRIVATE
%token <class lex_token> PROCEDURE
%token <class lex_token> RAISE
%token <class lex_token> RANGE
%token <class lex_token> RECORD
%token <class lex_token> REM
%token <class lex_token> RENAMES
%token <class lex_token> RETURN
%token <class lex_token> REVERSE
%token <class lex_token> SCO
%token <class lex_token> SL
%token <class lex_token> SQU
%token <class lex_token> SELECT
%token <class lex_token> SEPARATE
%token <class lex_token> STRING_LITERAL
%token <class lex_token> SUBTYPE
%token <class lex_token> TASK
%token <class lex_token> TERMINATE
%token <class lex_token> THEN
%token <class lex_token> TYPE
%token <class lex_token> USE
%token <class lex_token> VER
%token <class lex_token> WHEN
%token <class lex_token> WHILE
%token <class lex_token> WITH
%token <class lex_token> XOR
