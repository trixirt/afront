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

#define V(C)                                                                   \
  void chk::v(C *a) { a->caccept(this); }

chk::chk(std::shared_ptr<scope> a) {
  //
  // The compiler scope
  scope_stack.push(a);

  //
  // Keep track of the current function
  current_function = nullptr;

  debug = true;
  // debug = false;
}
chk::~chk() {}
void chk::descend() { indent += " "; }
void chk::ascend() { indent.pop_back(); }

V(abstract_array_declarator)
V(abstract_declarator)
V(abstract_function_declarator)
V(additive_expr)
V(alignment_specifier)
V(and_expr)
V(argument_expr_list)
V(array_declarator)
V(assignment_expr)
V(assignment_operator)
V(atomic_type_specifier)
V(block_item)
V(block_item_list)
V(cast_expr)
V(character_constant)

void chk::v(compound_statement *a) {
  //
  // compound statements can have declarations so
  // they need their own scope.
  std::string pn = scope_stack.top()->name();
  size_t num = scope_stack.top()->subscopes();
  std::string n = pn + "." + std::to_string(num);
  std::shared_ptr<scope> s =
      std::shared_ptr<scope>(new scope(a->here(), scope_stack.top().get(), n));
  a->set_scope(s);
  scope_stack.push(s);

  if (debug) {
    std::cout << indent << a->classname() << std::endl;
  }
  a->caccept(this);

  scope_stack.pop();
}

V(conditional_expr)
V(constant)
V(constant_expr)

void chk::v(declaration *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
  }
  auto c = a->children();
  // expecting { declaration-specifiers }
  // expecting { declaration-specifiers,  init-declarator-list }
  // expecting { static_assert-declaration }
  declaration_specifiers *ds =
      dynamic_cast<declaration_specifiers *>(c[0].get());
  if (ds != nullptr) {
    std::vector<type_specifier *> v;
    ds->type_specifiers(&v);
    for (auto i : v) {
      if (i->is_void()) {
        // make sure this is really a bare void
        bool void_pointer = false;
        if (c.size() == 2) {
          init_declarator_list *idl =
              dynamic_cast<init_declarator_list *>(c[1].get());
          if (idl != nullptr) {
            std::vector<declarator *> vv;
            idl->declarators(&vv);
            for (auto ii : vv) {
              if (ii->has_pointer()) {
                void_pointer = true;
              } else {
                // found at least 1 bad
                // no point continuing
                void_pointer = false;
                break;
              }
            }
          } else {
            throw(ice_exception(__FILE__, __LINE__, "malformed declaration"));
          }
        }
        if (!void_pointer) {
          // No bare void's
          throw(visitor_exception("invalid void usage", i));
        }
      }
    }
    //
    // expecting { declaration-specifiers,  init-declarator-list }
    //
    // Look for the identifiers
    if (c.size() == 2) {
      init_declarator_list *idl =
	dynamic_cast<init_declarator_list *>(c[1].get());
      if (idl != nullptr) {
	auto cc = idl->children();
	for (size_t i = 0; i < cc.size(); i++) {
	  init_declarator *id = dynamic_cast<init_declarator *>(cc[i].get());
	  if (id != nullptr) {
	    //
	    // expecting { declarator }
	    //           { declarator EQ initializer }
	    declarator *d = dynamic_cast<declarator *>(id->children()[0].get());
	    if (d != nullptr) {
	      identifier *i = d->identifier();
	      // TODO : check for multiple identifiers
	      if (i != nullptr) {
		scope *s = scope_stack.top().get();
		if (s->has_declaration(i->id())) {
		  throw(visitor_exception("identifier has already been defined", i));
		} else {
		  // add this identifier:declaration-specifiers to the current
		  // scope's declaration map.
		  s->set_declaration(i->id(), ds);
		}
	      }
	    }
	  }
	}
      }
    }
  }
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

          if ((what != afront::parser::token::EXTERN) &&
              (what != afront::parser::token::STATIC)) {
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

          if (what != afront::parser::token::REGISTER) {
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

V(direct_abstract_declarator)

void chk::v(direct_declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

V(enumeration_constant)
V(enumerator)

void chk::v(enumerator_list *a) {
  for (auto c : a->children()) {
    // expecting { enumerator }
    enumerator *e = dynamic_cast<enumerator *>(c.get());
    if (e != nullptr) {
      // check that the enumerator is unique
      enumerator *r = a->update_map(e);
      if (r == nullptr) {
        throw(visitor_exception("enumerator redefined", a));
      }
    } else {
      throw(ice_exception(__FILE__, __LINE__, "malformed enumerator list"));
    }
  }
  a->caccept(this);
}
void chk::v(enum_specifier *a) {
  // 6.7.2.3 Tags
  // Where two declarations that use the same tag declare the same type,
  // they shall both use the same choice of struct, union, or enum.
  auto c = a->children();
  // expecting { identifier, enumeration_list }
  // expecting { identifier }
  identifier *i = dynamic_cast<identifier *>(c[0].get());
  if (i != nullptr) {
    scope *s = scope_stack.top().get();
    enum_specifier *r = s->enum_tag(a);
    if (r == nullptr) {
      throw(visitor_exception("enum tag not unique to scope", a));
    } else {
      // passed unique tag
      if (c.size() == 2) {
        // a user type definition
        // check if the type is unique
        class n *r;
        r = s->user_type(i->id(), a);
        if (r == nullptr) {
          throw(visitor_exception("type redefined", a));
        }
      }
    }
  } else {
    // confused
    throw(ice_exception(__FILE__, __LINE__, "misconfigured enum_specifier"));
  }
  a->caccept(this);
}
V(equality_expr)
V(exclusive_or_expr)
V(expr)
V(expression_statement)
V(floating_constant)
V(function_body)

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
  current_function = a;
  //
  // A function definition has function scope
  std::string f = a->functionname();
  std::shared_ptr<scope> s =
      std::shared_ptr<scope>(new scope(a->here(), scope_stack.top().get(), f));
  scope_stack.push(s);

  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);

  scope_stack.pop();
  current_function = nullptr;
}

V(function_specifier)
V(generic_association)
V(generic_assoc_list)
V(generic_selection)

void chk::v(identifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what())
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }
  /* terminal */
}

