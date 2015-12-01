#ifndef _TRANSPORTVARS_PVMODEL_
#define _TRANSPORTVARS_PVMODEL_
#include "TransportVarsPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Transport/TransportSAN.h"
class TransportVarsPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  TransportVarsPVModel(bool expandtimepoints);
};

#endif
