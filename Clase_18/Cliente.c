#include "Cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int isValidNombre(char* nom);


Cliente* cli_newCliente(void)
{
    //return (Cliente*)malloc(sizeof(Cliente));
    Cliente* p;

    p = (Cliente*)malloc(sizeof(Cliente));

    return p;
}

Cliente* cli_newClienteParametros(char* nom, char*app,int id)
{
    Cliente* p;
    p = cli_newCliente();
    if(p!=NULL)
    {
        if(setNombre(p,nom)==-1 ||
            setApellido(p,app)==-1 ||
            setId(p,id) == -1)
        {
            // malllllllllllllllllllll
            cli_deleteCliente(p);
            p=NULL;
        }
    }
    return p;
}







int cli_setNombre(Cliente* this,char* nom)
{

    if(this!=NULL && isValidNombre(nom))
    {
        strncpy(this->nombre,nom,sizeof(this->nombre));
        return 0; // todo bien
    }
    return 1;
}

static int isValidNombre(char* nom)
{
    // utn.h
    return 1;
}

int cli_getNombre(Cliente* this,char* nom)
{
    if(this!=NULL && nom!=NULL)
    {
        strncpy(nom,this->nombre,sizeof(this->nombre));
        return 0;
    }
    return 1;
}

int cli_buscarLugarVacio(Cliente* array[], int len)
{
    int i;
    int ret=-1;
    if(array!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(array[i]==NULL)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int cli_inicializarArray(Cliente* array[], int len)
{
    int ret=-1;
    int i;
    if(array!=NULL)
    {
        ret=0;
        for(i=0; i<len;i++)
            array[i] = NULL;
    }
    return ret;
}

int cli_buscarPorId(Cliente* array[],int len,
                                        int id)
{
    int i;
    int ret=-1;
    Cliente* aux;
    for(i=0; i<len; i++)
    {
        aux = array[i];
        if(aux!=NULL && aux->id==id)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int cli_deleteCliente(Cliente* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free((void*)this);
        ret = 0;
    }
    return ret;
}




