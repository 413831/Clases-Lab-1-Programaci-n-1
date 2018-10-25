#include <stdio.h>
#include <stdlib.h>
#include "person.h"

/** ARCHIVOS
- fopen, fseek (opcional), fclose, fwrite, fread
- fscanf, fprintf
- Carga de array de punteros desde archivo
- Creacion de mascaras
- Parser
*/

int main()
{
    /*
    ﻿id,first_name,last_name,is_empty
    1,Eric,Knight,false
    */
    FILE* pArchivo = fopen("data.csv","r");//Se escribe path completo si no esta en carpeta,
                                            //Se escribe ./ o ../ para rutas relativas
    char bufferId[1024];
    char bufferName[1024];
    char bufferLastName[1024];
    char bufferIsEmpty[1024];

    Person* personita[4000];
    int index;
    int contador = 0;

 // char buffer[4096]; //Limite ficticio
    if(pArchivo != NULL)
    {
        //Se leen datos separados hasta el caracter , (COMA)
        //Se copia el caracter separados luego de la mascara
        //El formato [] recorre hasta el simbolo indicado
        while(!feof(pArchivo))//Mientras NO sea el final del archivo
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferIsEmpty);
            index = person_searchEmpty(personita,4000);
            personita[index] = person_newParametros(bufferName,bufferLastName,bufferId,bufferIsEmpty);
            contador++;
        }
        fclose(pArchivo);//Se cierra el archivo SIEMPRE al finalizar
    }
    else
    {
        printf("\nNo existe!");

    }

    index = 0;
    while(contador != 0)
    {
        person_showArray(personita[index]);
        index++;
        contador--;
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
