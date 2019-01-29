TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/cpp
SRCDIR= $(TOPSRCDIR)/cpp

LYPP_FLAGS+=-Dc99 -Dc11

all: dirs $(OBJDIR)/cpp

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

OBJS =	$(OBJDIR)/cpp.o \
	$(OBJDIR)/driver.o \
	$(OBJDIR)/lang_driver.o \
	$(OBJDIR)/oparser.o \
	$(OBJDIR)/parser.o \
	$(OBJDIR)/pt.o \
	$(TOPOBJDIR)/c/ping.o \
	$(TOPOBJDIR)/c/n.o \
	$(TOPOBJDIR)/c/pt.o \
	$(TOPOBJDIR)/c/typedefs.o \
	$(TOPOBJDIR)/pt/n.o \
	$(TOPOBJDIR)/con/m.o

YYS =	$(TOPSRCDIR)/y/directives.yy \
	$(TOPSRCDIR)/y/error.yy \
	$(TOPSRCDIR)/y/override.yy \
	$(TOPSRCDIR)/y/preamble.yy \
	$(TOPSRCDIR)/y/tokens.yy \
	$(TOPSRCDIR)/c/y/c.grammer.abstract_array_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.abstract_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.abstract_function_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.additive_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.alignment_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.and_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.argument_expr_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.array_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.assignment_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.assignment_operator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.atomic_type_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.cast_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.character_constant.yy \
	$(TOPSRCDIR)/c/y/c.grammer.conditional_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.constant_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.constant.yy \
	$(TOPSRCDIR)/c/y/c.grammer.declaration_specifiers.yy \
	$(TOPSRCDIR)/c/y/c.grammer.declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.direct_abstract_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.direct_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.enumeration_constant.yy \
	$(TOPSRCDIR)/c/y/c.grammer.enumerator_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.enumerator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.enum_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.equality_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.exclusive_or_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.floating_constant.yy \
	$(TOPSRCDIR)/c/y/c.grammer.function_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.function_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.generic_association.yy \
	$(TOPSRCDIR)/c/y/c.grammer.generic_assoc_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.generic_selection.yy \
	$(TOPSRCDIR)/c/y/c.grammer.identifier_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.identifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.inclusive_or_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.integer_constant.yy \
	$(TOPSRCDIR)/c/y/c.grammer.logical_and_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.logical_or_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.multiplicative_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.parameter_declaration.yy \
	$(TOPSRCDIR)/c/y/c.grammer.parameter_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.parameter_type_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.pointer.yy \
	$(TOPSRCDIR)/c/y/c.grammer.postfix_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.primary_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.relation_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.shift_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.specifier_qualifier_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.static_assert_declaration.yy \
	$(TOPSRCDIR)/c/y/c.grammer.storage_class_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.string_literal.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_declaration_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_declaration.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_declarator_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_declarator.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_or_union_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.struct_or_union.yy \
	$(TOPSRCDIR)/c/y/c.grammer.typedef_name.yy \
	$(TOPSRCDIR)/c/y/c.grammer.type_name.yy \
	$(TOPSRCDIR)/c/y/c.grammer.type_qualifier_list.yy \
	$(TOPSRCDIR)/c/y/c.grammer.type_qualifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.type_specifier.yy \
	$(TOPSRCDIR)/c/y/c.grammer.unary_expr.yy \
	$(TOPSRCDIR)/c/y/c.grammer.unary_operator.yy \
	$(SRCDIR)/y/cpp.grammer.control_line.yy \
	$(SRCDIR)/y/cpp.grammer.elif_groups.yy \
	$(SRCDIR)/y/cpp.grammer.elif_group.yy \
	$(SRCDIR)/y/cpp.grammer.else_group.yy \
	$(SRCDIR)/y/cpp.grammer.endif_line.yy \
	$(SRCDIR)/y/cpp.grammer.group_part.yy \
	$(SRCDIR)/y/cpp.grammer.group.yy \
	$(SRCDIR)/y/cpp.grammer.if_group.yy \
	$(SRCDIR)/y/cpp.grammer.if_section.yy \
	$(SRCDIR)/y/cpp.grammer.new_line.yy \
	$(SRCDIR)/y/cpp.grammer.non_directive.yy \
	$(SRCDIR)/y/cpp.grammer.pp_tokens.yy \
	$(SRCDIR)/y/cpp.grammer.preprocessing_file.yy \
	$(SRCDIR)/y/cpp.grammer.preprocessing_token.yy \
	$(SRCDIR)/y/cpp.grammer.replacement_list.yy \
	$(SRCDIR)/y/cpp.grammer.text_line.yy \
	$(SRCDIR)/y/cpp.grammer.white_space.yy \
	$(SRCDIR)/y/cpp.grammer.yy \
	$(SRCDIR)/y/cpp.parser.yy \
	$(SRCDIR)/y/cpp.tokens.yy \
	$(SRCDIR)/y/cpp.types.yy

LS = 	$(TOPSRCDIR)/l/digit.l \
	$(TOPSRCDIR)/l/lexer.l \

$(OBJDIR)/cpp.o : $(SRCDIR)/cpp.h $(SRCDIR)/cpp.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $(SRCDIR)/cpp.cpp

$(OBJDIR)/driver.o : $(TOPSRCDIR)/con/driver.cpp $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/l -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/lang_driver.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/lang_driver.cpp

$(OBJDIR)/oparser.o : $(OBJDIR)/parser.tab.cc $(TOPSRCDIR)/con/oparser.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(TOPSRCDIR)/con/oparser.cpp

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(YYS)
	$(LYPP) -I $(TOPSRCDIR)/y -I $(TOPSRCDIR)/c/y -I $(SRCDIR)/y $(LYPP_FLAGS) $(SRCDIR)/y/cpp.parser.yy > $@

$(OBJDIR)/pt.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/pt.cpp

$(OBJDIR)/cpp: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

