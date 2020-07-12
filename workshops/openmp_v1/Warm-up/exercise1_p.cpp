# include <stdio.h>
// Aqúi debe importar la libreria de openMP

/* Función Principal */
int main(int argc, char *argv[]){

	/* Esto se ejecuta secuencialmente */
	
	// Aqui debe inicializar la región paralela
	printf("%s\n","Hola Mundo");
	// Aqui debe terminar la región paralela

	/* Esto se ejecuta secuencialmente */	

}