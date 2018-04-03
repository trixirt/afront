#include "fig.h"
#include "fig/lang_driver.h"
#include "pt/pt.h"
#include "v/observers.h"
#include "v/ping.h"

llvm_configuration::llvm_configuration(std::string f) {
  lang_driver drv;
  if (drv.parse(f.c_str())) {
    c = std::dynamic_pointer_cast<configuration>(drv.get_root());
  }
}

bool llvm_configuration::has_triple() {
  bool ret = false;
  std::string s = triple();
  if (s.size())
    ret = true;
  return ret;
}

std::string llvm_configuration::triple() {
  std::string ret;
  std::shared_ptr<single_fetch_observer<class triple>> o =
      std::shared_ptr<single_fetch_observer<class triple>>(
          new single_fetch_observer<class triple>());
  m::attach(o);
  ping *v = new ping();
  class triple *t = nullptr;
  if (v) {
    c->accept(v);
    t = o->get();
    delete v;
    v = nullptr;
  }
  m::clear();
  if (t) {
    ret = t->who();
  }

  return ret;
}
