#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrices.h"

int **reservarMemoria(int nFil, int nCol){
	int **matriz;

	if((matriz = (int **)calloc(nFil, sizeof(int *))) == NULL){
		printf("ERROR EN LA RESERVA DE MEMORIA\n");
		exit(-1);
	}

		for (int i = 0; i < nFil; i++){
			if((matriz[i] = (int *)calloc(nCol, sizeof(int))) == NULL){
				printf("ERROR EN LA RESERVA DE MEMORIA\n");
				exit(-1);
			}
		}
	return matriz;
}

void rellenaMatriz(int **matriz, int nFil, int nCol){
	for (int i = 0; i < nFil; i++){
		for (int j = 0; j < nCol; j++){
			matriz[i][j] = rand()%20+1;
		}
	}
}

void imprimeMatriz(int **matriz, int nFil, int nCol){
	for (int i = 0; i < nFil; ++i){
		for (int j = 0; j < nCol; ++j){
			printf("M[%d][%d] = %d\t", i, j, matriz[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------------------------------------------------\n");

	for (int i = 0; i < nFil; ++i){
		for (int j = 0; j < nCol; ++j){
			printf("[%d]\t", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int *minCol(int **matriz, int nFil, int nCol){
	int *v=(int*)calloc(nCol, sizeof(int));

	for(int j=0; j<nCol; j++){
		v[j]=matriz[0][j];

		for(int i=0; i<nFil; i++){
			if(matriz[i][j] < v[j]){
				v[j]=matriz[i][j];
			}
		}
		printf("MENOR VALOR COLUMNA %i: %i\n", j, v[j]);
	}
	return v;
}

void liberarMemoria(int ***matriz, int nFil){
	for (int i = 0; i < nFil; ++i){
		free((*matriz)[i]);
	}
	free(*matriz);
}

int main(){
	srand(time(NULL));

	int **matriz;
	int nFil=3, nCol=4;
	
	matriz = reservarMemoria(nFil, nCol);
	rellenaMatriz(matriz, nFil, nCol);
	imprimeMatriz(matriz, nFil, nCol);
	minCol(matriz, nFil, nCol);
	liberarMemoria(&matriz, nFil);

	return 0;
}