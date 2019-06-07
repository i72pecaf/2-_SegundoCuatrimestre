#include "funciones.h"
#include <stdio.h>
	
int main(){

	int* v;
	int nElem;	

	printf("Introduce el numero de elementos\n");
	scanf("%i",&nElem);

	reservaMemoriaVector(&v,nElem);

	printf("Introduce los elementos\n");
	for(int i=0; i<nElem ; i++){
		scanf("%i",&v[i]);
	}

	burbuja(v,nElem);


	for(int i=0; i<nElem ; i++){
		printf("v[%i] = %i\n",i,v[i] );
	}
}