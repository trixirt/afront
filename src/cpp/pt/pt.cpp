/*
 * Copyright (c) 2019 Tom Rix
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
#include "v/observers.h"

control_line::control_line() {}
control_line::control_line(lex_token a, std::shared_ptr<pp_tokens> b) : n(a) {
  *this += b;
}
control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           std::shared_ptr<replacement_list> c)
    : n(a) {
  *this += b;
  *this += c;
}
control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           std::shared_ptr<identifier_list> c,
                           std::shared_ptr<replacement_list> d)
    : n(a) {
  *this += b;
  *this += c;
  *this += d;
}
control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           lex_token c, std::shared_ptr<replacement_list> d)
    : n(a) {
  *this += b;
  *this += d;
}

control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           std::shared_ptr<cpp_va_arg> c, std::shared_ptr<replacement_list> d)
    : n(a) {
  *this += b;
  *this += c;
  *this += d;
}

control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           std::shared_ptr<identifier_list> c, lex_token d,
                           std::shared_ptr<replacement_list> e)
    : n(a) {
  *this += b;
  *this += c;
  *this += e;
}

control_line::control_line(lex_token a, std::shared_ptr<identifier> b,
                           std::shared_ptr<identifier_list> c, std::shared_ptr<cpp_va_arg> d,
                           std::shared_ptr<replacement_list> e)
    : n(a) {
  *this += b;
  *this += c;
  *this += d;
  *this += e;
}

control_line::control_line(lex_token a, std::shared_ptr<identifier> b) : n(a) {
  *this += b;
}
control_line::control_line(lex_token a) : n(a) {}
void control_line::accept(visitor *a) { a->v(this); }
void control_line::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string control_line::classname() { return "control_line"; }

cpp_primary_expr::cpp_primary_expr(std::shared_ptr<defined> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_cpp_attribute> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_declspec_attribute> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_feature> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_include> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_include_next> a) { *this += a; }
cpp_primary_expr::cpp_primary_expr(std::shared_ptr<has_warning> a) { *this += a; }
void cpp_primary_expr::accept(visitor *a) { a->v(this); }
void cpp_primary_expr::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string cpp_primary_expr::classname() { return "cpp_primary_expr"; }

cpp_va_arg::cpp_va_arg(lex_token a) : n(a) { }
void cpp_va_arg::accept(visitor *a) { a->v(this); }
void cpp_va_arg::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string cpp_va_arg::classname() { return "cpp_va_arg"; }

defined::defined(std::shared_ptr<identifier> a) { *this += a; }
void defined::accept(visitor *a) { a->v(this); }
void defined::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string defined::classname() { return "defined"; }

elif_group::elif_group(std::shared_ptr<constant_expr> a) { *this += a; }
elif_group::elif_group(std::shared_ptr<constant_expr> a,
                       std::shared_ptr<group> b) {
  *this += a;
  *this += b;
}
void elif_group::accept(visitor *a) { a->v(this); }
void elif_group::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string elif_group::classname() { return "elif_group"; }

elif_groups::elif_groups(std::shared_ptr<elif_group> a) { *this += a; }
void elif_groups::accept(visitor *a) { a->v(this); }
void elif_groups::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string elif_groups::classname() { return "elif_groups"; }

else_group::else_group() {}
else_group::else_group(std::shared_ptr<group> a) { *this += a; }
void else_group::accept(visitor *a) { a->v(this); }
void else_group::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string else_group::classname() { return "else_group"; }

group::group(std::shared_ptr<group_part> a) { *this += a; }
void group::accept(visitor *a) { a->v(this); }
void group::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string group::classname() { return "group"; }

group_part::group_part(std::shared_ptr<if_section> a) { *this += a; }
group_part::group_part(std::shared_ptr<control_line> a) { *this += a; }
group_part::group_part(std::shared_ptr<text_line> a) { *this += a; }
group_part::group_part(std::shared_ptr<non_directive> a) { *this += a; }
void group_part::accept(visitor *a) { a->v(this); }
void group_part::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string group_part::classname() { return "group_part"; }

has_cpp_attribute::has_cpp_attribute(std::shared_ptr<identifier> a) { *this += a; }
has_cpp_attribute::has_cpp_attribute(std::shared_ptr<identifier> a, std::shared_ptr<identifier> b) { *this += a; *this += b; }
void has_cpp_attribute::accept(visitor *a) { a->v(this); }
void has_cpp_attribute::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_cpp_attribute::classname() { return "has_cpp_attribute"; }

has_declspec_attribute::has_declspec_attribute(std::shared_ptr<identifier> a) { *this += a; }
void has_declspec_attribute::accept(visitor *a) { a->v(this); }
void has_declspec_attribute::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_declspec_attribute::classname() { return "has_declspec_attribute"; }

has_feature::has_feature(std::shared_ptr<identifier> a) { *this += a; }
void has_feature::accept(visitor *a) { a->v(this); }
void has_feature::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_feature::classname() { return "has_feature"; }

has_include::has_include(std::shared_ptr<pp_tokens> a) { *this += a; }
void has_include::accept(visitor *a) { a->v(this); }
void has_include::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_include::classname() { return "has_include"; }

has_include_next::has_include_next(std::shared_ptr<pp_tokens> a) { *this += a; }
void has_include_next::accept(visitor *a) { a->v(this); }
void has_include_next::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_include_next::classname() { return "has_include_next"; }

has_warning::has_warning(std::shared_ptr<string_literal> a) { *this += a; }
void has_warning::accept(visitor *a) { a->v(this); }
void has_warning::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string has_warning::classname() { return "has_warning"; }

if_group::if_group(lex_token a, std::shared_ptr<constant_expr> b) : n(a) {
  *this += b;
}
if_group::if_group(lex_token a, std::shared_ptr<constant_expr> b,
                   std::shared_ptr<group> c)
    : n(a) {
  *this += b;
  *this += c;
}
if_group::if_group(lex_token a, std::shared_ptr<identifier> b) : n(a) {
  *this += b;
}
if_group::if_group(lex_token a, std::shared_ptr<identifier> b,
                   std::shared_ptr<group> c)
    : n(a) {
  *this += b;
  *this += c;
}
void if_group::accept(visitor *a) { a->v(this); }
void if_group::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string if_group::classname() { return "if_group"; }

if_section::if_section(std::shared_ptr<if_group> a) {
  *this += a;
}
if_section::if_section(std::shared_ptr<if_group> a,
                       std::shared_ptr<else_group> b) {
  *this += a;
  *this += b;
}
if_section::if_section(std::shared_ptr<if_group> a,
                       std::shared_ptr<elif_groups> b) {
  *this += a;
  *this += b;
}
if_section::if_section(std::shared_ptr<if_group> a,
                       std::shared_ptr<elif_groups> b,
                       std::shared_ptr<else_group> c) {
  *this += a;
  *this += b;
  *this += c;
}
void if_section::accept(visitor *a) { a->v(this); }
void if_section::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string if_section::classname() { return "if_section"; }

non_directive::non_directive(std::shared_ptr<pp_tokens> a) { *this += a; }
void non_directive::accept(visitor *a) { a->v(this); }
void non_directive::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string non_directive::classname() { return "non_directive"; }

pp_tokens::pp_tokens(std::shared_ptr<preprocessing_token> a) { *this += a; }
void pp_tokens::accept(visitor *a) { a->v(this); }
void pp_tokens::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string pp_tokens::classname() { return "pp_tokens"; }

preprocessing_file::preprocessing_file() {}
preprocessing_file::preprocessing_file(std::shared_ptr<group> a) { *this += a; }
void preprocessing_file::accept(visitor *a) { a->v(this); }
void preprocessing_file::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string preprocessing_file::classname() { return "preprocessing_file"; }

preprocessing_token::preprocessing_token(lex_token a) : n(a) {}
void preprocessing_token::accept(visitor *a) { a->v(this); }
void preprocessing_token::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string preprocessing_token::classname() { return "preprocessing_token"; }

replacement_list::replacement_list() {}
replacement_list::replacement_list(std::shared_ptr<pp_tokens> a) { *this += a; }
void replacement_list::accept(visitor *a) { a->v(this); }
void replacement_list::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string replacement_list::classname() { return "replacement_list"; }

text_line::text_line() {}
text_line::text_line(std::shared_ptr<pp_tokens> a) { *this += a; }
void text_line::accept(visitor *a) { a->v(this); }
void text_line::notify() {
  for (auto i : observers)
    i->update(this);
}
std::string text_line::classname() { return "text_line"; }

