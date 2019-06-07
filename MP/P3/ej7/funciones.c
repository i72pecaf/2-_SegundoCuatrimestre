#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

void cuentaPares(char* nombreF){

	FILE* f;
	int num;
	float contador=0;
	float suma=0;
	float media;

	if((f=fopen(nombreF,"r"))==NULL){
		printf("Error, el archivo no existe\n");
		exit(-1);
	}

	while(fscanf(f,"%i",&num)!=EOF){
		if(num!=0){
			if((num%2)==0){
				contador++;
				suma=suma+num;
			}
		}
	}

	media=suma/contador;

	printf("La media de los numeros pares del fichero: %f\n", media);

	fclose(f);
}