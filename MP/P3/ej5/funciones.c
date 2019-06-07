#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void copiarFichero(char* nombre,char* nombreMayus){

	FILE* f;
	FILE* d;
	int c;

	if((f=fopen(nombre,"r"))==NULL){
		printf("Error al abrir el archivo primero\n");
		exit(-1);
	}

	if((d=fopen(nombreMayus,"w"))==NULL){
		printf("Error al abrir el archivo segundo\n");
		exit(-1);
	}


	while((c=fgetc(f))!=EOF){

		if(isupper(c)==0){
			fputc((toupper(c)),d);
		} else {
			fputc(c,d);
		}

	}

	printf("Copia realizada!\n");

	fclose(f);
	fclose(d);
}
