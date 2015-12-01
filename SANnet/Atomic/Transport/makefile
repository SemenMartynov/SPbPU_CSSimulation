OBJS=TransportSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libTransportSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libTransportSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libTransportSAN.a: FORCE
	$(MAKE) lib TARGET=libTransportSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libTransportSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libTransportSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

