#!/bin/bash



echo -e
echo "· Se va a listar a los usuarios: "
sleep 1
who | awk '{print $1}' | sort -k1 | uniq #Uniq elimina aquellos que se repiten, y se debe de ordenar por la columna priemra (-k1)
echo -e "\n"


for x in $(ls)
do
	if [ -f $x ]
	then
		let num=num+1
	fi
done

echo "· El numero de archivos es: $num"
echo -e "\n"


read -t5 -p "· Introduce un caracter: " caracter

echo -e
if [ -z $caracter ] 
then
	caracter=a
	echo "· Se ha tomado el caracter por defecto!"
	echo -e
fi

echo "· Realizando muchas operaciones..."
sleep 3

contador=0
for x in $(ls -R)
do
	if [[ $x =~ $caracter ]]; #Se busca si coincide el caracter en alguna parte y aumenta el contador
	then
		let contador=contador+1
	fi
done

echo "· El numero de veces que aparece el caracter es: $contador"
echo -e