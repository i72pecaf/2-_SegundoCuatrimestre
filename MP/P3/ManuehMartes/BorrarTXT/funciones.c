#include "funciones.h"





void borrar(struct alumno aux, int num){

	FILE *fich; 
	FILE *new;

if((fich=fopen("Alumnos.txt", "r"))==NULL){
		printf("ERROR\n");
		exit(-1);
	}
	if((new=fopen("Modificado.txt", "w"))==NULL){
		printf("ERROR\n");
		exit(-1);
	}

		while(fscanf(fich,"%s %s %s %i %i\n", aux.nombre, aux.apellido1, aux.apellido2, &aux.x, &aux.y)!=EOF){
		if(aux.x != num){
		
			fprintf(new, "%s %s %s %i %i\n",  aux.nombre, aux.apellido1, aux.apellido2, aux.x, aux.y);

		}
	}


	fclose(fich);
	fclose(new);

	
}

