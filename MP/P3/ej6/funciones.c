#include "funciones.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void crearFichero(char* nombreF,int nElem,int nInf,int nSup){
	srand(time(NULL));
	int contador=0;
	int num;

	FILE* f;

	if((f=fopen(nombreF,"w"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while(contador!=nElem){

		num = nInf + rand()%(nSup+1-nInf);
		fprintf(f, "%i\n", num );	//Se va escribiendo linea a linea y se da un salto de linea, por el \n
		contador++;
	}

	fclose(f);
}