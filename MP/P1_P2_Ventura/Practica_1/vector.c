#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM	10

//	Funcion que lee un vector de elementos tipo double.
void leeVector(double *v){
	for(int i=0; i<TAM; i++){
		v[i]=rand()%10;
		v[i]=v[i]-3;
	}
}

//	Funcion que imprime los datos del vector por pantalla.
void escribeVector(double *v){
	for(int i=0; i<TAM; i++){
		printf("v[%i] =	%f\n", i, v[i]);
	}
}

//	Funcion que suma los elementos mayores que cero del vector.
void sumaPositivos(double *v){
	double suma=0;

	for(int i=0; i<TAM; i++){
		if(v[i]>0){
			suma=v[i]+suma;
		}
	}
	printf("\nSUMA: %f\n", suma);
}

int main(){
	srand(time(NULL));

	double v[TAM];

	leeVector(v);
	escribeVector(v);
	sumaPositivos(v);
}