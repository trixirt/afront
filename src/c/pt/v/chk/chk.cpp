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

#include "chk.h"
#include "e.h"

chk::chk(std::shared_ptr<ast> a) {
  t = a;

  // debug = true;
  debug = false;
}
chk::~chk() {}
void chk::descend() { indent += " "; }
void chk::ascend() { indent.pop_back(); }

void chk::v(abstract_array_declarator *a) { a->caccept(this); }
void chk::v(abstract_declarator *a) { a->caccept(this); }
void chk::v(abstract_function_declarator *a) { a->caccept(this); }
void chk::v(additive_expr *a) { a->caccept(this); }
void chk::v(and_expr *a) { a->caccept(this); }
void chk::v(argument_expr_list *a) { a->caccept(this); }
void chk::v(array_declarator *a) { a->caccept(this); }
void chk::v(assignment_expr *a) { a->caccept(this); }
void chk::v(assignment_operator *a) { a->caccept(this); }
void chk::v(cast_expr *a) { a->caccept(this); }

void chk::v(compound_statement *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
  }
  a->caccept(this);
}

void chk::v(conditional_expr *a) { a->caccept(this); }
void chk::v(constant_expr *a) { a->caccept(this); }

void chk::v(declaration *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(declaration_list *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
  }

  a->caccept(this);
}

void chk::v(declaration_specifiers *a) {

  if (debug) {
    std::cout << indent << a->classname() << std::endl;
  }

  bool sc = false;
  bool ts = false;

  for (auto c : a->children()) {
    if (dynamic_cast<storage_class_specifier *>(c.get())) {
      if (sc) {
        // c99 6.7.1 Storage-class specifiers
        // 2. At most, one storage-class specifier may be given
        //    in the declaration specifiers in a declaration
        throw(visitor_exception("declaration contains multiple storage classes",
                                c.get()));
      } else {
        storage_class_specifier *scs =
            dynamic_cast<storage_class_specifier *>(c.get());
        unsigned what = scs->what();
        if (a->parent() != nullptr) {

          if ((what != nada::parser::token::EXTERN) &&
              (what != nada::parser::token::STATIC)) {
            if (dynamic_cast<function_definition *>(a->parent())) {
              // c99 6.9.1 Function definitions
              // 4. The storage-class specifier, if any, in the declaration
              // specifiers
              //    shall be either extern or static.
              throw(visitor_exception(
                  "a function definition should be either 'extern' or 'static'",
                  a));
            }
          }

          if (what != nada::parser::token::REGISTER) {
            if (dynamic_cast<parameter_declaration *>(a->parent())) {
              // c99 6.9.1 Function Definitions
              // 6. The declarations in the declaration list shall contain
              //    no storage-class specifier other than register
              throw(visitor_exception(
                  "the only valid storage class for a parameter is 'register'",
                  c.get()));
            }
          }
        } else {
          throw(ice_exception(__FILE__, __LINE__, "no parent node"));
        }
        sc = true;
      }
    } else if (dynamic_cast<type_specifier *>(c.get())) {
      ts = true;
    } else if (dynamic_cast<type_qualifier *>(c.get())) {
    } else if (dynamic_cast<function_specifier *>(c.get())) {
    } else {
      throw(ice_exception(__FILE__, __LINE__, "unknown node"));
    }
  }
  // c99 6.7.1 c2
  // Need at least 1 type
  if (!ts) {
    // not sure which node to blame..
    // go with the first
    auto c = a->children();
    throw(visitor_exception("declaration contains no type specifiers",
                            c.front().get()));
  }
  // throw(visitor_exception("declaration contains multiple types", c.get()));

  a->caccept(this);
}

