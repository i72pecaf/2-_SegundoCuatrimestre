#include "funciones.h"


int calcularCaracter(char c, char x, int nEle){

	if(c > x) {
		return 0;
	}
	else {
		return calcularCaracter(c-x, c, nEle-1) + 1;
	}
}