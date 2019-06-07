#ifndef FUNCIONES_H
#define FUNCIONES_H

struct libro{
	char titulo[256];
	char autor[256];
	float precio;
	int unidades;
};


int contarRegistros();
void reservaMemoriaVector(struct libro** aux,int nElem);
void introducirDatos();
void leerficheroVector();
void verRegistroi();
void buscarPorLibro();
void modificarUnidiades();
void borrarAutor();
#endif