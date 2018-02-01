#include "scanner.h"

Scanner::Scanner() : yyFlexLexer() {}
Scanner::Scanner(std::ifstream *ifs) : yyFlexLexer((std::istream *)ifs) {}
Scanner::~Scanner() {}
