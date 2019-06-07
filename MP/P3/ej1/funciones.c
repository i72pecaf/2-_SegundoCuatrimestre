#include "funciones.h"
#include <stdio.h>


int euclides(int x, int y){
    if (y == 0){
        return x;
    }else{
        return euclides(y,x % y);
    }
}