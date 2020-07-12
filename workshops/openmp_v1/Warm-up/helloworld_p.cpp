# include <stdio.h> /* Libreria para imprimir por consola */
# include <omp.h> /* Libreria para importar OpenMP */

/* Función Principal */
int main(int argc, char *argv[]){

	/* Esto se ejecuta secuencialmente */

	/* sentinela = #pragma omp, directiva = parallel  [clausula, ....] */
	#pragma omp parallel 
	{ /* Inicio de la region paralela FORK */

	/*Esto se ejecuta en paralelo*/
		
	printf("%s\n","Hola Mundo");

	/*Esto se ejecuta en paralelo*/

	} /* Fin de la region paralera JOIN */

	/* Esto se ejecuta secuencialmente */

}
