#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	if ( argc!=3 ){
		printf("Numero de parametros incorrecto\n");
		exit(-1);
	}

	//int x, y;
	//printf("Introduce dos numeros para calcular su MCM, primero el grande luego el pequeño\n");
	//scanf("%i",&x);
	//scanf("%i",&y);
	printf("%i\n",atoi(argv[1]) );
	printf("%i\n",atoi(argv[2]) );
	printf("El resultado es: %i\n",euclides(atoi(argv[1]),atoi(argv[2])));
}