#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct monomio* nuevoElemento(){
	return ((struct monomio*)malloc(sizeof(struct monomio)));
}


void introduceMonomio(struct monomio** cabeza, int a, int e){
	
	struct monomio* nuevo = NULL;

	nuevo=nuevoElemento();
	nuevo->a=a;
	nuevo->e=e;
	nuevo->sig=*cabeza;

	*cabeza=nuevo;
}


void muestraPolinomio(struct monomio* cabeza){

	struct monomio* aux=NULL;

	aux=cabeza;

	printf("\nEl monomio es: ");

	while(aux!=NULL){
		printf("%ix^%i ",aux->a,aux->e );
		aux=aux->sig;
	}
	printf("\n");
}


void evaluaPolinomio(struct monomio* cabeza,float x){

	struct monomio* aux=NULL;
	float contador=0;

	aux=cabeza;

	while(aux!=NULL){
		contador=aux->a*powf(x,aux->e)+contador;
		aux=aux->sig;
	}

	printf("Para x=%f, el valor en el polinomio es: %f \n",x,contador);
}


void eliminaMonomio(struct monomio** cabeza, int r){

	struct monomio* aux=NULL;
	struct monomio* ant=NULL;

	aux=*cabeza;

	while(aux->e!=r){
		ant=aux;
		aux=aux->sig;
	}

	if(aux==*cabeza){
		*cabeza=aux->sig;
		free(aux);
	} else {
		ant->sig=aux->sig;
		free(aux);
	}
}