V(identifier_list)
V(inclusive_or_expr)

void chk::v(init_declarator *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

void chk::v(init_declarator_list *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

V(initializer)
V(initializer_list)
V(integer_constant)
V(iteration_statement)
V(jump_statement)

void chk::v(labeled_statement *a) {
  // 6.8.1
  // A case or default label shall appear only in a switch statement.
  if (a->what() >= 0) {
    bool in_switch = false;
    if (a->parent() != nullptr) {
      selection_statement *ss =
          dynamic_cast<selection_statement *>(a->parent());
      if (ss)
        if (ss->what() == afront::parser::token::SWITCH)
          in_switch = true;
    } else {
      throw(ice_exception(__FILE__, __LINE__, "no parent node"));
    }
    if (!in_switch) {
      if (a->what() == afront::parser::token::CASE)
        throw(visitor_exception("case not contained in a switch statement", a));
      else if (a->what() == afront::parser::token::DEFAULT)
        throw(visitor_exception("default not contained in a switch statement",
                                a));
      else
        throw(ice_exception(__FILE__, __LINE__, "unhandled node type"));
    }
  } else {
    // syntax checker should handle label at the file level
    if (current_function == nullptr) {
      throw(ice_exception(__FILE__, __LINE__,
                          "current function should not be null"));
    } else {
      labeled_statement *r = current_function->label(a);
      if (r == nullptr) {
        throw(ice_exception(__FILE__, __LINE__,
                            "problem with adding label to current function"));
      } else if (r != a) {
        // 6.8.1
        // Label names shall be unique within a function
        throw(visitor_exception("label name is not unique to function", a));
      }
    }
  }
  a->caccept(this);
}
V(logical_and_expr)
V(logical_or_expr)
V(m)
V(multiplicative_expr)
V(n)

void chk::v(parameter_declaration *a) {
  if (debug)
    std::cout << indent << a->classname() << std::endl;
  a->caccept(this);
}

V(parameter_list)

void chk::v(parameter_type_list *a) {
  auto c = a->children();
  // expecting { parameter-list }
  parameter_list *pl = dynamic_cast<parameter_list *>(c[0].get());
  if (pl != nullptr) {
    unsigned parameters_checked = a->has_vararg() ? 1 : 0;
    type_specifier *bare_void = nullptr;
    for (auto gc : pl->children()) {
      // expecting { parameter-declaration }
      parameter_declaration *pd =
          dynamic_cast<parameter_declaration *>(gc.get());
      if (pd != nullptr) {
        auto ggc = pd->children();
        // expecting { declaration-specifiers declarator }
        // expecting { declaration-specifiers abstract-declarator }
        // expecting { declaration-specifiers }
        declaration_specifiers *ds =
            dynamic_cast<declaration_specifiers *>(ggc[0].get());
        if (ds != nullptr) {
          if (bare_void != nullptr) {
            // a bare void is only valid if it is the only parameter
            throw(visitor_exception("invalid void usage", bare_void));
          } else {
            std::vector<type_specifier *> v;
            ds->type_specifiers(&v);
            for (auto i : v) {
              if (i->is_void()) {
                // make sure this is really a bare void
                bool void_pointer = false;
                if (ggc.size() == 2) {
                  abstract_declarator *ad =
                      dynamic_cast<abstract_declarator *>(ggc[1].get());
                  if (ad != nullptr) {
                    if (ad->has_pointer())
                      void_pointer = true;
                  } else {
                    declarator *d = dynamic_cast<declarator *>(ggc[1].get());
                    if (d != nullptr) {
                      if (d->has_pointer())
                        void_pointer = true;
                    } else {
                      throw(ice_exception(__FILE__, __LINE__,
                                          "malformed parameter-declaration"));
                    }
                  }
                }
                if (!void_pointer) {
                  if (parameters_checked != 0) {
                    // Only 1 bare void per parameter type list
                    throw(visitor_exception("invalid void usage", i));
                  } else {
                    bare_void = i;
                  }
                }
              }
            }
          }
        } else {
          throw(ice_exception(__FILE__, __LINE__,
                              "malformed parameter declaration"));
        }

      } else {
        throw(ice_exception(__FILE__, __LINE__, "malformed parameter list"));
      }
      parameters_checked++;
    }
  } else {
    throw(ice_exception(__FILE__, __LINE__, "malformed parameter type list"));
  }

  a->caccept(this);
}

V(pointer)
V(postfix_expr)
V(primary_expr)
V(relation_expr)
V(selection_statement)
V(shift_expr)
V(specifier_qualifier_list)
V(statement)
V(statement_list)
V(static_assert_declaration)

void chk::v(storage_class_specifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what())
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }
  /* terminal */
}

