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
	$(OBJDIR)/parser.o \
	$(TOPOBJDIR)/pt/n.o \
	$(TOPOBJDIR)/con/m.o

$(OBJDIR)/ada.lexer.o : $(OBJDIR)/ada.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/ada.lexer.yy.cc : $(OBJDIR)/ada.lexer.l 
	$(LEX) --outfile=$@ $<

$(OBJDIR)/ada.lexer.l : $(SRCDIR)/l/ada.lexer.l $(OBJDIR)/parser.tab.cc
	$(LYPP) -I$(SRCDIR)/l $< > $@

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(SRCDIR)/y/ada.parser.yy
	$(LYPP) -I $(SRCDIR)/y $(LYPP_FLAGS) $< > $@

$(OBJDIR)/ac1: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)

