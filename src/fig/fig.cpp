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
    } else {
      std::cout << drv->result() << std::endl;
    }
    delete drv;
  }
}

std::string llvm_configuration::data_layout() {
  std::string ret;

  return ret;
}

std::string llvm_configuration::triple() {
  std::string ret;
  class triple *t = _get<class triple>();
  if (t) {
    auto c = t->children();
    // expecting { string_constant }
    class string_constant *sc = dynamic_cast<string_constant *>(c[0].get());
    if (sc != nullptr) {
      ret = sc->who();
    }
  }
  return ret;
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
