#!/bin/bash

read -p "Introduce el primer numero: " num1
read -p "Introduce el segundo numero: " num2

echo "Suma: $num1+$num2"
echo "Resultado: $[num1+$num2]"
echo -e

echo "Resta: $num1-$num2"
echo "Resultado: $[num1-$num2]"
echo -e

echo "Multiplicacion: $num1*$num2"
echo "Resultado: $[num1*$num2]"
echo -e

echo "Division: $num1+$num2"
echo "Resultado: $[num1/$num2]"
echo -e

echo "Exponienciacion: $num1^$num2"
echo "Resultado: $[num1**$num2]"
echo -e

echo "Modulo: $num1%$num2"
echo "Resultado: $[num1%$num2]"
echo -e