#include "fig.h"
#include "fig/lang_driver.h"
#include "pt/pt.h"

llvm_configuration::llvm_configuration(std::string f) {
  lang_driver drv;
  if (drv.parse(f.c_str())) {
    c = std::dynamic_pointer_cast<fig::configuration>(drv.get_root());
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

  return ret;
}
