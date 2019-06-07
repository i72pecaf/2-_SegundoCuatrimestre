#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	float N;
	int opcion;

	float (*pf) (int);

	printf("Introduce el valor N\n");
	scanf("%f",&N);
	printf("------------------------------\n");
	printf("Introduce 1 para f(x)\n");
	printf("Introduce 2 para g(x)\n");
	printf("Introduce 3 para z(x)\n");
	scanf("%i",&opcion);
	printf("------------------------------\n");
	switch(opcion){

		case 1: 
				printf("\n");
				pf=&funcionF;
				for(int i=0;i<N;i++){
					printf("Resultado con x=%i: %f\n",i,pf(i));
				}
				printf("\n");
		break;


		case 2:

				printf("\n");
				pf=&funcionG;
				for(int i=0;i<N;i++){
					printf("Resultado con x=%i: %f\n",i,pf(i));
				}
				printf("\n");

		break;


		case 3:

				printf("\n");
				pf=&funcionZ;
				for(int i=0;i<N;i++){
					printf("Resultado con x=%i: %f\n",i,pf(i));
				}
				printf("\n");

		break;




	}
}