#include <stdio.h>
#include "cabecera.h"

void verFichero(char *nombreFichero)
{
    FILE* f;
    struct DatosPersonales aux;
    
    f = fopen(nombreFichero, "rb");
    
    while(fread(&aux, sizeof(struct DatosPersonales), 1, f)==1)
    {
        escribirDatosPersonales(aux);   
    }
    
    fclose(f);
}

long contarRegistros(char *nombreFichero)
{
    FILE* f; 
    long bytes;
    
    f = fopen(nombreFichero, "rb");
    
    //cursor al final del fichero
    fseek(f, 0L, SEEK_END);  
    
    //Bytes desde el principio hasta el final
    bytes = ftell(f);

    fclose(f);
    
    return bytes/sizeof(struct DatosPersonales);
}


void anadirRegistro(char *nombreFichero, struct DatosPersonales persona)
{
     FILE* f;
     
     f = fopen(nombreFichero, "ab");
     
     fwrite(&persona, sizeof(struct DatosPersonales), 1, f); 
      
     fclose(f);
}     

void vectorAFichero(char* nombreFichero, struct DatosPersonales* V, long nEle)
{
     FILE* f;
     
     f = fopen(nombreFichero, "wb"); //si el fichero existe lo elimina
     //f = fopen(nombreFichero, "ab"); //añade los elementos al final, sin eliminar fichero
     
     fwrite(V, sizeof(struct DatosPersonales), nEle, f);
     
     fclose(f);
     
}

struct DatosPersonales* ficheroAVector(char* nombreFichero, long* nEle)
{
    FILE* f;
    
    *nEle = contarRegistros(nombreFichero);
    struct DatosPersonales * V = reservarVector(*nEle);
    
    f=fopen(nombreFichero, "rb");
    
    fread(V, sizeof(struct DatosPersonales), *nEle, f);
 
 
    fclose(f);
    return V;       
}


int actualizarporDni(char* nombreFichero, long dni)
{
    FILE* f;  
    int encontrado = 0; 
    struct DatosPersonales aux;
    
    f = fopen(nombreFichero, "r+b");
    while(fread(&aux, sizeof(struct DatosPersonales), 1, f)==1)
    {
         if(aux.dni==dni)
         {
            encontrado = 1;
            aux = introducirDatosPersonales();
            
            //retrocedemos una posicion el cursor
            fseek(f, -1*sizeof(struct DatosPersonales), SEEK_CUR);
            
            //escribimos el registro actualizado
            fwrite(&aux, sizeof(struct DatosPersonales), 1, f);
            fflush(f);
         }                  
    }
    
    fclose(f);
    return encontrado;
}    
    
    
int borrarporDni(char *nombreFichero, long dni)
{
     FILE* forigen;
     FILE* fdestino;
     int encontrado = 0;
     struct DatosPersonales aux;
     
     forigen = fopen(nombreFichero, "rb");
     fdestino = fopen("temporal", "wb");
     
     while(fread(&aux, sizeof(struct DatosPersonales), 1, forigen)==1)
     {
        if(aux.dni != dni)
          fwrite(&aux, sizeof(struct DatosPersonales), 1, fdestino);  
        else
          encontrado = 1;
     }
     
    fclose(forigen);
    fclose(fdestino);
    
    remove(nombreFichero);
    rename("temporal", nombreFichero);
    
    return encontrado;
    
}    



