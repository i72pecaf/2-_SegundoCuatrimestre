if [ $# -ne 1 ]
then
	echo "ERROR: Ejecución del programa: ./ejercicio3.sh <nombre_fichero.txt>"
	exit 1
fi

echo "========================================================"
echo "Listado de archivos ocultos del directorio $HOME"
for x in $(ls -a $HOME | grep '^\.')
do
	numcar=$(echo "$x" | wc -m)
	echo "$x $numcar"
done | sort -k2 -n 


echo "========================================================"
if [ -e $1 ];
then
	if [ -f $1 ];
	then
		echo "El fichero a procesar es $1"
		cat $1 | egrep -v '^$' > $1.sinLineasVacias
		echo "El fichero sin lineas vacías se ha guardado en $1.sinLineasVacias"
	fi
fi

echo "========================================================"

echo "Listado de los procesos ejecutados por el usuario $USER: "
ps -u $USER -o pid,start,comm | sed -n -r -e 's/([0-9]+) (.*) (.*)/PID:"\1" Hora: "\2" Ejecutable: "\3"/pg'  
#nota:
#-o pid,comm nos sirve para decirle a ps que solo nos muestre los pids y los comandos
#-r para la UTILIZACIÓN DE EREs





