OBJS=RStdyRangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRStdyRangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRStdyRangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRStdyRangeStudy.a: FORCE
	$(MAKE) lib TARGET=libRStdyRangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRStdyRangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libRStdyRangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

