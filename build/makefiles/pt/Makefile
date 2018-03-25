TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/pt
SRCDIR= $(TOPSRCDIR)/pt

OBJS = $(OBJDIR)/n.o

all: dirs $(OBJS)

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

$(OBJDIR)/n.o : $(SRCDIR)/n.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -c $<


