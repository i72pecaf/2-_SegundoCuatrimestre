#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Debes de introducir un argumento"
	exit -1
fi

if [ -d $1 ]
then
	echo -e
else
	echo "No has introducido un directorio"
	exit -1
fi

#Usamos find para ver los ficheros.
#Usamos sort para ordenarlos.
#Usamos wc para contar el numero de caracteres.

#Find me da por cada linea un .c y .h, por lo tanto cuento estas lineas.

for x in $(find $1 -name "*.c" && find $1 -name "*.h")
do  #Tengo que leer los ficheros dados por find para poder contar el numero de caracteres, si no estaria contando
	#el numero de caracteres de la propia linea pasada por find.
	echo "El fichero $x tiene $(cat $x | wc -l) lineas y $(cat $x | wc -m) caracteres."
done | sort -r -k8

echo -e