#!/bin/bash 
echo -n "Introduzca un número entre 1 <= x < 10: "
read x 
case $x in
	1) echo "Valor de x es 1.";;
	2) echo "Valor de x es 2.";;
	3) echo "Valor de x es 3.";;
	4) echo "Valor de x es 4.";;
	5) echo "Valor de x es 5.";;
	6) echo "Valor de x es 6.";;
	7) echo "Valor de x es 7.";;
	8) echo "Valor de x es 8.";;
	9) echo "Valor de x es 9.";;
	0 | 10) echo "Número incorrecto.";;
	*) echo "Valor no reconocido.";;
esac 
