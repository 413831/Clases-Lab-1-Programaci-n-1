#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "../inc/Controller.h"
#include "../inc/LinkedList.h"
#include "../inc/People.h"
#include "../inc/utn.h"
#include "../inc/parser.h"

#define BUFFER 4000
#define LEN_LL 6

extern int errno ;

/**
* \brief Muestra la fecha actual y el horario
* \param void
* \return Retorna fecha y hora en formato string sino retorna NULL
*/
static char* fecha()
{
    char* retorno = NULL;
    time_t rawtime;//Variable tipo time_t
    struct tm *info;//Tipo de dato tm para cargar fecha y hora

    time(&rawtime);//Se obtiene dia y hora actual
    info = localtime( &rawtime );//Se obtiene formato para fecha y hora
    retorno = asctime(info);

    // printf("%s", asctime(info));//Se muestra informacion
    return retorno;
}

/**
 * \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path Ruta del archivo para leer
 * \param pLinkedList Es el LinkedList
 * \return retorna 0 si el array no es null y el archivo existe sino retorna -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pLinkedList)
{
    int retorno = -1;
    FILE* pFile = fopen(path,"r");

    if(pLinkedList != NULL && path != NULL)
    {
        ll_clear(pLinkedList);
        if(!parser_PeopleFromText(pFile,pLinkedList))
        {
            retorno = 0;
            fclose(pFile);
        }
    }
    return retorno;
}

/**
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path Ruta del archivo para leer
 * \param pLinkedList Es el LinkedList
 * \return retorna 0 si el array no es null y el archivo existe sino retorna -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pLinkedList)
{
    FILE* pArchivo = fopen(path,"rb");
    int retorno = -1;
    if(pLinkedList != NULL && path != NULL)
    {
        retorno = parser_PeopleFromBinary(pArchivo,pLinkedList);
    }
    fclose(pArchivo);
    return retorno;
}

/**
 * \brief Alta de empleados
 * \param pLinkedList Es el LinkedList donde se agregara el empleado
 * \return Retorna 0 si se logra hacer el alta sino retorna -1
 *
 */
