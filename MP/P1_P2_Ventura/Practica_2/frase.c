#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "frase.h"

char **reservaPalabras(int nPalabras){
	char **palabras;

	if((palabras = (char **)calloc(nPalabras, sizeof(char*))) == NULL){
		printf("ERROR 01: ESTOY AL INICIO Y NO SE RESERVAR UN MISERO VECTOR DE CHAR\n");
		exit(-1);
	}
	return palabras;
}

int main(){

	char frase[127], separadores[4] = " \n\t";
	char *ptr;
	char **palabras;
	int nPalabras = 1;

	printf("FRASE:\n");
    scanf("%[^\n]", frase);
	
//	Bucle que cuenta la cantidad de palabras que tiene una frase.
	for(int i=0; frase[i]!='\0'; i++){
		if(isspace(frase[i])){
			nPalabras++;
		}
	}
//	Reserva de la matriz** de frase de <nPalabras> palabras
	
	printf("PALABRAS:%d \n", nPalabras);
	palabras = reservaPalabras(nPalabras);

//	-------------------------------------------------------------------------------------------

	ptr = strtok(frase, separadores);
	if(ptr!=NULL)
	{	
	    if((palabras[0] = (char*)calloc(strlen(ptr)+1, sizeof(char))) == NULL){
		    printf("ERROR 02: ESTOY EN FRASE[0]\n");
		    exit(-1);
		}
	    printf( "<%s>\n", ptr );
	    strcpy(palabras[0], ptr);
        
        int j=1;
		while( (ptr = strtok( NULL, separadores)) != NULL )
		{
			if((palabras[j] = (char*)calloc(strlen(ptr)+1, sizeof(char))) == NULL){
				printf("ERROR");
		    }
		    strcpy(palabras[j], ptr);
		    j++;
		    printf( "<%s>\n", ptr );
		}

    }

    //Comprobacion
    int i;

	for(i=0; i<nPalabras; i++)
	printf("Palabras[%d]: <%s>\n", i, palabras[i]);

	return 0;
}