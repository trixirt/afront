#ifndef NADA_SCANNER
#define NADA_SCANNER

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "lex_token.h"
#include "location.h"
#include "parser.tab.hh"
#include <set>

namespace lex {
class scanner : public yyFlexLexer {
public:
  scanner(std::istream *i, std::string *f) : yyFlexLexer(i) {
    loc = new lex::location;
    loc->begin.filename = loc->end.filename = f;
  };
  scanner(const scanner &s){};
  virtual ~scanner(){};
  /* the one flex wants to use */
  virtual int yylex(nada::parser::semantic_type *lval);
  /* the one bison wants to use */
  virtual int yylex(nada::parser::semantic_type *lval, lex::location *loc);
  void user_action();
  void line();
  std::shared_ptr<std::string> get_line(size_t a);
  void add_typename(std::string a);

private:
  lex::location *loc = nullptr;
  std::shared_ptr<std::string> s;
  std::vector<std::shared_ptr<std::string>> ln; // lines of text
  std::set<std::string> tn;                     // custom type names
};
} // namespace lex

#endif
