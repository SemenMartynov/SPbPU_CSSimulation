OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lsimMain
MAINLIB_debug=-lsimMain_debug
SIMLIB=sim
SIMLIB_debug=sim_debug
SIMLIB_trace=sim_trace
PROJECTLIBS=-lRStdyRangeStudy -lTransportVarsPV -lTransportSAN 
PROJECTLIBS_debug=-lRStdyRangeStudy_debug -lTransportVarsPV_debug -lTransportSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
SimTransSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=SimTransSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
SimTransSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=SimTransSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
SimTransSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=SimTransSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/Transport/ && $(MAKE) clean
	cd ../../Reward/TransportVars/ && $(MAKE) clean
	cd ../../Study/RStdy/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[Transport]"
	cd ../../Atomic/Transport/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[TransportVars]"
	cd ../../Reward/TransportVars/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[RStdy]"
	cd ../../Study/RStdy/ && $(MAKE) $(@F)


