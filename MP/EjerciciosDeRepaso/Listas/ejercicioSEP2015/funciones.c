#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>


struct lista* nuevoElemento(){

	return ((struct lista*)malloc(sizeof(struct lista)));
}


void introducirElemento(struct lista** cabeza,int n){

	struct lista* nuevo;
	nuevo=nuevoElemento();

	nuevo->n=n;
	nuevo->sig=*cabeza;

	*cabeza=nuevo;
	printf("Nuevo elemento creado\n");

}


void mostrarLista(struct lista* cabeza){

	struct lista* aux = NULL;

	aux=cabeza;

	while(aux!=NULL){

		printf("El numero es: %i\n",aux->n);
		aux=aux->sig;
	}

}


void verMayorMenor(struct lista* cabeza,int* max,int* min){
	struct lista* aux;
	aux=cabeza;

	*max=aux->n;
	*min=aux->n;

	while(aux!=NULL){

		if(*max<aux->n){
			*max=aux->n;
		}

		if(*min>aux->n){
			*min=aux->n;
		}


		aux=aux->sig;
	}
}