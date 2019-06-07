#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

struct lista* nuevoElemento(){	//Devuelve la reserva de memoria para el nodo
	return ((struct lista*)malloc(sizeof(struct lista)));
}


void insertarDelante(struct lista** cabeza, int n){
	struct lista* nuevo = NULL;		//Creamos el nodo igualandolo a NULL

	nuevo=nuevoElemento(); //Doy la memoria necesaria para el nodo
	
	nuevo->n=n; //Introduzco el valor que quiero que tenga el nodo
	nuevo->sig=*cabeza; //Ahora nuevo sig apuntará donde apuntaba la cabeza.
		//En el caso de que sea el primer elemento insertado, nuevo sig apuntara a NULL, ya que la
		// cabeza apuntaba a NULL.
	*cabeza=nuevo; //Ahora cabeza sera el nodo nuevo.
	printf("\nNuevo elemento creado!\n");
}


void insertarDetras(struct lista** cabeza, int n){

	struct lista* aux = NULL;

	struct lista* nuevo = NULL;
	nuevo=nuevoElemento();

	nuevo->n=n;
	nuevo->sig=NULL; //Apuntará a NULL ya que es el ultimo elemento de la lista
	
	if(*cabeza==NULL){
		printf("Solo hay un elemento en la cabeza\n");
		*cabeza=nuevo; //La cabeza pasa a ser el nodo llamado nuevo
	} else {
		aux=*cabeza;

		while(aux->sig!=NULL){
			aux=aux->sig; //El nodo auxiliar será el nodo que apunte aux->sig (Ojo, NO aux->sig=aux->sig)
		}

		aux->sig=nuevo; //Una vez situados en el ultimo nodo, hacemos que apunte al nuevo elemento
	}


}

void mostrarLista(struct lista* cabeza){

	struct lista* aux = NULL;

	aux=cabeza; //Igualamos aux a la cabeza para asi usarla
 
	while(aux!=NULL){ //Que AUX sea distinto que NULL, si ponemos aux sig no llegariamos a ver el ultimo nodo.

		printf("El contenido del nodo es: %i\n",aux->n);
		aux=aux->sig; //La variable aux ahora será el nodo al que apuntaba aux siguiente.

	}

}


int buscarElemento(struct lista* cabeza,int b){

	int encontrado=0;
	struct lista* aux = NULL;

	aux=cabeza;

	while(aux!=NULL && encontrado==0){ //Recorro la lista hasta que termine de ver todos los elementos
									   //O hasta que haya encontrado el elemento
		if(b==aux->n){ //Comprobación con IFs para ver si esta el elemento
			encontrado=1;
		} else {
			aux=aux->sig;
		}
	}

	return encontrado; //Devuelvo el resultado de encontrarlo

}


void borrarElemento(struct lista** cabeza, int r){
	struct lista* ant;
	struct lista* aux;

	aux=*cabeza; //Ahora aux es el nodo de la cabeza

	while(aux->n!=r){ //Recoremos la lista hasta que encontremos el nodo que contenga el valor r.
		ant=aux;
		aux=aux->sig;
	}	

	if(aux==*cabeza){ //Comparamos el nodo
		*cabeza=aux->sig; //Si es la cabeza, la cabeza ahora apunta al siguiente nodo
		free(aux); //Liberamos memoria
	} else { 
		ant->sig=aux->sig; //En caso de que sea otro nodo, enlacamos el nodo anterior con el siguiente
		free(aux); //Liberamos memoria
	}

	printf("Elemento borrado!\n");
}


void borrarLista(struct lista** cabeza){
	struct lista* aux;
	struct lista* del;

	aux=*cabeza;

	while(aux!=NULL){ //Recorro la lista
		del=aux->sig; //El nodo siguiente se guarda en "del"
		free(aux); 	//Libero el nodo actual
		aux=del;	// "Paso" al nodo siguiente
	}

	*cabeza=NULL; //Ojo importante
}