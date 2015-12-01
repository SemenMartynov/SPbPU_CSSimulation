OBJS=TransportVarsPVNodes.o TransportVarsPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libTransportVarsPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libTransportVarsPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libTransportVarsPV.a: FORCE
	$(MAKE) lib TARGET=libTransportVarsPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libTransportVarsPV_debug.a: FORCE
	$(MAKE) lib TARGET=libTransportVarsPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

