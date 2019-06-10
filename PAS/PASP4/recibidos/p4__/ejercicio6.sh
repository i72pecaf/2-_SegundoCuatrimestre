if [ $# -ne 1 ];
then
	echo "ERROR: Ejecución del programa: ./ejercicio6.sh <cadena>"
	exit 1
fi


oldifs=$IFS
IFS=":"
#Saco aquellas líneas las cuales tengan la shell especificada al final de la línea
cat /etc/passwd | egrep "$1$" > temporal.txt


while read -a line
do
	nombreGrupo=$(cat /etc/group | egrep ":${line[3]}" | sed -r -e 's/(.*):.*:.*:.*/\1/g')
	#Buscamos en el who solo el logname que estamos buscando y si lo encontramos
	# es porque está logeado
	if [ "$(who | egrep -o "${line[0]}")" == ${line[0]} ]; #La igualdad es redundante pero hay que asegurarnos
	then
		let logeado=1
	else
		let logeado=0
	fi

	echo "===================="

	echo "Logname: ${line[0]}"
	echo "->UID: ${line[2]}"
	echo "->Grupo:$nombreGrupo"
	echo "->GID: ${line[3]}"
	echo "->gecos: ${line[4]}"
	echo "->Home: ${line[5]}"
	echo "->Sell por defecto: ${line[6]}"
	echo "->Logeado: $logeado"
done < temporal.txt
#Vamos leyendo como elementos de un vector todos aquellos campos que se 
#han almacenado en temporal.txt


IFS=$oldifs
rm temporal.txt