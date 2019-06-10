# Comprobación de argumentos
if [ $# -eq 0 ]; 
then
	echo "ERROR: El programa necesita, al menos, un fichero como argumento."
	exit 1
fi

# Borramos aquellos archivos de la carpeta Copia cuya antigüedad sea mayor a 200 segundos
if [ -e $PWD/Copia ]; 
then

	fecha_actual=$(date +%s)
	for x in $(find $PWD/Copia -type f) 
	do
		fecha_creacion=$(stat -c "%Y" $x)
		let "diferencia=$fecha_actual-$fecha_creacion"
		echo "$diferencia segundos"
		if [ $diferencia -gt 200 ]; 
		then
			echo "Borrando $x de $diferencia segundos"
			rm $x
		fi
	done	

fi

#Comprimimos aquellos archivos que han quedado en nuestro array de validos.
tar -czf copia-$USER-$fecha_actual.tar.gz $*

#Comprobamos si existe el directorio Copia sino lo creamos.
if [ ! -e $PWD/Copia ] || [ ! -d $PWD/Copia ];
then
	mkdir $PWD/Copia
fi
#Movemos el archivo comprimido al directorio Copia
mv copia-$USER-$fecha_actual.tar.gz $PWD/Copia/
echo "La copia de seguridad se ha creado correctamente."


