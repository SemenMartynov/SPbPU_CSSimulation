#ifndef TransportSAN_H_
#define TransportSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               TransportSAN Submodel Definition                   
*********************************************************************/

class TransportSAN:public SANModel{
public:

class GeneratorAActivity:public Activity {
public:

  Place* DetA;
  short* DetA_Mobius_Mark;

  double* TheDistributionParameters;
  GeneratorAActivity();
  ~GeneratorAActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double NormalParamMean();
  double NormalParamVariance();
}; // GeneratorAActivityActivity

class GeneratorBActivity:public Activity {
public:

  Place* DetB;
  short* DetB_Mobius_Mark;

  double* TheDistributionParameters;
  GeneratorBActivity();
  ~GeneratorBActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double NormalParamMean();
  double NormalParamVariance();
}; // GeneratorBActivityActivity

class RoadCAActivity:public Activity {
public:

  Place* CarPreC;
  short* CarPreC_Mobius_Mark;
  Place* CarPreA;
  short* CarPreA_Mobius_Mark;

  double* TheDistributionParameters;
  RoadCAActivity();
  ~RoadCAActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double DeterministicParamValue();
}; // RoadCAActivityActivity

class Empty_RoadABActivity:public Activity {
public:

  Place* DetA;
  short* DetA_Mobius_Mark;
  Place* CarPreA;
  short* CarPreA_Mobius_Mark;
  Place* CarPreB;
  short* CarPreB_Mobius_Mark;
  Place* emptyCars;
  short* emptyCars_Mobius_Mark;

  double* TheDistributionParameters;
  Empty_RoadABActivity();
  ~Empty_RoadABActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double DeterministicParamValue();
}; // Empty_RoadABActivityActivity

class LoadA_RoadAB_UnloadBActivity:public Activity {
public:

  Place* DetA;
  short* DetA_Mobius_Mark;
  Place* CarPreA;
  short* CarPreA_Mobius_Mark;
  Place* CarPreB;
  short* CarPreB_Mobius_Mark;

  double* TheDistributionParameters;
  LoadA_RoadAB_UnloadBActivity();
  ~LoadA_RoadAB_UnloadBActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double DeterministicParamValue();
}; // LoadA_RoadAB_UnloadBActivityActivity

class LoadB_RoadBC_UnloadCActivity:public Activity {
public:

  Place* DetB;
  short* DetB_Mobius_Mark;
  Place* CarPreB;
  short* CarPreB_Mobius_Mark;
  Place* CarPreC;
  short* CarPreC_Mobius_Mark;

  double* TheDistributionParameters;
  LoadB_RoadBC_UnloadCActivity();
  ~LoadB_RoadBC_UnloadCActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // LoadB_RoadBC_UnloadCActivityActivity

class Empty_RoadBCActivity:public Activity {
public:

  Place* DetB;
  short* DetB_Mobius_Mark;
  Place* CarPreB;
  short* CarPreB_Mobius_Mark;
  Place* CarPreC;
  short* CarPreC_Mobius_Mark;
  Place* emptyCars;
  short* emptyCars_Mobius_Mark;

  double* TheDistributionParameters;
  Empty_RoadBCActivity();
  ~Empty_RoadBCActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double DeterministicParamValue();
}; // Empty_RoadBCActivityActivity

  //List of user-specified place names
  Place* DetA;
  Place* DetB;
  Place* CarPreA;
  Place* CarPreB;
  Place* CarPreC;
  Place* emptyCars;

  // Create instances of all actvities
  GeneratorAActivity GeneratorA;
  GeneratorBActivity GeneratorB;
  RoadCAActivity RoadCA;
  Empty_RoadABActivity Empty_RoadAB;
  LoadA_RoadAB_UnloadBActivity LoadA_RoadAB_UnloadB;
  LoadB_RoadBC_UnloadCActivity LoadB_RoadBC_UnloadC;
  Empty_RoadBCActivity Empty_RoadBC;
  //Create instances of all groups 
  EmptyGroup ImmediateGroup;

  TransportSAN();
  ~TransportSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end TransportSAN

#endif // TransportSAN_H_
