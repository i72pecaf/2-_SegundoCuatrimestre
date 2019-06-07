#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int num;

	if(argc!=3){
		printf("Error al introducir el numero de parametros al programa\n");
		exit(-1);
	}

	num=contarCaracter(argv[1],argv[2]);

	printf("El numero de veces que aparece el caracter en la cadena es: %i\n",num );
}