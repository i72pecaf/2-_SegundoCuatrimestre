#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	struct alumno* vector;
	int nElem;
	int (*comparar) (int,int);

	if(argc!=3){
		printf("Error en el numero de parametros, debe de ser: <Numero de ordenacion> <Nombre del fichero>\n");
		exit(-1);
	}

	if(atoi(argv[1])==1){
		comparar=&mayor;
	} else {
		if(atoi(argv[1])==2){
			comparar=&menor;
		} else{
			printf("Error, el valor del primer parametro debe de ser 1 (Ascendente) o 2 (Descendente)\n");
		}
	}

	contarRegistros(argv[2],&nElem);	

	reservarMemoriaVector(&vector,nElem);

	rellenarVector(vector, nElem, argv[2]);

	ordenaVectorBurbuja(vector,nElem,comparar);

	for(int i=0; i<nElem;i++){
		printf("Nombre %i: %s\n",i,vector[i].nombre );
	}

	free(vector);
}