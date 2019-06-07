#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugadores.h"

struct Ficha_jugador* reservaVector(int nJugadores){
	struct Ficha_jugador *jugadores;

	if((jugadores = (struct Ficha_jugador*)calloc(nJugadores, sizeof(struct Ficha_jugador))) == NULL){
		printf("ERROR EN LA RESERVA DE MEMORIA\n");
		exit(-1);
	}
	return jugadores;
}

//CAMBIAR
struct Ficha_jugador leerJugador(struct Ficha_jugador *jugador, int i){

	printf("INTRODUCIENDO JUGADOR %i\n", i+1);
	printf("NOMBRE: \n");
	scanf("%s", jugador->nombre);

	printf("DORSAL: \n");
	scanf("%d", &jugador->dorsal);

	printf("PESO: \n");
	scanf("%f", &jugador->peso);

	printf("ESTATURA: \n");
	scanf("%d", &jugador->estatura);

	return *jugador;
}

//	Como solo imprimo datos --> void, ya que no devuelvo nada. El tipo de funcion es lo que voy a devolver
void imprimirJugador(struct Ficha_jugador jugador){
	printf("NOMBRE: %s\n", jugador.nombre);
	printf("DORSAL: %d\n", jugador.dorsal);
	printf("PESO: %3.2f\n", jugador.peso);
	printf("ESTATURA: %d\n", jugador.estatura);
}

void imprimirJugador2(struct Ficha_jugador *jugadores, int nJugadores){
	for(int i=0; i<nJugadores; i++){
			printf("NOMBRE: %s\n", jugadores[i].nombre);
			printf("DORSAL: %d\n", jugadores[i].dorsal);
			printf("PESO: %3.2f\n", jugadores[i].peso);
			printf("ESTATURA: %d\n", jugadores[i].estatura);
			printf("\n");
	}
}

//	INTRODUCIR UN CONTADOR QUE SE RESTE AL NUMERO DE JUGADORES Y REALLOCAR EL NUEVO VECTOR DE JUGADORES PARA IMPRIMIRLO
struct Ficha_jugador* borrarJugadoresA(struct Ficha_jugador *jugadores, int nJugadores, int caracter){

	struct Ficha_jugador *jugadores2;
	jugadores2 = reservaVector(nJugadores);

	for(int i=0; i<nJugadores; i++){
		if(strchr(jugadores[i].nombre, caracter)){
		}else{
			jugadores2[i]=jugadores[i];	//	AQUI HABRIA QUE USAR REALLOC PARA REAJUSTAR EL TAMAÑO DEL VECTOR
		}
	}

	jugadores2 = 
		
	return jugadores2;
}

int main(){

	struct Ficha_jugador jugador;
	struct Ficha_jugador *jugadores;
	int nJugadores;
	int caracter = 'a';

	printf("NUMERO DE JUGADORES: \n");
	scanf("%d", &nJugadores);
	printf("------------------------------------\n");
	jugadores = reservaVector(nJugadores);

	for(int i=0; i<nJugadores; i++){
		jugadores[i]=leerJugador(&jugador, i);
		printf("\n");
		imprimirJugador(jugador);
		printf("\n");
		jugadores=borrarJugadoresA(jugadores, nJugadores, caracter);
	}
	printf("SE IMPRIMIRAN LOS JUGADORES QUE NO CONTENGAN EL CARACTER SELECCIONADO\n");
	imprimirJugador2(jugadores, nJugadores);

	free(jugadores);

	return 0;
}