#!/bin/bash

echo -e
if [ $# -eq 0 ] || [ $# -ge 4 ];
then
	echo "Numero de parametros invalido"
	echo -e "\n"
	exit 1
else
	if [ $# -eq 1 ];
	then
		umbral1=10000
		umbral2=100000
	fi
fi

if [ $# -eq 2 ]
then
	echo "Error, debes de introducir al menos 3 parametros"
	exit 1
fi

if [ $# -eq 3 ];
then
	umbral1=$2
	umbral2=$3
fi

#Se puede indicar la carpeta donde queremos guardar los archivos, pero como el enunciado no lo indica, se localizaran las carpetas en el directorio
#donde se encuentra el script.

if [ -e grandes ] && [ -e medianos ] && [ -e medianos ]
then
	rm -d -r grandes
	rm -d -r medianos
	rm -d -r pequenos
fi

mkdir grandes
mkdir medianos
mkdir pequenos

echo "· Carpetas creadas"


echo "· Se van a copiar los archivos..."

for x in $(find $1)
do
	if [ -f $x ] #Solo entra cuando es un archivo
	then
		tam=$(stat -c "%s" $x) #Cuando es un archivo, toma su tamaño con stat
		
		if [ $tam -gt $umbral2 ]; #Se compara el tamaño con el umbral y apartir de aqui se decide en que carpeta guardarlo.
		then
				cp $x grandes
		else
			if [ $tam -lt $umbral1 ];
			then
					cp $x pequenos
			else
					cp $x medianos

			fi
		fi
	fi
done

sleep 3
echo -e
echo "· Archivos copiados!"
echo -e