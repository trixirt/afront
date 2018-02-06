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
#ifndef AFRONT_FIG_PT_VIS_VISITOR_H
#define AFRONT_FIG_PT_VIS_VISITOR_H

class abi;
class configuration;
class constant;
class data_layout;
class endian;
class identifier;
class language_type;
class language_type_list;
class layout_option_list;
class layout_option;
class mangle;
class object_class;
class object_list;
class object;
class stack;
class string_constant;
class triple;

class visitor {
public:
  visitor(){};
  virtual ~visitor(){};

  virtual void descend() {}
  virtual void ascend() {}

  virtual void v(abi *a) = 0;
  virtual void v(configuration *a) = 0;
  virtual void v(constant *a) = 0;
  virtual void v(data_layout *a) = 0;
  virtual void v(endian *a) = 0;
  virtual void v(identifier *a) = 0;
  virtual void v(language_type *a) = 0;
  virtual void v(language_type_list *a) = 0;
  virtual void v(layout_option_list *a) = 0;
  virtual void v(layout_option *a) = 0;
  virtual void v(mangle *a) = 0;
  virtual void v(object_class *a) = 0;
  virtual void v(object_list *a) = 0;
  virtual void v(object *a) = 0;
  virtual void v(stack *a) = 0;
  virtual void v(string_constant *a) = 0;
  virtual void v(triple *a) = 0;
};

#endif
