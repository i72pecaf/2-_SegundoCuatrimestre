#include "funciones.h"
#include <stdio.h>

int main(){

	char nombre[99];
	int newEdad; 
	printf("Introduce el usuario al que quieres cambiarle la edad (Su nombre, no apellidos): ");
	scanf("%s",nombre);

	printf("Introduce la nueva edad del usuario: ");
	scanf("%i",&newEdad);

	cambiarEdad(nombre,newEdad);


	printf("Introduce el nombre del usuario a borrar: ");
	scanf("%s",nombre);

	borrarAlumno(nombre);
}