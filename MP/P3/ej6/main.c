#include "funciones.h"
#include <stdio.h>


int main(){

	char nombreF[999];
	int nElem, nInf, nSup;

	printf("Introduce el nombre del fichero a crear: ");
	scanf("%s",nombreF);
	printf("\n");

	printf("Introduce el nombre de elementos del fichero: ");
	scanf("%i",&nElem);
	printf("\n");

	printf("Introduce el extremo inferior del rango de numeros ");
	scanf("%i",&nInf);
	printf("\n");

	printf("Introduce el extremo superior del rango de numeros ");
	scanf("%i",&nSup);
	printf("\n");


	crearFichero(nombreF, nElem, nInf, nSup);
}
