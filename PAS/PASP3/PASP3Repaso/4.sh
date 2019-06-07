#!/bin/bash

read -p "Introduce el nombre el usuario: " var

if [ $var == $USER ];
then
	echo "Bienvenido \"$USER\""
else
	echo "Uste es un trolero"
fi

echo -e

read -p "Introduce un numero entre [1 y 10): " num

if [ $num -lt 1 ] || [ $num -ge 10 ];
then
	echo "El numero no esta dentro del rango"
else
	echo "El numero si esta dentro del rango"
fi

echo -e

read -p "Introduce el nombre de un fichero: " fichero

if [ -f $fichero ];
then
	echo "Has introducido un fichero, realizando copia..."
	cp "$1" "$1$(date +%d-%m-%y)"
else
	echo "No has introducido un fichero"
fi