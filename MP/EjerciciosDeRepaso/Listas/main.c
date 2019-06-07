#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int n,b,resultado,r;
	struct lista* cabeza = NULL;	//Creamos el puntero cabeza y la inicializamos a NULL.
									//No hay ningun nodo creado todavia.

	printf("Introduce un numero para guardar en el nodo nuevo\n");
	scanf("%i",&n);

	
	//Vamos a crear y a insertar un nuevo elemento por delante (por la cabeza, de izquierad a derecha).
	insertarDelante(&cabeza,n); //Pasamos la dirección de la cabeza ya que la vamos a modificar
	insertarDelante(&cabeza,n+5); //Creo otro valor para otro nodo para ver que este ultimo nodo ira primero en la lista.
	
	//Insertamos por detras:
	insertarDetras(&cabeza,n*2);
	
	//Vamos a mostrar la lista:
	mostrarLista(cabeza);

	printf("Introduce el numero a buscar en la lista\n");
	scanf("%i",&b);

	
	resultado=buscarElemento(cabeza,b);

	if(resultado==1){ //Ya evaluo la información devuelta por la función.
		printf("Se ha encontrado el elemento a buscar\n");
	} else {
		printf("No se ha encontrado el elemento a buscar\n");
	}


	printf("Introduce la información del nodo a borrar.\n");
	scanf("%i",&r);

	borrarElemento(&cabeza,r);

	mostrarLista(cabeza);

	borrarLista(&cabeza);


	mostrarLista(cabeza); //No mostrara nada porque se ha borrado la lista

}