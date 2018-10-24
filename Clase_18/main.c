#include "Cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CLIENTES    100

int main()
{
    char nombreAux[64];
    int i;
    int indexVacio;

    Cliente* aux;
    Cliente* arrayClientes[CLIENTES];


    cli_inicializarArray(arrayClientes,CLIENTES);

    // ALTA
    aux = cli_newCliente();
    indexVacio = cli_buscarLugarVacio(arrayClientes,CLIENTES);
    if(aux!=NULL && indexVacio>=0)
    {
        //aux->nombre = "Camela"; // MAL
        cli_setNombre(aux,"Juan");
        arrayClientes[indexVacio] = aux;


        cli_getNombre(aux,nombreAux);
        printf("%s",nombreAux);


    }





    return 0;
}

