TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/c
SRCDIR= $(TOPSRCDIR)/c

LYPP_FLAGS+=-Dc99 -Dc11

all: dirs $(OBJDIR)/cc1

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

OBJS =	$(OBJDIR)/driver.o \
	$(OBJDIR)/c.lexer.o \
	$(OBJDIR)/cc1.o \
	$(OBJDIR)/lang_driver.o \
	$(OBJDIR)/parser.o \
	$(OBJDIR)/oparser.o \
	$(OBJDIR)/ping.o \
	$(OBJDIR)/chk.o \
	$(OBJDIR)/cg.o \
	$(OBJDIR)/typedefs.o \
	$(OBJDIR)/n.o \
	$(OBJDIR)/pt.o \
	$(OBJDIR)/ast.o \
	$(OBJDIR)/type.o \
	$(OBJDIR)/scope.o \
	$(TOPOBJDIR)/pt/n.o \
	$(TOPOBJDIR)/con/m.o

YYS =	$(TOPSRCDIR)/y/directives.yy \
	$(TOPSRCDIR)/y/error.yy \
	$(TOPSRCDIR)/y/override.yy \
	$(TOPSRCDIR)/y/preamble.yy \
	$(TOPSRCDIR)/y/tokens.yy \
	$(SRCDIR)/y/c.grammer.abstract_array_declarator.yy \
	$(SRCDIR)/y/c.grammer.abstract_declarator.yy \
	$(SRCDIR)/y/c.grammer.abstract_function_declarator.yy \
	$(SRCDIR)/y/c.grammer.additive_expr.yy \
	$(SRCDIR)/y/c.grammer.alignment_specifier.yy \
	$(SRCDIR)/y/c.grammer.and_expr.yy \
	$(SRCDIR)/y/c.grammer.argument_expr_list.yy \
	$(SRCDIR)/y/c.grammer.array_declarator.yy \
	$(SRCDIR)/y/c.grammer.assignment_expr.yy \
	$(SRCDIR)/y/c.grammer.assignment_operator.yy \
	$(SRCDIR)/y/c.grammer.atomic_type_specifier.yy \
	$(SRCDIR)/y/c.grammer.block_item_list.yy \
	$(SRCDIR)/y/c.grammer.block_item.yy \
	$(SRCDIR)/y/c.grammer.cast_expr.yy \
	$(SRCDIR)/y/c.grammer.character_constant.yy \
	$(SRCDIR)/y/c.grammer.compound_statement.yy \
	$(SRCDIR)/y/c.grammer.conditional_expr.yy \
	$(SRCDIR)/y/c.grammer.constant_expr.yy \
	$(SRCDIR)/y/c.grammer.constant.yy \
	$(SRCDIR)/y/c.grammer.declaration_list.yy \
	$(SRCDIR)/y/c.grammer.declaration_specifiers.yy \
	$(SRCDIR)/y/c.grammer.declaration.yy \
	$(SRCDIR)/y/c.grammer.declarator.yy \
	$(SRCDIR)/y/c.grammer.direct_abstract_declarator.yy \
	$(SRCDIR)/y/c.grammer.direct_declarator.yy \
	$(SRCDIR)/y/c.grammer.enumeration_constant.yy \
	$(SRCDIR)/y/c.grammer.enumerator_list.yy \
	$(SRCDIR)/y/c.grammer.enumerator.yy \
	$(SRCDIR)/y/c.grammer.enum_specifier.yy \
	$(SRCDIR)/y/c.grammer.equality_expr.yy \
	$(SRCDIR)/y/c.grammer.exclusive_or_expr.yy \
	$(SRCDIR)/y/c.grammer.expression_statement.yy \
	$(SRCDIR)/y/c.grammer.expr.yy \
	$(SRCDIR)/y/c.grammer.external_definition.yy \
	$(SRCDIR)/y/c.grammer.floating_constant.yy \
	$(SRCDIR)/y/c.grammer.function_body.yy \
	$(SRCDIR)/y/c.grammer.function_declarator.yy \
	$(SRCDIR)/y/c.grammer.function_definition.yy \
	$(SRCDIR)/y/c.grammer.function_specifier.yy \
	$(SRCDIR)/y/c.grammer.generic_association.yy \
	$(SRCDIR)/y/c.grammer.generic_assoc_list.yy \
	$(SRCDIR)/y/c.grammer.generic_selection.yy \
	$(SRCDIR)/y/c.grammer.identifier_list.yy \
	$(SRCDIR)/y/c.grammer.identifier.yy \
	$(SRCDIR)/y/c.grammer.inclusive_or_expr.yy \
	$(SRCDIR)/y/c.grammer.init_declarator_list.yy \
	$(SRCDIR)/y/c.grammer.init_declarator.yy \
	$(SRCDIR)/y/c.grammer.initializer_list.yy \
	$(SRCDIR)/y/c.grammer.initializer.yy \
	$(SRCDIR)/y/c.grammer.integer_constant.yy \
	$(SRCDIR)/y/c.grammer.iteration_statement.yy \
	$(SRCDIR)/y/c.grammer.jump_statement.yy \
	$(SRCDIR)/y/c.grammer.labeled_statement.yy \
	$(SRCDIR)/y/c.grammer.logical_and_expr.yy \
	$(SRCDIR)/y/c.grammer.logical_or_expr.yy \
	$(SRCDIR)/y/c.grammer.multiplicative_expr.yy \
	$(SRCDIR)/y/c.grammer.parameter_declaration.yy \
	$(SRCDIR)/y/c.grammer.parameter_list.yy \
	$(SRCDIR)/y/c.grammer.parameter_type_list.yy \
	$(SRCDIR)/y/c.grammer.pointer.yy \
	$(SRCDIR)/y/c.grammer.postfix_expr.yy \
	$(SRCDIR)/y/c.grammer.primary_expr.yy \
	$(SRCDIR)/y/c.grammer.relation_expr.yy \
	$(SRCDIR)/y/c.grammer.selection_statement.yy \
	$(SRCDIR)/y/c.grammer.shift_expr.yy \
	$(SRCDIR)/y/c.grammer.specifier_qualifier_list.yy \
	$(SRCDIR)/y/c.grammer.statement_list.yy \
	$(SRCDIR)/y/c.grammer.statement.yy \
	$(SRCDIR)/y/c.grammer.static_assert_declaration.yy \
	$(SRCDIR)/y/c.grammer.storage_class_specifier.yy \
	$(SRCDIR)/y/c.grammer.string_literal.yy \
	$(SRCDIR)/y/c.grammer.struct_declaration_list.yy \
	$(SRCDIR)/y/c.grammer.struct_declaration.yy \
	$(SRCDIR)/y/c.grammer.struct_declarator_list.yy \
	$(SRCDIR)/y/c.grammer.struct_declarator.yy \
	$(SRCDIR)/y/c.grammer.struct_or_union_specifier.yy \
	$(SRCDIR)/y/c.grammer.struct_or_union.yy \
	$(SRCDIR)/y/c.grammer.translation_unit.yy \
	$(SRCDIR)/y/c.grammer.typedef_name.yy \
	$(SRCDIR)/y/c.grammer.type_name.yy \
	$(SRCDIR)/y/c.grammer.type_qualifier_list.yy \
	$(SRCDIR)/y/c.grammer.type_qualifier.yy \
	$(SRCDIR)/y/c.grammer.type_specifier.yy \
	$(SRCDIR)/y/c.grammer.unary_expr.yy \
	$(SRCDIR)/y/c.grammer.unary_operator.yy \
	$(SRCDIR)/y/c.grammer.yy \
	$(SRCDIR)/y/c.parser.yy \
	$(SRCDIR)/y/c.postamble.yy \
	$(SRCDIR)/y/c.tokens.yy \
	$(SRCDIR)/y/c.types.yy

