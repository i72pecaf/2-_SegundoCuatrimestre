#!/bin/bash



case $# in 

	0)
		echo "Se deben de introducir al menos la ruta de la carpeta"
		exit -1
		;;

		
	1)
		echo "Se ha introducido solo la ruta de la carpeta"
		echo -e
		echo "Nombre | Nº de caracteres | Fecha de creacion | Fecha de creacion UNIX | Nº Bytes | Nº Bloques | Permisos | Ejecutable o no"

		for x in $(find $1 -size +0)
		do

			if [ -x $x ]
			then
				let e=1
			else
				let e=0
			fi

			echo "$(basename $x);$(stat -c %U $x | wc -m);$(stat -c %w $x);$(stat -c %W $x);$(stat -c %s $x);$(stat -c %b $x);$(stat -c %A $x);$e"
			echo -e

		done | sort -n 
		;;
	

	2)
		if [ $2 -lt 0 ];
		then
			echo "El numero de byts no puede ser negativo"
			exit -1
		fi
		
		echo "El numero es igual o mayor que cero"
		echo -e
		echo "Nombre | Nº de caracteres | Fecha de creacion | Fecha de creacion UNIX | Nº Bytes | Nº Bloques | Permisos | Ejecutable o no"
		for x in $(find $1 -size +$2)
		do

			if [ -x $x ]
			then
				let e=1
			else
				let e=0
			fi

			echo "$(basename $x);$(stat -c %U $x | wc -m);$(stat -c %w $x);$(stat -c %W $x);$(stat -c %s $x);$(stat -c %b $x);$(stat -c %A $x);$e"
			echo -e
			
		done | sort -n
		;;


	*) 
		echo "Has introducido mas de dos parametros"
esac