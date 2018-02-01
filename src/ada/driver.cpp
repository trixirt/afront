#include "driver.h"
#include "ada.parser.tab.hh"
#include "scanner.h"
#include <fstream>

namespace Ada {
Driver::~Driver() {
  if (scanner)
    delete (scanner);
  if (parser)
    delete (parser);
}

bool Driver::parse(const char *const filename) {
  bool ret = false;
  if (filename != nullptr) {
    std::ifstream *ifs = new std::ifstream(filename);
    if (ifs->good()) {
      scanner = new Scanner(ifs);
      parser = new Ada::Parser(this);
    }
  }
  ret = true;
  return ret;
}

std::string Driver::result() { return "Add something here"; }

void Driver::add_char() {}
int Driver::yylex(void *a, void *b) { return 0; }
}
