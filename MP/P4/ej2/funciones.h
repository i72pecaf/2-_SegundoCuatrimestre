#ifndef FUNCIONES_H
#define FUNCIONES_H

struct alumno {
	char nombre[50];
	int DNI;
	float nota;
};

int mayor(int a, int b);
int menor(int a, int b);
void contarRegistros(char* fichero,int* nElem);
void reservarMemoriaVector(struct alumno** vector,int nElem);
void rellenarVector(struct alumno* vector,int nElem,char* fichero);
void ordenaVectorBurbuja(struct alumno* vector,int nElem, int (*comparar) (int,int));

#endif