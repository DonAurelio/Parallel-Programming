# include <stdio.h> /* Libreria para imprimir por consola */
# include <omp.h> /* Libreria para importar OpenMP */
# define N 1000 /* tamaño de los vectores */

int main(int argc, char *argv[]) {

int i;
float a[N], b[N], c[N], d[N];

/* Inicializaciń de los vectores a y b */
for (i=0; i < N; i++) {
 a[i] = i * 2;
 b[i] = i + 4;
 }

#pragma omp parallel shared(a,b,c,d) private(i) 
 { /* Inicio de la region paralela */

 #pragma omp sections nowait
   { /* inicio de las secciones */

   #pragma omp section
   for (i=0; i < N; i++)
     c[i] = a[i] + b[i];

   #pragma omp section
   for (i=0; i < N; i++)
     d[i] = a[i] * b[i];

   }  /* fin de las secciones */

 }  /* fin de la region paralela */

}
