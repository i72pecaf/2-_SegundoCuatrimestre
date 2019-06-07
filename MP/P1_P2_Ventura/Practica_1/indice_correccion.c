//	NOTA: Un indice es un vector de punteros que almacena la direccion de los elementos que se quieren recorrer.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

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
void crearIndicesImpares(int *v, int **v2, int *nEle){

	for(int i=0, j=0; i<TAM; i++){
		if(v[i]%2!=0){
			v2[j]=&v[i];
			j++;
			printf("v2[%d] = %d\n", i, *v2[j]);
		}
	}
	*nEle = j;
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
void imprimirIndice(int** indice, int nEle){

	for(i=0; i<nEle; i++)
		printf("", *indice[i]);     
}

int main(){
	srand(time(NULL));
	int v[TAM];
	int *v2[TAM];
	int *v3[TAM];
	int nEle = 10, nImpares, nDiv; //scanf
	rellenaVector(v, nEle);

	imprimeVector(v, nEle);

	printf("\nINDICES IMPARES:\n");
	crearIndicesImpares(v, v2, &nImpares);

	printf("\nINDICES DIVISIBLES POR 3:\n");
	crearIndiceDivisibles(v, v3, &nMulti);

	return 0;
}
