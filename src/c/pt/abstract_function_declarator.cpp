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
#include "pt.h"

abstract_function_declarator::abstract_function_declarator() {}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<parameter_type_list> a) {
  *this += a;
}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<direct_abstract_declarator> a) {
  *this += a;
}
abstract_function_declarator::abstract_function_declarator(
    std::shared_ptr<direct_abstract_declarator> a,
    std::shared_ptr<parameter_type_list> b) {
  *this += a;
  *this += b;
}

void abstract_function_declarator::accept(visitor *a) { a->v(this); };
std::string abstract_function_declarator::classname() {
  return "abstract_function_declarator";
};
