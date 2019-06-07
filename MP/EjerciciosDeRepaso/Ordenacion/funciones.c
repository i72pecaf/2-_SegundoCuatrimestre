#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>

void reservaMemoriaVector(int** v, int nElem){
	if((*v=(int*)calloc(nElem,sizeof(int)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}
	printf("Memoria reservada\n");
}

void burbuja(int* v, int nElem){
	int aux;
	for(int i=0; i<nElem-1 ; i++){
		for(int j=0; j<nElem-i-1 ; j++){
			if(v[j]>v[j+1]){	//De menor a mayor
				aux=v[j+1];		//Cambiar el '>' del if
				v[j+1]=v[j];	//Para ser de mayor a menor
				v[j]=aux;
			}
		}
	}
}