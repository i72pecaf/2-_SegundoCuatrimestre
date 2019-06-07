#!/bin/bash


if [ $# -ne 1 ]
then
	echo "Error, numero de parametros incorrecto"
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "$1 no es un fichero"
	exit 1
fi

echo "El nombre introducido ha sido: $1"





sed -r -e '/^$/d' $1 | sed -r -e '/=+/d' | sed -r 's/^(\(.*\))/|-> Fecha de estreno: \1/g' | sed -r 's/Dirigida por (.*)/|-> Director: \1/g' | sed -r 's/Reparto: (.*)/|-> Reparto: \1/g' | sed -r 's/([[:digit:]]*hr[[:space:]][[:digit:]]*min)/|-> Duracion: \1/g' | sed -r '/^[[:space:].*]/d' | sed -r 's/(^[^(|)].*)/Titulo: \1/g'