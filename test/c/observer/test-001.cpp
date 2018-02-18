#include "pt/pt.h"
#include "pt/v/observer.h"

class my_observer : public observer {
  virtual void update(m *a) { std::cout << a->classname() << '\n'; }
  virtual void update(identifier *a) {
    std::cout << "A class specific update " << a->classname() << '\n';
  }
  virtual void update(struct_or_union *a) {
    std::cout << "Another class specific update " << a->classname() << '\n';
  }
};

int main(int argc, char *argv[]) {
  std::shared_ptr<my_observer> o =
      std::shared_ptr<my_observer>(new my_observer());
  m::attach(o);

  std::shared_ptr<identifier> i =
      std::shared_ptr<identifier>(new identifier(lex_token()));
  i->notify();
  std::shared_ptr<struct_or_union> s =
      std::shared_ptr<struct_or_union>(new struct_or_union(lex_token()));
  s->notify();
}
