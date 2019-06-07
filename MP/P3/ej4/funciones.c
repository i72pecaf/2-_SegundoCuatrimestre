#include "funciones.h"
#include <stdio.h>

int sumarDig(int num){
	if(num<10){
		return (num);
	} else {
		return(num%10+sumarDig(num/10));
	}

}
