#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numero de parametros invalido"
	exit 1
fi

if [ -d /home/fran/Escritorio ]
then
	find /home/fran/Escritorio/ -type f | while read x
	do
		seg=$(date +%s) #Segundos desde el 1 de enero de 1970
		modif=$(stat -c "%Y" $x) #Última modificación del fichero
	
		dif=$(($seg - $modif))
	
		if [ $dif -gt 200 ]; #Si la diferencia es mayor a 200 segundos
		then
			#rm  $x			#No entiendo donde esta el error
		fi
	done
fi



contador=0
for x
do
	if [ -e $x ];
	then
		fecha=$(date +%s)
		vector[$contador]="$x"
		let contador=$contador+1
	else
		echo "No existe el argumento"
	fi
done

if [ $contador -eq 0 ]
then
	echo "No hay argumentos, el valor es 0"
	exit 1
fi



tar -czf copia-$USER-$fecha.tar.gz ${vector[*]}

if [ ! -e /home/fran/Escritorio ]
then
	mkdir /home/fran/Escritorio
fi

mv copia-$USER-$fecha.tar.gz /home/fran/Escritorio

echo -e
echo "· Se creado el archivo comprimido"
echo -e
