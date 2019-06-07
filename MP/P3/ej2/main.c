#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	
	if (argc!=3){
		printf("Numero de parametros incorrecto\n");
		exit(-1);
	}
	
	printf("El resultado de la divison es: %i\n", divisionRestas(atoi(argv[1]),atoi(argv[2])));
}