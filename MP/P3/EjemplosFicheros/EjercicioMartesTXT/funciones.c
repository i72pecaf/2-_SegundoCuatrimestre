#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cambiarEdad(char* nombre,int newEdad){
	
	FILE* f;
	FILE* d;

	char nombre1[99];
	char nombre2[99];
	char nombre3[99];
	int edad;
	int num;

	if((f=fopen("Alumnos.txt","r"))==NULL){
		printf("Error al abrir el fichero origen\n");
		exit(-1);
	}

	if((d=fopen("cambiado.txt","w"))==NULL){
		printf("Error al abrir el fichero destino\n");
		exit(-1);
	}

	while((fscanf(f,"%s %s %s %i %i",nombre1,nombre2,nombre3,&edad,&num))!=EOF){

		if((strcmp(nombre1,nombre))==0){
			edad=newEdad;
			fprintf(d,"%s %s %s %i %i\n",nombre1,nombre2,nombre3,edad,num);

		} else {
		fprintf(d,"%s %s %s %i %i\n",nombre1,nombre2,nombre3,edad,num);
		}
	}

	fclose(f);
	fclose(d);

}




void borrarAlumno(char* nombre){

	FILE* f;
	FILE* d;

	char nombre1[99];
	char nombre2[99];
	char nombre3[99];
	int edad;
	int num;

	if((f=fopen("Alumnos.txt","r"))==NULL){
		printf("Error al abrir el fichero origen\n");
		exit(-1);
	}

	if((d=fopen("eliminado.txt","w"))==NULL){
		printf("Error al abrir el fichero destino\n");
		exit(-1);
	}

	while((fscanf(f,"%s %s %s %i %i",nombre1,nombre2,nombre3,&edad,&num))!=EOF){
		if((strcmp(nombre1,nombre))!=0){
			fprintf(d,"%s %s %s %i %i\n",nombre1,nombre2,nombre3,edad,num);
		}
	}

	fclose(f);
	fclose(d);


}