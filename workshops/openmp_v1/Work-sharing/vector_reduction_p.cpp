# include <stdio.h> /* Libreria para imprimir por consola */
# include <omp.h> /* Libreria para importar OpenMP */
# define N 1000 /* tamaño del vector */

int main(int argc, char *argv[]){

	/* Declaracion del variables */
	int a[N];
	int i;
	int sum = 0;

	/* Inicialización del vector */
	for(i=0;i<N;i++){
		a[i] = i+1;
	}

	/* Reduccion */
	#pragma omp parallel for reduction(+:sum) private(i) shared(a)
	for(i=0;i<N;i++){
		sum = sum + a[i];
	}

	printf("Suma %d\n",sum);
}