//	gcc estadisticas.c -lm -o estadisticas.o
//	./estadisticas.o

//	Funcion que recibe un vector de enteros y calcula, usando parametros por referencia,
//	la media, la varianza y la desviacion tipica de los datos del vector.

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#define tam	10

int imprimeVector(int *v){
	for(int i=0; i<tam; i++){
		printf("v[%i] =	%i\n", i, v[i]);
	}
	printf("\n");
}

int estadisticasVector(int *v){
	float media, varianza, dt, aux=0, aux2=0, aux3=0;

	//Media
	for(int i=0; i<tam; i++){
		aux=v[i]+aux;
	}
	media=aux/tam;
	printf("MEDIA =	%f\n", media);

	//Varianza
	for(int i=0; i<tam; i++){
		aux2=pow((v[i]-media), 2);
		aux3=aux2+aux3;
	}
	varianza=aux3/tam;
	printf("VARIANZA = %f\n", varianza);

	//Desviacion tipica
	dt=sqrt(varianza);
	printf("DESVIACION TIPICA = %f\n", dt);
}

int main(){
	int v[tam];
	srand(time(NULL));

	for(int i=0; i<tam; i++){
		v[i]=rand()%10+1;
	}
	imprimeVector(v);
	estadisticasVector(v);
	return 0;
}
