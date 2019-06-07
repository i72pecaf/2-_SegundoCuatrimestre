#!/bin/bash

function listar_combinar () #Funcion recursiva que nos va a crear el listado
{
	find "$1" -maxdepth 1 | while read f
	do
		if [ ! -d "$f" ] 
		then
			echo -n "<ul>" >> "$ficheroHTML"
			echo -n "<li>$f</li>" >> "$ficheroHTML"
			echo "</ul>" >> "$ficheroHTML"
		
		else
			if [ "$1" != "$f" ] 
			then
				echo "<ul>" >> "$ficheroHTML"
				
				echo "<li><strong>$f</strong></li>" >> "$ficheroHTML"
				
				listar_combinar "$f"
				
				echo "</ul>" >> "$ficheroHTML"
			
			fi
		fi
	done
}





if [ $# -ne 1 ] || [ ! -d "$1" ] || [ $# -gt 1 ]
then
	echo "ERROR: Debe introducir $0 <nombre_directorio>"
	echo -e "\n"
	exit 1
fi

fichero="$1"
ficheroHTML="$(basename "$fichero").html"


#Se empieza a crear el fichero HTML
cat > "$ficheroHTML" << terminar 
<html>
<head>
<title>Listado del directorio $(basename "$fichero")</title>
</head>
<body>
<h1>Listado del directorio $(basename "$fichero")</h1>
terminar

listar_combinar "$fichero" 	#Se llama la funcion para que rellene el fichero HTML con el listado correspondiente

cat >> "$ficheroHTML" << terminar
</body> 
</html> 
terminar


echo -e
echo "HTML creado"
echo -e 