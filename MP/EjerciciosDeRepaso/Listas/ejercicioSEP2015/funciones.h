#ifndef FUNCIONES_H
#define FUNCIONES_H

struct lista{
	int n;
	struct lista* sig;
};

struct lista* nuevoElemento();
void introducirElemento(struct lista** cabeza,int a);
void mostrarLista(struct lista* cabeza);
void verMayorMenor(struct lista* cabeza,int* max,int* min);

#endif