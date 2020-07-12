# include <stdio.h> /* Libreria para imprimir por consola */
# include <omp.h> /* Libreria para importar OpenMP */
# define VUELTAS_A_LA_PISTA 1000 /* tamaño de los vectores */

int main(int argc, char *argv[]) {

int thread_id = 0;
int thread_laps = 0;
int i = 0;

printf("Ha iniciado la carrera de hilos, cada hilo debe dar %d vueltas a la pista\n",VUELTAS_A_LA_PISTA);

#pragma omp parallel private(thread_id,i,thread_laps) num_threads(8)
 { /* Inicio de la region paralela */
	
	
	for(i=0;i<VUELTAS_A_LA_PISTA;i++){
		thread_laps = thread_laps + 1;
	}
	
	thread_id = omp_get_thread_num();

	#pragma omp single
	{
		printf("El hilo número %d llego primero a la meta y dío %d vueltas\n",thread_id,thread_laps);
	}

 
 }  /* fin de la region paralela */

}