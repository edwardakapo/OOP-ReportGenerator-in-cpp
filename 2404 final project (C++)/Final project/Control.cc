#include "Control.h"

Control::Control()
{
  ReportGenerator::loadRecords();
  behaviour1 = new DescBehaviour<float>();
  ReportGenerator* report1 = new RegionalBreakdownReport(behaviour1);
  reports.push_back(report1);

  behaviour2 = new AscBehaviour<float>();
  ReportGenerator* report2 = new PercentageBreakDownReport(behaviour2);
  reports.push_back(report2);

  behaviour3 = new DescBehaviour<int>();
  ReportGenerator* report3 = new HorsesAndPoniesByRegionReport(behaviour3);
  reports.push_back(report3);

}
Control::~Control()
{
}
void Control::launch()
{
  int choice = 1;
  while(choice != 0)
  {
  menu.showMenu(choice);
    if(choice == 1)
    {
      reports[choice -1]->compute();
      reports[choice -1]->printReport();
      reports[choice -1]->cleanup();

    }
    else if(choice == 2)
    {
      reports[choice -1]->compute();
      reports[choice -1]->printReport();
      reports[choice -1]->cleanup();

    }
    else if(choice == 3)
    {
      reports[choice -1]->compute();
      reports[choice -1]->printReport();
      reports[choice -1]->cleanup();

    }
  }
  ReportGenerator::cleanUp();
  for(int i = 0 ; i < reports.size() ; ++i)
  {
    delete reports[i];
  }
  delete behaviour1;
  delete behaviour2;
  delete behaviour3;




}
