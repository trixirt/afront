TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/fig
SRCDIR= $(TOPSRCDIR)/fig
VISIBILITY=

all: dirs $(OBJDIR)/figc1

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

LOBJS = $(OBJDIR)/fig.o \
	$(OBJDIR)/lang_driver.o \
	$(OBJDIR)/ping.o \
	$(OBJDIR)/oparser.o \
	$(OBJDIR)/fig.lexer.o \
	$(OBJDIR)/parser.o \
	$(OBJDIR)/driver.o \
	$(OBJDIR)/pt.o \
	$(OBJDIR)/n.o \
	$(OBJDIR)/m.o

OBJS = 	$(OBJDIR)/figc1.o

YYS =	$(TOPSRCDIR)/y/directives.yy \
	$(TOPSRCDIR)/y/error.yy \
	$(TOPSRCDIR)/y/override.yy \
	$(TOPSRCDIR)/y/preamble.yy \
	$(TOPSRCDIR)/y/tokens.yy \
	$(SRCDIR)/y/fig.grammer.abi.yy \
	$(SRCDIR)/y/fig.grammer.configuration.yy \
	$(SRCDIR)/y/fig.grammer.constant_list.yy \
	$(SRCDIR)/y/fig.grammer.constant.yy \
	$(SRCDIR)/y/fig.grammer.data_layout.yy \
	$(SRCDIR)/y/fig.grammer.endian.yy \
	$(SRCDIR)/y/fig.grammer.language_type_list.yy \
	$(SRCDIR)/y/fig.grammer.language_type.yy \
	$(SRCDIR)/y/fig.grammer.layout_option_list.yy \
	$(SRCDIR)/y/fig.grammer.layout_option.yy \
	$(SRCDIR)/y/fig.grammer.mangle.yy \
	$(SRCDIR)/y/fig.grammer.object_class.yy \
	$(SRCDIR)/y/fig.grammer.object_list.yy \
	$(SRCDIR)/y/fig.grammer.object.yy \
	$(SRCDIR)/y/fig.grammer.stack.yy \
	$(SRCDIR)/y/fig.grammer.string_constant.yy \
	$(SRCDIR)/y/fig.grammer.triple.yy \
	$(SRCDIR)/y/fig.grammer.yy \
	$(SRCDIR)/y/fig.parser.yy \
	$(SRCDIR)/y/fig.tokens.yy \
	$(SRCDIR)/y/fig.types.yy

LS = 	$(TOPSRCDIR)/l/digit.l \
	$(TOPSRCDIR)/c/l/c.constant.l \
	$(TOPSRCDIR)/c/l/c.identifier.l \
	$(TOPSRCDIR)/c/l/c.whitespace.l \
	$(SRCDIR)/l/fig.lexer.l

$(OBJDIR)/driver.o : $(TOPSRCDIR)/co/driver.cpp $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBILITY) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/l -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/fig.lexer.o : $(OBJDIR)/fig.lexer.yy.cc
	$(CXX) -o $@ $(CXXFLAGS) $(TOOL_INCLUDES) $(VISIBLITY) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/fig.lexer.yy.cc : $(OBJDIR)/fig.lexer.l $(OBJDIR)/parser.tab.cc
	$(LEX) --outfile=$@ $<

$(OBJDIR)/fig.lexer.l : $(LS) $(SRCDIR)/l/fig.lexer.l 
	$(LYPP) -I$(TOPSRCDIR)/l -I$(SRCDIR)/l -I$(TOPSRCDIR)/c/l  $(SRCDIR)/l/fig.lexer.l > $@

$(OBJDIR)/fig.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/fig.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(SRCDIR) -I$(OBJDIR) -c $(SRCDIR)/fig.cpp

$(OBJDIR)/figc1.o : $(SRCDIR)/figc1.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(LLVM_INCLUDEDIR) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $<

$(OBJDIR)/lang_driver.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/lang_driver.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(SRCDIR)/pt -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/lang_driver.cpp

$(OBJDIR)/m.o : $(TOPSRCDIR)/co/m.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $<

$(OBJDIR)/n.o : $(TOPSRCDIR)/pt/n.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $<

$(OBJDIR)/oparser.o : $(OBJDIR)/parser.tab.cc $(TOPSRCDIR)/co/oparser.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $(TOPSRCDIR)/co/oparser.cpp

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(YYS)
	$(LYPP) -I $(TOPSRCDIR)/y -I $(SRCDIR)/y $(LYPP_FLAGS) $(SRCDIR)/y/fig.parser.yy > $@

$(OBJDIR)/ping.o : $(OBJDIR)/parser.tab.cc $(TOPSRCDIR)/pt/v/ping.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(TOPSRCDIR)/pt/v/ping.cpp

$(OBJDIR)/pt.o : $(SRCDIR)/pt/pt.h $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(VISIBLITY) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(SRCDIR) -c $(SRCDIR)/pt/pt.cpp

$(OBJDIR)/libfig.so : $(LOBJS)
	$(LD) -Wl,-z,defs -shared -o $@ $(LOBJS) $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) 

$(OBJDIR)/figc1: $(OBJS) $(OBJDIR)/libfig.so
	$(LD) -o $@ $(LDFLAGS) $(OBJS) -L$(OBJDIR) -lfig $(LLVM_LIBS) $(LLVM_SYSTEM_LIBS) $(LIBS)



