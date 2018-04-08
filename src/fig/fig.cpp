#include "fig.h"
#include "fig/lang_driver.h"
#include "pt/pt.h"
#include "v/observers.h"
#include "v/ping.h"

class fig_driver : public lang_driver {};

llvm_configuration::llvm_configuration(std::string f) {
  fig_driver *drv;
  drv = new fig_driver();
  if (drv) {
    if (drv->parse(f.c_str())) {
      _c = std::dynamic_pointer_cast<configuration>(drv->get_root());
      _triple();
      _data_layout();
    } else {
      std::cout << drv->result() << std::endl;
    }
    delete drv;
  }
}
void llvm_configuration::_data_layout() {
  if (str_data_layout.size())
    return;

  class endian *e = _get<class endian>();
  if (e != nullptr) {
    if (e->what() == afront::parser::token::BIG)
      str_data_layout += "E";
    else
      str_data_layout += "e";

    class object_list *ol = _get<class object_list>();
    if (ol != nullptr) {
      for (auto c : ol->children()) {
        // expecting { object }
        class object *o = dynamic_cast<object *>(c.get());
        if (o != nullptr) {
          auto gc = o->children();
          // expecting { object_class constant_list }
          if (gc.size() == 2) {
            class object_class *oc = dynamic_cast<object_class *>(gc[0].get());
            class constant_list *cl =
                dynamic_cast<constant_list *>(gc[1].get());
            if (oc != nullptr && cl != nullptr) {
              bool first = true;
              str_data_layout += "-";
              if (oc->what() == afront::parser::token::POINTER)
                str_data_layout += "p";
              else if (oc->what() == afront::parser::token::INTEGER)
                str_data_layout += "i";
              else if (oc->what() == afront::parser::token::VECTOR)
                str_data_layout += "v";
              else if (oc->what() == afront::parser::token::REAL)
                str_data_layout += "f";
              else if (oc->what() == afront::parser::token::AGGREGATE)
                str_data_layout += "a";
              else if (oc->what() == afront::parser::token::NATIVE)
                str_data_layout += "n";
              else
                // TBD : Handle error
                ;
              for (auto ggc : cl->children()) {
                // expecting { constant }
                class constant *t = dynamic_cast<constant *>(ggc.get());
                if (t != nullptr) {
                  if (!first) {
                    str_data_layout += ":";
                  } else {
                    first = false;
                  }
                  str_data_layout += t->who();
                }
              }
            }
          }
        }
      }
    }

    class fig_stack *s = _get<class fig_stack>();
    if (s != nullptr) {
      auto c = s->children();
      // expecting { constant }
      class constant *t = dynamic_cast<constant *>(c[0].get());
      if (t != nullptr) {
        str_data_layout += "-S";
        str_data_layout += t->who();
      }
    }
  }
}

std::string llvm_configuration::data_layout() { return str_data_layout; }

void llvm_configuration::_triple() {
  if (str_triple.size())
    return;

  class triple *t = _get<class triple>();
  if (t) {
    auto c = t->children();
    // expecting { string_constant }
    class string_constant *sc = dynamic_cast<string_constant *>(c[0].get());
    if (sc != nullptr) {
      std::string s = sc->who();
      if (s.length() >= 2)
        str_triple = s.substr(1, s.length() - 2);
    }
  }
}

std::string llvm_configuration::triple() { return str_triple; }

template <class T> T *llvm_configuration::_get() {
  T *ret = nullptr;
  if (_c != nullptr) {
    std::shared_ptr<single_fetch_observer<T>> o =
        std::shared_ptr<single_fetch_observer<T>>(
            new single_fetch_observer<T>());
    m::attach(o);
    ping *v = new ping();
    if (v) {
      _c->accept(v);
      ret = o->get();
      delete v;
      v = nullptr;
    }
    m::clear();
  }
  return ret;
}
