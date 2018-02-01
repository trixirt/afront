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

postfix_expr::postfix_expr(std::shared_ptr<primary_expr> _a) { *this += _a; }
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a,
                           std::shared_ptr<expr> _b) {
  *this += _a;
  *this += _b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a) { *this += _a; }
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a,
                           std::shared_ptr<argument_expr_list> _b) {
  *this += _a;
  *this += _b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a,
                           std::shared_ptr<identifier> _b) {
  *this += _a;
  *this += _b;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a, lex::token _b,
                           std::shared_ptr<identifier> _c)
    : n(_b) {
  *this += _a;
  *this += _c;
}
postfix_expr::postfix_expr(std::shared_ptr<postfix_expr> _a, lex::token _b)
    : n(_b) {
  *this += _a;
}
postfix_expr::postfix_expr(std::shared_ptr<type_name> _a,
                           std::shared_ptr<identifier_list> _b) {
  *this += _a;
  *this += _b;
}
void postfix_expr::accept(visitor *_a) { _a->v(this); };
std::string postfix_expr::classname() { return "postfix_expr"; };
