#include "cabecera.h"
#include <stdio.h>
void verFichero(char *nombreFichero)
{
     FILE* f;
     struct DatosPersonales aux;
     
     f=fopen(nombreFichero, "r");
     
     while(fscanf(f, "%ld%s%s%f", &aux.dni, aux.nombre, aux.apellido, &aux.salario)!=EOF)
     {
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
     return cont;
}

void anadirRegistro(char *nombreFichero, struct DatosPersonales persona)
{
     FILE* f;
     
     f=fopen(nombreFichero, "a");
     fprintf(f, "%ld %s %s %f\n", persona.dni, persona.nombre, persona.apellido, persona.salario);
     fclose(f);
}

void vectorAFichero(char* nombreFichero, struct DatosPersonales* V, long nEle)
{
     FILE* f;
     long i;
     
     f = fopen(nombreFichero, "w");
     for(i=0; i<nEle; i++)
        fprintf(f, "%ld %s %s %f\n", V[i].dni, V[i].nombre, V[i].apellido, V[i].salario);  
     
     fclose(f);
}

struct DatosPersonales* ficheroAVector(char* nombreFichero, long* nEle)
{
    FILE* f;
    struct DatosPersonales* V;
    long i=0;
    
    *nEle = contarRegistros(nombreFichero);
    V = reservarVector(*nEle);
    
    f=fopen(nombreFichero, "r");
    while(fscanf(f, "%ld%s%s%f", &V[i].dni, V[i].nombre, V[i].apellido, &V[i].salario)!=EOF)
    {
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
    
    int encontrado = 0 ;
    forigen = fopen(nombreFichero, "r");
    fdestino = fopen("temporal.txt", "w");
    
    while(fscanf(forigen, "%ld%s%s%f", &aux.dni, aux.nombre, aux.apellido, &aux.salario)!=EOF)
    {
       if(aux.dni==dni)
       {  
           aux = introducirDatosPersonales();
           encontrado = 1;
       }
       
       fprintf(fdestino, "%ld %s %s %f\n", aux.dni, aux.nombre, aux.apellido, aux.salario);
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
    struct DatosPersonales aux;
    
    int encontrado = 0 ;
    forigen = fopen(nombreFichero, "r");
    fdestino = fopen("temporal.txt", "w");
    
    while(fscanf(forigen, "%ld%s%s%f", &aux.dni, aux.nombre, aux.apellido, &aux.salario)!=EOF)
    {
       if(aux.dni!=dni)
         fprintf(fdestino, "%ld %s %s %f\n", aux.dni, aux.nombre, aux.apellido, aux.salario);
       else
        encontrado = 1;
    }
    
    
    fclose(forigen);
    fclose(fdestino);
    
    remove(nombreFichero);
    rename("temporal.txt", nombreFichero);
    
    return encontrado;
    
}
