#!/bin/bash

if [ -d $1 ]
then
	echo "Has introducido un fichero"
else
	echo "Es obligatorio que el primer argumento sea un directorio"
	exit -1
fi

if [ $# -eq 2 ]
then
	echo "Debes de introducir los dos umbrales o ninguno."
	exit -1
fi

umbral1=10000
umbral2=100000

if [ $# -eq 3 ]
then
	umbral1=$2
	umbral2=$3
fi


if [ -d pequeno ]
then
	rm -r pequeno
fi

if [ -d mediano ]
then
	rm -r mediano
fi

if [ -d grande ]
then
	rm -r grande
fi

mkdir pequeno
mkdir mediano
mkdir grande

for x in "$(find $1 -type f)"
do
	tam=$(stat -c %s $1)
	
	if [ $tam -gt $umbral2 ]
	then
		cp $x grandes
	else
		if [ $tam -lt $umbral2 ] && [ $tam -gt $umbral1 ]
		then
			cp $x medianos
		else
			cp $x pequeno
		fi
	fi
done