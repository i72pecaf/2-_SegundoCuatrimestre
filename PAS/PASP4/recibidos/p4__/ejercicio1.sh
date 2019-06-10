if [ $# -ne 1 ];
then 
	echo "ERROR: Debe ejecutar el progama ./ejercicio1.sh <nombre_fichero.txt>"
	exit 1
fi

if [ ! -f "$1" ]; #Si no ha introducido un fichero salimos
then
	echo "ERROR: El argumento introducido no es un fichero"
	exit 1
fi

#Mostrar aquellas lı́neas que contienen la duración de la pelı́cula 
#(uno o más dı́gitos al principio de la l linea, un espacio y la secuencia “min”).

echo "***************************************************"
echo "1) Líneas con la duración de las peliculas: "
cat $1 | sed -r -n -e 's/([[:digit:]]*)(hr) ([[:digit:]]*)(min)/\1\2 \3\4/p'
# -r para el uso de EREs
# -e para ejecutar el comando indicado entre ''
# \1 \2 \3 \4 indican los valores en orden que se han cogido y los sustituyo por ellos mismos
# Cambiamos todo aquello que sea 0 o mas digitos seguido de hr y min


echo "***************************************************"
echo "2) Líneas con el país de las películas:"
#Como nos indican los paises vendran entre guiones
cat $1 | egrep '\-.+-'
#Cogeme todo aquello que tenga un guión uno o más caracteres cualesquiera y un guion.

#\ para que se coja el caracter literal del guion


echo "***************************************************"
echo "3) Sólo el país de las películas:"
cat $1 | egrep -o '\-.+-' | egrep -o '[^-].+[^-]'
# -o : le indica a grep que nos muestre sólo la parte de la línea que coincide con el patrón.


#4. Contar cuantas pel ́ıculas son del 2016 y cuantas del 2017.
echo "***************************************************"
pelicula16=$(cat $1 | egrep '\([0-9]+/[0-9]+/2016\)' | wc -l)
pelicula17=$(cat $1 | egrep '\([0-9]+/[0-9]+/2017\)' | wc -l)

echo "4) Hay $pelicula16 películas de 2016 y $pelicula17 películas de 2017"

#5. Mostrar todo el fichero pero sin lıneas vacıas.
echo "***************************************************"
echo "5) Eliminar líneas vacías:"
#-v muestra todo aquello que NOOO coincida con 'expresion'
#^$ de principio a final de la línea sin caracteres intermedios
cat $1 | egrep -v '^$'

#6. Mostrar aquellas lıneas que empiezan por la letra E (haya o no espacios antes de la misma).
echo "***************************************************"
echo "6) Lı́neas que empiezan la letra E (con o sin espacios antes):"
cat $1 | egrep '^[ ]*\E[a-z]+'


#7. Mostrar aquellas lıneas que contengan una letra ’d’, ’l’ o ’t’, una vocal, y la misma letra (por ejemplo, “Universidad”, “expectativas”, “dedicarse”...).
echo "***************************************************"	
#() para poder utilizar \1
# Emparejame todas aquellas lineas que tenga dlt-vocal-dlt siempre que el segundo dlt sea igual que el primero por eso la sustitución
#No se puede hacer con ors porque siempre cogera una de las tres, es decir, o solo coje d o l o t. ATENTOO
echo "7) Lı́neas que contienen d, l o t, una vocal y la misma letra:"
cat $1 | egrep  '([dlt])[aeiou]\1'


#8. Todas aquellas lı́neas que tengan, en total, 8 vocales a o más (mayúsculas o minú sculas y no necesariamente seguidas).
echo "***************************************************"	
echo "8) Lı́neas que contienen ocho aes o más:"
cat $1 | egrep -i '(a.*){8,}'


#9. Mostrar aquellas lıneas que terminan con tres puntos (“...”) y no empiezan por espacio, utilizando el operador de repetición \{...\} o {...}.
echo "***************************************************"	
echo "9) Lı́neas que terminan con tres puntos y no empiezan por espacio:"
cat $1 | egrep '^[^ ].+(\.{3,3})$'



#10. Utilizar sed para mostrar, entre comillas dobles, las vocales con tilde (mayúsculas o minúsculas).
# -e para el uso de ERES
# -e para ejecutar el comando que lo continua
# s:sustituir aquellas vocales con tilde por el mismo elemento \1 entre comillas y bandera g para que lo reemplace en todas las ocurrencias
echo "***************************************************"	
echo "10) Mostrar entre comillas las vocales con tilde:"
cat $1 | sed -r -e 's/([áéíóúÁÉÍÓÚ])/"\1"/g'









