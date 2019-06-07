/*
Programa que escribe un fichero en binario con informacion sobre esta estructura:
struct libro{
	char titulo[256]
	char autor[256]
	float precio;
	int unidades;
}
El formato del fichero debe de ser:
	titulo
	autor
	precio unidades
Justo en ese orden.
*/
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){ 

	struct libro book1;

	if(argc!=5){
		printf("Error en el numero de parametros\n");
	}

	rellenaEstructura(&book1,argv[1] ,argv[2] ,argv[3],argv[4]);


	escribirEstructura(&book1);

}