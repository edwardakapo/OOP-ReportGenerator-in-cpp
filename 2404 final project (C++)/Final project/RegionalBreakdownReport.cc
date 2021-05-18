#include "RegionalBreakdownReport.h"

RegionalBreakdownReport::RegionalBreakdownReport(CompareBehaviour<float>* compare)
{
  data = new ReportData<float>(compare);
}
RegionalBreakdownReport::~RegionalBreakdownReport()
{
  delete data;
}

void RegionalBreakdownReport::compute()
{
  Map<string>& regionMapCopy = ReportGenerator::regionMap;
  Map<string>& animalMapCopy = ReportGenerator::animalMap;

vector<string>& animalKeys = animalMapCopy.getKeys();
vector<string>& regionMapCopyKeys = regionMapCopy.getKeys();
vector<vector<float>> numFarmsByRegion;
vector<string> regionKeys;

for(int i = 0 ; i < regionMapCopyKeys.size() ; ++i)
{
  if(regionMapCopyKeys[i] != "CAN")
  {
    regionKeys.push_back(regionMapCopyKeys[i]);
  }
}

for(int i = 0 ; i < regionKeys.size() ; ++i)
{
  try {
    vector<Record*>& holder = regionMapCopy[regionKeys[i]];
    fillTotals(animalKeys, numFarmsByRegion , holder );
  }
  catch(string str) {
    cout<<endl<< "Error! "<< str <<endl<<endl;
    return;
  }
}

int totalFarms;
vector<float> totalsByAnimal;
for(int i = 0 ; i < animalKeys.size() ; ++i)
{
  totalsByAnimal.push_back(0);
}
getTotals(totalFarms, totalsByAnimal, numFarmsByRegion);

for(int i = 0 ; i < regionKeys.size() ; ++i)
{

  formatData(regionKeys[i],numFarmsByRegion[i], totalFarms, totalsByAnimal);
}
}

void RegionalBreakdownReport::getTotals(int &total, vector<float> &totalbyAnimals , vector<vector<float>> &arr) const
{
  int sum = 0;

  for(int j = 0 ; j < totalbyAnimals.size() ; ++j)
  {
    for(int i = 0 ; i < arr.size() ; ++i)
    {
      totalbyAnimals.at(j) += arr.at(i).at(j);
    }

  }
  for(int i = 0 ; i < arr.size() ; ++i)
  {
    sum += sumRow(arr[i]);
  }
  total = sum;
}

void RegionalBreakdownReport::formatData(string region , vector<float> &row, int total , vector<float> &totalByAnimal)
{
 string dataString;
 float percentTotal;

percentTotal = sumRow(row)/total * 100.0f;
 dataString += region;
 for(int i = 0 ; i < row.size() ; i++)
 {
  if(totalByAnimal[i] > 0){
   float temp = (row[i] / totalByAnimal[i]) * 100.0f ;
   formatString(dataString, temp);
  }
  else
  {
    formatString(dataString, 0.0f);
  }
 }
formatString(dataString, percentTotal);
  data->add(percentTotal , dataString);
}

void RegionalBreakdownReport::formatString(string &s, float x) const
{
  string temp;
  ostringstream ss;
  ss<<setw(13)<< setprecision(1)<<fixed<<x;
  s = s + ss.str();
}

void RegionalBreakdownReport::printReport() const
{
  Map<string>& animalMapCopy = ReportGenerator::animalMap;
  vector<string>& animalKeys = animalMapCopy.getKeys();

  string header;
  ostringstream ss;
  ss <<setw(80) << "PERCENTAGE OF FARMS BY REGION IN 2016"<<endl;
  ss<<setw(80) << "--------------------------------------"<<endl<<endl;
  ss<<"    ";
  for(int i = 0 ; i < animalKeys.size() ; ++i)
  {
    ss<<"   "<<animalKeys[i];
  }
  ss<<"       "<<"TOTAL";
  header += ss.str();


  cout<<endl<< header<<endl<<endl;
  cout<<(*data);

  ofstream reportFile;
  reportFile.open(FILENAME_A);
  reportFile<<endl<< header<<endl<<endl;
  reportFile <<(*data);
  reportFile.close();
}

void RegionalBreakdownReport::fillTotals(vector<string> &animalKeys , vector<vector<float>> &arr, vector<Record*> &records) const
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

      if(records[j]->getYear() == YEAR_X && records[j]->getSubRegion() == "All" && records[j]->getAnimalType() == animalKeys.at(i))
      {
        temp[i] = records[j]->getNumFarms();
      }
    }
  }
  arr.push_back(temp);;
}


float RegionalBreakdownReport::sumRow(vector<float> &row) const
{
  float sum = 0;
  for(int i = 0  ; i < row.size() ; ++i)
  {
    sum += row[i];
  }
  return sum;
}

void RegionalBreakdownReport::cleanup()
{
  data->cleanup();
}
