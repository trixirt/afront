#ifndef AFRONT_SCANNER
#define AFRONT_SCANNER

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "lex_token.h"
#include "location.h"
#include "parser.tab.hh"
#include <set>

class scanner : public yyFlexLexer {
public:
  scanner(std::istream *i, std::string *f) : yyFlexLexer(i) {
    loc = new location;
    loc->begin.filename = loc->end.filename = f;
  };
  scanner(const scanner &s){};
  virtual ~scanner(){};
  /* the one flex wants to use */
  virtual int yylex(afront::parser::semantic_type *lval);
  /* the one bison wants to use */
  virtual int yylex(afront::parser::semantic_type *lval, location *loc);
  void user_action();
  void line();
  std::shared_ptr<std::string> get_line(size_t a);
  void add_typename(std::string a);

private:
  location *loc = nullptr;
  std::shared_ptr<std::string> s;
  std::vector<std::shared_ptr<std::string>> ln; // lines of text
  std::set<std::string> tn;                     // custom type names
};

#endif
