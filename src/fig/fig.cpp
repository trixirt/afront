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
      _language_type_list();
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

void llvm_configuration::_language_type_list() {
  class language_type_list *ltl = _get<class language_type_list>();
  if (ltl != nullptr) {
    for (auto c : ltl->children()) {
      // expecting { language_type }
      class language_type *lt = dynamic_cast<language_type *>(c.get());
      if (lt != nullptr) {
        auto gc = lt->children();
        // expecting { string_constant object_class }
        // expecting { string_constant object_class constant_list }

        string_constant *sc = nullptr;
        object_class *oc = nullptr;
        constant_list *cl = nullptr;
        std::string str_type;

        if (gc.size() >= 2) {
          sc = dynamic_cast<string_constant *>(gc[0].get());
          oc = dynamic_cast<object_class *>(gc[1].get());
        }
        if (gc.size() >= 3) {
          cl = dynamic_cast<constant_list *>(gc[2].get());
        }
        if (sc != nullptr and oc != nullptr) {
          // Assuming if you got this far, the children are ok.
          std::string s = sc->who();
          if (s.length() >= 2)
            str_type = s.substr(1, s.length() - 2);

          if (oc->what() == afront::parser::token::VOID) {
            /* Done not bother with checking size and extent */
            _language_type_map[str_type] = llvm::Type::getVoidTy(_ctx);
          } else if (cl != nullptr) {
            unsigned size(0), extent(0);
            auto ggc = cl->children();
            size_t nggc = ggc.size();
            if (nggc > 0) {
              // expecting { constant }
              constant *ct = dynamic_cast<constant *>(ggc[0].get());
              if (ct != nullptr)
                size = std::stoi(ct->who());
            }
            if (nggc > 1) {
              // expecting { constant }
              constant *ct = dynamic_cast<constant *>(ggc[1].get());
              if (ct != nullptr)
                extent = std::stoi(ct->who());
            }
            /* ignore extras */
            if (size > 0) {
              if (extent > 0) {
                if ((oc->what() == afront::parser::token::INTEGER) ||
                    (oc->what() == afront::parser::token::NATIVE)) {
                  _language_type_map[str_type] = llvm::ArrayType::get(
                      llvm::Type::getIntNTy(_ctx, size), extent);
                } else if (oc->what() == afront::parser::token::REAL) {
                  if (size == 16)
                    _language_type_map[str_type] = llvm::ArrayType::get(
                        llvm::Type::getHalfTy(_ctx), extent);
                  else if (size == 32)
                    _language_type_map[str_type] = llvm::ArrayType::get(
                        llvm::Type::getFloatTy(_ctx), extent);
                  else if (size == 64)
                    _language_type_map[str_type] = llvm::ArrayType::get(
                        llvm::Type::getDoubleTy(_ctx), extent);
                  /* ignore other sizes */
                }
                /* vector, aggregate are not handled */
              } else {
                if ((oc->what() == afront::parser::token::INTEGER) ||
                    (oc->what() == afront::parser::token::NATIVE)) {
                  _language_type_map[str_type] =
                      llvm::Type::getIntNTy(_ctx, size);
                } else if (oc->what() == afront::parser::token::REAL) {
                  if (size == 16)
                    _language_type_map[str_type] = llvm::Type::getHalfTy(_ctx);
                  else if (size == 32)
                    _language_type_map[str_type] = llvm::Type::getFloatTy(_ctx);
                  else if (size == 64)
                    _language_type_map[str_type] =
                        llvm::Type::getDoubleTy(_ctx);
                  /* ignore other sizes */
                }
                /* vector, aggregate are not handled */
              }
            }
            /* ignore errors in setting either size or extent */
          }
        }
      }
    }
  }
}

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
