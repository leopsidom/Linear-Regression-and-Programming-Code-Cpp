#include<iostream>
#include<vector>
#include<string>
#include"CalResult.cpp"
using namespace std;


int main()
{
  double intercept, prediction;
  vector <double> p, coordinates;
  int novariable;
  string filename;
  cout<<"Type in the complete csv file name: "<<'\n';
  cin>>filename;
  CalResult(filename.c_str(),p,&novariable);
  
  coordinates.resize(novariable);
  intercept=p[2*novariable];
  for(int i=0; i<novariable; i++)
  {
    intercept-=p[2*i]*p[2*i+1];
  }
  cout<<intercept<<'\n';
  prediction=intercept;
  for(int i=0; i<novariable; i++)
  {
    cout<<"Type in your No "<<i+1<<" coordinate: "<<'\n';
    cin>>coordinates[i];
    prediction+=coordinates[i]*p[2*i];
    cout<<p[2*i]<<'\n';
   }
  cout<<"The predicted value for your coordinates are: "<<prediction<<'\n';
}
