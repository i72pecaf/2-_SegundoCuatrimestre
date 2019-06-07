#include "funciones.h"
#include <stdio.h>


int main(){
	int nElem,a,r;
	float x;	

	struct monomio* cabeza=NULL;

	printf("Introduce el numero de elementos de tu polinomio: ");
	scanf("%i",&nElem);

	for(int i=0 ; i<nElem ; i++){
		printf("Introduce el coeficiente del monomio con exponente %i: ",i);
		scanf("%i",&a);
		introduceMonomio(&cabeza,a,i);

	}

	muestraPolinomio(cabeza);

	printf("\nIntroduce el valor de 'x' para evaluar el polinomio: ");
	scanf("%f",&x);

	evaluaPolinomio(cabeza,x);


	printf("\nIntroduce el polinomio a borrar (segun el exponente del monomio): ");
	scanf("%i",&r);

	eliminaMonomio(&cabeza,r);

	printf("\nLa lista resultante es: ");

	muestraPolinomio(cabeza);

}