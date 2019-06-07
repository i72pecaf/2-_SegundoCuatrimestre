#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){


	if(argc!=2){
		printf("Error en el numero de parametros\n");
		exit(-1);
	}
	
	cuentaPares(argv[1]);
}