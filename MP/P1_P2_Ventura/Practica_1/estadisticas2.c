//	Funcion que recibe una cadena de caracteres y calcula, usando paso de parametros por referencia, el numero de digitos, 
//	mayusculas, minusculas y espacios que hay en la cadena.

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define MAXIMO	30
int estadisticasCadena(char *cad){
	int contador=0, i;

	//	Longitud de la cadena.
	for(i=0; cad[i]!='\0'; i++){
	}
		printf("LONGITUD: %i\n", i);

	//	Numero de digitos de la cadena.
	for(i=0; cad[i]!='\0'; i++){
		if(isdigit(cad[i])){
			contador++;
		}
	}
		printf("DIGITOS: %i\n", contador);
		contador=0;

	//	Numero de letras mayusculas.
	for(i=0; cad[i]!='\0'; i++){
		if(isupper(cad[i])){
			contador++;
		}
	}
		printf("MAYUSCULAS: %i\n", contador);
		contador=0;

	//	Numero de letras minusculas.
	for(i=0; cad[i]!='\0'; i++){
		if(islower(cad[i])){
			contador++;
		}
	}
		printf("MINUSCULAS: %i\n", contador);
		contador=0;

	//	Numero de espacios.
	for(i=0; cad[i]!='\0'; i++){
		if(isspace(cad[i])){
			contador++;
		}
	}
		printf("ESPACIOS: %i\n", contador);
		contador=0;
}

int main(){
	char cad[MAXIMO]="ESX87y4RWpfUXS43 35g3rRHS";
	char *ptr;

	estadisticasCadena(cad);

	return 0;
}