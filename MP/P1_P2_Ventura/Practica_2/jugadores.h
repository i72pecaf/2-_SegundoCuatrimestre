#ifndef FICHA_H
#define FICHA_H

struct Ficha_jugador{
	char nombre[50];
	int dorsal;
	float peso;
	int estatura;
};

struct Ficha_jugador* reservaVector(int nJugadores);
struct Ficha_jugador leerJugador();
void imprimirJugador(struct Ficha_jugador jugador);
void imprimirJugador2(struct Ficha_jugador *jugadores, int nJugadores);
struct Ficha_jugador* borrarJugadoresA(struct Ficha_jugador *jugadores, int nJugadores, int caracter);

#endif