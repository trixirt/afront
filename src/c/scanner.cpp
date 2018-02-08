#include "scanner.h"

Scanner::Scanner() : yyFlexLexer() {}
Scanner::Scanner(std::istream *i) : yyFlexLexer(i) {}
Scanner::~Scanner() {}

C::Parser::token_type Scanner::yylex(C::Parser::semantic_type *lval,
                                     C::Parser::location_type *location) {
  return yyFlexLexer::yylex();
}
