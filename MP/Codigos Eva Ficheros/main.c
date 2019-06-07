#include "cabecera.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    struct DatosPersonales persona;
    struct DatosPersonales* V;
    long nEle;
    int i;
    
    if(argc!=2)
    {
      printf("\nError en los parametros. Sintaxis correcta\n\t main.exe <ficheroEntrada>");
      exit (-1);
    }
    else
    {
      /*  
      persona = introducirDatosPersonales();
      anadirRegistro(argv[1], persona);
      
      persona = introducirDatosPersonales();
      anadirRegistro(argv[1], persona);
      
      persona = introducirDatosPersonales();
      anadirRegistro(argv[1], persona);  
      */
       
       printf("\nEl fichero <%s> tiene %d registros\n\n", argv[1], contarRegistros(argv[1])); 
       verFichero(argv[1]); 
       //printf("\nSe va incluir un nuevo registro:\n");
       //persona = introducirDatosPersonales();
       //anadirRegistro(argv[1], persona);
       //printf("\nEl fichero <%s> actualizado tiene %d registros\n\n", argv[1], contarRegistros(argv[1])); 
       //verFichero(argv[1]); 
      
       //printf("\nPasando fichero a un vector.....");
       //V = ficheroAVector(argv[1], &nEle);
       //vectorAFichero(argv[1], V, nEle);
       //printf("\nEl fichero <%s> tiene %d registros\n\n", argv[1], contarRegistros(argv[1])); 
       //verFichero(argv[1]); 
    
       //printf("\nActualizado registro 3333 .....\n");
       // if(actualizarporDni(argv[1], 3333))
       //    printf("\nRegistro con dni 3333 actualizado");
       // else
       //    printf("\nEl registro con dni 3333 no se encuentra en el fichero");   
       //printf("\nEl fichero actualizado <%s> tiene %d registros\n\n", argv[1], contarRegistros(argv[1])); 
       //verFichero(argv[1]); 
       
       printf("\nBorrando registro 4444 .... \n");
       if(borrarporDni(argv[1], 4444))
           printf("\nRegistro con dni 444 borrado");
       else
           printf("\nEl registro con dni 4444 no se encuentra en el fichero");   
       printf("\nEl fichero actualizado <%s> tiene %d registros\n\n", argv[1], contarRegistros(argv[1])); 
       verFichero(argv[1]); 
       
    }   
}
