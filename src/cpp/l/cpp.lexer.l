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

void scanner::add_typename(std::string a) {
  tn.insert(a);
}

using token = afront::parser::token;

int yyFlexLexer::yylex() { return -1; /* to silence undefined reference in yyFlexLex class */ }

static void comment();

%}

%option debug
%option noyywrap
%option c++
%option yylineno
%x COMMENT CPP_COMMENT PP_DIRECTIVE


%include digit.l
%include c.identifier.l
%include c.constant.l
%include c.string_literal.l
%include c.whitespace.l

%%
%{

%}

"/*"             { BEGIN(COMMENT); }
<COMMENT>"*/"    { BEGIN(INITIAL); }
<COMMENT>.       {                 }
<COMMENT>\n      { this->line();   }

"//"             { BEGIN(CPP_COMMENT); }
<CPP_COMMENT>.   { }
<CPP_COMMENT>\n  { this->line(); BEGIN(INITIAL); }

^"#"             { BEGIN(PP_DIRECTIVE); };
^"??="             { BEGIN(PP_DIRECTIVE); };
<PP_DIRECTIVE>.  { }
<PP_DIRECTIVE>\n { this->line(); BEGIN(INITIAL); }

"\n"       { this->line(); }
"\\\n"     { this->line(); }
"??/\n"    { this->line(); }

%include lexer.l

"->"       { LEXTOK(PTR); }
"!="       { LEXTOK(NE); }
"&="       { LEXTOK(AND_ASSIGN); }
"++"                        { LEXTOK(INC); }
"--"                        { LEXTOK(DEC); }
"+="                        { LEXTOK(ADD_ASSIGN); }
"-="                        { LEXTOK(SUB_ASSIGN); }
"??-"                       { LEXTOK(TIL); }
"*="                        { LEXTOK(MUL_ASSIGN); }
"%="                        { LEXTOK(MOD_ASSIGN); }
"??("                       { LEXTOK(OBK); }
"<:"                        { LEXTOK(OBK); }
"??)"                       { LEXTOK(CBK); }
":>"                        { LEXTOK(CBK); }
"??<"                       { LEXTOK(OBR); }
"<%"                        { LEXTOK(OBR); }
"??>"                       { LEXTOK(CBR); }
"%>"                        { LEXTOK(CBR); }
"??!"                       { LEXTOK(VER); }
"||"                        { LEXTOK(OROR); }
"??!|"                      { LEXTOK(OROR); }
"|??!"                      { LEXTOK(OROR); }
"??!??!"                    { LEXTOK(OROR); }
"|="                        { LEXTOK(OR_ASSIGN); }
"??!="                      { LEXTOK(OR_ASSIGN); }
"/="                        { LEXTOK(DIV_ASSIGN); }
"??'"                       { LEXTOK(CIR); }
"^="                        { LEXTOK(XOR_ASSIGN); }
"??'="                      { LEXTOK(XOR_ASSIGN); }
"<<="                       { LEXTOK(LEFT_ASSIGN); }
">>="                       { LEXTOK(RIGHT_ASSIGN); }
"..."                       { LEXTOK(ELLIPSIS); }
"auto"                      { LEXTOK(AUTO); }
"char"                      { LEXTOK(CHAR); }
"const"                     { LEXTOK(CONST); }
"volatile"                  { LEXTOK(VOLATILE);   }
"default"                   { LEXTOK(DEFAULT); }
"double"                    { LEXTOK(DOUBLE); }
"else"                      { LEXTOK(ELSE); }
"enum"                      { LEXTOK(ENUM); }
"extern"                    { LEXTOK(EXTERN); }
"float"                     { LEXTOK(FLOAT); }
"if"                        { LEXTOK(IF); }
"int"                       { LEXTOK(INT); }
"long"                      { LEXTOK(LONG); }
"register"                  { LEXTOK(REGISTER); }
"short"                     { LEXTOK(SHORT);      }
"sizeof"                    { LEXTOK(SIZEOF);     }
"signed"                    { LEXTOK(SIGNED);     }
"static"                    { LEXTOK(STATIC);     }
"struct"                    { LEXTOK(STRUCT);     }
"typedef"                   { LEXTOK(TYPEDEF);    }
"union"                     { LEXTOK(UNION);      }
"unsigned"                  { LEXTOK(UNSIGNED);   }
"void"                      { LEXTOK(VOID);       }
%ifdef c99
"inline"                    { LEXTOK(INLINE); }
"restrict"                  { LEXTOK(RESTRICT); }
"_Bool"                     { LEXTOK(_BOOL); }
"_Complex"                  { LEXTOK(_COMPLEX); }
"_Imaginary"                { LEXTOK(_IMAGINARY); }
%endif
%ifdef c11
"_Alignas"                  { LEXTOK(_ALIGNAS); }
"_Alignof"                  { LEXTOK(_ALIGNOF); }
"_Atomic"                   { LEXTOK(_ATOMIC); }
"_Generic"                  { LEXTOK(_GENERIC); }
"_Noreturn"                 { LEXTOK(_NORETURN) }
"_Static_assert"            { LEXTOK(_STATIC_ASSERT); }
"_Thread_local"             { LEXTOK(_THREAD_LOCAL); }
%endif
{identifier}                { if (tn.count(yytext)) {
                                LEXTOK(TYPENAME_IDENTIFIER); 
                              } else {
                                LEXTOK(IDENTIFIER); 
                              }
		            }
{integer_constant}          { LEXTOK(INTEGER_CONSTANT);   }
{floating_constant}         { LEXTOK(FLOATING_CONSTANT);   }
{character_constant}        { LEXTOK(CHARACTER_CONSTANT);   }
{string_literal}            { LEXTOK(STRING_CONSTANT);   }
{whitespace}                { }
.                           { LEXTOK(UNSUPPORTED_INPUT_CHAR);   }
%%

