/*
 * Copyright (c) 2017-2019 Tom Rix
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
#ifndef AFRONT_CON_M_H
#define AFRONT_CON_M_H

#include <deque>
#include <memory>
#include <string>

class visitor;
class observer;
class m;

class m {
public:
  m();
  virtual ~m(){};
  virtual std::string classname();

  //
  // Node manipulation
  //
  // return a list of children
  std::deque<std::shared_ptr<m>> &children();
  // return a list of siblings
  std::deque<std::shared_ptr<m>> &siblings();
  // set the parent
  void parent(class m *a);
  // return the parent
  class m *parent();
  // add to children, back 
  class m &operator+=(std::shared_ptr<m> &rhs);
  // add to children, front
  class m &operator*=(std::shared_ptr<m> &rhs);
  // remove child
  class m &operator-=(class m *rhs);
  // remove sibling */
  class m &operator/=(class m *rhs);

  //
  // Visitor pattern
  //
  // accept visitor on this node
  virtual void accept(visitor *a);
  // accept visitor on the children
  void caccept(visitor *a);

  //
  // Observer pattern
  //
  // Add an observer
  static bool attach(std::shared_ptr<observer> a);
  // detach all observers
  static void clear();
  // notifiy the observer
  virtual void notify() = 0;
  
protected:
  // The children of this node
  std::deque<std::shared_ptr<m>> c;
  // The parent
  class m *p;
  // The list of observers
  static std::deque<std::shared_ptr<observer>> observers;
};

#endif
