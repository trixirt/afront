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
%x C_COMMENT CPP_COMMENT SH_COMMENT


%include digit.l
%include c.identifier.l
%include c.constant.l
%include c.whitespace.l

graphic_char       ("-"|"_"|" ")
char  [a-zA-Z0-9]|{graphic_char}
char_sequence  {char}*
string_constant {dq}{char_sequence}{dq}

%%
%{

%}

"/*"                        { BEGIN(C_COMMENT);   }
<C_COMMENT>"*/"             { BEGIN(INITIAL);     }
<C_COMMENT>.                { }
<C_COMMENT>\n               { this->line();       }

"//"                        { BEGIN(CPP_COMMENT); }
<CPP_COMMENT>.              { }
<CPP_COMMENT>\n             { this->line(); BEGIN(INITIAL); }

"#"                         { BEGIN(SH_COMMENT); }
<SH_COMMENT>.               { }
<SH_COMMENT>\n              { this->line(); BEGIN(INITIAL); }

"\n"                        { this->line(); }
"\\\n"                      { this->line(); }

"mangle"                    { LEXTOK(MANGLE); }
"stack"                     { LEXTOK(STACK); }
"triple"                    { LEXTOK(TRIPLE); }
"little"                    { LEXTOK(LITTLE); }
"big"                       { LEXTOK(BIG); }
"integer"                   { LEXTOK(INTEGER); }
"real"                      { LEXTOK(REAL); }
"aggregate"                 { LEXTOK(AGGREGATE); }
"native"                    { LEXTOK(NATIVE); }
"pointer"                   { LEXTOK(POINTER); }
"vector"                    { LEXTOK(VECTOR); }
"void"                      { LEXTOK(VOID); }
{identifier}                { LEXTOK(IDENTIFIER);  }
{string_constant}           { LEXTOK(STRING_CONSTANT);   }
{decimal_constant}|0        { LEXTOK(INTEGER_CONSTANT);   }
{whitespace}                { }
.                           { LEXTOK(UNSUPPORTED_INPUT_CHAR);   }

%%

