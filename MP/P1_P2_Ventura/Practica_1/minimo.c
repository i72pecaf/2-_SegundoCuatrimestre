/**
	@file minimo.c
	@brief Programa que comprueba cual de los dos número introducidos por teclado es el mínimo.
	@author Ventura Lucena Martínez
	@date 26-03-2019
	@version 1.0
*/
#include <stdio.h>

/**
	@fn int minimo(int num1, int num2)
	@brief Funcion que recibe dos numeros num1 y num2 de tipo int pasados por valor.
	@param num1 Primero número introducido por teclado.
	@param num2 Segundo número introducido por teclado.
	@return El mínimo de los dos números introducidos.
*/
int minimo(int num1, int num2){
	if(num1<num2){
		return num1;
	}
	if(num1>num2){
		return num2;
	}
	if(num1==num2){
		return num1;
	}
}

/**
	@fn int minimo_referencia(int num1, int num2, int *resultado)
	@brief Funcion que recibe dos numeros num1 y num 2 de tipo int pasados por valor. Recibe ademas otro parametro denominado resultado de tipo int pero pasado por referencia.
	@param num1 Primero número introducido por teclado.
	@param num2 Segundo número introducido por teclado.
	@param *resultado Mínimo de los dos números.
	@return El mínimo de los dos números introducidos.
*/
int minimo_referencia(int num1, int num2, int *resultado){
	*resultado=minimo(num1, num2);
	return *resultado;
}

/**
	@fn int main()
	@brief Función principal del programa.
	@return 0 si el programa funciona con normalidad.
*/
int main(){
	int num1, num2, resultado;

	printf("Introduzca el primer dígito\n");
	scanf("%i", &num1);

	printf("Introduzca el segundo dígito\n");
	scanf("%i", &num2);

	if((num1<num2) || (num1>num2)){
		printf("FUNCION MINIMO: %i\n", minimo(num1, num2));
	}else{
		printf("FUNCION MINIMO: %i\n", minimo(num1, num2));
	}

	printf("FUNCION MINIMO_REFERENCIA: %i\n", minimo_referencia(num1, num2, &resultado));
	return 0;
}