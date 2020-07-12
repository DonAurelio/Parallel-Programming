# include <stdio.h>
# include <omp.h>
# define N 10

 main(int argc, char *argv[]) {

	 /* Suma del anterior con el siguiente */
	 /* Resultado secuencial */
	 int r_s[N] = {1,2,3,4,5,6,7,8,9,10};
	 int i;

	 /* Suma del anterior con el siguiente algoritmo secuencial*/
	 for(i=1;i<N;i++){
	 	r_s[i] = r_s[i-1] + r_s[i];
	 }

	 printf("%s\n","Resultado algoritmo secuencial");
	 for(i=0;i<N;i++){
	 	printf("%d\n",r_s[i]);
	 }



	 /* Suma del anterior con el siguiente algorimo paralelo */
	 /* Resultado paralelo */
	 int r_p[N] = {1,2,3,4,5,6,7,8,9,10};
	 int j;

	 #pragma omp parallel for private(j) shared(r_p)
	 for(j=1;j<N;j++){
	 	r_p[j] = r_p[j-1] + r_p[j];
	 }

	 printf("%s\n","Resultado algoritmo paralelo");
	 for(j=0;j<N;j++){
	 	printf("%d\n",r_p[j]);
	 }




 }