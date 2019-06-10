#Fichero /proc/cpuinfo
#Nota:
	#con head -1 o -n 1 le digo que solo me muestre la primera línea de la ocurrencia que le estamos diciendo

#Modelo de procesador y Megahercios
cat /proc/cpuinfo | sed -n -r -e 's/model name[[:blank:]]*: (.+)/Modelo de procesador: \1/p' | head -1
cat /proc/cpuinfo | sed -n -r -e 's/cpu MHz[[:blank:]]*: (.+)/Megahercios: \1/p' | head -1
#Tam de la caché
cat /proc/cpuinfo | sed -n -r -e 's/cache size[[:blank:]]*: (.+)/Tamaño de cache: \1/p' | head -1
#Id del vendedor
cat /proc/cpuinfo | sed -n -r -e 's/vendor_id[[:blank:]]*: (.+)/ID vendedor: \1/p' | head -1
#Nº máximo de hilos en ejecución.
cat /proc/cpuinfo | egrep  'processor[[:blank:]]*: .+' | echo "Número de hilos máximo de ejecución: $(wc -l)"


#Fichero /proc/mounts
#Puntos de montaje activos, incluyendo el punto de montaje, el dispositivo y el tipo de dis-
#positivo. Ordenarlos de forma alfabética inversa por punto de montaje.

#Formato:
#La primera columna especifica el dispositivo que se monta.
#La segunda columna revela el punto de montaje.
#La tercera columna indica el tipo de sistema de archivos.

echo "Puntos de montaje:"
cat /proc/mounts | sed -n -r -e 's/([^ ]+) ([^ ]+) ([^ ]+) .+/->Punto de montaje: \2, Dispositivo: \1, Tipo de dispositivo: \3/p' | sort -r -k2

#Fichero /proc/partitions
#major (1ªColumna)— Número principal (major number) del dispositivo con esta partición. El número principal en nuestro ejemplo en /proc/partitions (3), corresponde con el dispositivo ide0 en /proc/devices.
#minor (2ªColumna)— Número menor del dispositivo con esta partición. Separa las particiones en diferentes dispositivos físicos y los relaciona con el número al final del nombre de la partición.
#blocks (3ªColumna)— Lista el número de bloques de disco físicos contenidos en una partición particular.
#name (4ªColumna)— Nombre de la partición. 

echo "Partición:"
cat /proc/partitions | sed -r -e '1,2d' -e 's/ *[0-9]+ +[0-9]+ +([0-9]+) +(.+)/->Patición: \2, Nº de bloques: \1/g' | sort -r -k2