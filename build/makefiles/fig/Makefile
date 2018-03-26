TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/fig
SRCDIR= $(TOPSRCDIR)/fig

all: dirs $(OBJDIR)/figc1

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

OBJS = 	$(TOPOBJDIR)/con/m.o \
	$(TOPOBJDIR)/pt/n.o \
	$(OBJDIR)/driver.o \
	$(OBJDIR)/fig.lexer.o \
	$(OBJDIR)/figc1.o \
	$(OBJDIR)/lang_driver.o \
	$(OBJDIR)/parser.o \
	$(OBJDIR)/pt.o \

$(OBJDIR)/driver.o : $(TOPSRCDIR)/con/driver.cpp $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/l -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/fig.lexer.o : $(OBJDIR)/fig.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/fig.lexer.yy.cc : $(OBJDIR)/fig.lexer.l $(OBJDIR)/parser.tab.cc
	$(LEX) --outfile=$@ $<

$(OBJDIR)/fig.lexer.l : $(SRCDIR)/l/fig.lexer.l 
	$(LYPP) -I$(SRCDIR)/l -I$(TOPSRCDIR)/c/l  $< > $@

$(OBJDIR)/figc1.o : $(SRCDIR)/figc1.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $<

$(OBJDIR)/lang_driver.o : $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<

$(OBJDIR)/parser.yy : $(SRCDIR)/y/fig.parser.yy
	$(LYPP) -I $(SRCDIR)/y $(LYPP_FLAGS) $< > $@

$(OBJDIR)/pt.o : $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $<

$(OBJDIR)/figc1: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)

