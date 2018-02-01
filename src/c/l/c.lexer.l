/*
 * Original work :
 *
 * From Jeff Leff publish of lex/yacc c specification in 1985
 * It is part of the comp.lang.c FAQ
 *
 * From tps@sdchemf.UUCP Tue Mar  3 16:31:17 1987
 * Path: beno!seismo!lll-lcc!ames!ucbcad!ucbvax!sdcsvax!sdchem!tps
 * From: tps@sdchem.UUCP (Tom Stockfisch)
 * Newsgroups: net.sources
 * Subject: ANSI C draft yacc grammar
 * Message-ID: <645@sdchema.sdchem.UUCP>
 * Date: 3 Mar 87 21:31:17 GMT
 * References: <403@ubc-vision.UUCP>
 * Sender: news@sdchem.UUCP
 * Reply-To: tps@sdchemf.UUCP (Tom Stockfisch)
 * Organization: UC San Diego
 * Lines: 775
 *
 * People keep asking me for a copy, so I am reposting a yacc grammar (actually,
 * a complete program) for the April 1985 draft of the ANSI C standard.  It
 * finds syntax errors in its input.
 * 
 * Oh yeah, this was originally posted by Jeff Lee.
 *
 * || Tom Stockfisch, UCSD Chemistry	tps%chem@sdcsvax.UCSD
 *
 * Modifications :
 *
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

#undef YY_DECL
#define	YY_DECL			 	\
    int		\
    lex::scanner::yylex( nada::parser::semantic_type* lval \
	)

#define YY_USER_ACTION user_action();
void lex::scanner::user_action () {
  if (s == nullptr)
    s = std::shared_ptr<std::string> (new std::string());
  if (s != nullptr)
    *s += yytext;
  loc->step();
  loc->columns(yyleng);
}
void lex::scanner::line () {
  loc->lines();
  ln.push_back(s);
  s = nullptr;
}

std::shared_ptr<std::string> lex::scanner::get_line(size_t a) {
  std::shared_ptr<std::string> r = nullptr;
  if (a > 0) {
    /* input line is 1 base, vector is 0 based, so subtract 1*/
    a--;
    if (a < ln.size()) {
      r = ln[a];
    } else if (a == ln.size()) {
      r = s;
    }
  }
  return r;  
}

int lex::scanner::yylex(nada::parser::semantic_type* lval, lex::location* loc) {
  *loc = *this->loc;
  return yylex(lval);
}

void lex::scanner::add_typename(std::string a) {
  tn.insert(a);
}

#define LEXTOK(A) lval->build<lex::token>(lex::token(yytext, *this->loc, nada::parser::token::A)); return (nada::parser::token::A)

/* TBD */
#define RESERVED(A) 

int yyFlexLexer::yylex() { return -1; /* to silence undefined reference in yyFlexLex class */ }

using token = nada::parser::token;

#define yyterminate() return nada::parser::token::END;

static void comment();

%}

%option debug
%option noyywrap
%option c++
%option yylineno
%x COMMENT CPP_COMMENT PP_DIRECTIVE


%include c.constant.l

letter			[a-zA-Z_]


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
"<"        { LEXTOK(LT); }
"->"       { LEXTOK(PTR); }
">"        { LEXTOK(GT); }
"="        { LEXTOK(EQ); }
"=="       { LEXTOK(EQEQ); }
"!="       { LEXTOK(NE); }
","        { LEXTOK(COM); }
"&"        { LEXTOK(AMP); }
"&&"       { LEXTOK(AMPAMP); }
"&="       { LEXTOK(AND_ASSIGN); }
"+"        { LEXTOK(ADD); }
"++"       { LEXTOK(INC); }
"--"       { LEXTOK(DEC); }
"+="       { LEXTOK(ADD_ASSIGN); }
"-"        { LEXTOK(SUB); }
"-="       { LEXTOK(SUB_ASSIGN); }
"~"        { LEXTOK(TIL); }
"??-"      { LEXTOK(TIL); }
"!"        { LEXTOK(EXL); }
"."        { LEXTOK(DOT); }
"*"        { LEXTOK(MUL); }
"*="       { LEXTOK(MUL_ASSIGN); }
"%"        { LEXTOK(MOD); }
"%="       { LEXTOK(MOD_ASSIGN); }
"?"        { LEXTOK(QUE); }
"["        { LEXTOK(OBK); }
"??("        { LEXTOK(OBK); }
"]"        { LEXTOK(CBK); }
"??)"        { LEXTOK(CBK); }
"{"        { LEXTOK(OBR); }
"??<"        { LEXTOK(OBR); }

