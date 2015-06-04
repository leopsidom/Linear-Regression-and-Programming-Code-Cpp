This folder contains the files that are needed to solve the linear programming problem.

Usage:
Set the run path:
Firstly put the directory path of the lib folder under LD_LIBRARY_PATH name. You can do this by adding the line below in the .bashrc file.

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:Dir/problem2/lib 

where Dir is the directory where the problem2 folder is.

Compilation:
g++ -o main main.cpp Dir/problem2/lib/liblpsolve55.so

Run main as executable and type in the complete file name of the csv file which contains the coefficient matrix.

Files:
---------------------------------------------------------------------
main.cpp
---------------------------------------------------------------------
main.cpp takes in the coefficient matrix csv file and transform it into the format which then is read and solved by lp_solver. It will print the model both on the screen and into a file called "model.lp". 
The optimization result will also be printed out.

----------------------------------------------------------------------
readcsv.cpp
----------------------------------------------------------------------
Read csv file into a two dimensional array and return the number of variable as well as the number of rows.

----------------------------------------------------------------------
CoeffMatrix.csv
----------------------------------------------------------------------
Contains the coefficient matrix derived from the problem, where the first row contains the objective function which I need to maximize and the last column contains the constrains value. Beside these two, the remaining block of the matrix contains the coefficient of the constrain inequality.

-----------------------------------------------------------------------
.h
-----------------------------------------------------------------------
Files with an extension of .h are header files needed by main.cpp( the lp solver )

-----------------------------------------------------------------------
lib
-----------------------------------------------------------------------
Contains the shared library file for the lp solver.

-----------------------------------------------------------------------
Output variable
-----------------------------------------------------------------------
The output variables are in the same order as given by Demand Forcasts table, ie the topmost will be variable C1 and the bottom will be variable C30 for question 2 and C90 for question 3.

