int controller_addPeople(LinkedList* pLinkedList)
{
    int retorno = -1;
    limpiarPantalla();

    if(pLinkedList != NULL)
    {
        printf("<ALTA>");
        if(!people_add(pLinkedList))
        {
            printf("\nAlta realizada.");
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Modifica datos de empleado
 * \param pLinkedList Es el LinkedList del cual se va a editar un empleado
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_editPeople(LinkedList* pLinkedList)
{
    int retorno = -1;
    limpiarPantalla();
    if(pLinkedList != NULL)
    {
        if(!people_edit(pLinkedList))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *          El listado de bajas se guarda automaticamente
 * \param listaPrincipal Es el array de LinkedList para utilizar listados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_removePeople(LinkedList* listaPrincipal[])
{
    int retorno = -1;
    char path[BUFFER] = {"../files/bajas.csv"};

    limpiarPantalla();
    if(listaPrincipal != NULL)
    {
        printf("<BAJA>");
        if(!people_remove(listaPrincipal[1],listaPrincipal[2]))
        {
            controller_saveAsText(path,listaPrincipal[2]);
            printf("\nBaja realizada.");
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Reincorpora un empleado del listado de inactivos hacia el de activos
 * \param listaPrincipal Es el array de LinkedList para utilizar listados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_insertPeople(LinkedList* listaPrincipal[])
{
    int retorno = -1;

    if(listaPrincipal != NULL)
    {
        if(!people_insert(listaPrincipal[1],listaPrincipal[2]))
        {
            printf("\nEmpleado incorporado.");
            retorno = 0;
        }
    }
    return retorno;
}


/**
 * \brief Listar empleados
 * \param pLinkedList Es la LinkedList de la cual se desea listar los elementos
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListPeople(LinkedList* pLinkedList)
{
    int retorno = -1;

    if(pLinkedList != NULL && !ll_isEmpty(pLinkedList))
    {
        ll_map(pLinkedList,people_show);
        printf("\nTotal empleados %d",ll_len(pLinkedList));
    }
    else
    {
        printf("\nLista inexistente");
    }
    return retorno;
}

/** \brief Genera una nueva lista a partir de la primer lista
 *          la nueva lista se guarda como archivo
 * \param listaPrincipal Es el array de LinkedList para utilizar listados
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_generateNewList(LinkedList* listaPrincipal[])
{
    limpiarPantalla();
    int retorno = -1;
    char nombreArchivo[BUFFER];
    int index;
    char path[BUFFER] = {"../files/"};

    if(listaPrincipal != NULL)
    {
        printf("<GENERAR LISTA>");

        if(!people_generarLista(listaPrincipal[1],listaPrincipal,&index))
        {
            printf("\n>> Atención! si el archivo ya existe sera reemplazado por el actual.");
            input_getPath(nombreArchivo,BUFFER,"\nIngrese nombre de archivo a guardar\n>>","Nombre invalido",2);
            strcat(path,nombreArchivo);
            controller_saveAsText(path,listaPrincipal[index]);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Eliminar una lista o todas las listas
 * \param pLinkedList Es el LinkedList del cual se va a editar un empleado
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_deleteList(LinkedList* pLinkedList[])
{
    int retorno = -1;

    if(pLinkedList != NULL)
    {
        printf("<BORRAR LISTA>");
        if(!people_borrarLista(pLinkedList))
        {
            retorno = 0;
        }
    }
    else
    {
        printf("\nLista inexistente.");
    }
    return retorno;
}

/**
 * \brief Ordenar empleados por criterio y orden
 * \param pLinkedList Es la LinkedList que se desea ordenar
 * \return retorna 0 si se logra ordenar sino retorna -1
 *
 */
int controller_sortPeople(LinkedList* pLinkedList)
{
    int retorno = -1;

    if(pLinkedList != NULL)
    {
        if(!people_sort(pLinkedList))
        {
            retorno = 0;
        }
    }
    return retorno;
}


/** \brief Carga la lista temporal para deshacer todos los cambios
 *          Se reemplaza lista de activos por lista temporal
 * \param pLinkedList Es la LinkedList que se desea deshacer cambios
 * \param pLinkedListTemp Es la LinkedList de donde se toman los datos
 * \return retorna 0 si se logra ordenar sino retorna -1
 *
 */
int controller_undoList(LinkedList* listaPrincipal[])
{
    int retorno = -1;
    char verification[5];

    if(listaPrincipal != NULL)
    {
        input_getLetras(verification,2,"\nATENCION!\nDesea deshacer todos los cambios? S/N\n","\nError.",2);
        if(!strcasecmp("s",verification))
        {
            listaPrincipal[1] = ll_clone(listaPrincipal[0]);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Guarda los datos de los empleados en archivo en la carpeta /files (modo texto).
 * \param path Ruta donde se guardara el archivo
 * \param pLinkedList Es la LinkedList con los elementos a guardar
 * \return Retorna 0 si se logra guardar sino retorna -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pLinkedList)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    printf("<GUARDAR TEXTO>");
    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pLinkedList))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/**
 * \brief Guarda los datos de los empleados en archivo en la carpeta /files (modo binario).
 * \param path Ruta donde se guardara el archivo
 * \param pLinkedList Es la LinkedList con los elementos a guardar
 * \return Retorna 0 si se logra guardar sino retorna -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pLinkedList)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pLinkedList))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/**
 * \brief Menu con opciones para trabajar con la LinkedList
 * \param void
 * \return Retorna 0 siempre
 */
int controller_init()
{
    int option;
    int flag = 0;
    int counter = 0;//variable de seguridad del len del linkedlist
    LinkedList* listaPrincipal[LEN_LL];//Array estatico que agrupa 6 linkedlist
    char nombreArchivo[BUFFER];//auxiliar para escribir nombre de archivo
    char path[BUFFER];//ruta para guardar el archivo. ../files/ Es la carpeta de archivos predeterminada

    ll_initLinkedList(listaPrincipal);
    /*
    /   lista[1] - listado activos
    /   lista[2] - listado modificado
    */

    do
    {
        printf("%s\n>>>MENU PRINCIPAL<<<\n",fecha());
        printf("\n1) Abrir archivo\n2) Listar\n3) Alta\n4) Editar\n5) Baja");
        printf("\n10) Reincorporar empleado\n11) Deshacer cambios\n12) Salir");
        input_getEnteros(&option,"\nIngrese opcion: ","\nDato invalido",2);

        switch(option)
        {
            case 1: //ABRIR ARCHIVO
                strcpy(path,"../files/");//Seteo el path predeterminado
                if(!input_getEnteros(&option,"\n1) Abrir modo texto\n2) Abrir en modo binario\n3) Volver\n>> ","\nError",2))
                {
                    if(option == 3){
                        break;
                    }

                    if(!input_getPath(nombreArchivo,BUFFER,"\nIngrese nombre de archivo: ","Nombre invalido",2))
                    {
                        strcat(path,nombreArchivo);//Union entre nombre de archivo y path
                        if(!controller_loadFromText(path,listaPrincipal[1]))//Cargo el archivo
                        {
                            printf("\nArchivo |%s| cargado.",nombreArchivo);
                            counter = ll_len(listaPrincipal[1]);
                            flag = 1;
                        }
                        else if(option == 2 && !controller_loadFromBinary(path,listaPrincipal[1]))
                        {
                            printf("\nArchivo |%s| cargado.",nombreArchivo);
                            counter = ll_len(listaPrincipal[1]);
                            flag = 1;
                        }
                    }
                    else
                    {
                        printf("\nArchivo inexistente.");
                    }
                    printf("\nTotal empleados: %d",ll_len(listaPrincipal[1]));
                }
                break;
            case 2: //LISTAR
                if(counter > 0)
                {
                    limpiarPantalla();
                    printf("<LISTAR>");//Selecciono lista para mostrar
                    printf("\n1) Empleados activos\n2) Listado modificado");
                    printf("\n3) Volver");
                    input_getEnteros(&option,"\nIngrese opcion: ","\nError",2);

                    if(option == 3)
                    {
                        break;
                    }
                    else if(option >= 1 && option <= 2 )
                    {
                        controller_ListPeople(listaPrincipal[option]);
                    }
                }
                else
                {
                    printf("\nNo hay datos cargados");
                }
                break;
             case 3 : //GENERAR LISTAS
                if(counter > 0)
                {
                    if(!controller_generateNewList(listaPrincipal))
                    {
                        printf("\nLista generada.");
                    }
                }
                else
                {
                    printf("\nNo hay datos cargados");
                }
                break;
            case 4: //GUARDAR ARCHIVO
                strcpy(path,"../files/");//Seteo el path predeterminado
                if(!input_getEnteros(&option,"\n1) Guardar modo texto\n2) Guardar en modo binario\n3) Volver\n>> ","\nError",2))
                {
                    if(option == 3){
                        break;
                    }

                    if(!input_getPath(nombreArchivo,BUFFER,"\nIngrese nombre de archivo: ","Nombre invalido",2))
                    {
                        strcat(path,nombreArchivo);//Union entre nombre de archivo y path
                        if(!controller_saveAsText(path,listaPrincipal[1]))//Cargo el archivo
                        {
                            printf("\nArchivo |%s| cargado.",nombreArchivo);
                            counter = ll_len(listaPrincipal[1]);
                            flag = 1;
                        }
                        else if(option == 2 && !controller_saveAsBinary(path,listaPrincipal[1]))
                        {
                            printf("\nArchivo |%s| cargado.",nombreArchivo);
                            counter = ll_len(listaPrincipal[1]);
                            flag = 1;
                        }
                    }
                    else
                    {
                        printf("\nArchivo inexistente.");
                    }
                    printf("\nTotal empleados: %d",ll_len(listaPrincipal[1]));
                }
                break;
            case 5 : //SALIR
                break;
            default :
                printf("\nOpcion incorrecta");
        }
        pause();
        limpiarPantalla();
    }while(option != 5);
    return 0;
}
