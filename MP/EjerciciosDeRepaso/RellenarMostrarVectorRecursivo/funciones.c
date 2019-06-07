#include "funciones.h"
#include "stdlib.h"
#include "stdio.h"

void reservaMemoriaVector(int** v,int nElem){
	if((*v=(int*)calloc(nElem,sizeof(int)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}
	printf("\nMemoria reservada\n");
}


void rellenaVectorRecursivo(int* v,int nElem){
	if(nElem>0){
		rellenaVectorRecursivo(v,nElem-1);
		scanf("%i",&v[nElem-1]);
	}
}


void muestraVectorRecursivo(int* v, int nElem){
	if(nElem>0){
		muestraVectorRecursivo(v,nElem-1);
		printf("v[%i] = %i\n",nElem-1, v[nElem-1] );
	}
}