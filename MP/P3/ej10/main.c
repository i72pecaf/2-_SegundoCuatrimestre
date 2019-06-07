#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]){

	int numRegistros;
	int* vector;

	if(argc!=2){
		printf("Error con el numero de argumentos, debes de introducir la ruta al ejecutar el programa\n");
		exit(-1);
	}

	numRegistros=calcularRegistros(argv[1]);

	reservaMemoria(&vector, numRegistros);

	leerFicheroAvector(vector,argv[1]);

	printf("\nVoy a recorrer el vector\n");
	for(int i=0; i<numRegistros; i++){
		printf("Elemento v[%i]: %i\n",i,vector[i]);
	}

	calcularMedia(vector, numRegistros);
}