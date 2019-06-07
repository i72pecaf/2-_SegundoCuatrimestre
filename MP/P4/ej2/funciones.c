#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>


int mayor(int a, int b){
	if(a>b){
		return 1;
	} else {
		return 0;
	}
}

int menor(int a, int b){
	if(a<b){
		return 1;
	} else {
		return 0;
	}
}

void contarRegistros(char* fichero,int* nElem){

	FILE* f;

	if((f=fopen(fichero,"rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	fseek(f,0L,SEEK_END);

	*nElem=ftell(f)/sizeof(struct alumno);

	fclose(f);
}


void reservarMemoriaVector(struct alumno** vector,int nElem){

	if((*vector=(struct alumno*)calloc(nElem,sizeof(struct alumno)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}

	printf("\nMemoria reservada!\n\n");
}


void rellenarVector(struct alumno* vector,int nElem,char* fichero){
	FILE* f;
	
	if((f=fopen(fichero,"rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}


	fread(vector,sizeof(struct alumno),nElem,f);

	fclose(f);
}


void ordenaVectorBurbuja(struct alumno* vector,int nElem, int (*comparar) (int,int)){
	struct alumno aux;
	for(int i=0;i<nElem-1;i++){
		for(int j=0;j<nElem-i-1;j++){
			if(((*comparar) (vector[j].DNI,vector[j+1].DNI))==1){
				aux=vector[j+1];		//Repasar esto, no ordena bien
				vector[j+1]=vector[j];
				vector[j]=aux;
			}
		}
	}
}
