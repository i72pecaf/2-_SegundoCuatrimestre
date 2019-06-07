#include "funciones.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarRegistros(){ //Listar registros de un fichero 
	//Contamos los registros con el tamaño de la estructura.
	//En definitiva, estamos contando cuantas estructuras tenemos.
	FILE* f;
	float tam=0;
	float tamRegistro=0;

	if((f=fopen("patata.bin", "rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	//Vemos el tamaño del fichero:

	fseek(f,0L,SEEK_END); //Posicionamiento del apuntador
	tam=ftell(f);

	//Vemos el tamaño de cada registro:
	tamRegistro=sizeof(struct libro);

	printf("El numero de registros son: %f\n", tam/tamRegistro );

	fclose(f);

	return tam/tamRegistro;
	//OJO: En el fichero en verdad tenemos distintos campos con datos, pero nos referimos a registros
	//como aquellos conjuntos de datos, que en este caso, son las estructuras.
}


void reservaMemoriaVector(struct libro** aux, int nElem){

	if((*aux=(struct libro*)malloc(nElem*sizeof(struct libro)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}

	printf("Memoria reservada!\n");

}


void introducirDatos(){ //Añadir datos a un fichero
		//Se escribe solo UNA estructura en esta función.
	FILE* f;
	struct libro book1;

	printf("Introduce el titulo del libro:\n");
	scanf("%s",book1.titulo);

	printf("Introduce el autor del libro:\n");
	scanf("%s",book1.autor);

	printf("Introduce el precio del libro:\n");
	scanf("%f",&book1.precio);

	printf("Introduce el numero de unidades del libro:\n");
	scanf("%i",&book1.unidades);

	if((f=fopen("patata.bin", "ab"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	fwrite(&book1,sizeof(struct libro),1,f);

	printf("Libro escrito\n");

	fclose(f);

}


void leerficheroVector(){ //Debo de usar un vector, ya que estoy leyendo estructuras

	FILE* f;
	int nElem;
	struct libro* aux;

	nElem=contarRegistros();

	reservaMemoriaVector(&aux, nElem);

	if((f=fopen("patata.bin", "rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}
	fseek(f,0L,SEEK_SET);

	fread(aux,sizeof(struct libro),nElem,f);

	printf("\n-----------------------------\n");
	for(int i=0 ; i<nElem ; i++){

		printf("Titulo -- %s\n", aux[i].titulo );
		printf("Autor -- %s\n", aux[i].autor);
		printf("Precio -- %f\n", aux[i].precio);
		printf("Unidades -- %i\n", aux[i].unidades);
		printf("-----------------------------\n");

	}

	fclose(f);
}


void verRegistroi(){ //Ver registro i-esimo
	
	FILE* f;
	int r;
	struct libro aux;

	printf("Introduce el registro que quieres ver (0 para la 1º estructura, 1 para la 2º...): ");
	scanf("%i",&r);

	if((f=fopen("patata.bin", "rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	fseek(f,r*sizeof(struct libro),SEEK_SET); //Situo el cursor al principio y me muevo hasta el registro 'r'.
											  //Es multiplicar por el tamaño de cada estructura
	fread(&aux,sizeof(struct libro),1,f);

	printf("\n-----------------------------\n");
	printf("Titulo -- %s\n", aux.titulo );
	printf("Autor -- %s\n", aux.autor);
	printf("Precio -- %f\n", aux.precio);
	printf("Unidades -- %i\n", aux.unidades);
	printf("-----------------------------\n");

	fclose(f);

}


void buscarPorLibro(){ //Buscar uno de los registros (la informacion correspondiente a ese registro)

	FILE* f;
	struct libro aux;
	char libro[999];

	printf("Introduce el nombre del libro\n");
	scanf("%s",libro);

	if((f=fopen("patata.bin","rb"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while(fread(&aux,sizeof(struct libro),1,f)==1){
		

		if(strcmp(aux.titulo,libro)==0){//Si son iguales, entonces lo muestro (Devuelve 0 si coinciden)
			printf("\n-----------------------------\n");
			printf("Los datos del libro son:\n");
			printf("Titulo -- %s\n", aux.titulo );
			printf("Autor -- %s\n", aux.autor);
			printf("Precio -- %f\n", aux.precio);
			printf("Unidades -- %i\n", aux.unidades);
			printf("-----------------------------\n");
		}
	}

	fclose(f);
}


void modificarUnidiades(){ //Modificar uno de los registros

	FILE* f;
	char libro[999];
	struct libro aux;
	int unidadesAUX;
	int Uds;

	printf("Introduce el nombre del libro del cual quieres modificar sus unidades: ");
	scanf("%s",libro);

	printf("Introduce el numero de unidades que quieres que tenga el libro anterior: ");
	scanf("%i",&Uds);

	if((f=fopen("patata.bin","r+b"))==NULL){ //Lo abro con r+b para leer y escribir
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while(fread(&aux,sizeof(struct libro),1,f)==1){ //OJO!! El cursor se mueve al leer!
		if(strcmp(aux.titulo,libro)==0){
			aux.unidades=Uds; //Escribimos en la estructura el nuevo numero de unidades
			fseek(f,-(int)sizeof(struct libro),SEEK_CUR); //Muevo el cursor una vez hacia atras para posicionarme donde en la estructura correcta
			fwrite(&aux,sizeof(struct libro),1,f); //Escribo la estructura completa de nuevo con el campo ya modificado.
			printf("Dato modificado!\n");
		}
	}
}


void borrarAutor(){ //Borrar uno de los campos

	FILE* f;
	char name[999];
	struct libro aux;

	printf("Introduce el nombre del autor que quieres borrar ");
	scanf("%s",name);

	if((f=fopen("patata.bin","r+b"))==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}

	while(fread(&aux,sizeof(struct libro), 1, f)==1){

		if(strcmp(aux.autor,name)==0){
			strcpy(aux.autor,""); //Introduzco la cadena en blanco para asi "borrarla"
 			fseek(f,-(int)sizeof(struct libro),SEEK_CUR); //Situo el cursor en el registro anterior
 			fwrite(&aux,sizeof(struct libro),1 ,f); //Escribo el registro (la estructura) en el lugar indicado
		}
	}
	fclose(f);
}