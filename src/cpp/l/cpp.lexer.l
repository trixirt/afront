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

%{

#include <string>
#include "scanner.h"

using token = afront::parser::token;

int yyFlexLexer::yylex() { return -1; /* to silence undefined reference in yyFlexLex class */ }

static void comment();

%}

%option debug
%option noyywrap
%option c++
%option yylineno
%x NPP PP D DL U I C COMMENT CXX_COMMENT

%def c_start C
%def common_start C

%include digit.l
%include c.identifier.l
%include c.constant.l
%include c.string_literal.l
%include cpp.whitespace.l

%%
%{

%}

<*>"/*"                   { yy_push_state(COMMENT); }
<COMMENT>"*/"             { yy_pop_state(); }
<COMMENT>.                {                 }
<COMMENT>\n               { this->line();   }

<*>"//"                   { BEGIN(CXX_COMMENT); }
<CXX_COMMENT>.            { }


"#"                       { BEGIN(PP); LEXTOK(HASH); };  
"??="                     { BEGIN(PP); LEXTOK(HASH); };
<*>\n                     { this->line(); BEGIN(INITIAL); LEXTOK(NL); }
<*>"\\\n"                 { this->line(); /* do not pass escaped nl */ }


<PP>"include"             { BEGIN(NPP); LEXTOK(INCLUDE); };
<PP>"include_next"        { BEGIN(NPP); LEXTOK(INCLUDE_NEXT); };
<PP>"pragma"              { BEGIN(NPP); LEXTOK(PRAGMA); };
<PP>"error"               { BEGIN(NPP); LEXTOK(ERROR); };
<PP>"warning"             { BEGIN(NPP); LEXTOK(WARNING); };
<PP>"line"                { BEGIN(NPP); LEXTOK(LINE); };

<PP>"define"              { BEGIN(D); LEXTOK(DEFINE); };
<DL>","                   { LEXTOK(COM); }
<DL>"..."                 { LEXTOK(ELLIPSIS); }
<DL>")"                   { BEGIN(NPP); LEXTOK(CPA); }

<PP>"undef"               { BEGIN(U); LEXTOK(UNDEF); };

<PP>"ifdef"               { BEGIN(I); LEXTOK(IFDEF); };
<PP>"ifndef"              { BEGIN(I); LEXTOK(IFNDEF); };
<PP>"endif"               { LEXTOK(ENDIF); };
<PP>"else"                { LEXTOK(ELSE); };

<PP>"if"                  { BEGIN(C); LEXTOK(IF); }
<PP>"elif"                { BEGIN(C); LEXTOK(ELIF); }

<C>"defined"              { LEXTOK(DEFINED); }

<INITIAL>{whitespace}     { }
<INITIAL>.                { BEGIN(NPP); LEXTOK(TOKEN); }
<NPP>.*                   { LEXTOK(TOKEN); }

%include lexer.l
%include c.assign.l
%include c.trigraph.l
%include c.digraph.l
%include c.misc.l
%include c.type_qualifier.l
%include c.type_specifier.l
%include c.storage_class_specifier.l
%include c.unary_expression.l
%include c.function_specifier.l
%include c.alignment_specifier.l

<D>{identifier}           { BEGIN(NPP); LEXTOK(IDENTIFIER); }
<D>{identifier}"("        { BEGIN(DL); LEXTOK(IDENTIFIER_LPAREN); }
<DL>{identifier}"..."     { LEXTOK(VA_ARG); }
<PP,DL,U,I,C>{identifier} { LEXTOK(IDENTIFIER); }

%include c.constant2.l			      
<*>{whitespace}              { }
.                         { LEXTOK(UNSUPPORTED_INPUT_CHAR);   }

%%

