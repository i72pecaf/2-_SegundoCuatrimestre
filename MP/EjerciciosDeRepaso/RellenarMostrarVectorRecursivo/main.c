#include "funciones.h"
#include <stdio.h>

int main(){

	int nElem;
	int* v;
	printf("Introduce el numero de elementos del vector\n");
	scanf("%i",&nElem);

	reservaMemoriaVector(&v,nElem);

	rellenaVectorRecursivo(v, nElem);
	printf("Vector rellenado!\n");
	muestraVectorRecursivo(v, nElem);
/*
	for(int i=0 ; i<nElem ; i++){
		printf("v[%i] = %i\n",i,v[i] );
	}
*/
}