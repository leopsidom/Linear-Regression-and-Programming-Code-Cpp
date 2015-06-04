#include<iostream>
#include "CalResult.cpp"
#include<string>
using namespace std;

int main()
{
  vector <double> p;
  string filename;
  int novariable;

  cout<<"Type in the complete csv file name:"<<" "<<'\n';
  cin>>filename;
  CalResult(filename.c_str(),p,&novariable);
   for (int i=0; i<novariable;i++)
  {
    cout<<"linear coefficient for variable "<<i+1<<" (column "<<i+1<<") is "<<p[2*i]<<'\n';
  }
}
