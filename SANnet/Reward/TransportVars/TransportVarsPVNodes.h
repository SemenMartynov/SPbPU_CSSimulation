#ifndef _TRANSPORTVARS_PVS_
#define _TRANSPORTVARS_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Transport/TransportSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class TransportVarsPV0Worker:public InstantOfTime
{
 public:
  TransportSAN *Transport;
  
  TransportVarsPV0Worker();
  ~TransportVarsPV0Worker();
  double Reward_Function();
};

class TransportVarsPV0:public PerformanceVariableNode
{
 public:
  TransportSAN *TheTransportSAN;

  TransportVarsPV0Worker *TransportVarsPV0WorkerList;

  TransportVarsPV0(int timeindex=0);
  ~TransportVarsPV0();
  void CreateWorkerList(void);
};

class TransportVarsPV1Worker:public InstantOfTime
{
 public:
  TransportSAN *Transport;
  
  TransportVarsPV1Worker();
  ~TransportVarsPV1Worker();
  double Reward_Function();
};

class TransportVarsPV1:public PerformanceVariableNode
{
 public:
  TransportSAN *TheTransportSAN;

  TransportVarsPV1Worker *TransportVarsPV1WorkerList;

  TransportVarsPV1(int timeindex=0);
  ~TransportVarsPV1();
  void CreateWorkerList(void);
};

class TransportVarsPV2Worker:public InstantOfTime
{
 public:
  TransportSAN *Transport;
  
  TransportVarsPV2Worker();
  ~TransportVarsPV2Worker();
  double Reward_Function();
};

class TransportVarsPV2:public PerformanceVariableNode
{
 public:
  TransportSAN *TheTransportSAN;

  TransportVarsPV2Worker *TransportVarsPV2WorkerList;

  TransportVarsPV2(int timeindex=0);
  ~TransportVarsPV2();
  void CreateWorkerList(void);
};

#endif
