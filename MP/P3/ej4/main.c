#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int num;

	if(argc!=2){
		printf("Error al introducir el numero de parametros al programa\n");
		exit(-1);
	}

	num=sumarDig(atoi(argv[1]));

	printf("La suma final es: %i \n",num );
}