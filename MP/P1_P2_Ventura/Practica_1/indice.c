//	NOTA: Un indice es un vector de punteros que almacena la direccion de los elementos que se quieren recorrer.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

//	Funcion que rellena un vector de enteros con numeros aleatorios entre 0 < x < 11.
void rellenaVector(int *v){
	for(int i=0; i<20; i++){
		v[i]=rand()%10+1;
	}
}

//	Funcion que imprime el vector completo.
void imprimeVector(int *v){
	for(int i=0; i<TAM; i++){
		printf("v[%d] = %d\n", i, v[i]);
	}
}

//	Funcion que crea e imprime un indice con las direcciones de los elementos impares del vector original. 
void crearIndicesImpares(int *v, int **v2){

	for(int i=0; i<TAM; i++){
		if(v[i]%2!=0){
			v2[i]=&v[i];
			printf("v2[%d] = %d\n", i, *v2[i]);
		}
	}
}

//	Funcion que crea e imprime un indice con las direcciones de los elementos divisibles por 3 que hay en el vector original.
void crearIndiceDivisibles(int *v, int **v3){

	for(int i=0; i<TAM; i++){
		if(v[i]%3==0){
			v3[i]=&v[i];
			printf("v3[%d] = %d\n", i, *v3[i]);
		}
	}
}

int main(){
	srand(time(NULL));
	int v[TAM];
	int *v2[TAM];
	int *v3[TAM];
	rellenaVector(v);

	imprimeVector(v);

	printf("\nINDICES IMPARES:\n");
	crearIndicesImpares(v, v2);

	printf("\nINDICES DIVISIBLES POR 3:\n");
	crearIndiceDivisibles(v, v3);

	return 0;
}