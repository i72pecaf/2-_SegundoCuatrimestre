#include "vectores.h"
#include "orden.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	int* v;
	int nElem,o;

	int (*compara) (int,int);

	printf("\nIntroduce el numero de elementos del vector: ");
	scanf("%i",&nElem);

	reservaVector(&v,nElem);
	
	rellenaVector(v,nElem);

	printf("\n-- Vector sin ordenar --\n");
	muestraVector(v,nElem);
	printf("------------------------\n");

	printf("\nIntroduce 1 para ordenacion descendente, 2 para ascendente: ");
	scanf("%i",&o);

	if(o==1){
		compara=&menor;
	} else {
		compara=&mayor;
	}

	ordenaVector(v,nElem,compara);

	printf("\n-- Vector ordenado --\n");
	muestraVector(v,nElem);
	printf("---------------------\n\n");
}