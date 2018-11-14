#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

#define BUFFER 2000

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno = -1;
    char bufferId[BUFFER];
    char bufferName[BUFFER];
    char bufferHorasTrabajadas[BUFFER];
    char bufferFile[BUFFER];
    Empleado* pEmployee;
    FILE* auxFile = fopen(fileName,"r");

    if(auxFile != NULL)
    {
        //Se puede utilizar el nombre del archivo como el primer string para el strtok
        fgets(bufferFile,sizeof(bufferFile),auxFile);//Leo todo el archivo y guardo en string bufferFile

        if(bufferFile != NULL)
        {
            strtok(bufferFile,"\n");//Seteo el el strtok
            while(!feof(auxFile))//Mientras no sea el end of file
            {
                bufferId[BUFFER] = strtok(NULL,",");//Cargo las variables con los datos hasta el token ","
                bufferName[BUFFER] = strtok(NULL,",");
                bufferHorasTrabajadas[BUFFER] = strtok(NULL,"\n");

                if(pEmployee != NULL && atoi(bufferId) >= 0)
                {
                    pEmployee = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,0);
                    ll_add(listaEmpleados,pEmployee);//Se agrega ELEMENTO a LINKED LIST
                    retorno = 0;
                }
            }
        }
        bufferId[BUFFER] = strtok(bufferFile,",");
        bufferName[BUFFER] = strtok(bufferFile,",");
        bufferHorasTrabajadas[BUFFER] = strtok(bufferFile,"\n");
    }
    return retorno;
}

//Estudiar strstr (Busca un string dentro de un string)
//Tratar de parsear un archivo JSON
