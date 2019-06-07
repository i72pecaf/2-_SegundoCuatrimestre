//	https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm

/**
	@file es_sufijo.c
	@brief El programa comprobará al introducir dos palabras, si la segunda es prefijo o sufijo de la primera.
	@author Ventura Lucena Martínez
	@date 21-03-2019
	@version 1.0
*/
#include <string.h>
#include <stdio.h>

/**
	@fn int es_prefijo(char *cadena, char *prefijo)
	@brief La función comprobará si la segunda palabra es un prefijo de la primera.
	@param cadena Primera cadena.
	@param prefijo Segunda cadena.
	@return Retorna 1 si es prefijo.
	@return Retorna 0 si no es prejijo.
*/
int es_prefijo(char *cadena, char *prefijo){
	char *ret=cadena;

	ret=strstr(cadena, prefijo);

	if(ret==cadena){
		printf("\nES PREFIJO\n");
		return 1;
	}else{
		printf("\nNO ES PREFIJO\n");
		return 0;
	}
}

/**
	@fn int es_sufijo(char *cadena, char *sufijo)
	@brief La función comprobará si la segunda palabra es un sufijo de la primera.
	@param cadena Primera cadena.
	@param sufijo Segunda cadena.
	@return Retorna 1 si es sufijo.
	@return Retorna 0 si no es sujijo.
*/
int es_sufijo(char *cadena, char *sufijo){
	char *ret=cadena;

	ret=strstr(cadena, sufijo);
	if(ret==NULL){
		printf("NO ES SUFIJO\n");
		return 0;
	}else{
		if(strlen(ret)!=strlen(sufijo)){
			printf("NO ES SUFIJO\n");
			return 0;
		}else{
			printf("ES SUFIJO\n");
			return 1;
		}
	}
}

/**
	@fn int main()
	@brief Función principal del programa.
	@return Retorna 0 si el programa funciona con normalidad.
*/
int main(){
	char cadena[50];
	char palabra[25];

	printf("Primera palabra:\n");
	scanf("%s", cadena);

	printf("\nSegunda palabra:\n");
	scanf("%s", palabra);

	es_prefijo(cadena, palabra);
	printf("------------------------\n");
	es_sufijo(cadena, palabra);
	return 0;
}

/**
	@mainpage Introducción
	Ejercicios correspondientes a la pŕactica 1 de la asignatura de Metodología de la Programación.	
*/