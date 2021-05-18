#include "PercentageBreakDownReport.h"


PercentageBreakDownReport::PercentageBreakDownReport(CompareBehaviour<float>* compare)
{
  data = new ReportData<float>(compare);
}
PercentageBreakDownReport::~PercentageBreakDownReport()
{
  delete data;
}

void PercentageBreakDownReport::compute()
{
  Map<int>& yearMapCopy = ReportGenerator::yearMap;
  Map<string>& animalMapCopy = ReportGenerator::animalMap;

  vector<string>& animalKeys = animalMapCopy.getKeys();
  vector<vector<float>> numAnimalsbyYear;

  vector<int> years;
  years.push_back(YEAR_A);
  years.push_back(YEAR_B);

for(int i = 0 ; i < years.size() ; ++i)
{
  try {
    vector<Record*>& holder = yearMapCopy[years[i]];
    fillTotals(animalKeys, numAnimalsbyYear , holder ,years[i]);
  }
  catch(string str) {
    cout<<endl<< "Error! "<< str <<endl<<endl;
    return;
  }
}

calcuatePercentages(numAnimalsbyYear);
formatData(animalKeys,numAnimalsbyYear[0],numAnimalsbyYear[1]);
}

void PercentageBreakDownReport::calcuatePercentages(vector<vector<float>> &arr) const
{
  float totalForYr1;
  float totalForYr2;
    totalForYr1 = (sumRow(arr[0]));
    totalForYr2 = (sumRow(arr[1]));

    for(int i = 0 ; i < arr[0].size() ; ++i)
    {
     arr.at(0).at(i) =  (arr.at(0).at(i) / totalForYr1) * 100.0f;
    }
    for(int i = 0 ; i < arr[1].size() ; ++i)
    {
      arr.at(1).at(i) =  (arr.at(1).at(i) / totalForYr2) * 100.0f;
    }
}

void PercentageBreakDownReport::formatData(vector<string> &animalKeys, vector<float> &year1 , vector<float> &year2)
{

 for(int i = 0 ; i < animalKeys.size() ; ++i)
 {
   string dataString;
   float percentChange;
   percentChange = (year2[i] - year1[i]);
  formatString(dataString,animalKeys[i], year1[i] , year2[i] , percentChange);
  data->add(percentChange , dataString);
 }

}

void PercentageBreakDownReport::formatString(string &s, string animal ,float year1 , float year2 , float change) const
{
  ostringstream ss;
  ss <<setw(15) << animal;
  ss <<setw(10) << setprecision(1)<<fixed<<year1;
  ss <<setw(10) << setprecision(1)<<fixed<<year2;
  ss <<setw(10) << setprecision(1)<<fixed<<showpos<<change;
  s = s + ss.str();
}

void PercentageBreakDownReport::printReport() const
{
  string header;
  ostringstream ss;
  ss <<setw(55) << "PERCENTAGE CHANGE OF ANIMALS (2011 - 2016)"<<endl;
  ss<<setw(55) <<"------------------------------------------"<<endl<<endl;
  ss<<"                     "<< YEAR_A<<"      "<<YEAR_B<<"      "<<"Change";
  header += ss.str();
  cout<<endl<< header<<endl<<endl;
  cout<<(*data);

  ofstream reportFile;
  reportFile.open(FILENAME_B);
  reportFile<<endl<< header<<endl<<endl;
  reportFile <<(*data);
  reportFile.close();
}

void PercentageBreakDownReport::fillTotals(vector<string> &animalKeys , vector<vector<float>> &arr, vector<Record*> &records , int year) const
{
  vector<float> temp;
  for(int i = 0 ; i < animalKeys.size() ; ++i)
  {
    temp.push_back(0);
  }
  for(int i = 0 ; i < animalKeys.size() ; ++i)
  {
    for(int j = 0 ; j < records.size() ; ++j)
    {
      if(records[j]->getYear() == year && records[j]->getRegion() == "CAN" && records[j]->getAnimalType() == animalKeys.at(i))
      {
        temp[i] = records[j]->getNumAnimals();
      }
    }
  }
  arr.push_back(temp);;
}


float PercentageBreakDownReport::sumRow(vector<float> &row) const
{
  float sum = 0;
  for(int i = 0  ; i < row.size() ; ++i)
  {
    sum += row[i];
  }
  return sum;
}

void PercentageBreakDownReport::cleanup()
{
  data->cleanup();
}
