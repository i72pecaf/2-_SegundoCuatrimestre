#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>

struct alumno
{
	char nombre[50];
	char apellido1[50];
	char apellido2[50];
	int x;
	int y;
};


void borrar(struct alumno aux, int num);


#endif