V(string_literal)
V(struct_declaration)

void chk::v(struct_declaration_list *a) {
  for (auto c : a->children()) {
    // expecting { struct-declaration }
    struct_declaration *sd = dynamic_cast<struct_declaration *>(c.get());
    if (sd != nullptr) {
      auto gc = sd->children();
      // expecting { specifier-qualifier-list }
      // expecting { specifier-qualifier-list struct-declarator-list }
      // expecting { static-assert-declaration }
      specifier_qualifier_list *sql =
          dynamic_cast<specifier_qualifier_list *>(gc[0].get());
      if (sql != nullptr) {
        std::vector<type_specifier *> v;
        sql->type_specifiers(&v);
        for (auto i : v) {
          if (i->is_void()) {
            // make sure this is really a bare void
            bool void_pointer = false;
            if (gc.size() == 2) {
              struct_declarator_list *sdl =
                  dynamic_cast<struct_declarator_list *>(gc[1].get());
              if (sdl != nullptr) {
                std::vector<declarator *> vv;
                sdl->declarators(&vv);
                for (auto ii : vv) {
                  if (ii->has_pointer()) {
                    void_pointer = true;
                  } else {
                    // found at least 1 bad
                    // no point continuing
                    void_pointer = false;
                    break;
                  }
                }
              } else {
                throw(ice_exception(__FILE__, __LINE__,
                                    "malformed struct-declaration"));
              }
            }
            if (!void_pointer) {
              // No bare void's
              throw(visitor_exception("invalid void usage", i));
            }
          }
        }
      }
    } else {
      throw(ice_exception(__FILE__, __LINE__,
                          "malformed struct-declaration-list"));
    }
  }
  a->caccept(this);
}
V(struct_declarator)
V(struct_declarator_list)
V(struct_or_union)

void chk::v(struct_or_union_specifier *a) {
  // 6.7.2.3 Tags
  // Where two declarations that use the same tag declare the same type,
  // they shall both use the same choice of struct, union, or enum.
  auto c = a->children();
  // expecting { struct_or_union, identifier, struct_declaration_list }
  // expecting { struct_or_union, struct_declaration_list }
  // expecting { struct_or_union, identifier }
  //
  // the tag is the identifier
  class identifier *i = dynamic_cast<identifier *>(c[1].get());
  if (i != nullptr) {
    scope *s = scope_stack.top().get();
    struct_or_union_specifier *r = s->struct_or_union_tag(a);
    if (r == nullptr) {
      if (a->is_struct()) {
        throw(visitor_exception("struct tag not unique to scope", a));
      } else if (a->is_union()) {
        throw(visitor_exception("union tag not unique to scope", a));
      } else {
        // confused
        throw(ice_exception(__FILE__, __LINE__,
                            "misconfigured struct_or_union_specifier"));
      }
    } else {
      // passed unique tag
      if (c.size() == 3) {
        // A user type definition
        // check if the type is unique
        class n *r;
        r = s->user_type(i->id(), a);
        if (r == nullptr) {
          throw(visitor_exception("type redefined", a));
        }
      }
    }
  }
  //
  // check that declarators are unique
  std::vector<declarator *> dl;
  a->declarators(&dl);
  for (auto d : dl) {
    declarator *r = a->update_map(d);
    if (r == nullptr) {
      throw(visitor_exception("element redefined", d));
    }
  }

  a->caccept(this);
}

