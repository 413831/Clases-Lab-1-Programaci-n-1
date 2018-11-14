#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

#define BUFFER 2000

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno = -1;
    char* bufferId;
    char* bufferName;
    char* bufferHorasTrabajadas;
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
                bufferId = strtok(bufferFile,",");//Cargo las variables con los datos hasta el token ","
                bufferName = strtok(NULL,",");
                bufferHorasTrabajadas = strtok(NULL,"\n");

                if(pEmployee != NULL && atoi(bufferId) >= 0)
                {
                    pEmployee = employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,0);
                    ll_add(listaEmpleados,pEmployee);//Se agrega ELEMENTO a LINKED LIST
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

//Estudiar strstr (Busca un string dentro de un string)
//Tratar de parsear un archivo JSON
