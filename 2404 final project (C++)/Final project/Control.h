#ifndef CONTROL_H
#define CONTROL_H

#include "HorsesAndPoniesByRegionReport.h"
#include "RegionalBreakdownReport.h"
#include "PercentageBreakDownReport.h"
#include "ReportGenerator.h"
#include "View.h"

// Control class uses a vector of reports and some CompareBehaviour pointers that are allocated in the constructor
class Control
{
  public:
    Control();
    ~Control();
    void launch();
  private:
    View menu;
    vector<ReportGenerator*> reports;
    CompareBehaviour<float>* behaviour1;
    CompareBehaviour<float>* behaviour2;
    CompareBehaviour<int>* behaviour3;

};

#endif
