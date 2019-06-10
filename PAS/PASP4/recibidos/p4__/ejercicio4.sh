if [ $# -ne 2 ]
then
	echo "ERROR: La ejecución del programa es: ./ejercicio2.sh <nombre_fichero.txt> <numero_segundos>"
	exit 1
fi
if [ ! -f $1 ];
then
	echo "$1 no es un fichero"
	exit 1
fi

if [ $2 -lt 1 ];
then
	echo "El número de segundos debe ser mayor o igual que 1"
	exit 1
fi


for x in $(cat $1)
do
	ping -c 1 -w $2 $x > leido.txt
	#$? : se usa para almacenar el resultado del últ comando ejecutado
	if [ ! $?  -eq 0 ];
	then
		echo "La IP $x no respondió tras $2 segundos"
	else
		cat leido.txt | sed -n -r -e '1,1d' -e '3,$d' -e 's/^.* from (.*)\:.* time\=(.*) ms/ La IP \1 respondió en \2 milisegundos/gp'
	fi
done | sort -k 5