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

#undef YY_DECL
#define	YY_DECL			 	\
    int		\
    scanner::yylex( afront::parser::semantic_type* lval \
	)

#define YY_USER_ACTION user_action();
void scanner::user_action () {
  if (s == nullptr)
    s = std::shared_ptr<std::string> (new std::string());
  if (s != nullptr)
    *s += yytext;
  loc->step();
  loc->columns(yyleng);
}
void scanner::line () {
  loc->lines();
  ln.push_back(s);
  s = nullptr;
}

std::shared_ptr<std::string> scanner::get_line(size_t a) {
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

int scanner::yylex(afront::parser::semantic_type* lval, location* loc) {
  *loc = *this->loc;
  return yylex(lval);
}

#define LEXTOK(A) lval->build<lex_token>(lex_token(yytext, *this->loc, afront::parser::token::A)); return (afront::parser::token::A)

/* TBD */
#define RESERVED(A) 

int yyFlexLexer::yylex() { return -1; /* to silence undefined reference in yyFlexLex class */ }

using token = afront::parser::token;

#define yyterminate() return afront::parser::token::END;

static void comment();

%}

%option debug
%option noyywrap
%option c++
%option yylineno
%x C_COMMENT CPP_COMMENT SH_COMMENT


%include c.constant.l

letter			[a-zA-Z_]


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

"abi"                       { LEXTOK(ABI); }
"mangle"                    { LEXTOK(MANGLE); }
"stack"                     { LEXTOK(STACK); }
"triple"                    { LEXTOK(TRIPLE); }
"little"                    { LEXTOK(LITTLE); }
"big"                       { LEXTOK(BIG); }
"integer"                   { LEXTOK(INTEGER); }
"real"                      { LEXTOK(REAL); }
"vector"                    { LEXTOK(VECTOR); }
{letter}({letter}|{digit})* { LEXTOK(IDENTIFIER);  }
{decimal_constant}          { LEXTOK(CONSTANT);   }
.                           {                     }

%%