"}"        { LEXTOK(CBR); }
"??>"        { LEXTOK(CBR); }
"("        { LEXTOK(OPA); }
")"        { LEXTOK(CPA); }
":"        { LEXTOK(COL); }
";"        { LEXTOK(SCO); }
"'"        { LEXTOK(SQU); }
"|"        { LEXTOK(OR); }
"??!"      { LEXTOK(OR); }
"||"                        { LEXTOK(OROR); }
"??!|"                      { LEXTOK(OROR); }
"|??!"                      { LEXTOK(OROR); }
"??!??!"                    { LEXTOK(OROR); }
"|="                        { LEXTOK(OR_ASSIGN); }
"??!="                      { LEXTOK(OR_ASSIGN); }
"/"                         { LEXTOK(DIV); }
"/="                        { LEXTOK(DIV_ASSIGN); }
"^"                         { LEXTOK(XOR); }
"??'"                       { LEXTOK(XOR); }
"^="                        { LEXTOK(XOR_ASSIGN); }
"??'="                      { LEXTOK(XOR_ASSIGN); }
"<<"                        { LEXTOK(LTLT); }
"<<="                       { LEXTOK(LEFT_ASSIGN); }
">>"                        { LEXTOK(GTGT); }
">>="                       { LEXTOK(RIGHT_ASSIGN); }
"<="                        { LEXTOK(LTE); }
">="                        { LEXTOK(GTE); }
"..."                       { LEXTOK(ELIPSIS); }
"auto"                      { LEXTOK(AUTO); }
"break"                     { LEXTOK(BREAK); }
"case"                      { LEXTOK(CASE); }
"char"                      { LEXTOK(CHAR); }
"const"                     { LEXTOK(CONST); }
"volatile"                  { LEXTOK(VOLATILE);   }
%ifdef c99 
"restrict"                  { LEXTOK(RESTRICT);   }
%endif
%ifdef c11
"_Atomic"                   { LEXTOK(ATOMIC);   }
%endif
"continue"                  { LEXTOK(CONTINUE); }
"default"                   { LEXTOK(DEFAULT); }
"do"                        { LEXTOK(DO); }
"double"                    { LEXTOK(DOUBLE); }
"else"                      { LEXTOK(ELSE); }
"enum"                      { LEXTOK(ENUM); }
"extern"                    { LEXTOK(EXTERN); }
"float"                     { LEXTOK(FLOAT); }
"for"                       { LEXTOK(FOR); }
"goto"                      { LEXTOK(GOTO); }
"if"                        { LEXTOK(IF); }
"int"                       { LEXTOK(INT); }
"long"                      { LEXTOK(LONG); }
"register"                  { LEXTOK(REGISTER); }
"return"                    { LEXTOK(RETURN); }
"short"                     { LEXTOK(SHORT);      }
"sizeof"                    { LEXTOK(SIZEOF);     }
"signed"                    { LEXTOK(SIGNED);     }
"static"                    { LEXTOK(STATIC);     }
"struct"                    { LEXTOK(STRUCT);     }
"switch"                    { LEXTOK(SWITCH);     }
"typedef"                   { LEXTOK(TYPEDEF);    }
"union"                     { LEXTOK(UNION);      }
"unsigned"                  { LEXTOK(UNSIGNED);   }
"void"                      { LEXTOK(VOID);       }
"while"                     { LEXTOK(WHILE);      }
%ifndef c99
"inline"                    { RESERVED("c99"); }
"restrict"                  { RESERVED("c99"); }
"_Bool"                     { RESERVED("c99"); }
"_Complex"                  { RESERVED("c99"); }
"_Imaginary"                { RESERVED("c99"); }
%endif
%ifndef c11
"_Alignas"                  { RESERVED("c11"); }
"_Alignof"                  { RESERVED("c11"); }
"_Atomic"                   { RESERVED("c11"); }
"_Generic"                  { RESERVED("c11"); }
"_Noreturn"                 { RESERVED("c11"); }
"_Static_assert"            { RESERVED("c11"); }
"_Thread_local"             { RESERVED("cll"); }
%endif
{letter}({letter}|{digit})* { if (tn.count(yytext)) {
                                LEXTOK(TYPENAME_IDENTIFIER); 
                              } else {
                                LEXTOK(IDENTIFIER); 
                              }
                            }
{decimal_constant}          { LEXTOK(CONSTANT);   }
{octal_constant}            { LEXTOK(CONSTANT);   }
{hexadecimal_constant}      { LEXTOK(CONSTANT);   }

%%

