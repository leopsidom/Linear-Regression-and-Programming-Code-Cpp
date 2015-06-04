/* demo.c */

#include "lp_lib.h"
#include<string>
#include<vector>
#include<iostream>
#include "readcsv.cpp"
//using nampespace std;

int demo()
{
  lprec *lp;
  int Ncol, *colno = NULL, j, ret = 0, novariable, dim;
  REAL *row = NULL;
  string filename;
  std::vector <std::vector <int> > CoeffMatrix;  
  
  std::cout<<"Type in the csv file name which consists of the coefficient matrix"<<'\n';
  std::cin>>filename;
  readcsv(filename.c_str(),CoeffMatrix, &dim, &novariable);
  /* We will build the model row by row
     So we start with creating a model with 0 rows and 2 columns */
  Ncol = novariable; /* there are two variables in the model */
  cout<<Ncol<<'\n';
  lp = make_lp(0, Ncol);
  if(lp == NULL)
    ret = 1; /* couldn't construct a new model... */

  if(ret == 0) {
    /* let us name our variables. Not required, but can be useful for debugging */
    for(int i=0;i<Ncol; i++)
    {set_col_name(lp, i+1,"C1");}
    
    /* create space large enough for one row */
    colno = (int *) malloc(Ncol * sizeof(*colno));
    row = (REAL *) malloc(Ncol * sizeof(*row));
    if((colno == NULL) || (row == NULL))
      ret = 2;
  }

  if(ret == 0) {
    set_add_rowmode(lp, TRUE);  
  }/* makes building the model faster if it is done rows by row */

  for(int m=1 ; m<dim; m++){
   
    if(ret == 0){
 
    /* construct mth rows  */
      j = 0;
      for( int n=0; n < novariable; n++){

        colno[j] = n+1; /* nth column */
        row[j] = CoeffMatrix[m][j];
        j++;

      }
    
     /* add the row constraint to lpsolve */
    if(!add_constraintex(lp, j, row, colno, LE, CoeffMatrix[m][novariable]))
      ret = 3;
   }
  }

  

  if(ret == 0) {
    set_add_rowmode(lp, FALSE); /* rowmode should be turned off again when done building the model */

    /* set the objective function (143 x + 60 y) */
    j = 0;

    for( int n=0; n < novariable; n++){

      colno[j] = n+1; /* mth column */
      row[j] = CoeffMatrix[0][j];
      j++;

      }

    /* set the objective in lpsolve */
    if(!set_obj_fnex(lp, j, row, colno))
      ret = 4;
  }

  if(ret == 0) {
    /* set the object direction to maximize */
    set_maxim(lp);

    /* show the model in lp format on screen */
    write_LP(lp, stdout);
    write_lp(lp, "model.lp"); 

    /* I only want to see important messages on screen while solving */
    set_verbose(lp, IMPORTANT);

    /* Now let lpsolve calculate a solution */
    ret = solve(lp);
    if(ret == OPTIMAL)
      ret = 0;
    else
      ret = 5;
  }

  if(ret == 0) {
    /* print results */

    /* objective value */
    printf("Objective value: %f\n", get_objective(lp));

    /* variable values */
    get_variables(lp, row);
    for(j = 0; j < Ncol; j++)
      printf("%s: %f\n", get_col_name(lp, j + 1), row[j]);
  }

  /* free allocated memory */
  if(row != NULL)
    free(row);
  if(colno != NULL)
    free(colno);

  if(lp != NULL) {
    delete_lp(lp);
  }

  return(ret);
}

int main()
{
  demo();
}
