#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	int* elementos;

	if(argc!=5){
		printf("Error en el numero de parametros\n");
		exit(-1);
	}
	reservarVector(&elementos,atoi(argv[2]));

	rellenaVector(elementos,atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));

	rellenaFichero(elementos,atoi(argv[2]),argv[1]);

	free(elementos);
}