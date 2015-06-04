#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include "readcsv.cpp"
using namespace std;

void CalResult(const string &filename, vector<double>& CalResult, int* noVar)
{
 
  int novariable,dim;
  double xbar(0),ybar(0),Sx,Sxy,coefficient,sumx(0),
         sumy(0);
  vector< vector<double> > data;

  readcsv(filename.c_str(), data, &dim, &novariable);

  *noVar=novariable;
  CalResult.resize(2*novariable+1);
  
  for (int i=0; i<novariable; i++)
  {
    sumx=0; sumy=0; Sx=0; Sxy=0;
    for(int j=0; j<dim; j++)
    {
      sumx+=data[i][j];
      sumy+=data[novariable][j];
    }
      xbar=sumx/dim;
      ybar=sumy/dim;
      
   for(int j=0; j<dim; j++)
   {
     Sx+=pow(data[i][j]-xbar,2);
     Sxy+=(data[i][j]-xbar)*(data[novariable][j]-ybar);
   }
  
  
  coefficient=Sxy/Sx;
  CalResult[2*i]=coefficient;
  CalResult[2*i+1]=xbar;
  CalResult[2*novariable]=ybar;
  
  }
  
  
  
}


