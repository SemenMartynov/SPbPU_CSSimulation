

// This C++ file was created by SanEditor

#include "Atomic/Transport/TransportSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         TransportSAN Constructor             
******************************************************************/


TransportSAN::TransportSAN(){


  Activity* InitialActionList[7]={
    &GeneratorA, //0
    &GeneratorB, //1
    &RoadCA, //2
    &Empty_RoadAB, //3
    &LoadA_RoadAB_UnloadB, //4
    &LoadB_RoadBC_UnloadC, //5
    &Empty_RoadBC  // 6
  };

  BaseGroupClass* InitialGroupList[7]={
    (BaseGroupClass*) &(GeneratorA), 
    (BaseGroupClass*) &(GeneratorB), 
    (BaseGroupClass*) &(RoadCA), 
    (BaseGroupClass*) &(Empty_RoadAB), 
    (BaseGroupClass*) &(LoadA_RoadAB_UnloadB), 
    (BaseGroupClass*) &(LoadB_RoadBC_UnloadC), 
    (BaseGroupClass*) &(Empty_RoadBC)
  };

  DetA = new Place("DetA" ,0);
  DetB = new Place("DetB" ,0);
  CarPreA = new Place("CarPreA" ,8);
  CarPreB = new Place("CarPreB" ,0);
  CarPreC = new Place("CarPreC" ,0);
  emptyCars = new Place("emptyCars" ,0);
  BaseStateVariableClass* InitialPlaces[6]={
    DetA,  // 0
    DetB,  // 1
    CarPreA,  // 2
    CarPreB,  // 3
    CarPreC,  // 4
    emptyCars   // 5
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Transport", 6, InitialPlaces, 
                        0, InitialROPlaces, 
                        7, InitialActionList, 7, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[18][2]={ 
    {0,0}, {1,1}, {4,2}, {2,2}, {3,3}, {0,3}, {2,3}, {5,3}, {3,4}, 
    {0,4}, {2,4}, {4,5}, {1,5}, {3,5}, {4,6}, {1,6}, {3,6}, {5,6}
  };
  for(int n=0;n<18;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[9][2]={ 
    {4,2}, {0,3}, {2,3}, {0,4}, {2,4}, {1,5}, {3,5}, {1,6}, {3,6}
  };
  for(int n=0;n<9;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<7;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void TransportSAN::CustomInitialization() {

}
TransportSAN::~TransportSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void TransportSAN::assignPlacesToActivitiesInst(){
}
void TransportSAN::assignPlacesToActivitiesTimed(){
  GeneratorA.DetA = (Place*) LocalStateVariables[0];
  GeneratorB.DetB = (Place*) LocalStateVariables[1];
  RoadCA.CarPreC = (Place*) LocalStateVariables[4];
  RoadCA.CarPreA = (Place*) LocalStateVariables[2];
  Empty_RoadAB.DetA = (Place*) LocalStateVariables[0];
  Empty_RoadAB.CarPreA = (Place*) LocalStateVariables[2];
  Empty_RoadAB.CarPreB = (Place*) LocalStateVariables[3];
  Empty_RoadAB.emptyCars = (Place*) LocalStateVariables[5];
  LoadA_RoadAB_UnloadB.DetA = (Place*) LocalStateVariables[0];
  LoadA_RoadAB_UnloadB.CarPreA = (Place*) LocalStateVariables[2];
  LoadA_RoadAB_UnloadB.CarPreB = (Place*) LocalStateVariables[3];
  LoadB_RoadBC_UnloadC.DetB = (Place*) LocalStateVariables[1];
  LoadB_RoadBC_UnloadC.CarPreB = (Place*) LocalStateVariables[3];
  LoadB_RoadBC_UnloadC.CarPreC = (Place*) LocalStateVariables[4];
  Empty_RoadBC.DetB = (Place*) LocalStateVariables[1];
  Empty_RoadBC.CarPreB = (Place*) LocalStateVariables[3];
  Empty_RoadBC.CarPreC = (Place*) LocalStateVariables[4];
  Empty_RoadBC.emptyCars = (Place*) LocalStateVariables[5];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================GeneratorAActivity========================*/

TransportSAN::GeneratorAActivity::GeneratorAActivity(){
  TheDistributionParameters = new double[2];
  ActivityInitialize("GeneratorA",0,Normal, RaceEnabled, 1,0, false);
}

TransportSAN::GeneratorAActivity::~GeneratorAActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::GeneratorAActivity::LinkVariables(){
  DetA->Register(&DetA_Mobius_Mark);
}

bool TransportSAN::GeneratorAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(true);
  return NewEnabled;
}

double TransportSAN::GeneratorAActivity::NormalParamMean(){
  return 20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::GeneratorAActivity::NormalParamVariance(){
  return 3;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::GeneratorAActivity::Weight(){ 
  return 1;
}

bool TransportSAN::GeneratorAActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::GeneratorAActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::GeneratorAActivity::SampleDistribution(){
  return TheDistribution->Normal(20, 3);
}

double* TransportSAN::GeneratorAActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = NormalParamMean();
  TheDistributionParameters[1] = NormalParamVariance();
  return TheDistributionParameters;
}

int TransportSAN::GeneratorAActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::GeneratorAActivity::Fire(){
  (*(DetA_Mobius_Mark))++;
  return this;
}

/*======================GeneratorBActivity========================*/

TransportSAN::GeneratorBActivity::GeneratorBActivity(){
  TheDistributionParameters = new double[2];
  ActivityInitialize("GeneratorB",1,Normal, RaceEnabled, 1,0, false);
}

TransportSAN::GeneratorBActivity::~GeneratorBActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::GeneratorBActivity::LinkVariables(){
  DetB->Register(&DetB_Mobius_Mark);
}

bool TransportSAN::GeneratorBActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(true);
  return NewEnabled;
}

double TransportSAN::GeneratorBActivity::NormalParamMean(){
  return 20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::GeneratorBActivity::NormalParamVariance(){
  return 5;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::GeneratorBActivity::Weight(){ 
  return 1;
}

bool TransportSAN::GeneratorBActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::GeneratorBActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::GeneratorBActivity::SampleDistribution(){
  return TheDistribution->Normal(20, 5);
}

double* TransportSAN::GeneratorBActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = NormalParamMean();
  TheDistributionParameters[1] = NormalParamVariance();
  return TheDistributionParameters;
}

int TransportSAN::GeneratorBActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::GeneratorBActivity::Fire(){
  (*(DetB_Mobius_Mark))++;
  return this;
}

/*======================RoadCAActivity========================*/

TransportSAN::RoadCAActivity::RoadCAActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("RoadCA",2,Deterministic, RaceEnabled, 2,1, false);
}

TransportSAN::RoadCAActivity::~RoadCAActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::RoadCAActivity::LinkVariables(){
  CarPreC->Register(&CarPreC_Mobius_Mark);
  CarPreA->Register(&CarPreA_Mobius_Mark);
}

bool TransportSAN::RoadCAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(CarPreC_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TransportSAN::RoadCAActivity::DeterministicParamValue(){
  return 20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::RoadCAActivity::Weight(){ 
  return 1;
}

bool TransportSAN::RoadCAActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::RoadCAActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::RoadCAActivity::SampleDistribution(){
  return 20;
}

double* TransportSAN::RoadCAActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = DeterministicParamValue();
  return TheDistributionParameters;
}

int TransportSAN::RoadCAActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::RoadCAActivity::Fire(){
  (*(CarPreC_Mobius_Mark))--;
  (*(CarPreA_Mobius_Mark))++;
  return this;
}

/*======================Empty_RoadABActivity========================*/

TransportSAN::Empty_RoadABActivity::Empty_RoadABActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("Empty_RoadAB",3,Deterministic, RaceEnabled, 4,2, false);
}

TransportSAN::Empty_RoadABActivity::~Empty_RoadABActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::Empty_RoadABActivity::LinkVariables(){
  DetA->Register(&DetA_Mobius_Mark);
  CarPreA->Register(&CarPreA_Mobius_Mark);
  CarPreB->Register(&CarPreB_Mobius_Mark);
  emptyCars->Register(&emptyCars_Mobius_Mark);
}

bool TransportSAN::Empty_RoadABActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((!DetA->Mark() && CarPreA->Mark()));
  return NewEnabled;
}

double TransportSAN::Empty_RoadABActivity::DeterministicParamValue(){
  return 20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::Empty_RoadABActivity::Weight(){ 
  return 1;
}

bool TransportSAN::Empty_RoadABActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::Empty_RoadABActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::Empty_RoadABActivity::SampleDistribution(){
  return 20;
}

double* TransportSAN::Empty_RoadABActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = DeterministicParamValue();
  return TheDistributionParameters;
}

int TransportSAN::Empty_RoadABActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::Empty_RoadABActivity::Fire(){
  --DetA->Mark();
--CarPreA->Mark();
++emptyCars->Mark();
  (*(CarPreB_Mobius_Mark))++;
  return this;
}

/*======================LoadA_RoadAB_UnloadBActivity========================*/

TransportSAN::LoadA_RoadAB_UnloadBActivity::LoadA_RoadAB_UnloadBActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("LoadA_RoadAB_UnloadB",4,Deterministic, RaceEnabled, 3,2, false);
}

TransportSAN::LoadA_RoadAB_UnloadBActivity::~LoadA_RoadAB_UnloadBActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::LoadA_RoadAB_UnloadBActivity::LinkVariables(){
  DetA->Register(&DetA_Mobius_Mark);
  CarPreA->Register(&CarPreA_Mobius_Mark);
  CarPreB->Register(&CarPreB_Mobius_Mark);
}

bool TransportSAN::LoadA_RoadAB_UnloadBActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((DetA->Mark() && CarPreA->Mark()));
  return NewEnabled;
}

double TransportSAN::LoadA_RoadAB_UnloadBActivity::DeterministicParamValue(){
  return 20+30+20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::LoadA_RoadAB_UnloadBActivity::Weight(){ 
  return 1;
}

bool TransportSAN::LoadA_RoadAB_UnloadBActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::LoadA_RoadAB_UnloadBActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::LoadA_RoadAB_UnloadBActivity::SampleDistribution(){
  return 20+30+20;
}

double* TransportSAN::LoadA_RoadAB_UnloadBActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = DeterministicParamValue();
  return TheDistributionParameters;
}

int TransportSAN::LoadA_RoadAB_UnloadBActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::LoadA_RoadAB_UnloadBActivity::Fire(){
  --DetA->Mark();
--CarPreA->Mark();
  (*(CarPreB_Mobius_Mark))++;
  return this;
}

/*======================LoadB_RoadBC_UnloadCActivity========================*/

TransportSAN::LoadB_RoadBC_UnloadCActivity::LoadB_RoadBC_UnloadCActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("LoadB_RoadBC_UnloadC",5,Exponential, RaceEnabled, 3,2, false);
}

