 # include <stdio.h>
 # include <omp.h>

 main(int argc, char *argv[]) {

 int x;
 x = 0;

 #pragma omp parallel shared(x) num_threads(1000)
   { /* Inicio de la region paralela  */

 	// cada hilo suma 1 a x
   	x = x + 1;

   } /* Fin de la region paralera */

   printf("Suma total %d\n",x);

 }