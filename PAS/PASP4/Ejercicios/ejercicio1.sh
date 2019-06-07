#!/bin/bash

echo "-- Este es el ejercicio 1 de la practica 4 --"

echo "-------------------------------------------------------------"

grep -E '^[[:digit:]]+hr[[:space:]][[:digit:]]{2}min' peliculas.txt --colour #Todo que empiece (^) por numero (digit) una o mas veces (+) 
																	#Luego es añadir el resto de la cadena (Puede ser {2} o +) 
echo "-------------------------------------------------------------"


echo "-------------------------------------------------------------"

grep -E '\-.+\-' peliculas.txt --colour	#Empareja todo lo que se encuentre entre '-', pero debe de ser un o varios caracteres (.+)

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"

grep -o -E '\-.+\-' peliculas.txt --colour | grep -o -E '[^-].+[^-]' --colour
	#En este caso hemos pasado la salida del primer grep, que contiene los paises con '-', a la entrada del segundo grep.
	#En este segundo grep se omiten los '-' para mostrar así sólo el nombre de los paises.
echo "-------------------------------------------------------------"


echo "-------------------------------------------------------------"
	#Aqui busco por el año junto con ')' para asegurarme de que es una fecha. Despues "elimino" dicho caracter y le paso por
	#tuberia la inforamcion al comando wc para contar asi el número de lineas, que será el numero de películas que hay de ese año.
echo "Numero de peliculas del 2016:"
grep -E -o '2016)' peliculas.txt --colour | grep -E -o '.*[^)]' --colour | wc -l
echo "Y del 2017:"
grep -E -o '2017)' peliculas.txt --colour | grep -E -o '.*[^)]' --colour | wc -l

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"

grep -E '.' peliculas.txt --colour

echo "-------------------------------------------------------------"


echo "-------------------------------------------------------------"

grep -E '^[[:space:]]*E' peliculas.txt --colour

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"
	#El \1 indica que se va a usar la primera coincidencia encontrada, en este caso, se va a repetir lo que se encuentre en
	# ([dlt]{1}) .
grep -E '([dlt]{1})[aeiou]{1}\1' peliculas.txt --colour

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"

echo "** Comando de 8) en el codigo **"
#Muestra las lineas que tengan la vocal indicada, esten separadas por uno o mas caracteres cualesquiera, pero esto
#como minimo 8 o mas veces.
#--->  grep -E -i '([Aa].*){8,}' peliculas.txt --colour

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"

grep -E '^[^\ ].*[\.]{3}$' peliculas.txt --colour

echo "-------------------------------------------------------------"

echo "-------------------------------------------------------------"
	# Remplazo las vocales con tilde por esas mismas vocales (\1) pero con ' "" '.
sed -r 's/([áéíóúÁÉÍÓÚ])/"\1"/g' peliculas.txt

echo "-------------------------------------------------------------"