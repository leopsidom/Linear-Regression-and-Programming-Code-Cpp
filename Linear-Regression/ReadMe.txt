This folder contains the files needed to solve the linear regression problem.

Usage:
Compile coefficient.cpp or prediction.cpp based on what you want to see, run the executable and type in the complete name of the csv files.

--------------------------------------------------------------------
readcsv.cpp
--------------------------------------------------------------------
readcsv.cpp reads a standard .csv file and return a two dimensional 
array. In order for the csv file be read correctly, it must be arranged in such a way:

1) Every column holds for one variable or the response value;
2) Data starts from the first column and there should no blank columns between variables or response value;
3) Extra rows for name of variables should also be removed;
4) Response value comes as the last column after all the independt variables;

--------------------------------------------------------------------
CalResult.cpp
--------------------------------------------------------------------
CalResult.cpp do the regression calculation. where 

Sx=sum((xi-xbar)^2) and Sxy=sum((xi-xbar)*(yi-ybar))
slope=Sxy/Sx

The coefficients are calculated for each variable respectively.

---------------------------------------------------------------------
coefficient.cpp
---------------------------------------------------------------------
call the above two cpp files and print the coefficients on screen

---------------------------------------------------------------------
prediction.cpp
---------------------------------------------------------------------
Based on the coefficient and mean value returned by CalResult function, prediction.cpp calculate the intercept of the fit function and further predict the response value at the coordinates received from outside.

---------------------------------------------------------------------
ProblemData1.csv and ProblemData2.csv are the rearranged datasets from the excel datasets for question 1.



 