void chk::v(translation_unit *a) {
  //
  // A translation unit is file scope
  std::string f = a->filename();
  std::shared_ptr<scope> s =
      std::shared_ptr<scope>(new scope(a->here(), scope_stack.top().get(), f));
  a->set_scope(s);
  scope_stack.push(s);

  if (debug) {
    std::cout << std::endl;
    std::cout << indent << a->classname() << std::endl;
  }
  a->caccept(this);

  scope_stack.pop();
}

V(type_name)

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

V(type_qualifier_list)

void chk::v(type_specifier *a) {
  if (debug) {
    std::cout << indent << a->classname() << std::endl;
    if (a->what() > -1)
      std::cout << indent << a->where() << " " << a->who() << std::endl;
  }

  std::shared_ptr<type_data>td;
  if (dynamic_cast<type_qualifier_list *>(a->parent())) {
    type_qualifier_list *tql = dynamic_cast<type_qualifier_list *>(a->parent());
    td = tql->get_type_data();
  } else if (dynamic_cast<declaration_specifiers *>(a->parent())) {
    declaration_specifiers *ds = dynamic_cast<declaration_specifiers *>(a->parent());
    td = ds->get_type_data();
  } else {
    std::string str = "unexpected parent of type_specifier ";
    str += a->parent()->classname();
    throw(ice_exception(__FILE__, __LINE__, str));
  }

  unsigned tsd = td->type_specifier.get();
  unsigned ts = 0;
  if (a->is_primitive()) {
    signed tok = a->what();
    size_t i, max;
    if (tok == afront::parser::token::VOID) {
      ts = TYPE_SPECIFIER_VOID;
      unsigned vts[] = { 0,
      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }
    } else if (tok == afront::parser::token::CHAR) {
      ts = TYPE_SPECIFIER_CHAR;
      unsigned vts[] = { 0,
			  TYPE_SPECIFIER_SIGNED,
			  TYPE_SPECIFIER_UNSIGNED,
      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }
      
    } else if (tok == afront::parser::token::SHORT) {
      ts = TYPE_SPECIFIER_SHORT;
      unsigned vts[] = { 0,
			  TYPE_SPECIFIER_SIGNED,
			  TYPE_SPECIFIER_UNSIGNED,
			  TYPE_SPECIFIER_INT,
			  TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_INT,
			  TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT,
      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }

    } else if (tok == afront::parser::token::INT) {
      ts = TYPE_SPECIFIER_INT;
      unsigned vts[] = { 0,
			  TYPE_SPECIFIER_SIGNED,
			  TYPE_SPECIFIER_UNSIGNED,
			  TYPE_SPECIFIER_SHORT,
			  TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_SHORT,
			  TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_SHORT,
			  TYPE_SPECIFIER_LONG,
			  TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_LONG,
			  TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_LONG,
			  TYPE_SPECIFIER_LONG_LONG,
			  TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_LONG_LONG,
			  TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_LONG_LONG,
      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }

    } else if (tok == afront::parser::token::LONG) {
      ts = TYPE_SPECIFIER_LONG;
      unsigned vts[] = { 0,
			 TYPE_SPECIFIER_SIGNED,
			 TYPE_SPECIFIER_UNSIGNED,
			 TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_LONG,
			 TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_LONG,
			 TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_LONG,
			 TYPE_SPECIFIER_LONG | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_SIGNED | TYPE_SPECIFIER_LONG | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_LONG | TYPE_SPECIFIER_INT,

      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }
    } else if (tok == afront::parser::token::SIGNED || tok == afront::parser::token::UNSIGNED) {
      ts = TYPE_SPECIFIER_SIGNED;
      if (tok == afront::parser::token::UNSIGNED)
	ts = TYPE_SPECIFIER_UNSIGNED;
      unsigned vts[] = { 0,
			 TYPE_SPECIFIER_CHAR,
			 TYPE_SPECIFIER_SHORT,
			 TYPE_SPECIFIER_SHORT | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_LONG,
			 TYPE_SPECIFIER_LONG | TYPE_SPECIFIER_INT,
			 TYPE_SPECIFIER_LONG_LONG,
			 TYPE_SPECIFIER_LONG_LONG | TYPE_SPECIFIER_INT,
      };
      max = sizeof(vts)/sizeof(vts[0]);
      for (i = 0; i < max; i++) {
	if (tsd == vts[i])
	  break;
      }
    } else {
      std::string str = "unexpected token for type_specifier ";
      throw(ice_exception(__FILE__, __LINE__, str));
    }

    if (i < max) {
      td->type_specifier.set(ts);
    } else {
      throw(visitor_exception("overspecified type", a));
    }
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
        if (scs->what() == afront::parser::token::TYPEDEF) {
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

V(unary_expr)
V(unary_operator)
