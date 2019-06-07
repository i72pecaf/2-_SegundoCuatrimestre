#!/bin/bash


if [ $# -ne 2 ]
then
	echo "Error en el numero de argumentos"
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "Error, el primer argumento debe de ser un fichero"
	exit 1
fi


for x in $(cat "$1")
do

	ping -W "$2" -c 1 $x > ficheroAux1 #Guardo la información del ping en un fichero auxiliar
	
	if [ $? -eq 0 ] #La comprobación del posible error del ping
	then #Leo la informacion de ese fichero auxiliar y muestro la información en el formato deseado con seed.
		cat ficheroAux1 | sed -r -n -e 's/from ([0-9]{1}.*\.[0-9]{1}): .* time=([0.9]*.*$)/La IP \1 ha tardado: \2/p'
	else
		echo "Una de las IP no respondió corretamente"
	fi	
done | sort -k8

rm -f ficheroAux1
