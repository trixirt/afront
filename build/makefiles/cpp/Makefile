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
	$(OBJDIR)/parser.o \
	$(OBJDIR)/pt.o \


YYS =	$(TOPSRCDIR)/y/directives.yy \
	$(TOPSRCDIR)/y/error.yy \
	$(TOPSRCDIR)/y/override.yy \
	$(TOPSRCDIR)/y/preamble.yy \
	$(TOPSRCDIR)/y/tokens.yy \
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

$(OBJDIR)/parser.o : $(OBJDIR)/parser.tab.cc
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(TOPSRCDIR)/l -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(OBJDIR) -I$(SRCDIR) -c $<

$(OBJDIR)/parser.tab.cc : $(OBJDIR)/parser.yy
	$(YACC) -o $@ $(YACC_FLAGS) -d -v $<
	sed -e "s#private:#public:#g" < $(OBJDIR)/parser.tab.hh > $(OBJDIR)/parser.tab.hh.s
	mv $(OBJDIR)/parser.tab.hh.s $(OBJDIR)/parser.tab.hh

$(OBJDIR)/parser.yy : $(YYS)
	$(LYPP) -I $(TOPSRCDIR)/y -I $(SRCDIR)/y $(LYPP_FLAGS) $(SRCDIR)/y/cpp.parser.yy > $@

$(OBJDIR)/pt.o : $(OBJDIR)/parser.tab.cc $(SRCDIR)/pt/pt.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -I$(SRCDIR)/pt -I$(TOPSRCDIR)/pt -I$(TOPSRCDIR)/pt/v -I$(OBJDIR) -I$(SRCDIR) -c $(SRCDIR)/pt/pt.cpp

$(OBJDIR)/cpp: $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

