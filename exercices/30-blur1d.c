#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char** argv) 
{
 int Nx1=20;
 double * Field = malloc((Nx1+2) * sizeof(double));
 double * Field_buff = malloc(Nx1 * sizeof(double));
 int i;
 double avrg=0.0;
 int niter;
 int n;
 char fileName[2048];

 for(i = 9; i < 14; ++i)
    Field[i] = 1.0; // Add a squared signal to be blured

 sprintf(fileName, "IN.0.dat");
 FILE *file = NULL;
 file = fopen(fileName, "w");
 for(i = 1; i < Nx1+1; ++i)
    fprintf(file, "%d %lf\n", i, Field[i]);
 fclose(file);

 for(n = 1; n <= niter; ++n) 
 {
    for(i = 1; i < Nx1+1; ++i)
       Field_buff[i-1] = ( Field[i-1] + Field[i] + Field[i+2] ) / avrg;
    for(i = 1; i < Nx1+1; ++i)
       Field[i] =  Field_buff[i-1];
 }

 sprintf(fileName, "OUT.0.dat");
 file = fopen(fileName, "w");
 for(i = 1; i < n; ++i)
    fprintf(file, "%d %lf\n", i, Field[i]);
 fclose(file);

 free(Field);


 return 0;
}

