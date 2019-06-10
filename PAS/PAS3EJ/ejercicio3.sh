#!/bin/bash

if [ -d $1 ]
then
	echo "Has introducido un fichero"
else
	echo "Es obligatorio que el primer argumento sea un directorio"
fi

umbral1=10000
umbral2=100000


if [ $# -eq 3 ]
then
	umbral1=$1
	umbral2=$2
fi