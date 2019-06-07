#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>


void reservaMemoria(int** vector, int nElem){

	if((*vector=(int*)calloc(nElem,sizeof(int)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}

	printf("Memoria reservada!\n\n");
}

int calcularRegistros(char* fichero){

	FILE* f;
	long tam;
	int num;

	if((f=fopen(fichero,"rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	if(fseek(f, 0L, SEEK_END)){
		printf("Error al usar el fichero con seek\n");
		exit(-1);
	}
	

	tam=ftell(f);
	num=tam/sizeof(int);

	printf("El numero de registros es: %ld\n\n", ftell(f)/sizeof(int));

	fclose(f);

	return num;
}


void leerFicheroAvector(int* vector, char* fichero){

	FILE* f;
	int i=0;
	int aux;

	if((f=fopen(fichero,"rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while((fread(&aux,sizeof(int),1,f))==1){
		vector[i]=aux;
		i++;
	}

	fclose(f);

}

void calcularMedia(int* vector, int nElem){

	float suma=0;
	float contador=0;
	float media=0;

	for(int i=0; i<nElem; i++){
		if((vector[i]%2)==0){
			suma=suma+vector[i];
			contador++;
		}
	}

	if(contador==0){
		printf("No hay numeros divisibles entre 2\n");
	} else {
		media=suma/contador;
		printf("La media de los elementos divisibles entre dos es: %f \n", media);	
	}

}