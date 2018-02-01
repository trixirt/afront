#ifndef SCANNER
#define SCANNER

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

class Scanner : public yyFlexLexer {
public:
    Scanner();
    Scanner(std::ifstream *ifs);
    Scanner(const Scanner &s);
    Scanner &operator =(const Scanner &s);
    virtual ~Scanner();
};
    
#endif
