#include "TransportVarsPVNodes.h"

TransportVarsPV0Worker::TransportVarsPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Transport);
}

TransportVarsPV0Worker::~TransportVarsPV0Worker() {
  delete [] TheModelPtr;
}

double TransportVarsPV0Worker::Reward_Function(void) {

return Transport->emptyCars->Mark();

return (0);



}

TransportVarsPV0::TransportVarsPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheTransportSAN);
  double startpts[6]={10000.0, 20000.0, 30000.0, 40000.0, 50000.0, 60000.0};
  double stoppts[6]={10000.0, 20000.0, 30000.0, 40000.0, 50000.0, 60000.0};
  Initialize("EmptyCars",(RewardType)0,6, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("emptyCars","Transport");
}

TransportVarsPV0::~TransportVarsPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void TransportVarsPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new TransportVarsPV0Worker;
}
TransportVarsPV1Worker::TransportVarsPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Transport);
}

TransportVarsPV1Worker::~TransportVarsPV1Worker() {
  delete [] TheModelPtr;
}

double TransportVarsPV1Worker::Reward_Function(void) {

return Transport->DetA->Mark();

return (0);



}

TransportVarsPV1::TransportVarsPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheTransportSAN);
  double startpts[3]={20000.0, 40000.0, 60000.0};
  double stoppts[3]={20000.0, 40000.0, 60000.0};
  Initialize("DetA",(RewardType)0,3, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("DetA","Transport");
}

TransportVarsPV1::~TransportVarsPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void TransportVarsPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new TransportVarsPV1Worker;
}
TransportVarsPV2Worker::TransportVarsPV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Transport);
}

TransportVarsPV2Worker::~TransportVarsPV2Worker() {
  delete [] TheModelPtr;
}

double TransportVarsPV2Worker::Reward_Function(void) {

return Transport->DetB->Mark();

return (0);



}

TransportVarsPV2::TransportVarsPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheTransportSAN);
  double startpts[3]={20000.0, 40000.0, 60000.0};
  double stoppts[3]={20000.0, 40000.0, 60000.0};
  Initialize("DetB",(RewardType)0,3, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("DetB","Transport");
}

TransportVarsPV2::~TransportVarsPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void TransportVarsPV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new TransportVarsPV2Worker;
}