TransportSAN::LoadB_RoadBC_UnloadCActivity::~LoadB_RoadBC_UnloadCActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::LoadB_RoadBC_UnloadCActivity::LinkVariables(){
  DetB->Register(&DetB_Mobius_Mark);
  CarPreB->Register(&CarPreB_Mobius_Mark);
  CarPreC->Register(&CarPreC_Mobius_Mark);
}

bool TransportSAN::LoadB_RoadBC_UnloadCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((DetB->Mark() && CarPreB->Mark()));
  return NewEnabled;
}

double TransportSAN::LoadB_RoadBC_UnloadCActivity::Rate(){
  return 20+30+20;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::LoadB_RoadBC_UnloadCActivity::Weight(){ 
  return 1;
}

bool TransportSAN::LoadB_RoadBC_UnloadCActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::LoadB_RoadBC_UnloadCActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::LoadB_RoadBC_UnloadCActivity::SampleDistribution(){
  return TheDistribution->Exponential(20+30+20);
}

double* TransportSAN::LoadB_RoadBC_UnloadCActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int TransportSAN::LoadB_RoadBC_UnloadCActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::LoadB_RoadBC_UnloadCActivity::Fire(){
  --DetB->Mark();
--CarPreB->Mark();
  (*(CarPreC_Mobius_Mark))++;
  return this;
}

/*======================Empty_RoadBCActivity========================*/

TransportSAN::Empty_RoadBCActivity::Empty_RoadBCActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("Empty_RoadBC",6,Deterministic, RaceEnabled, 4,2, false);
}

