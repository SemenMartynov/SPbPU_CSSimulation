
#include "Study/RStdy/RStdyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************

//********************************************************
//RStdyRangeStudy Constructor
//********************************************************
RStdyRangeStudy::RStdyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 0;
  NumExps = 1;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];

  // create the arrays to store the values of each gv

  // call methods to assign values to each gv
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//RStdyRangeStudy Destructor
//******************************************************
RStdyRangeStudy::~RStdyRangeStudy() {
  delete ThePVModel;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void RStdyRangeStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *RStdyRangeStudy::GetGVValue(char *TheGVName) {
  
    cerr<<"!! RStdyRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void RStdyRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  
    cerr<<"!! RStdyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void RStdyRangeStudy::SetGVs(int expNum) {
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new RStdyRangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* RStdyRangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new TransportVarsPVModel(expandTimeArrays);
  return ThePVModel;
}


