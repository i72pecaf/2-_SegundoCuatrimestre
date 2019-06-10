if [ $# -ne 1 ]
then
	echo "ERROR: La ejecución del programa es: ./ejercicio2.sh <nombre_fichero.txt>"
	exit 1
fi

if [ ! -f "$1" ]
then
	echo "$1 no es un fichero."
	exit 1
fi

cat $1 | sed -r -e '/^$/d' -e '/\=+/d' -e 's/\((.*)\) (.*)/|-> Fecha de estreno: \1/g' -e 's/Dirigida por (.*)/|-> Director: \1/g' -e 's/Reparto\: (.*)/|-> Reparto: \1/g' -e '/^ (.*)/d' -e 's/([0-9]hr [0-9]*min)/|-> Duración: \1/g' -e 's/(^[^\|])/Título: \1/g' 
																																																											#Para eliminar sinopsis				