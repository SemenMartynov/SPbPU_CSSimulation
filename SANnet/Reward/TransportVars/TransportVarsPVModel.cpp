#include "TransportVarsPVModel.h"

TransportVarsPVModel::TransportVarsPVModel(bool expandTimeArrays) {
  TheModel=new TransportSAN();
  DefineName("TransportVarsPVModel");
  CreatePVList(3, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* TransportVarsPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new TransportVarsPV0(timeindex);
    break;
  case 1:
    return new TransportVarsPV1(timeindex);
    break;
  case 2:
    return new TransportVarsPV2(timeindex);
    break;
  }
  return NULL;
}
