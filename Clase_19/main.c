#include <stdio_ext.h>
#include <stdlib.h>
#include "person.h"

/** ARCHIVOS
- fopen, fseek (opcional), fclose, fwrite, fread
- fscanf, fprintf
*/

int main()
{
    /*
    ﻿id,first_name,last_name,is_empty
    1,Eric,Knight,false
    */
    FILE* pArchivo = fopen("data.csv","r");//Se escribe path completo si no esta en carpeta, ./ o ../ para rutas relativas

    char bufferId[1024];
    char bufferName[1024];
    char bufferLastName[1024];
    char bufferIsEmpty[1024];

    Person* personita = NULL;

 //   char buffer[4096]; //Limite ficticio

    if(pArchivo != NULL && personita == NULL)
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferIsEmpty);

        personita = person_newParametros(bufferName,bufferLastName,bufferId,bufferIsEmpty);

        printf("\nNOMBRE - %s",personita->name);
        printf("\nAPELLIDO - %s",personita->lastName);
        printf("\nID - %s",personita->id);
        printf("\nIS EMPTY - %s",personita->status);




    /*  while(!feof(pArchivo))
        {
            //  fscanf(pArchivo,"%s\n",buffer);
            //  printf("\n%s",buffer);
            //Se leen datos separados hasta el caracter , (COMA)
            //Se copia el caracter separados luego de la mascara
            //El formato [] recorre hasta el simbolo indicado
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferIsEmpty);
            printf("\n%s - %s - %s - %s ",bufferId,bufferName,bufferLastName,bufferIsEmpty);
        }*/
        fclose(pArchivo);//Se cierra el archivo SIEMPRE al finalizar
    }
    else
    {
        printf("\nNo existe!");

    }

    return 0;

 /*   do//Contabilizar cantidad de elementos de un archivo
    {

    cantidadLeida = read(texto,sizeof(Empanada),1,pArchivo);
    //new
    //se van creando de uno elementos auxiliares y se contabilizan
    }
    while(cantidadLeida != 0);*/

    return 0;
}
