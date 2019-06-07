#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void reservarVector(int** elementos, int nElem){
	
	printf("El numero de elementos es: %i\n\n",nElem );
	if((*elementos=(int*)calloc(nElem,sizeof(int)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}
}

void rellenaVector(int* vector, int nElem, int limSup, int limInf){

	int num;
	srand(time(NULL));

	for(int i=0; i<nElem; i++){
		num=limInf+rand()%(limSup+1-limInf);
		vector[i]=num;
		printf("Numero v[%i] introducido: %i\n",i,vector[i]);
	}
	printf("\n");
}

void rellenaFichero(int* vector,int nElem, char* nombreFichero){

	FILE* f;

	if((f=fopen(nombreFichero,"wb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	fwrite(vector, sizeof(int), nElem, f);

	fclose(f);


}
