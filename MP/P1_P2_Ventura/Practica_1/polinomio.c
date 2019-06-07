//	https://www.tutorialspoint.com/cprogramming/c_structures.htm
//	http://platea.pntic.mec.es/vgonzale/cyr_0204/cyr_01/control/lengua_C/estructuras.htm

/**
	@file polinomio.c
	@brief El programa leerá e imprimirá un monomio introducido por teclado.
	@author Ventura Lucena Martínez
	@date 26-03-2019
	@version 1.0
*/
#include <stdio.h>
/**
	@struct Monomio
	@brief Estructura que almacenará los datos de un monomio: coeficiente y grado.
*/
struct Monomio{
		///	Coeficiente del monomio.
		int coeficiente;
		///	Grado del monomio.
		int grado;
};

/**
	@fn struct Monomio leerMonomio(struct Monomio *m, int i)
	@brief Funcion que recibe una estructura pasada por referencia y permite leer los datos de un monomio.
	@param *m Puntero de tipo estructura monomio.
	@param i Indicador del monomio actual.
	@return *m.
*/
struct Monomio leerMonomio(struct Monomio *m, int i){
	printf("\nCOEFICIENTE MONOMIO %i: \n", i+1);
	scanf("%d", &m->coeficiente);
	printf("GRADO MONOMIO: \n");
	scanf("%d", &m->grado);

	return *m;
}

/**
	@fn struct Monomio imprimirMonomio(struct Monomio m)
	@brief Funcion que recibe una estructura y muestra el coeficiente y el grado del monomio.
	@param m Monomio m cualquiera de tipo estructura monomio.
	@return
*/
struct Monomio imprimirMonomio(struct Monomio m){
	printf("(%dx^%d)", m.coeficiente, m.grado);
}

/**
	@fn int main()
	@brief Función principal del programa.
	@return Retorna 0 si el programa funciona con normalidad.
*/
int main(){

	struct Monomio m;
	struct Monomio polinomio[50];
	int cantidad;

	printf("¿Cuantos monomios desea introducir?\n");
	scanf("%i", &cantidad);
	printf("-------------------------------------------\n");

	for(int i=0; i<cantidad; i++){
		polinomio[i]=leerMonomio(&m, i);
		imprimirMonomio(m);
		printf("\n");
	}
	printf("-------------------------------------------\n");
	for(int i=0; i<cantidad; i++){	
		polinomio[i]; 
		if(i<cantidad){
			printf("(%dx^%d)", polinomio[i].coeficiente, polinomio[i].grado);
			if(i<cantidad-1){
			printf(" + ");
			}
		}
	}
	printf("\n");

	return 0;
}
