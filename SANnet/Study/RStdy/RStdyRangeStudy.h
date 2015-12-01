
#ifndef RStdyRangeSTUDY_H_
#define RStdyRangeSTUDY_H_

#include "Reward/TransportVars/TransportVarsPVNodes.h"
#include "Reward/TransportVars/TransportVarsPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"


class RStdyRangeStudy : public BaseStudyClass {
public:

RStdyRangeStudy();
~RStdyRangeStudy();

private:



void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

