#include "vectores.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void reservaVector(int** v,int nElem){

	if((*v=(int*)calloc(nElem,sizeof(int)))==NULL){
		printf("Error al reservar memoria\n");
	}
}

void rellenaVector(int* v, int nElem){

	srand(time(NULL));

	for(int i=0; i<nElem;i++){
		v[i]=1+rand()%10;
	}

}


void muestraVector(int* v, int nElem){

	if(nElem>0){
		muestraVector(v,nElem-1);
		printf("v[%i]=%i\n",nElem-1,v[nElem-1] );
	}
}