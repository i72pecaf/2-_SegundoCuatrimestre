# Comprobación de argumentos
if [ $# -ne 1 ]; #Solo recibe el nombre del directorio que tenemos que recorrer
then
	echo "ERROR: La ejecución del programa debe ser '$0 <nombre_directorio>'"
	exit 1
fi
#Compruebo que el argumento pasado sea un directorio
if [ ! -d "$1" ];
then
	echo "ERROR: El argumento $1 no es un directorio"
	exit 1
fi

#Funcionesa auxiliares
#########################################################################################
function recursivo () 
{
	find "$1" -maxdepth 1 | while read f
	do
		if [ ! -d "$f" ]; #Si no es un directorio, es un fichero
		then
			echo -n "<ul>" >> "$fichero"
			echo -n "<li>$f</li>" >> "$fichero"
			echo "</ul>" >> "$fichero"
		
		else
			if [ "$1" != "$f" ];  #Si no compruebo esto al hacer ejercicio6 . siempre se queda en la carpeta actual.
			#Si es un directorio distinto al actual
			then
				echo "<ul>" >> "$fichero"				
				#Escribimos en negrita el nombre del directorio
				echo "<li><strong>$f</strong></li>" >> "$fichero"				
				#Recorremos de nuevo la carpeta
				recursivo "$f"				
				echo "</ul>" >> "$fichero"
			
			fi
		fi
	done
}

########################################################################################
#Necesito la ruta de la carpeta introducida para poder hacerle el basename
ruta_fichero=$(readlink -f "$1")
fichero="$(basename "$ruta_fichero").html"
echo "Generando el listado de la carpeta $(basename "$ruta_fichero") sobre el fichero $fichero..."
#NOTA:
	# cat > "$FicheroHTML" << EOF
	#Permite introducir líneas que deseemos hasta que introduzcamos un carácter concreto, 
	#en este caso EOF (fin del fichero HTML)
cat > "$fichero" << EOF 
<html>
<head>
	<title>Listado del directorio $(basename "$ruta_fichero")</title>
</head>
<body>
<h1>Listado del directorio $(basename "$ruta_fichero")</h1>
<style type="text/css">
	body { font-family: sans-serif;}
</style>
EOF
recursivo "$ruta_fichero" 	


# cat >> "$FicheroHTML" << EOF --> añade información a FicheroHTML (sin sobreescribir) hasta introducir EOF
cat >> "$fichero" << EOF
</body> 
</html> 
EOF

echo "Terminado!"