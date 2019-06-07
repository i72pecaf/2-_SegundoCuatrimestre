#ifndef FUNCIONES_H
#define FUNCIONES_H

struct monomio{
	int a;
	int e;
	struct monomio* sig;
};


struct monomio* nuevoElemento();
void introduceMonomio(struct monomio** cabeza, int a, int e);
void muestraPolinomio(struct monomio* cabeza);
void evaluaPolinomio(struct monomio* cabeza,float x);
void eliminaMonomio(struct monomio** cabeza, int r);

#endif