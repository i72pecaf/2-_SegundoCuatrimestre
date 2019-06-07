#!/bin/bash


if [ $# -eq 0 ] || [ $# -gt 1 ];
then
	echo -n
	echo "Debes de introducir solo un argumento"
	exit 1
	echo -n
fi

echo "El argumento introducido ha sido $1"

echo -e 

cant1=$(find $1 -name "*.c" | wc -l)	#OJO, cuenta el numero de lineas DE LO QUE SE LE HA PASADO 
cant2=$(find $1 -name "*.h" | wc -l)	#TIENE LAS RUTAS DE LOS ARCHIVOS

echo "Hay un total de $cant1 archivos .c"
echo "Hay un total de $cant2 archivos .h"

echo -e 

 for x in $(find $1 -name "*.c" -o -name "*.h") #Por cada archivo .c o .h se pasa el for. Se puede ver
 do 											#como que find "devuelve una lista y cada elemento de la lista se pasa a x"
 	echo "El numero de lines de $x es $(cat $x | wc -l) y el numero de caracteres es: $(cat $x | wc -m) "
 done | sort -nr -k8 #El resultado del for se le pasa a sort para ordenarlo y mostrarlo despues.
