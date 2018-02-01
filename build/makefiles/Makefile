TOP=../..
include $(TOP)/build/makefiles/Makefile.pre.inc

SUB=.
SOBJS=${OBJ}/cpu.o \
	${OBJ}/cmdline.o \
	${OBJ}/forth.o \
	${OBJ}/lang.o \
	${OBJ}/main.o \

TARGET=$(OBJ)/nuf1
DEBUG_TARGET=$(OBJ)/nuf1.debug
MEMSAN_TARGET=$(OBJ)/nuf1.memsan
UBSAN_TARGET=$(OBJ)/nuf1.ubsan
SCAN_TARGET=$(OBJ)/nuf1.scan

INC+=$(LLVM_INC)
CXXFLAGS+=$(LLVM_CXXFLAGS)

LDFLAGS+=-L$(OBJ)/scan -L$(OBJ)/parse -L$(OBJ)/ast -L$(OBJ)/visitors
LDFLAGS+=$(LLVM_LDFLAGS)

LIBS+=-lscan -lparse -lutil -last -lvisitors
LIBS+=$(LLVM_LIBS)

DEBUG_LIBS+=-lscan.debug -lparse.debug -last.debug -lvisitors.debug
DEBUG_LIBS+=$(LLVM_LIBS)

MEMSAN_LIBS+=-lscan.memsan -lparse.memsan -last.memsan -lvisitors.memsan
MEMSAN_LIBS+=$(LLVM_LIBS)

UBSAN_LIBS+=-lscan.ubsan -lparse.ubsan -last.ubsan -lvisitors.ubsan
UBSAN_LIBS+=$(LLVM_LIBS)

all: $(TARGET) $(DEBUG_TARGET) $(MEMSAN_TARGET)
nuf1 : $(TARGET)
nuf1.debug : $(DEBUG_TARGET)
nuf1.memsan : $(MEMSAN_TARGET)
nuf1.ubsan : $(UBSAN_TARGET)
nuf1.scan : $(SCAN_TARGET)

SUBDIRS = parse scan ast visitors runtime

include $(TOP)/build/makefiles/MakeMacros

$(TARGET) : suball $(OBJS) 
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(DEBUG_TARGET) : suball $(DEBUG_OBJS) 
	$(LD) $(LDFLAGS) $(DEBUG_OBJS) $(DEBUG_LIBS) -o $@

$(MEMSAN_TARGET) : suball $(MEMSAN_OBJS) 
	$(LD) $(LDFLAGS) $(MEMSAN_FLAGS) $(MEMSAN_OBJS) $(MEMSAN_LIBS) -o $@

$(UBSAN_TARGET) : suball $(UBSAN_OBJS) 
	$(LD) $(LDFLAGS) $(UBSAN_FLAGS) $(UBSAN_OBJS) $(UBSAN_LIBS) -o $@

$(SCAN_TARGET) : suball $(SCAN_OBJS) 


clean : subclean
	- rm -rf $(OBJ)/*

format : subformat
	- $(FORMAT) -i ${SRC}/*.cpp
	- $(FORMAT) -i ${_INC}/*.h
