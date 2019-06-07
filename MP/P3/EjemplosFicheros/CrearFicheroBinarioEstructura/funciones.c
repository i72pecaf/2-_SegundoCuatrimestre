#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rellenaEstructura(struct libro* book1,char* titulo ,char* autor ,char* precio,char* unidades){
	strcpy(book1->titulo,titulo);
	strcpy(book1->autor,autor);
	strcpy(book1->precio,precio);
	strcpy(book1->unidades,unidades);

	printf("Libro: %s\n", book1->titulo);
	printf("Autor: %s\n", book1->autor);
	printf("Precio: %s\n",book1->precio );
	printf("Copias: %s\n",book1->unidades );
}



void escribirEstructura(struct libro* book1){
	FILE* f;
	char aux[999];
	char* fichero="patata.bin";

	if((f=fopen(fichero,"ab"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	fwrite(book1->titulo,sizeof(struct libro),1,f);	
	fwrite(book1->autor,sizeof(struct libro),1,f);

	strcat(aux,book1->precio);
	strcat(aux," ");
	strcat(aux,book1->unidades);
	//printf("%s\n",aux );	
	fwrite(aux,sizeof(struct libro),1,f);

	fclose(f);
}