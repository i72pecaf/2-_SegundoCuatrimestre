
#Comprobamos el numero de parametros sea igual a 1
# si el numero de argumentos ($#) no es igual (-ne) a 1 entonces
if [ $# -ne 1 ];
then
	echo "Error: El programa necesita un argumento $0 nombre_directorio"
	exit 1
fi


cant1=0
cant2=0
cant1=$(find $1 -name "*.c" | wc -l)
cant2=$(find $1 -name "*.h" | wc -l)
#Mostramos el resultado
echo "Existen $cant1 ficheros con extension .c y $cant2 ficheros con extension .h"

#Recorremos de nuevo el directorio y cada vez que encontremos o un .c o .h le contamos sus lineas y sus caracteres
#Mirar abajo las notas sobre cat y wc
for x in $(find $1 -type f -name "*.c" && find -type f -name "*.h")
do
	echo "El fichero $x tiene $(cat $x| wc -l) líneas y $(cat $x| wc -m) caracteres."
	#	  1     2     3   4           5          6    7         8             9
done | sort -nr -k8
