#include "funciones.h"
#include <stdio.h>

int contarCaracter(char* cadena, char* c){
	
	if(*cadena == '\0'){
		return 0;
	} else {
		if (*cadena == *c){	//El * por la aritmetica de punteros (con cadenas)
			return 1 + contarCaracter(cadena + 1 , c);	//Se pasa siempre el siguiente elemento de la cadena
		} else {
			return 0 + contarCaracter(cadena +1, c);
		}
	}	
}