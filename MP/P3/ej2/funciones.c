#include "funciones.h"


int divisionRestas(int a, int b){

	if(b > a) {
		return 0;
	}
	else {
		return divisionRestas(a-b, b) + 1;
	}
}