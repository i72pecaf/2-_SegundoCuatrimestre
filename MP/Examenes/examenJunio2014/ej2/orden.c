#include "orden.h"
#include <stdio.h>


int mayor(int a, int b){

	if(a>b){
		return 1;
	} else {
		return 0;
	}

}


int menor(int a, int b){

	if(a<b){
		return 1;
	} else {
		return 0;
	}

}




void ordenaVector(int* v, int nElem, int (*compara) (int,int)){
	int aux;

	for(int i=0 ; i<nElem-1 ; i++){
		for(int j=0 ; j<nElem-i-1 ; j++ ){
			if(compara(v[j],v[j+1])==1){ //Si el primero es mayor que el segundo, de menor a mayor
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}