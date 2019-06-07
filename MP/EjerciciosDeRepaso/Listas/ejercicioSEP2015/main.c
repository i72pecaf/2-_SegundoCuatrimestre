#include "funciones.h"
#include <stdio.h>


int main(){
	
	int nElem,n;
	int max,min;
	struct lista* cabeza = NULL;

	printf("Introduce el numero de elementos de la lista: ");
	scanf("%i",&nElem);

	for(int i=0 ; i<nElem ; i++){
		printf("Introduce el valor para el nodo: ");
		scanf("%i",&n);
		introducirElemento(&cabeza,n);
	}

	printf("La lista es:\n");

	mostrarLista(cabeza);

	verMayorMenor(cabeza,&max,&min);
¡
	printf("El valor mayor es: %i y el menor: %i \n",max,min );
}