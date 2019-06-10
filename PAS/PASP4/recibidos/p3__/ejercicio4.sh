#Contar el numero de archivos en el directorio actual
	#la opcion ls -p añade una / a los directorios
	# con grep -v devolvemos aquellas líneas que no tenga el caracter especificado
numero=$(ls -p|grep -v /| wc -l)
echo "El numero de archivos en la carpeta actual es $numero"

#Muestra de los usuarios conectados
echo "$(who | awk '{print $1}' | sort -k1 | uniq )"
#Peticion del caracter a buscar
if ! read -t 5 -p "¿Qué caracter desea contar? " letra;
then
	echo "ERROR: Tiempo expirado, buscando la letra a..."
	letra=a
fi

veces=0
for x in $(find .)
do
	veces=$["$(basename "$x" | grep $letra -o | wc -l)"+$veces]
done
echo "El caracter $letra aparece $veces veces en nombres de fichero o capetas contenidos en la carpeta actual."
