#Comprobamos el numero de parametros sea 1 o 2
# si el numero de argumentos ($#) es igual (-ne) a 0 o mayor que 3 entonces
if [ $# -eq 0 ]|| [ $# -ge 3 ];
then
	echo "Error: El prgrama se inicia de la forma: $0 <nombre_directorio> [<numero_bytes>]"
	exit 1
fi

if [ $# -eq 1 ];
then
	#No han introducido el segundo argumeto, establecemos el valor a 0.
	tamano=0
else
	#si se han introducido dos argumentos, el segundo es el numero de bytes
	#tamano es el numero de bytes pasados por agumento
	tamano=$2
fi
echo "Nombre, longitud usuario, fecha de modificacion, fecha ultimo acceso, tamaño, bloques, permisos, ejecutable"
#Recorremos los ficheros del directorio indicado, de los cuales cogeremos aquellos cuyo  tamaño sea igual o superior al indicado en el segundo argumento del programa.
for x in $(find $1 -type f -size "$tamano"c -or -size +"$tamano"c)
do
	#COmprobamos si es un fichero ejecutable
	if [ -x $x ];
	then
		ejecutable="Ejecutable"
	else
		ejecutable="No ejecutable"
	fi

	#Nombre del fichero sin ruta.
	nombre_fichero=$(basename $x)
	#Numero de caracteres del nombre del usuario propietario
	n_nombre_prop=$(stat -c %U $x | wc -m)
	#Fecja ultima modificación
	fecha_mod=$(stat -c %y $x)
	#Fecha del ultimo acceso al fichero
	ult_acc=$(stat -c %X $x)
	#Tamaño en bytes
	tam_bytes=$(stat -c %s $x)
	#Numero de bloques que ocupa en memoria
	num_bloq=$(stat -c %b $x)
	#La cadena de permisos del fichero
	permisos=$(stat -c %A $x)	
	echo "$nombre_fichero ; $n_nombre_prop ; $fecha_mod ; $ult_acc ; $tam_bytes ; $num_bloq ; $permisos ; $ejecutable"
	#               1               2                3         4          5            6             7           8            
done | sort -n -k5 -t ";"
#la opcion -t le indica al sort que el caracter separador de columnas es el ;

