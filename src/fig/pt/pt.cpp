/*
 * Copyright (c) 2018 Tom Rix
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

abi::abi(std::shared_ptr<string_constant> a) { *this += a; }
void abi::accept(visitor *a) { a->v(this); }

configuration::configuration(std::shared_ptr<data_layout> a,
                             std::shared_ptr<language_type_list> b) {
  *this += a;
  *this += b;
}
configuration::configuration(std::shared_ptr<triple> a,
                             std::shared_ptr<data_layout> b,
                             std::shared_ptr<language_type_list> c) {
  *this += a;
  *this += b;
  *this += c;
}
void configuration::accept(visitor *a) { a->v(this); }

constant::constant(lex::token a) : n(a) {}
void constant::accept(visitor *a) { a->v(this); }

data_layout::data_layout(std::shared_ptr<endian> a,
                         std::shared_ptr<object_list> b) {
  *this += a;
  *this += b;
}
data_layout::data_layout(std::shared_ptr<endian> a,
                         std::shared_ptr<layout_option_list> b,
                         std::shared_ptr<object_list> c) {
  *this += a;
  *this += b;
  *this += c;
}
void data_layout::accept(visitor *a) { a->v(this); }

endian::endian(lex::token a) : n(a) {}
void endian::accept(visitor *a) { a->v(this); }

identifier::identifier(lex::token a) : n(a) {}
void identifier::accept(visitor *a) { a->v(this); }

language_type::language_type(std::shared_ptr<string_constant> a,
                             std::shared_ptr<object_class> b,
                             std::shared_ptr<constant> c) {
  *this += a;
  *this += b;
  *this += c;
}
language_type::language_type(std::shared_ptr<string_constant> a,
                             std::shared_ptr<object_class> b,
                             std::shared_ptr<constant> c,
                             std::shared_ptr<constant> d) {
  *this += a;
  *this += b;
  *this += c;
  *this += d;
}
void language_type::accept(visitor *a) { a->v(this); }

language_type_list::language_type_list(std::shared_ptr<language_type> a) {
  *this += a;
}
void language_type_list::accept(visitor *a) { a->v(this); }

layout_option_list::layout_option_list(std::shared_ptr<layout_option> a) {
  *this += a;
}
void layout_option_list::accept(visitor *a) { a->v(this); }

layout_option::layout_option(std::shared_ptr<stack> a) { *this += a; }
layout_option::layout_option(std::shared_ptr<mangle> a) { *this += a; }
layout_option::layout_option(std::shared_ptr<abi> a) { *this += a; }
void layout_option::accept(visitor *a) { a->v(this); }

mangle::mangle(std::shared_ptr<string_constant> a) { *this += a; }
void mangle::accept(visitor *a) { a->v(this); }

object_class::object_class(lex::token a) : n(a) {}
void object_class::accept(visitor *a) { a->v(this); }

object_list::object_list(std::shared_ptr<object> a) { *this += a; }
void object_list::accept(visitor *a) { a->v(this); }

object::object(std::shared_ptr<object_class> a, std::shared_ptr<constant> b) {
  *this += a;
  *this += b;
}
object::object(std::shared_ptr<object_class> a, std::shared_ptr<constant> b,
               std::shared_ptr<constant> c) {
  *this += a;
  *this += b;
  *this += c;
}
void object::accept(visitor *a) { a->v(this); }

stack::stack(std::shared_ptr<constant> a) { *this += a; }
void stack::accept(visitor *a) { a->v(this); }

string_constant::string_constant(lex::token a) : n(a) {}
void string_constant::accept(visitor *a) { a->v(this); }

triple::triple(std::shared_ptr<string_constant> a) { *this += a; }
void triple::accept(visitor *a) { a->v(this); }
