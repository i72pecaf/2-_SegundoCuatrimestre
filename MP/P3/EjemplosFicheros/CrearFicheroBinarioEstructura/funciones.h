#ifndef FUNCIONES_H
#define FUNCIONES_H

struct libro{
	char titulo[256];
	char autor[256];
	char precio[999];
	char unidades[999];
};

void rellenaEstructura(struct libro* book1,char* titulo ,char* autor ,char* precio,char* unidades);
void escribirEstructura(struct libro* book1);

#endif