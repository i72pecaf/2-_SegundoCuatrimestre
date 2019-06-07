#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#define MAX 999


void reservaVector(char** v, int nElem){

	if((*v=(char*)calloc(nElem,sizeof(char)))==NULL){
		printf("Error al reservar memoria\n");
		exit(-1);
	}

}


void crearFichero(char* name){

	FILE* f;

	if((f=fopen(name,"a"))==NULL){
		printf("Error al crear el archivo\n");
		exit(-1);
	}
	printf("\nFichero creado\n");

	fclose(f);
}

int comprobarFichero(char* name){
	
	FILE* f;
	char aux[99];

	if((f=fopen(name,"r"))==NULL){
		printf("Error al crear el archivo\n");
		exit(-1);
	}
	/* Compruebo si se lee algo del fichero, en caso verdadero devuelvo 1, si no, 0. */
	if((fgets(aux,1,f))==NULL){
		return 0;
	} else {
		return 1;
	}
	fclose(f);
}

void comprobarExistencia1(char* name){
	FILE* f;
	char titulo[999];
	char tituloTXT[999];
	int contador=0;
	int comp=0;
	int aux=0;

	printf("- Introduce el libro a buscar: ");
	scanf("%s",titulo);

	comp=comprobarFichero(name);

	if(comp==0){
		printf("No hay nada escrito en el fichero\n");
		exit(-1);
	}

	if((f=fopen(name,"r"))==NULL){
		printf("Error al abrir el archivo\n");
		exit(-1);
	}

	printf("\n - Leyendo...\n");
	sleep(2);

	while((fgets(tituloTXT, 999, f))!=NULL){

		if((contador%4)==0){
			//En este caso, se esta leyendo el campo que corresponde al titulo del libro

			if(tituloTXT[strlen(tituloTXT)-1]=='\n'){
				tituloTXT[strlen(tituloTXT)-1]='\0';
			}

			if((strcmp(tituloTXT,titulo))==0){
				aux=1;
			}
		}
		contador++; //Contador que me indica la posicion en la que estoy
	}

	if(aux==0){
		printf("[!] El libro no se encuentra en el stock [!]\n");
	} else {
		printf("[!] El libro se encuentra en el stock [!]\n");
	}

	fclose(f);
}

void introducirLibro2(char* name){
	FILE* f;
	int comp=0;
	char titulo[MAX];
	char autor[MAX];
	float precio;
	int unidades;

	/* Compruebo si hay algo escrito en el fichero, dependiendo del resultado habro en un modo u otro */
	comp=comprobarFichero(name);

	if(comp==0){
		if((f=fopen(name,"w"))==NULL){ //No hay nada, por lo tanto empiezo desde el principio
			printf("Error al abrir el archivo\n");
			exit(-1);
		}
	} else {
		if((f=fopen(name,"a"))==NULL){ //Hay cosas, pongo el puntero al final
			printf("Error al abrir el archivo\n");
			exit(-1);
		}
	}

	/* Pido los datos al usuario */
	printf("Introduce el título: ");
	scanf("%s",titulo);
	printf("\n");
	
	printf("Introduce el autor: ");
	scanf("%s",autor);
	printf("\n");
	
	printf("Introduce el precio: ");
	scanf("%f",&precio);
	printf("\n");
	
	printf("Introduce el numero de unidades disponibles: ");
	scanf("%i",&unidades);
	printf("\n");
	
	/* Introduzco uno por uno los datos en el fichero */
	fprintf(f,"%s",titulo);
	fprintf(f,"%s","\n");

	fprintf(f,"%s",autor);
	fprintf(f,"%s","\n");

	fprintf(f,"%f",precio);
	fprintf(f,"%s","\n");

	fprintf(f,"%i",unidades);
	fprintf(f,"%s","\n");

	printf("\n------Saliendo de la funcion------\n");
	fclose(f);
}

int comprobarDistintos3(char* name){
	
	FILE* f;
	char tituloTXT[999];
	int contador=0;
	int comp=0;
	int contadorLibros=0;

	comp=comprobarFichero(name);

	if(comp==0){
		printf("No hay nada escrito en el fichero\n");
		exit(-1);
	}

	if((f=fopen(name,"r"))==NULL){
		printf("Error al abrir el archivo\n");
		exit(-1);
	}

	printf("\n - Leyendo...\n");
	sleep(2);

	
	while((fgets(tituloTXT, 999, f))!=NULL){

		if((contador%4)==0){//En este caso, se esta leyendo el campo que corresponde al titulo del libro
		
			contadorLibros++;

		}

		contador++; //Contador que me indica la posicion en la que estoy
	}

	//printf("Hay un total de %i libros\n", contadorLibros );

	return contadorLibros;

	fclose(f);
}


void listarLibros4(char* name){

	FILE* f;
	int comp=0;
	int nLibros=0;
	int contador=0;
	char* v;
	char tituloTXT[999];
	int i=0;

	comp=comprobarFichero(name);

	if(comp==0){
		printf("No hay nada escrito en el fichero\n");
		exit(-1);
	}



	nLibros=comprobarDistintos3(name); //nLibros son el numero de libros, nos permitira crear el vector dinamico;

	reservaVector(&v, nLibros);	//Creo el vector dinamico


	if((f=fopen(name,"r"))==NULL){
		printf("Error al abrir el archivo\n");
		exit(-1);
	}

	while((fgets(tituloTXT, 999, f))!=NULL){	//Ahora empiezo a leer el fichero y guardar los datos en el vector

		if((contador%4)==0){//En este caso, se esta leyendo el campo que corresponde al titulo del libro
		
			if(tituloTXT[strlen(tituloTXT)-1]=='\n'){
				tituloTXT[strlen(tituloTXT)-1]='\0';
			}

			strcpy(&v[i],tituloTXT);

			printf("%s\n", &v[i]);	//SOLO PUEDO MOSTRARLO BIEN AQUI, SI LO HAGO FUERA DEL WHILE ME CAMBIA LOS VALORES DEL VECTOR, NO SE LA RAZON
			i++;
		}
		contador++; //Contador que me indica la posicion en la que estoy
	}

	fclose(f);
}


void venderUnidades5(char* name){

	FILE* f;
	char titulo[999];
	char tituloTXT[999];
	int comp=0;
	int contador=0;
	int aux;

	comp=comprobarFichero(name);

	if(comp==0){
		printf("No hay nada escrito en el fichero\n");
		exit(-1);
	}

	printf("Introduce el titulo del libro: \n");
	scanf("%s",titulo);


	if((f=fopen(name,"r"))==NULL){
		printf("Error al abrir el archivo\n");
		exit(-1);
	}


	while((fgets(tituloTXT, 999, f))!=NULL){

		if((contador%4)==0){
			//En este caso, se esta leyendo el campo que corresponde al titulo del libro

			if(tituloTXT[strlen(tituloTXT)-1]=='\n'){
				tituloTXT[strlen(tituloTXT)-1]='\0';
			}

			if((strcmp(tituloTXT,titulo))==0){
				
				aux=contador;	//Se pasa a aux el numero de registro en el que se encuentra el libro a buscar

			}
		}
		contador++; //Contador que me indica la posicion en la que estoy
	}

	fclose(f);

	printf("El libro a buscar es el numero: %i \n",aux);
	printf("El campo correspondiente al numero de copias del libro es el: %i \n",aux+3 );

	
	
}



