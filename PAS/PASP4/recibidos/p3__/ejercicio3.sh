# Comprobación de argumentos
if [ $# -eq 0 ] || [ $# -ge 4 ]; 
then
	echo "Error! Debe ejecutar el programa de la forma:"
	echo "$0 <nombre_directorio> [<umbral_inferior>] [<umbral_superior>]"
	exit 1
else
	#Comprobamos si ha introducido los umbrales
	if [ $# -eq 1 ]; 
	then
		umbral1=10000
		umbral2=100000
	else
		if [ $# -eq 2 ]; then
			umbral1=$1
			umbral2=100000
		else
			umbral1=$1
			umbral2=$2
		fi
	fi
fi #fin comprobación argumentos
#comprobación si existen las carpetas
if [ -d pequenos ] && [ -d medianos ] && [ -d grandes ]; 
then
	echo  "Las carpetas de salida ya existen, se va a proceder a borrarlas..."
	rm -d -r pequenos
	rm -d -r medianos
	rm -d -r grandes
#-d borra directorios vacios
# -r de forma recursiva, borra tambien el contenido de carpetas que tenga
fi
#Creación de carpetas
echo "Creando las carpetas pequenos, medianos y grandes..."
mkdir pequenos
mkdir medianos
mkdir grandes

#Inclusión de los ficheros segun su tamaño
	#comando cp : Copy SOURCE to DEST
echo "Copiando los archivos..."
for x in $(find $1 -type f)
do	
	if [ $(stat -c "%s" $x) -lt $umbral1 ]; 
	then
		cp $x pequenos
	else
		if [ $(stat -c "%s" $x) -gt $umbral1 ] && [ $(stat -c "%s" $x) -lt $umbral2 ]; then
			cp $x medianos
		else
			cp $x grandes
		fi
	fi
done