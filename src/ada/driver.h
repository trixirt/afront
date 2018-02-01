#ifndef NADA_DRIVER
#define NADA_DRIVER

#include <string>

class Scanner;
namespace Ada {
    class Parser;
class Driver {
public:
    Driver() = default;
    virtual ~Driver();
    
    bool parse(const char *filename);
    void add_char();
    
    std::string result();
    int yylex(void *a, void *b);
    
private:
    Parser *parser = nullptr;
    Scanner *scanner = nullptr;
    
    friend class Parser;
};
}

#endif
