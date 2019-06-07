#include "funciones.h" 
#include <stdio.h>


int main(int argc, char* argv[]){

	int c;

	printf("\n[!]POR FAVOR LEER BIEN LOS MENSAJES QUE APARECEN POR PANTALLA [!]\n");
	printf("------------------------------------------------------------------\n");
	printf("Introduce 1 para escribir el fichero binario \n");
	printf("Introduce 2 para leer el fichero binario \n");
	printf("Introduce 3 para leer un registro en concreto \n");
	printf("Introduce 4 para buscar por nombre del libro \n");
	printf("Introduce 5 para modificar las unidades de un libro \n");
	printf("Introduce 6 para borrar el autor de un libro \n");
	printf("Introduce 0 para salir del programa \n");

	printf("\nIntroduce la opción: ");
	scanf("%i",&c);
	printf("\n");

while(c!=0){
	switch(c){

		case 1:
			introducirDatos();
		break;



		case 2:
			leerficheroVector();
		break;



		case 3: 
			verRegistroi();
		break;



		case 4:
			buscarPorLibro();
		break;



		case 5:
			modificarUnidiades();
		break;



		case 6:
			borrarAutor();;
		break;
	}
	printf("\nIntroduce la opción: ");
	scanf("%i",&c);
	printf("\n");
}
}