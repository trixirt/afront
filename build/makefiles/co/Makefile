TOP = ../../..
include $(TOP)/build/makefiles/Makefile.pre.inc
TOPOBJDIR= $(TOP)/obj
TOPSRCDIR= $(TOP)/src
OBJDIR= $(TOPOBJDIR)/co
SRCDIR= $(TOPSRCDIR)/co

OBJS = $(OBJDIR)/m.o

all: dirs $(OBJS)

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)

.PHONY: clean
clean: dirs
	- rm $(OBJDIR)/*

$(OBJDIR)/m.o : $(SRCDIR)/m.cpp
	$(CXX) -o $@ $(CXXFLAGS) -I$(TOPSRCDIR) -c $<


