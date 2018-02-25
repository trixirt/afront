/*
 * Copyright (c) 2017-2018 Tom Rix
 * All rights reserved.
 *
 * You may distribute under the terms of :
 *
 * the BSD 2-Clause license
 *
 * Any patches released for this software are to be released under these
 * same license terms.
 *
 * BSD 2-Clause license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "at/at.h"
#include "c/c_driver.h"
#include "c/pt/v/cg.h"
#include "c/pt/v/chk.h"
#include "e.h"

void init_types(std::shared_ptr<scope> a) {
  // 6.7.2 Type specifiers
  const char *ctypes[] = {
      "void",
      "char",
      "signed char",
      "unsigned char",
      "short",
      "signed short",
      "short int",
      "signed short int",
      "unsigned short",
      "unsigned short int",
      "int",
      "signed",
      "signed int",
      "unsigned",
      "unsigned int",
      "long",
      "signed long",
      "long int",
      "signed long int",
      "unsigned long",
      "unsigned long int",
      "long long",
      "signed long long",
      "long long int",
      "signed long long int",
      "float",
      "double",
      "long double",
      // TBD _Bool
      // TBD float _Complex
      // TBD double _Complex
      // TBD long double _Complex
      "",
  };
  for (const char **c = ctypes; **c != '\0'; c++) {
    std::shared_ptr<type> t = std::shared_ptr<type>(new type(*c, nullptr));
    (*a) += t;
  }
  /* Additional builtin types */
  /* XXX this should be common */
  const char *builtin_types[] = {
      "__builtin_va_list",
      "",
  };
  for (const char **c = builtin_types; **c != '\0'; c++) {
    std::shared_ptr<type> t = std::shared_ptr<type>(new type(*c, nullptr));
    (*a) += t;
  }
}

int main(int argc, char *argv[]) {
  int ret = 0;
  c_driver drv;
  char *f = nullptr;
  chk *vchk = nullptr;
  cg *vcg = nullptr;
  if (argc == 2)
    f = argv[1];
  if (!drv.parse(f)) {
    std::cout << drv.result() << std::endl;
    ret = 1;
  } else {
    location loc;
    std::shared_ptr<n> root = drv.get_root();
    std::shared_ptr<scope> a =
        std::shared_ptr<scope>(new scope(loc, nullptr, "cc1"));
    if (a == nullptr) {
      fprintf(stderr, "Failed to allocate memory for AST");
      ret = 1;
    } else {
      init_types(a);
      vchk = new chk(a);
      try {
        root->accept(vchk);
        vcg = new cg();
        try {
          root->accept(vcg);

        } catch (ice_exception &e) {
          drv.ice(e.file(), e.line(), e.what());
          ret = 2;
          goto end;
        } catch (visitor_exception &e) {
          drv.error(e.who()->here(), e.what());
          ret = 1;
          goto end;
        }
      } catch (ice_exception &e) {
        drv.ice(e.file(), e.line(), e.what());
        ret = 2;
        goto end;
      } catch (visitor_exception &e) {
        drv.error(e.who()->here(), e.what());
        ret = 1;
        goto end;
      }
    }
  }
end:
  if (vchk != nullptr)
    delete vchk;
  if (vcg != nullptr)
    delete vcg;

  return ret;
}
