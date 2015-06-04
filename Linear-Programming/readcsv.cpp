#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<stdlib.h>
using namespace std;

void readcsv(const string &filename, vector< vector<int> >& Data, int* dim, int* novariable )
{
  Data.clear();
  ifstream myfile(filename.c_str());
  vector <vector <string> > data;
  string line;
  
  
  if (myfile.is_open())
  {
    while(getline (myfile,line))
    { 
      
      istringstream ss(line);
      string s;
      vector <string> record;
      
      while(getline(ss,s,','))
      {
        record.push_back(s);
       }
         
      data.push_back(record);
    }
    myfile.close();
    
  }

  else cout << "Unable to open file"; 
  
  *dim=data.size();
  *novariable=data[0].size()-1;
  Data.resize(data.size());
  for(int j=0; j<data.size(); j++)
  {
    Data[j].resize(data[0].size());
    for(int i=0; i<data[0].size(); i++)
    {
     Data[j][i]=atoi(data[j][i].c_str()); 
      
    } 
  }
  
}



