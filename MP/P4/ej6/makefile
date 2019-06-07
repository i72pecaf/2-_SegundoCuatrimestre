#Makefile del ejercicio 6 de la practica 4 de Metodologia de la Programacion

crucigrama: crucigrama.x clean
	
crucigrama.x: libMemoria.a main.o ficheros.o crucigrama.o
	gcc -o crucigrama.exe libMemoria.a main.o ficheros.o crucigrama.o
	
libMemoria.a: liberaMemoria.o reservaMemoria.o
	ar -rsv libMemoria.a liberaMemoria.o reservaMemoria.o
	
main.o: main.c
	gcc -c main.c
	
crucigrama.o: crucigrama.c
	gcc -c crucigrama.c
	
ficheros.o: ficheros.c
	gcc -c ficheros.c
	
liberaMemoria.o: liberaMemoria.c
	gcc -c liberaMemoria.c
	
reservaMemoria.o: reservaMemoria.c
	gcc -c reservaMemoria.c
	
clean:
	rm -f *.o