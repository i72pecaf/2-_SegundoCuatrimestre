#include "funciones.h"
#include <stdio.h>
#include <string.h>


int main(){

	char nombre[999];
	char aux[999];
	char aux2[999];
	char nombreMayus[]="mayusculas-";

	printf("Introduce el nombre del fichero de texto\n");
	scanf("%s",nombre);

	strcpy(aux2,nombre);	//Tengo que usar auxiliares por que sino se me borra un caracter, no se la razon
	strcpy(aux,nombre);

	strcat(nombreMayus,aux);

	copiarFichero(aux2,nombreMayus);

}