TransportSAN::Empty_RoadBCActivity::~Empty_RoadBCActivity(){
  delete[] TheDistributionParameters;
}

void TransportSAN::Empty_RoadBCActivity::LinkVariables(){
  DetB->Register(&DetB_Mobius_Mark);
  CarPreB->Register(&CarPreB_Mobius_Mark);
  CarPreC->Register(&CarPreC_Mobius_Mark);
  emptyCars->Register(&emptyCars_Mobius_Mark);
}

bool TransportSAN::Empty_RoadBCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((!DetB->Mark() && CarPreB->Mark()));
  return NewEnabled;
}

double TransportSAN::Empty_RoadBCActivity::DeterministicParamValue(){
  return 30;
  return 1.0;  // default rate if none is specified
}

double TransportSAN::Empty_RoadBCActivity::Weight(){ 
  return 1;
}

bool TransportSAN::Empty_RoadBCActivity::ReactivationPredicate(){ 
  return false;
}

bool TransportSAN::Empty_RoadBCActivity::ReactivationFunction(){ 
  return false;
}

double TransportSAN::Empty_RoadBCActivity::SampleDistribution(){
  return 30;
}

double* TransportSAN::Empty_RoadBCActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = DeterministicParamValue();
  return TheDistributionParameters;
}

int TransportSAN::Empty_RoadBCActivity::Rank(){
  return 1;
}

BaseActionClass* TransportSAN::Empty_RoadBCActivity::Fire(){
  --DetB->Mark();
--CarPreB->Mark();
emptyCars->Mark();
  (*(CarPreC_Mobius_Mark))++;
  return this;
}