void chk::v(declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(direct_abstract_declarator *a) { a->caccept(this); }

void chk::v(direct_declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(enumerator *a) { a->caccept(this); }
void chk::v(enumerator_list *a) { a->caccept(this); }
void chk::v(enum_specifier *a) { a->caccept(this); }
void chk::v(equality_expr *a) { a->caccept(this); }
void chk::v(exclusive_or_expr *a) { a->caccept(this); }
void chk::v(expr *a) { a->caccept(this); }
void chk::v(expression_statement *a) { a->caccept(this); }

void chk::v(function_body *a) { a->caccept(this); }

void chk::v(external_definition *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(function_declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;

  a->caccept(this);
}

void chk::v(function_definition *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(function_specifier *a) { a->caccept(this); }
void chk::v(generic_association *a) { a->caccept(this); }
void chk::v(generic_assoc_list *a) { a->caccept(this); }
void chk::v(generic_selection *a) { a->caccept(this); }

void chk::v(identifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what())
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }
  /* terminal */
}

void chk::v(identifier_list *a) { a->caccept(this); }
void chk::v(inclusive_or_expr *a) { a->caccept(this); }

void chk::v(init_declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(init_declarator_list *a) { a->caccept(this); }
void chk::v(initializer *a) { a->caccept(this); }
void chk::v(initializer_list *a) { a->caccept(this); }
void chk::v(iteration_statement *a) { a->caccept(this); }
void chk::v(jump_statement *a) { a->caccept(this); }
void chk::v(labeled_statement *a) { a->caccept(this); }
void chk::v(logical_and_expr *a) { a->caccept(this); }
void chk::v(logical_or_expr *a) { a->caccept(this); }
void chk::v(m *a) { a->caccept(this); }
void chk::v(multiplicative_expr *a) { a->caccept(this); }
void chk::v(n *a) { a->caccept(this); }

void chk::v(parameter_declaration *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(parameter_list *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(parameter_type_list *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(pointer *a) { a->caccept(this); }
void chk::v(postfix_expr *a) { a->caccept(this); }
void chk::v(primary_expr *a) { a->caccept(this); }
void chk::v(relation_expr *a) { a->caccept(this); }
void chk::v(selection_statement *a) { a->caccept(this); }
void chk::v(shift_expr *a) { a->caccept(this); }
void chk::v(specifier_qualifier_list *a) { a->caccept(this); }
void chk::v(statement *a) { a->caccept(this); }
void chk::v(statement_list *a) { a->caccept(this); }

void chk::v(storage_class_specifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what())
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }
  /* terminal */
}

void chk::v(struct_declaration *a) { a->caccept(this); }
void chk::v(struct_declaration_list *a) { a->caccept(this); }
void chk::v(struct_declarator *a) { a->caccept(this); }
void chk::v(struct_declarator_list *a) { a->caccept(this); }
void chk::v(struct_or_union *a) { /* terminal */ }
void chk::v(struct_or_union_specifier *a) { a->caccept(this); }

void chk::fiddle() {}
void chk::v(translation_unit *a) {
  if (debug) {
    std::cout << std::endl;
    std::cout << indent << a->classname() << std::endl;
  }
  fiddle();
  a->caccept(this);
}

void chk::v(type_name *a) { a->caccept(this); }

void chk::v(type_qualifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what())
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }

  bool self = false;
  auto sib = a->siblings();
  unsigned what = a->what();
  for (auto s : sib) {
    /* Do not bother with younger siblings */
    if (s.get() == a) {
      self = true;
      break;
    }

    class type_qualifier *tq = dynamic_cast<type_qualifier *>(s.get());
    if (tq) {
      if (tq->what() == what) {
        // c99 6.7.3 Type Qualifiers
        // 4. If the same qualifier appears more than once in
        //    the same specifier-qualifier-list, either directly
        //    or via one or more typedefs, the behavior is the
        //    same as if it appeared only once.
        //
        // So it is ok to remove the older sibling
        *a /= tq;
      }
#ifdef C99
#error "Handle restrict"
#endif
    }
  }
}

void chk::v(type_qualifier_list *a) { a->caccept(this); }

void chk::v(type_specifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what() > -1)
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }

  bool self = false;
  bool tdef = false;
  auto sib = a->siblings();
  signed what = (signed)a->what();
  if (what > 0) {
    std::deque<unsigned> compound_type;
    for (auto s : sib) {
      class type_specifier *ts = dynamic_cast<type_specifier *>(s.get());
      if (ts) {
        // A primative type specifier
        if (ts->what() > 0)
          compound_type.push_front(ts->what());
      }
      /* Do not bother with younger siblings */
      if (s.get() == a) {
        self = true;
        break;
      }
    }
    if (compound_type.size() > 0) {
      // c99 Type Specifiers
      // 2. At least one type specifier shall be given
      //    in the declaration specifiers in each declaration,
      //    and in the specifier-qualifier list in each
      //    struct declaration and type name. Each list of
      //    type specifiers shall be one of the following sets
      //
      //
      //    void
      if (compound_type[0] == nada::parser::token::VOID) {
        if (compound_type.size() > 1) {
          throw(visitor_exception("overspecified void type", a));
        }
      }
      //
      //    char
      //    signed char
      //    unsigned char
      else if (compound_type[0] == nada::parser::token::CHAR) {
        if (compound_type.size() > 2) {
          throw(visitor_exception("overspecified char type", a));
        } else {
          bool valid = false;
          if (compound_type.size() == 1) {
            valid = true;
          } else /* 2 */ {
            if ((compound_type[1] == nada::parser::token::SIGNED) ||
                (compound_type[1] == nada::parser::token::UNSIGNED))
              valid = true;
          }
          if (!valid)
            throw(visitor_exception("invalid char type", a));
        }
      }
      //
      //    short
      //    signed short
      //    unsigned short
      else if (compound_type[0] == nada::parser::token::SHORT) {
        if (compound_type.size() > 2) {
          throw(visitor_exception("overspecified short type", a));
        } else {
          bool valid = false;
          if (compound_type.size() == 1) {
            valid = true;
          } else /* 2 */ {

            if ((compound_type[1] == nada::parser::token::SIGNED) ||
                (compound_type[1] == nada::parser::token::UNSIGNED))
              valid = true;
          }
          if (!valid)
            throw(visitor_exception("invalid short type", a));
        }
      }
      //    int
      //
      //    signed int
      //    unsigned int
      //    short int
      //    long int
      //
      //    signed short int
      //    unsigned short int
      //    signed long int
      //    unsigned long int
      //    long long int
      //
      //    signed long long int
      //    unsigned long long int
      else if (compound_type[0] == nada::parser::token::INT) {
        if (compound_type.size() > 4) {
          throw(visitor_exception("overspecified int type", a));
        } else {
          bool valid = false;
          if (compound_type.size() == 1) {
            valid = true;
          } else if (compound_type.size() == 2) {
            if ((compound_type[1] == nada::parser::token::SIGNED) ||
                (compound_type[1] == nada::parser::token::UNSIGNED) ||
                (compound_type[1] == nada::parser::token::SHORT) ||
                (compound_type[1] == nada::parser::token::LONG))
              valid = true;
          } else if (compound_type.size() == 3) {
            if ((compound_type[1] == nada::parser::token::SHORT) &&
                ((compound_type[2] == nada::parser::token::SIGNED) ||
                 (compound_type[2] == nada::parser::token::UNSIGNED)))
              valid = true;
            else if ((compound_type[1] == nada::parser::token::LONG) &&
                     ((compound_type[2] == nada::parser::token::SIGNED) ||
                      (compound_type[2] == nada::parser::token::UNSIGNED) ||
                      (compound_type[2] == nada::parser::token::LONG)))
              valid = true;
          } else /* 4 */ {
            if ((compound_type[1] == nada::parser::token::LONG) &&
                (compound_type[2] == nada::parser::token::LONG) &&
                ((compound_type[3] == nada::parser::token::SIGNED) ||
                 (compound_type[3] == nada::parser::token::UNSIGNED)))
              valid = true;
          }
          if (!valid)
            throw(visitor_exception("invalid int type", a));
        }
      }
      //
      //    signed
      else if (compound_type[0] == nada::parser::token::SIGNED) {
        if (compound_type.size() > 1) {
          throw(visitor_exception("overspecified signed type", a));
        }
      }
      //
      //    unsigned
      else if (compound_type[0] == nada::parser::token::UNSIGNED) {
        if (compound_type.size() > 1) {
          throw(visitor_exception("overspecified unsigned type", a));
        }
      }
      //
      //    long
      //    signed long
      //    unsigned long
      //    long long
      //    signed long long
      //    unsigned long long
      else if (compound_type[0] == nada::parser::token::LONG) {
        if (compound_type.size() > 3) {
          throw(visitor_exception("overspecified long type", a));
        } else {
          bool valid = false;
          if (compound_type.size() == 1) {
            valid = true;
          } else if (compound_type.size() == 2) {
            if ((compound_type[1] == nada::parser::token::SIGNED) ||
                (compound_type[1] == nada::parser::token::UNSIGNED) ||
                (compound_type[1] == nada::parser::token::LONG))
              valid = true;
          } else /* 3 */ {
            if ((compound_type[1] == nada::parser::token::LONG) &&
                ((compound_type[2] == nada::parser::token::SIGNED) ||
                 (compound_type[2] == nada::parser::token::UNSIGNED)))
              valid = true;
          }

          if (!valid)
            throw(visitor_exception("invalid long type", a));
        }
      }
      //
      //    float
      else if (compound_type[0] == nada::parser::token::FLOAT) {
        if (compound_type.size() > 1) {
          throw(visitor_exception("overspecified float type", a));
        }
      }
      //
      //    double
      //    long double
      else if (compound_type[0] == nada::parser::token::DOUBLE) {
        if (compound_type.size() > 2) {
          throw(visitor_exception("overspecified double type", a));
        } else {
          bool valid = false;
          if (compound_type.size() == 1) {
            valid = true;
          } else /* 2 */ {

            if (compound_type[1] == nada::parser::token::LONG)
              valid = true;
          }
          if (!valid)
            throw(visitor_exception("invalid double type", a));
        }
      }
#ifdef C99
      //
      //    _Bool
      else if (compound_type[0] == nada::parser::token::_BOOL) {
      }
      //
      //     float _Complex
      //     double _Complex
      //     long double _Complex
      else if (compound_type[0] == nada::parser::token::_COMPLEX) {
      }
#error "Add _Bool and _Complex"
#endif
      else {
        // Unhandled what
        throw(ice_exception(__FILE__, __LINE__, "unhandled token"));
      }
    } else {
      // The current node must be in it's sibling list.
      throw(ice_exception(__FILE__, __LINE__, "could not build compound type"));
    }

  } else {
    // A negative what means the type specifier is not primative
    // ie. a struct, union, enum..
    // There can be only one of these
    for (auto s : sib) {
      /* Do not bother with younger siblings */
      if (s.get() == a) {
        self = true;
        break;
      }
      //
      // check for typedef
      if (dynamic_cast<storage_class_specifier *>(s.get())) {
        class storage_class_specifier *scs =
            dynamic_cast<storage_class_specifier *>(s.get());
        if (scs->what() == nada::parser::token::TYPEDEF) {
          // This is not a simple aggregate type
          // Defer checking till later
          tdef = true;
          break;
        }
      } else if (dynamic_cast<type_specifier *>(s.get())) {
        class type_specifier *ts = dynamic_cast<type_specifier *>(s.get());
        std::cout << indent << ts->classname() << std::endl;
        // c99 Type Specifiers
        // 2. At least one type specifier shall be given
        //    in the declaration specifiers in each declaration,
        //    and in the specifier-qualifier list in each
        //    struct declaration and type name. Each list of
        //    type specifiers shall be one of the following sets
        //    ...
        //    struct or union specifier
        //    enum specifier
        //    typedef name
        throw(visitor_exception("overspecified aggregate type", a));
      }
    }
  }

  // typedef can come before self
  // So do not ice if we see a typedef
  if (!self && !tdef) {
    // The current node must be in it's sibling list.
    throw(ice_exception(__FILE__, __LINE__, "could not find self in siblings"));
  }

  a->caccept(this);
}

void chk::v(typedef_name *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what() > -1)
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }
  a->caccept(this);
}

void chk::v(unary_expr *a) { a->caccept(this); }
void chk::v(unary_operator *a) { /* terminal */ }
