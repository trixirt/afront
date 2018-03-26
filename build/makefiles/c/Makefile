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


$(OBJDIR)/driver.o : $(TOPSRCDIR)/con/driver.cpp $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/l -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/c.lexer.o : $(OBJDIR)/c.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/c.lexer.yy.cc : $(OBJDIR)/c.lexer.l 
	$(LEX) --outfile=$@ $<

$(OBJDIR)/c.lexer.l : $(SRCDIR)/l/c.lexer.l $(OBJDIR)/parser.tab.cc
	$(LYPP) -I$(SRCDIR)/l $< > $@

$(OBJDIR)/cc1.o : $(SRCDIR)/cc1.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/lang_driver.o : $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(SRCDIR)/y/c.parser.yy
	$(LYPP) -I $(SRCDIR)/y $(LYPP_FLAGS) $< > $@

$(OBJDIR)/n.o : $(SRCDIR)/pt/n.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/chk.o : $(SRCDIR)/pt/v/chk.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/cg.o : $(SRCDIR)/pt/v/cg.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/ping.o : $(SRCDIR)/pt/v/ping.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/typedefs.o : $(SRCDIR)/pt/v/typedefs.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/pt.o : $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/ast.o : $(TOPSRCDIR)/at/ast.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/type.o : $(TOPSRCDIR)/at/type.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/scope.o : $(TOPSRCDIR)/at/scope.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/oparser.o : $(SRCDIR)/oparser.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/cc1: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)

