%{

#include "scanner.h"
#include "parser.tab.hh"

using token = afront::parser::token;
int yyFlexLexer::yylex() { return -1; /* to silence undefined reference in yyFlexLex class */ }


%}

%option debug
%option noyywrap
%option c++

%include digit.l
%include ada.identifier.l
%include ada.numeric_literal.l
%include ada.character_literal.l
%include ada.string_literal.l

%%

%include lexer.l

"/=" { LEXTOK(NEQ); }
"**" { LEXTOK(MULMUL); }
"=>" { LEXTOK(ARROW); }
"<>" { LEXTOK(BOX); }
".." { LEXTOK(DOTDOT); }
":=" { LEXTOK(ASSIGN); }
"abort"    { LEXTOK(ABORT); }
"abs"      { LEXTOK(ABS); }
"accept"   { LEXTOK(ACCEPT); }
"access"   { LEXTOK(ACCESS); }
"all"      { LEXTOK(ALL); }
"and"      { LEXTOK(AND); }
"array"    { LEXTOK(ARRAY); }
"at"       { LEXTOK(AT); }
"begin"    { LEXTOK(KEYWORD_BEGIN); }
"body"     { LEXTOK(BODY); }
"case"     { LEXTOK(CASE); }
"constant" { LEXTOK(CONSTANT); }
"declare" { LEXTOK(DECLARE); }
"delay" { LEXTOK(DELAY); }
"delta" { LEXTOK(DELTA); }
"digits" { LEXTOK(DIGITS); }
"do" { LEXTOK(DO); }
"else" { LEXTOK(ELSE); }
"elsif" { LEXTOK(ELSIF); }
"end" { LEXTOK(END); }
"entry" { LEXTOK(ENTRY); }
"exception" { LEXTOK(EXCEPTION); }
"exit" { LEXTOK(EXIT); }
"for" { LEXTOK(FOR); }
"function" { LEXTOK(FUNCTION); }
"generic" { LEXTOK(GENERIC); }
"goto" { LEXTOK(GOTO); }
"if" { LEXTOK(IF); }
"in" { LEXTOK(IN); }
"is" { LEXTOK(IS); }
"limited" { LEXTOK(LIMITED); }
"loop" { LEXTOK(LOOP); }
"mod" { LEXTOK(MOD); }
"new" { LEXTOK(NEW); }
"not" { LEXTOK(NOT); }
"null" { LEXTOK(KEYWORD_NULL); }
"of" { LEXTOK(OF); }
"or" { LEXTOK(OR); }
"others" { LEXTOK(OTHERS); }
"package" { LEXTOK(PACKAGE); }
"pragma" { LEXTOK(PRAGMA); }
"private" { LEXTOK(PRIVATE); }
"procedure" { LEXTOK(PROCEDURE); }
"raise" { LEXTOK(RAISE); }
"range" { LEXTOK(RANGE); }
"record" { LEXTOK(RECORD); }
"renames" { LEXTOK(RENAMES); }
"return" { LEXTOK(RETURN); }
"reverse" { LEXTOK(REVERSE); }
"select" { LEXTOK(SELECT); }
"seperate" { LEXTOK(SEPARATE); }
"subtype" { LEXTOK(SUBTYPE); }
"task" { LEXTOK(TASK); }
"terminate" { LEXTOK(TERMINATE);}
"then" { LEXTOK(THEN); }
"type" { LEXTOK(TYPE);}
"use" { LEXTOK(USE); }
"when" { LEXTOK(WHEN); }
"while" { LEXTOK(WHILE); }
"with" { LEXTOK(WITH); }
"xor" { LEXTOK(XOR); }
{character_literal} { LEXTOK(CHARACTER_LITERAL); }
{string_literal}    { LEXTOK(STRING_LITERAL); }
{numeric_literal}   { LEXTOK(NUMERIC_LITERAL); }
{identifier}        { LEXTOK(IDENTIFIER); }

%%
