#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	if (argc!=2){
		printf("Numero de parametros incorrecto\n");
		exit(-1);
	}
	
	printf("Introduce la cadena de caracteres:\n");

	char cadena[999];
	scanf("%s",cadena);

	int nEle;
	nEle=strlen(cadena);

	printf("El resultado de la funcion es: %i\n", calcularCaracter(*argv[1],*argv[2], nEle));
}