LS = 	$(TOPSRCDIR)/l/digit.l \
	$(TOPSRCDIR)/l/lexer.l \
	$(SRCDIR)/l/c.constant.l \
	$(SRCDIR)/l/c.identifier.l \
	$(SRCDIR)/l/c.lexer.l \
	$(SRCDIR)/l/c.string_literal.l \
	$(SRCDIR)/l/c.whitespace.l

$(OBJDIR)/driver.o : $(TOPSRCDIR)/con/driver.cpp $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/l -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/c.lexer.o : $(OBJDIR)/c.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/c.lexer.yy.cc : $(OBJDIR)/c.lexer.l 
	$(LEX) --outfile=$@ $<

$(OBJDIR)/c.lexer.l : $(LS) $(OBJDIR)/parser.tab.cc
	$(LYPP) -q -I$(TOPSRCDIR)/l -I$(SRCDIR)/l $(SRCDIR)/l/c.lexer.l > $@

$(OBJDIR)/cc1.o : $(SRCDIR)/cc1.h $(SRCDIR)/cc1.opt $(SRCDIR)/cc1.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/cc1.cpp

$(OBJDIR)/lang_driver.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/lang_driver.cpp

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(YYS)
	$(LYPP) -I $(TOPSRCDIR)/y -I $(SRCDIR)/y $(LYPP_FLAGS) $(SRCDIR)/y/c.parser.yy > $@

$(OBJDIR)/n.o : $(SRCDIR)/pt/n.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/chk.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/v/chk.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/v/chk.cpp

$(OBJDIR)/cg.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/v/cg.h $(SRCDIR)/pt/v/cg.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/fig -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/v/cg.cpp

$(OBJDIR)/ping.o : $(OBJDIR)/parser.tab.cc $(TOPSRCDIR)/pt/v/ping.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(TOPSRCDIR)/pt/v/ping.cpp

$(OBJDIR)/typedefs.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/v/typedefs.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/v/typedefs.cpp

$(OBJDIR)/pt.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/pt.cpp

$(OBJDIR)/ast.o : $(TOPSRCDIR)/at/ast.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/type.o : $(TOPSRCDIR)/at/type.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/scope.o : $(TOPSRCDIR)/at/scope.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/oparser.o : $(OBJDIR)/parser.tab.cc $(TOPSRCDIR)/con/oparser.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(TOPSRCDIR)/con/oparser.cpp

$(OBJDIR)/cc1: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) -L$(TOPOBJDIR)/fig -lfig $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)

