#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "ej2.h"

int* reservaVector(int nElementos){
	int *v;

	if((v = (int*)calloc(nElementos, sizeof(int)))==NULL){
		printf("ERROR EN LA RESERVA DE MEMORIA\n");
		exit(-1);
	}
	return v;
}

int imprimeVectores(int *v, int nElementos, int num){
	int v2[nElementos], v3[nElementos];

	for(int i=0; i<nElementos; i++){
		v[i]=rand()%10+1;
		printf("	v[%d] = %d\n", i, v[i]);
	}

	printf("--------------------------------------\n");
	printf("NUM = %d\n", num);

	for(int i=0; i<nElementos; i++){
		if(v[i]<=num){
			v2[i]=v[i];
		}else{
			v2[i]=-1;
		}
	}

	for(int i=0; i<nElementos; i++){
		if(v[i]>num){
			v3[i]=v[i];
		}else{
			v3[i]=-1;
		}
	}

	printf("--------------------------------------\n");

	printf("MENORES O IGUALES QUE NUM: \n");
	for(int i=0; i<nElementos; i++){
		printf("	v[%d] = %d\n", i, v2[i]);
	}

	printf("--------------------------------------\n");
	printf("MAYORES QUE NUM: \n");
	for(int i=0; i<nElementos; i++){
		printf("	v[%d] = %d\n", i, v3[i]);
	}
}

int main(){
	srand(time(NULL));
	int num, nElementos=5;
	int *v;

	num=rand()%10+1;
	v=reservaVector(nElementos);
	imprimeVectores(v, nElementos, num);

	free(v);

	return 0;
}