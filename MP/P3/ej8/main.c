#include "funciones.h"
#include <stdio.h>
#define MAX 999


int main(){
	int n;
	char name[MAX];
	int nLibros;


	printf("[!]ESTE PROGRAMA SUPONE QUE NO SE VAN A INTRODUCIR DOS LIBROS CON EL MISMO NOMBRE[!]\n");
	printf("Introduce el nombre del fichero: ");
	scanf("%s",name);
	crearFichero(name);

	printf("\n");
	printf("\n Bienvenido a la libreria:\n\n");
	printf("	----------------------------------------------------------\n");
	printf("	| 1 ---> Comprobar existencia por título		 |\n");			
	printf("	| 2 ---> Introducir un libro nuevo		     	 |\n");				
	printf("	| 3 ---> Comprobar numero de libros distintos 		 |\n");		
	printf("	| 4 ---> Listar libros en el stock usando un vector      |\n");
	printf("	| 5 ---> Vender 'n' unidades de un libro por título      |\n");
	printf("	| 6 ---> Borrar registros con 0 unidades                 |\n");			
	printf("	| 0 ---> Salir del programa				 |\n");
	printf("	----------------------------------------------------------\n\n");
	printf(" Introduce que quieres hacer: ");
	scanf("%i",&n);

	while(n!=0){

		switch(n){
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1: 
				
				printf("\n----- Comprobar existencia de un libro -----\n");
				comprobarExistencia1(name);

			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 2:
				
				printf("\n----- Introducir un nuevo libro en stock -----\n");
				introducirLibro2(name);

			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 3:
				
				printf("\n----- Contar el número de libros -----\n");
				nLibros=comprobarDistintos3(name);
				printf("Hay un total de %i \n", nLibros );

			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 4:
				printf("\n----- Listar los libros  -----\n");
				listarLibros4(name);
			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 5:
				printf("\n----- Vender 'n' unidades  -----\n");
				venderUnidades5(name);
			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 6:
				printf("Caso 3\n");
			break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////			
		}

		printf("\n Introduce que quieres hacer: ");
		scanf("%i",&n);

	}

	printf("\nSaliendo del programa...\n");
}