# include <stdio.h> /* Libreria para imprimir por consola */
// Aqúi debe importar la libreria de openMP

/* Función Principal */
int main(int argc, char *argv[]){

	int numero_iteraciones = 20;
	int i = 0;
	// cree la variable thread_id he inicialisela en 0
	// cree la variable chunk_size he inicialisela en 3

	/* Esto se ejecuta secuencialmente */
	
	// Aqui debe inicializar la región paralela
	// cada hilo debe tener thread_id como variable privada
	
	// Aqui debe obtener el id del hilo

	// #pragma omp for private(i)
	// #pragma omp for private(i) schedule(static,chunk_size)
	// #pragma omp for private(i) schedule(dynamic,chunk_size)
	for(i=0;i<numero_iteraciones;i++){
		// Aqui debe imprimir el id del hilo y el i del ciclo
	}

	// Aqui debe terminar la región paralela

	/* Esto se ejecuta secuencialmente */	

}