#!/bin/bash


					#Para buscar solo en la carpeta actual
echo "Hay un total de $(find -maxdepth 1 -type f | wc -l) ficheros."
echo "Los usuarios logeados son: "

who | awk '{print $1}' | uniq | sort 


if ! read -t 5 -p "Introduce la letra a buscar: " caracter;
then
	caracter="a"
fi

var=0
for x in $(find .)
do
	var=$["$(basename $x | grep $caracter -o | wc -l)+$var"]
done

echo -e
echo "Se ha encontrado $var veces la letra"