#include "cabecera.h"
#include <stdio.h>
#include <string.h>

void verFichero(char *nombreFichero)
{
     FILE* f;
     struct DatosPersonales aux;
     char linea[MAX_LINEA];
     
     f=fopen(nombreFichero, "r");

     while(fgets(linea, MAX_LINEA, f)!=NULL)
     {
          //Procesamos dni              
          sscanf(linea, "%ld", &aux.dni);
                        
          //Procesamos nombre
          fgets(linea, MAX_LINEA, f); 
          limpiarLinea(linea);
          strcpy(aux.nombre, linea); 
          
          //Procesamos apellido
          fgets(linea, MAX_LINEA, f);
          limpiarLinea(linea);
          strcpy(aux.apellido, linea);  
                    
          //procesamos salario          
          fgets(linea, MAX_LINEA, f);
          sscanf(linea, "%f", &aux.salario);  
          
          escribirDatosPersonales(aux);               
     }
     
     
     fclose(f);
}     

long contarRegistros(char *nombreFichero)
{
     FILE* f;
     long cont=0;
     char linea[MAX_LINEA];
     
     f=fopen(nombreFichero, "r");
     while(fgets(linea, MAX_LINEA, f)!=NULL)
     {
        cont++;
     }
     
     fclose(f);
     return cont/NUM_CAMPOS;
}

void anadirRegistro(char *nombreFichero, struct DatosPersonales persona)
{
     FILE* f;
     
     f=fopen(nombreFichero, "a");
     fprintf(f, "%ld\n%s\n%s\n%f\n", persona.dni, persona.nombre, persona.apellido, persona.salario);
     fclose(f);
}

void vectorAFichero(char* nombreFichero, struct DatosPersonales* V, long nEle)
{
     FILE* f;
          
     long i;
     
     f = fopen(nombreFichero, "w");
     for(i=0; i<nEle; i++)
        fprintf(f, "%ld\n%s\n%s\n%f\n", V[i].dni, V[i].nombre, V[i].apellido, V[i].salario);  
     
     fclose(f);
}

struct DatosPersonales* ficheroAVector(char* nombreFichero, long* nEle)
{
    FILE* f;
    struct DatosPersonales* V;
    long i=0;
    char linea[MAX_LINEA];
    
    *nEle = contarRegistros(nombreFichero);
    V = reservarVector(*nEle);
    
    f=fopen(nombreFichero, "r");
    while(fgets(linea, MAX_LINEA, f)!=NULL)
    {
         //procesamos el dni
         sscanf(linea, "%ld", &V[i].dni);
         
         //procesamos el nombre
         fgets(linea, MAX_LINEA, f);
         limpiarLinea(linea);
         strcpy(V[i].nombre, linea);
         
         //procesamos el apellido
         fgets(linea, MAX_LINEA, f);
         limpiarLinea(linea);
         strcpy(V[i].apellido, linea);
 
         //procesamos el salario               
         fgets(linea, MAX_LINEA, f);
         sscanf(linea, "%f", &V[i].salario);    
         
         i++;          
    }
    
    fclose(f);
    return V;
}    


int actualizarporDni(char* nombreFichero, long dni)
{
    FILE* forigen;
    FILE* fdestino;
    struct DatosPersonales aux;
    char linea[MAX_LINEA];
    
    int encontrado = 0 ;
    forigen = fopen(nombreFichero, "r");
    fdestino = fopen("temporal.txt", "w");
    
    while(fgets(linea, MAX_LINEA, forigen)!=NULL)
    {
          //Procesamos dni              
          sscanf(linea, "%ld", &aux.dni);
                        
          //Procesamos nombre
          fgets(linea, MAX_LINEA, forigen); 
          limpiarLinea(linea);
          strcpy(aux.nombre, linea); 
          
          //Procesamos apellido
          fgets(linea, MAX_LINEA, forigen);
          limpiarLinea(linea);
          strcpy(aux.apellido, linea);  
                    
          //procesamos salario          
          fgets(linea, MAX_LINEA, forigen);
          sscanf(linea, "%f", &aux.salario);  
    
          if(aux.dni == dni)
          {
              aux = introducirDatosPersonales();
              encontrado = 1;           
          }
          
          fprintf(fdestino, "%ld\n%s\n%s\n%f\n", aux.dni, aux.nombre, aux.apellido, aux.salario);  
   
    }
    fclose(forigen);
    fclose(fdestino);
    
    remove(nombreFichero);
    rename("temporal.txt", nombreFichero);
    
    return encontrado;
    
}    


int borrarporDni(char *nombreFichero, long dni)
{
   FILE* forigen;
   FILE* fdestino;
   int encontrado = 0;
   struct DatosPersonales aux;
   char linea[MAX_LINEA];
     
   forigen = fopen(nombreFichero, "rb");
   fdestino = fopen("temporal", "wb");
    
    while(fgets(linea, MAX_LINEA, forigen)!=NULL)
    {
          //Procesamos dni              
          sscanf(linea, "%ld", &aux.dni);
                        
          //Procesamos nombre
          fgets(linea, MAX_LINEA, forigen); 
          limpiarLinea(linea);
          strcpy(aux.nombre, linea); 
          
          //Procesamos apellido
          fgets(linea, MAX_LINEA, forigen);
          limpiarLinea(linea);
          strcpy(aux.apellido, linea);  
                    
          //procesamos salario          
          fgets(linea, MAX_LINEA, forigen);
          sscanf(linea, "%f", &aux.salario);  
    
          if(aux.dni != dni)
            fprintf(fdestino, "%ld\n%s\n%s\n%f\n", aux.dni, aux.nombre, aux.apellido, aux.salario);  
          else
            encontrado = 1;  
    }
    
    
    fclose(forigen);
    fclose(fdestino);
    
    remove(nombreFichero);
    rename("temporal", nombreFichero);
    
    return encontrado;
    
}
