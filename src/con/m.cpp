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
#include "m.h"
#include "e.h"

m::m() { p = nullptr; }
std::string m::classname() { return "m"; }
std::deque<std::shared_ptr<m>> &m::children() { return c; }
std::deque<std::shared_ptr<m>> &m::siblings() {
  if (p != nullptr) {
    return p->children();
  }
  throw(ice_exception(__FILE__, __LINE__, "could not find the parent"));
}
void m::parent(class m *a) { p = a; }
class m *m::parent() {
  return p;
}
/* add to children, back */
class m &m::operator+=(std::shared_ptr<m> &rhs) {
  // add child to childrent
  c.push_back(rhs);
  // the child gets a parent
  rhs->parent(this);
  return *this;
}
/* add to children, front */
class m &m::operator*=(std::shared_ptr<m> &rhs) {
  // add child to children
  c.push_front(rhs);
  // the child gets a parent
  rhs->parent(this);
  return *this;
}
/* remove child */
class m &m::operator-=(class m *rhs) {
  bool r = false;
  std::deque<std::shared_ptr<m>>::iterator itr;
  for (itr = c.begin(); itr != c.end(); itr++) {
    auto i = *itr;
    if (i.get() == rhs) {
      c.erase(itr);
      r = true;
      break;
    }
  }

  if (r == false) {
    throw(ice_exception(__FILE__, __LINE__, "could not remove"));
  }

  return *this;
}
/* remove sibling */
class m &m::operator/=(class m *rhs) {
  if (p != nullptr) {
    *p -= rhs;
  }
  return *this;
}

bool m::attach(std::shared_ptr<observer> a) {
    bool ret = false;
    auto i = std::find(observers.begin(), observers.end(), a);
    if (i == observers.end()) {
	observers.push_back(a);
	ret = true;
    }
    return ret;
}
void m::clear() { observers.clear(); }

std::deque<std::shared_ptr<observer>> m::observers;
