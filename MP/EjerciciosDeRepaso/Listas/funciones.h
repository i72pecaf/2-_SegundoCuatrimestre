#ifndef FUNCIONES_H
#define FUNCIONES_H

struct lista{ //Creación de la estructura de cada nodo de la lista.
	int n;	//Cualquier información que haya dentro del nodo.
	struct lista* sig; //Puntero del mismo tipo que permite unir los nodos.
};

void insertarDelante(struct lista** cabeza, int n); //Reserva memoria para un nuevo elemento y lo introduce por la cabeza
void insertarDetras(struct lista** cabeza, int n);
void mostrarLista(struct lista* cabeza);
int buscarElemento(struct lista* cabeza,int b);
void borrarElemento(struct lista** cabeza, int r);
void borrarLista(struct lista** cabeza);

#endif