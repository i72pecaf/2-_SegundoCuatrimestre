#!/bin/bash


byte=$2

if [ $# -eq 1 ]
then
	byte=0
fi



if [ -d $1 ]
then
	echo -e
else
	echo "No has introducido un directorio en el primer argumento"
	exit -1
fi


for x in $(find $1 -size +$byte)
do
	if [ -x $x ]
	then
		ej=1
	else
		ej=0
	fi


	echo "$(basename $x);$(stat -c %U $x | wc -m);$(stat -c %w $x);$(stat -c %W $x);$(stat -c %s $x);$(stat -c %b $x);$(stat -c %a $x);$ej"

done | sort -r -n -k5 -t ";"

echo -e