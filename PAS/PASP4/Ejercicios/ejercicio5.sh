#!/bin/bash


#Modelo de procesador y megahercios ---> /proc/cpuinfo

#Busco las lineas que tengan la información que necesito, luego tomo solamente la información que necesito,
#Esta informacion concretamente es la que se encuentra entre los ' ( )  '. 
#Muestro solo una de las lineas que dan informacion gracias al segundo sed.
cat /proc/cpuinfo | sed -r -n 's/.*(: .*[0-9]{2}GHz)/- Modelo del procesodor: \1/p' | sed -r -n '1s/(^.*$)/\1/p'
cat /proc/cpuinfo | sed -r -n 's/.* @ (.*$)/- Megahercios: \1/p' | sed -r -n '1s/(^.*$)/\1/p'


#Tamaño de caché e identificador de vendedor ---> /proc/cpuinfo

#La expresion regular es basciamente, la palabra que me localiza el dato en cuestion y despues tomar el resto de la linea
# entre parentesis, ya que este es el dato que me interesa. Luego vuelvo a hacer un sed para solo mostrar unicamente
# una vez esta informacion.
cat /proc/cpuinfo | sed -r -n 's/cache size.*: (.*$)/- Tamaño de caché: \1/p' | sed -r -n '1s/(^.*$)/\1/p'
cat /proc/cpuinfo | sed -r -n 's/vendor_id.*: (.*$)/- Identificador del vendedor: \1/p' | sed -r -n '1s/(^.*$)/\1/p'


#Numero máximo de hilos de ejecución ---> /proc/cpuinfo

#En este caso, cuento el numero de cpus gracias 'wc'. Lo almaceno en una variable para luego mostrarlo por pantalla
# con el formato deseado.
aux1=$(cat /proc/cpuinfo | grep -E 'processor.*$' | wc -l)   
echo "- Número máximo de hilos de ejecución: $aux1"


#Puntos de montaje activos ---> /proc/mounts
#Voy leyendo cada uno de los campos y los escribo en el formato deseado. Despues con sort ordeno inversamente la segunda columna.
cat /proc/mounts | sed -r -e 's/([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+)/| Punto de montaje: \2	| Dispositivo: \1	| Tipo de dispositivo: \3/' | sort -r -k2


#Listado de las particiones ---> /proc/partitions
#Leo e identifico todos los datos que da el fichero. Tomo entre parentesis aquellos que me interesan y los escribo
# en el formato que quiero. Despues elimino las dos primeras lineas ya que no interesan y despues los ordeno con sort. 
cat /proc/partitions | sed -r -e 's/[[:digit:]] *[[:digit:]]* *([[:digit:]]*) ([[:alnum:]]*$)/| Particion: \2  |  Nº de bloques: \1/p' | sed -e '1,2d' | sort -r -k1 