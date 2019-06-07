#!/bin/bash


if [ $# -ne 1 ] #En el caso de que el numero de parametros introducido sera mayor que uno, dara un Error
then			#Ya que solo se debe de introducir un solo parametro
	echo "Error en el numero de parametros"
	exit 1
fi

if [ ! -f "$1" ] #Comprobamos que el parametro introducido sea un fichero, en caso de que no lo sea, saltara un error
then
	echo "Error, se debe de introducir un fichero"
	exit 1
fi


echo "=== Ficheros ocultos ordenados por su numero de caracteres ==="

for x in $(ls -a $HOME) #La opcion '-a' nos muestra un listado con los ficheros ocultos
do
	#Utilizo una expresion regular para comprobar si la linea dada por "ls" comienza con '.' ya que si es así, significa
	#que el fichero esta oculto. Se usa el ' =~ ' para comprara con una expresion regular.
	
	if [[ "$x" =~ ^\. ]]
	then #Guardo la informacion del nombre del fichero y su numero de caracteres en un fichero auxiliar
		echo "$x $(echo "$x" | wc -m)" >> ej3Prueba.txt
	fi

done
	#Despues leo ese fichero ordenandolo por la segunda columna y por orden numerico.
	#Con seed elimino el numero de caracteres del fichero, solo toma la parte que empieza por ' . ' hasta el espacio.
cat ej3Prueba.txt | sort -n -k2 | sed -r 's/(\..*[[:space:]]).*$/\1/g'
	#Finalmente borro el fichero auxiliar, evitando repetir informacion y para no usar memoria del disco.
rm -f ej3Prueba.txt

echo "=============================================================="

echo -e "\n"

echo "=== Copia del fichero que se ha introducido por la linea de comandos ==="

cat "$1" | sed '/^$/d' > $1.sinLineasVacias #Simlpemente leo el fichero, se lo paso a sed donde se eliminaran las lineas en blanco
											#Y creare el fichero sin espacios con el nombre del fichero original ($1)
echo -e
echo "Realizando copia..."
sleep 2
echo -e
echo "Se ha realizado la copia del fichero"
echo -e
echo "========================================================================="

echo -e

echo "=== Listado de procesos del usuario ejecutandose actualmente ==="


ps -u $USER | sed -r 's/[[:space:]]([0-9]*) (.*) ([0-9]*:[0-9]*:[0-9]*) (.*)$/PID -> \1 | TTY -> \2 | TIME -> \3 | CMD -> \4/'