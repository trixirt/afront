TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/ada
SRCDIR= $(TOPSRCDIR)/ada

LYPP_FLAGS+=-Dada83

all: dirs $(OBJDIR)/ac1

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

OBJS =	$(OBJDIR)/ada.lexer.o \
	$(OBJDIR)/ac1.o \
	$(OBJDIR)/lang_driver.o \
	$(OBJDIR)/n.o \
	$(OBJDIR)/parser.o \
	$(TOPOBJDIR)/pt/n.o \
	$(TOPOBJDIR)/con/m.o

YYS =	$(TOPSRCDIR)/y/directives.yy \
	$(TOPSRCDIR)/y/error.yy \
	$(TOPSRCDIR)/y/override.yy \
	$(TOPSRCDIR)/y/preamble.yy \
	$(TOPSRCDIR)/y/tokens.yy \
	$(SRCDIR)/y/ada.directives.yy \
	$(SRCDIR)/y/ada.error.yy \
	$(SRCDIR)/y/ada.grammer.yy \
	$(SRCDIR)/y/ada.override.yy \
	$(SRCDIR)/y/ada.parser.yy \
	$(SRCDIR)/y/ada.preamble.yy \
	$(SRCDIR)/y/ada.tokens.yy \
	$(SRCDIR)/y/ada.types.yy

LS = 	$(TOPSRCDIR)/l/digit.l \
	$(TOPSRCDIR)/l/lexer.l \
	$(SRCDIR)/l/ada.identifier.l \
	$(SRCDIR)/l/ada.lexer.l \
	$(SRCDIR)/l/ada.numeric_literal.l

$(OBJDIR)/ada.lexer.o : $(OBJDIR)/ada.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/ada.lexer.yy.cc : $(OBJDIR)/ada.lexer.l 
	$(LEX) --outfile=$@ $<

$(OBJDIR)/ada.lexer.l : $(LS) $(OBJDIR)/parser.tab.cc
	$(LYPP) -q -I$(TOPSRCDIR)/l -I$(SRCDIR)/l $(SRCDIR)/l/ada.lexer.l > $@

$(OBJDIR)/ac1.o : $(SRCDIR)/ac1.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/lang_driver.o : $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/n.o : $(SRCDIR)/pt/n.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(YYS)
	$(LYPP) -I $(TOPSRCDIR)/y -I $(SRCDIR)/y $(LYPP_FLAGS) $(SRCDIR)/y/ada.parser.yy > $@

$(OBJDIR)/ac1: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)

