#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/People.h"
#include "../inc/LinkedList.h"
#include "../inc/utn.h"

#define BUFFER 4000
#define LEN_LL 6

/////////////////////////////////////////////////STATIC/////////////////////////////////////////////////////////////////////

/**
*\brief Valida un nombre del elemento
*\param name Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidName(char* name)
{
    int retorno = 0;

    if(name != NULL && validacion_Letras(name,strlen(name)))
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida un apellido del elemento
*\param name Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidLastName(char* lastName)
{
    int retorno = 0;

    if(lastName != NULL && validacion_Letras(lastName,strlen(lastName)))
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida sueldo del elemento
*\param sueldo Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidSueldo(int sueldo)
{
    int retorno = 0;

    if(sueldo > 1000)
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida ID del elemento
*\param id Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidId(int id)
{
    int retorno = 0;

    if(id >= 0)
    {
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Valida isEmpty del elemento
*\param id Es el string a validar
*\return Retorna 1 si es correcto sino retorna 0
*/
static int isValidIsEmpty(int isEmpty)//Revisar parametros
{
    int retorno = 0;

    if(isEmpty == 1 || isEmpty == 0)
    {
        retorno = 1;
    }
    return retorno;
}


/**
*\brief Filtra elemento por el campo nombre segun parametro establecido por usuario
*\param this Es el elemento a filtrar
*\return Retorna 0 si es correcto sino retorna 1
*/
static int criterioNombre(void* this)
{
    int retorno = -1;
    static char paramName[BUFFER];
    static int flag = 0;
    char elementName[BUFFER];

    if(this != NULL)
    {
        if(flag == 0)
        {
            input("\n>>Ingrese nombre: ",paramName,BUFFER,validacion_Letras);//Solicito nombre para comparar;
            flag = 1;
        }
        people_getNombre(this,elementName);//Obtengo nombre del elemento
        if(!strcmp(elementName,paramName))//Comparo ambos datos
        {
            retorno = 0;
        }
    }
    else//Si el elemento es NULL se resetea el flag para solicitar nuevamente parametro
    {
        flag = 0;//RESET
    }
    return retorno;
}

/**
*\brief Filtra elemento por el campo sueldo segun parametro establecido por usuario
*\param this Es el elemento a filtrar
*\return Retorna 0 si es correcto sino retorna 1
*/
static int criterioSueldo(void* this)
{
    int retorno = -1;
    static char paramSueldo[BUFFER];
    static int flag = 0;
    int elementSalary;

    if(this != NULL)
    {
        if(flag == 0)
        {
            input("\n>>Sueldos mayores a cifra\nIngrese cifra: ",paramSueldo,BUFFER,validacion_Int);
            flag = 1;
        }
        people_getSueldo(this,&elementSalary);
        if(elementSalary > atof(paramSueldo))//Comparo el sueldo del elemento contra el numero ingresado
        {
            retorno = 0;
        }
    }
    else//Si el elemento es NULL se resetea el flag para solicitar nuevamente parametro
    {
        flag = 0;//RESET
    }
    return retorno;
}

/**
*\brief Filtra elemento por el campo nombre segun parametro establecido por usuario
*\param this Es el elemento a filtrar
*\return Retorna 0 si es correcto sino retorna 1
*/
static int criterioApellido(void* this)
{
    int retorno = -1;
    static char paramLastName[BUFFER];
    static int flag = 0;
    char elementLastName[BUFFER];

    if(this != NULL)
    {
        if(flag == 0)
        {
            input("\n>>Ingrese nombre: ",paramLastName,BUFFER,validacion_Letras);//Solicito nombre para comparar;
            flag = 1;
        }
        people_getNombre(this,elementLastName);//Obtengo nombre del elemento
        if(!strcmp(elementLastName,paramLastName))//Comparo ambos datos
        {
            retorno = 0;
        }
    }
    else//Si el elemento es NULL se resetea el flag para solicitar nuevamente parametro
    {
        flag = 0;//RESET
    }
    return retorno;
}

/**
*\brief Filtra elemento por el campo id segun parametro establecido por usuario
*\param this Es el elemento a filtrar
*\return Retorna 0 si es correcto sino retorna 1
*/
static int criterioId(void* this)
{
    int retorno = -1;
    static char paramId[BUFFER];
    static int flag = 0;
    int elementId;

    if(this != NULL)
    {
        if(flag == 0)
        {
             input("\n>>Filtrar por ID mayor a numero\nIngrese numero: ",paramId,BUFFER,validacion_Int);
             flag = 1;
        }
        people_getId(this,&elementId);
        if(elementId > atoi(paramId))//Se compara el Id del elemento contra el Id ingresado
        {
            retorno = 0;
        }
    }
    else//Si el elemento es NULL se resetea el flag para solicitar nuevamente parametro
    {
        flag = 0;//RESET
    }
    return retorno;
}


/**
*\brief Se setea las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
static int copyId(People* this,char* id)
{
    int retorno=-1;
    int auxId;

    if(this!=NULL && isValidId(atoi(id)))
    {
        auxId = atoi(id);
        this->id = auxId;
        retorno=0;
    }
    return retorno;
}


////////////SORT CRITERIOS///////////////


/**
*\brief Funcion criterio por campo nombre
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el campo del primer elemento es mayor al segundo,
*\       retorna -1 si el campo del primer elemento es menor al segundo,
*\       retorno 0 si son iguales,
*/
static int people_criterioNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char bufferStrA[BUFFER];
    char bufferStrB[BUFFER];

    people_getNombre(((People*)thisA),bufferStrA);
    people_getNombre(((People*)thisB),bufferStrB);

    printf("\nOrdenando.");
    if(strcmp(bufferStrA,bufferStrB) > 0)
    {
        printf("\nOrdenando..");
        retorno = 1;
    }
    else if(strcmp(bufferStrA,bufferStrB) < 0)
    {
        printf("\nOrdenando...");
        retorno = -1;
    }
    printf("\nOrdenando....");
    return retorno;
}

/**
*\brief Funcion criterio por campo sueldo
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el campo del primer elemento es mayor al segundo,
*\       retorna -1 si el campo del primer elemento es menor al segundo,
*\       retorno 0 si son iguales,
*/
static int people_criterioSueldo(void* thisA,void* thisB)
{
    int retorno = 0;
    int sueldoA = 0;
    int sueldoB = 0;

    people_getSueldo(((People*)thisA),&sueldoA);
    people_getSueldo(((People*)thisB),&sueldoB);

    if(sueldoA > sueldoB)
    {
        printf("\nOrdenando.");
        retorno = 1;
    }
    else if(sueldoA < sueldoB)
    {
        printf("\nOrdenando..");
        retorno = -1;
    }
    printf("\nOrdenando...");
    return retorno;
}

/**
*\brief Funcion criterio por campo apellido
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el campo del primer elemento es mayor al segundo,
*\       retorna -1 si el campo del primer elemento es menor al segundo,
*\       retorno 0 si son iguales,
*/
static int people_criterioApellido(void* thisA,void* thisB)
{
    int retorno = 0;
    char bufferStrA[BUFFER];
    char bufferStrB[BUFFER];

    people_getApellido(((People*)thisA),bufferStrA);
    people_getApellido(((People*)thisB),bufferStrB);

    printf("\nOrdenando.");
    if(strcmp(bufferStrA,bufferStrB) > 0)
    {
        printf("\nOrdenando..");
        retorno = 1;
    }
    else if(strcmp(bufferStrA,bufferStrB) < 0)
    {
        printf("\nOrdenando...");
        retorno = -1;
    }
    printf("\nOrdenando....");
    return retorno;
}

/**
*\brief Funcion criterio por campo ID
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el campo del primer elemento es mayor al segundo,
*\       retorna -1 si el campo del primer elemento es menor al segundo,
*\       retorno 0 si son iguales,
*/
static int people_criterioId(void* thisA,void* thisB)
{
    int retorno = 0;
    int idA = 0;
    int idB = 0;

    people_getId(((People*)thisA),&idA);
    people_getId(((People*)thisB),&idB);

    if(idA > idB)
    {
        printf("\nOrdenando.");
        retorno = 1;
    }
    else if(idA < idB)
    {
        printf("\nOrdenando..");
        retorno = -1;
    }
    printf("\nOrdenando...");
    return retorno;
}

///////////////////////////////////////////////////PUBLIC/////////////////////////////////////////////////////////////////

/**
*\brief Reserva espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
People* people_new()
{
    People* this;
    this=malloc(sizeof(People));
    if(this != NULL)
    {
      return this;
    }
    else
    {
        return NULL;
    }
}

/**
*\brief Es el constructor del elemento donde se reserva memoria y se setean los campos
*\param id Es el dato id para setear en el campo del elemento
*\param nombre Es el dato nombre para setear en el campo del elemento
*\param horasTrabajadas Es el dato horasTrabajadas para setear en el campo del elemento
*\param sueldo Es el dato sueldo para setear en el campo del elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
People* people_newConParametros(char* id,char* nombre,char* apellido,char* isEmpty,char* sueldo)
{
    People* this;
    this = people_new();

    int idInt = atoi(id);
    int sueldoInt = atoi(sueldo);
    int isEmptyInt;

    if(!strcasecmp("true",isEmpty))
    {
        isEmptyInt = 1;
    }
    else if(!strcasecmp("false",isEmpty))
    {
        isEmptyInt = 0;
    }

    if(isValidId(idInt) &&
       isValidName(nombre) &&
       isValidIsEmpty(isEmptyInt) &&
       isValidSueldo(sueldoInt) &&
       !people_setAll(this,idInt,nombre,apellido,sueldoInt,isEmptyInt))
    {
        return this;
    }
    else
    {
        people_delete(this);
        return NULL;
    }
}

/**
*\brief Se recorre array para encontrar elemento por ID
*\param pLinkedList Es el array para recorrer
*\param idIngresado Es ID para encontrar
*\return Retorna el elemento sino retorna NULL
*/
People* people_getById(void* pLinkedList,int idIngresado)
{
    People* retorno = NULL;
    People* auxPeople;
    int index;
    int auxID = 0;

    if(pLinkedList != NULL)
    {
        for(index=0;index<ll_len(pLinkedList);index++)//Recorro todo el array hasta el LEN
        {
            auxPeople = ll_get(pLinkedList,index);//Obtengo el elemento del array en posicion index
            people_getId(auxPeople,&auxID);//Obtengo el ID del elemento
            if(auxID == idIngresado)//Comparo el Id del elemento con el Id ingresado
            {
                retorno = auxPeople;
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pLinkedList Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
int people_add(void* pLinkedList)
{
    int retorno = -1;
    char bufferName[BUFFER];
    char bufferLastName[BUFFER];
    char bufferSueldo[BUFFER];
    char bufferIsEmpty[BUFFER];
    People* this = NULL;

    if( !input("nombre",bufferName,BUFFER,validacion_Letras) &&
        !input("apellido",bufferLastName,BUFFER,validacion_Letras) &&
        !input("sueldo",bufferSueldo,BUFFER,validacion_Int) &&
        !input("estado",bufferIsEmpty,BUFFER,validacion_Int))
    {
        this = people_newConParametros("0",bufferName,bufferLastName,bufferIsEmpty,bufferSueldo);//Revisar
        if(this != NULL)
        {
            people_show(this);
            ll_add(pLinkedList,this);
            retorno = 0;;
        }
    }
    return retorno;
}

/**
*\brief Se da de baja un elemento seteando el ID en valor especifico
*\param pArray Es el array para recorrer
*\return Retorna 0 si existe el ID sino retorna -1
*/
int people_remove(void* pLinkedList,void* pListInactives)
{
    int retorno = -1;
    int index;
    char bufferId[BUFFER];
    char option[2];
    People* this = NULL;

    if(!input("ID",bufferId,BUFFER,validacion_Int))
    {
        this = people_getById(pLinkedList,atoi(bufferId));//Busco el elemento del Id ingresado
        if(this != NULL)
        {
            people_show(this);//Muestro datos del elemento
            input_getLetras(option,2,"\nATENCION!\nDesea dar de baja a empleado? S/N\n","\nError.Dato invalido",2);
            if(!strcasecmp("s",option))
            {
                index = ll_indexOf(pLinkedList,this);
                this = ll_pop(pLinkedList,index);//Se saca el elemento del LinkedList

                ll_add(pListInactives,this);//Se agrega el elemento a la otra LinkedList
                retorno = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado no existe");
        }
    }
    return retorno;
}

/**
*\brief Libera espacio en memoria ocupado por un elemento
*\param this Es el elemento
*\return Retorna 0 si logra liberar sino retorna -1
*/
int people_delete(People* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Copia los campos de un elemento a otro
*\param thisA Es el elemento hacia donde se va a copiar (destination)
*\param thisB Es el elemento de donde se va a copiar (source)
*\return Retorna 0 si logra copiar sino retorna -1
*/
int people_copy(People* thisA,People* thisB)
{
    int retorno = -1;
    char bufferName[BUFFER];
    char bufferLastName[BUFFER];
    char bufferId[BUFFER];
    int auxId;
    int auxIsEmpty;
    int auxSueldo;

    if(thisA != NULL && thisB != NULL)
    {
        people_getAll(thisB,&auxId,bufferName,bufferLastName,&auxSueldo,&auxIsEmpty);
        sprintf(bufferId,"%d",auxId);////CORREGIR
        copyId(thisA,bufferId);
        people_setNombre(thisA,bufferName);
        people_setApellido(thisA,bufferLastName);
        people_setSueldo(thisA,auxSueldo);
        people_setIsEmpty(thisA,auxIsEmpty);

        retorno = 0;
    }
    return retorno;
}

/**
*\brief Reemplaza un elemento del LinkedList por otro
*\param pLinkedList Es el puntero al LinkedList
*\param auxElement Es el elemento con el que se va a reemplazar
*\param index Es el indice donde se desea reemplazar elemento
*\return Retorna 0 si logra reemplazar sino retorna -1
*/
int people_replace(LinkedList* pLinkedList,void* auxElement,int index)
{
    int retorno = -1;
    char option[2];

    if(pLinkedList != NULL && auxElement != NULL && index >= 0 && index <= ll_len(pLinkedList))
    {
        input_getLetras(option,2,"\nDesea modificar dato? S/N\n","\nError.Dato invalido",2);
        if(!strcasecmp("s",option))
        {
            ll_set(pLinkedList,index,auxElement);
            printf("\nModificacion realizada.");
            retorno = 0;
        }
        pause();
    }
    return retorno;
}

/**
*\brief Reincorpora un empleado en el listado de activos
*\param pListActives Es el puntero al listado de activos
*\param pListInactives Es el puntero al listado de inactivos
*\return Retorna 0 si logra reincorporar sino retorna -1
*/
int people_insert(LinkedList* pListActives,LinkedList* pListInactives)
{
    int retorno = -1;
    char bufferId[BUFFER];
    People* auxPeople;
    People* prevPeople;
    int index;
    int idIngresado;

    if(pListActives != NULL && pListInactives != NULL)
    {
        printf("\n<CAMBIAR STATUS EMPLEADO>");
        ll_map(pListInactives,people_show);//Muestro los datos del empleado inactivo
        printf("\nSeleccione ID de empleado");

        input("ID",bufferId,BUFFER,validacion_Int);
        idIngresado= atoi(bufferId);

        auxPeople = people_getById(pListInactives,idIngresado);//Obtengo el empleado inactivo seleccionado
        if(auxPeople != NULL)
        {
            people_show(auxPeople);

            do//Se busca el anterior al ID ingresado hasta encontrar elemento valido
            {
                prevPeople = people_getById(pListActives,idIngresado-1);
                idIngresado--;
            }
            while(prevPeople == NULL);

            index = ll_indexOf(pListActives,prevPeople);
            ll_push(pListActives,index+1,auxPeople);//Se reincorpora el empleado inactivo
            index = ll_indexOf(pListInactives,auxPeople);//Busco indice del empleado inactivo en listado de bajas
            ll_remove(pListInactives,index);
            retorno = 0;
        }
    }
    return retorno;
}


/**
*\brief Se busca elemento por ID a modificar con opciones de campos
*\param pLinkedList Es el array a recorrer
*\return Retorna 0 si logra modificar campo sino retorna -1
*/
int people_edit(void* pLinkedList)
{
    int retorno = -1;
    int option;
    char bufferId[BUFFER];
    char buffer[BUFFER];
    int index;
    People* this = NULL;
    People* auxElement = people_new();

    if(pLinkedList != NULL)
    {
        do
        {
            retorno = 0;
            limpiarPantalla();
            printf("\n<MODIFICAR DATOS>");
            printf("\n1) Nombre\n2) Sueldo\n3) Horas trabajadas\n4) Volver");
            input_getEnteros(&option,"\nIngrese opcion: ","\nError.Dato invalido",2);

            if(option == 4)
            {
                break;
            }
            input("ID",bufferId,BUFFER,validacion_Int);
            this = people_getById(pLinkedList,atoi(bufferId));
            index = ll_indexOf(pLinkedList,this);

            if(this == NULL)
            {
                printf("\nID no encontrado");
                continue;
            }
            else if(this != NULL && auxElement != NULL)
            {
                people_copy(auxElement,this);
                people_show(auxElement);
            }

            switch(option)
            {
                case 1 :
                    input("nombre",buffer,BUFFER,validacion_Letras);
                    people_setNombre(auxElement,buffer);
                    people_replace(pLinkedList,auxElement,index);
                    break;
                case 2 :
                    input("apellido",buffer,BUFFER,validacion_Letras);
                    people_setApellido(auxElement,buffer);
                    people_replace(pLinkedList,auxElement,index);
                    break;
                case 3 :
                    input("sueldo",buffer,BUFFER,validacion_Int);
                    people_setSueldo(auxElement,atoi(buffer));
                    people_replace(pLinkedList,auxElement,index);
                    break;
                case 4 :
                    break;
                default :
                    printf("\nOpcion invalida");
            }
        }while(option != 4);
    }
    return retorno;
}

/**
*\brief Se muestran los datos de todos los campos del elemento
*\param this Es el puntero al elemento
*\return Retorna 0 si el elemento es diferente a NULL sino retorna -1
*/
int people_show(void* this)
{
    int retorno = -1;
    int auxId;
    int auxSueldo;
    int auxIsEmpty;
    char auxNombre[128];
    char auxApellido[128];
    char IsEmpty[BUFFER];
    if(this != NULL)
    {
        people_getId(this,&auxId);
        if(auxId != -1)
        {
            people_getNombre(this,auxNombre);
            people_getApellido(this,auxApellido);
            people_getId(this,&auxId);
            people_getIsEmpty(this,&auxIsEmpty);
            people_getSueldo(this,&auxSueldo);

            sprintf(IsEmpty,"%d",auxIsEmpty);

            printf("\nID -- %d",auxId);
            printf(" / Nombre -- %s",auxNombre);
            printf(" / Apellido -- %s",auxApellido);
            printf(" / Sueldo -- $%d",auxSueldo);
            printf(" / Is Empty -- %s",IsEmpty);
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Funcion para ordenar el LinkedList segun criterio y orden
*\param pLinkedList Es la LinkedList para ordenar
*\return Retorna 0 si logra ordenar sino retorna -1
*/
int people_sort(void* pLinkedList)
{
    int retorno = -1;
    function_type criterio;
    int orden;

    limpiarPantalla();
    if(pLinkedList != NULL)
    {
        printf("\n<ORDENAR>");
        criterio = people_ordenCriterio();
        if(criterio != NULL)
        {
            input_getEnteros(&orden,"\n-Seleccione orden\n Descendente (0)\n Ascendente (1)","Error.",2);

            if(orden == 0 || orden == 1)
            {
                ll_sort(pLinkedList,criterio,orden);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
*\brief Aumentar sueldo
*\param pPeople Es el elemento para aumentarle el sueldo
*\param porcentaje Es el porcentaje de aumento
*\return Retorna puntero a funcion segun criterio seleccionado si no es correcto retorna NULL
*/
int people_aumentarSueldo(void* this,int porcentaje)
{
    int retorno = -1;
    int sueldo;

    if(this != NULL && porcentaje > 0 && porcentaje <= 100)
    {
        people_getSueldo(this,&sueldo);
        printf("\nSUELDO SIN AUMENTO %d",sueldo);
        sueldo += (porcentaje * sueldo) / 100;
        people_setSueldo(this,sueldo);
        printf("\nSUELDO SIN AUMENTO %d",sueldo);
    }
    return retorno;
}

/**
*\brief Funcion selector de criterio para ordenar
*\return Retorna puntero a funcion segun criterio seleccionado si no es correcto retorna NULL
*/
void* people_ordenCriterio()
{
    int opcion;

    void* retorno = NULL;
    input_getEnteros(&opcion,"\nSeleccione opcion\n1) Nombre\n2) Apellido\n3) Sueldo\n4) ID\n5) Volver\n","\nOpcion incorrecta",2);

    switch(opcion)
    {
        case 1 :
            printf("\nNombre");
            retorno = people_criterioNombre;
            break;
        case 2 :
            printf("\nApellido");
            retorno = people_criterioApellido;
            break;
        case 3 :
            printf("\nSueldo");
            retorno = people_criterioSueldo;
            break;
        case 4 :
            printf("\nID");
            retorno = people_criterioId;
            break;
        case 5 :
            return retorno;
            break;
        default :
            printf("\nOpcion incorrecta");
    }
    return retorno;
}

/**
* \brief Generar una lista de empleados segun opciones, sublist, filter, clone.
* \param this Es el puntero al LinkedList original
* \param newList Es el puntero al LinkedList nuevo
* \return Retorna 0 si el LinkedList no es NULL sino retorna -1
*/
int people_generarLista(LinkedList* pLinkedList,LinkedList* listaPrincipal[],int* index)
{
    int retorno = -1;
    int option;
    int from = 0;
    int to = 0;
    int len;
 //   criterio_type criterio;
    void* auxLinkedList = ll_newLinkedList();
    printf("\n1) Aumentar sueldos\n2) Volver\n");
    input_getEnteros(&option,"\nIngrese opcion: ","\nDato invalido",2);

    if(pLinkedList != NULL)
    {
        len = ll_len(pLinkedList);
        switch(option)
        {
            case 1 :
                if(from >= 0 && from < len && to >= 1 && to < len)
                {
                    auxLinkedList = ll_subList(pLinkedList,from,to);
                    if(auxLinkedList != NULL)
                    {
                        listaPrincipal[3] = auxLinkedList;
                        *index = 3;
                        retorno = 0;
                    }
                }
                else
                {
                    printf("\nIndice invalido.");
                }
                break;
        /*    case 2 :
                printf("\nSeleccione criterio para filtrar");
                criterio = people_selectorCriterio();
                auxLinkedList  = ll_filter(pLinkedList,criterio);
                if(auxLinkedList != NULL)
                {
                    listaPrincipal[4] = auxLinkedList;
                    *index = 4;
                    retorno = 0;
                }
                break;
            case 3 :
                printf("\nRealizando back-up...");
                auxLinkedList = ll_clone(pLinkedList);
                if(ll_containsAll(pLinkedList,auxLinkedList))
                {
                    listaPrincipal[5] = auxLinkedList;
                    *index = 5;
                    retorno = 0;
                }
                break;*/
            case 2 :
                break;
            default :
                printf("\nError.Opcion incorrecta");
                break;
        }
    }
    return retorno;
}


/**
*\brief Funcion selector de criterio para filtrar
*\return Retorna puntero a funcion segun criterio seleccionado si no es correcto retorna NULL
*/
void* people_selectorCriterio()
{
    int opcion;

    void* retorno = NULL;
    input_getEnteros(&opcion,"\n1) Nombre\n2) Sueldo\n3) ID\n4) Is Empty\n","\nOpcion incorrecta",2);

    switch(opcion)
    {
        case 1 :
            printf("\nFiltrar por nombre");
            criterioNombre(NULL);
            retorno = criterioNombre;
            break;
        case 2 :
            printf("\nFiltrar por Is Empty");
            criterioId(NULL);
            retorno = criterioId;
            break;
        case 3 :
            printf("\nFiltrar por sueldo");
            criterioSueldo(NULL);
            retorno = criterioSueldo;
            break;
        case 4 :
            printf("\nFiltrar por ID");
            criterioId(NULL);
            retorno = criterioId;
            break;

        default :
            printf("\nOpcion incorrecta");
    }
    return retorno;
}

/**
*\brief Funcion para borrar listados de empleados, principal y filtrados
*\param pLinkedList Es el puntero al listado principal que contiene todos los listados
*\return Retorna 0 si el listado principal existe sino retorna -1
*/
int people_borrarLista(LinkedList* pLinkedList[])
{
    int retorno = -1;
    int option;
    int list;
    char verification[2];

    if(pLinkedList != NULL)
    {
        printf("\n1) Vaciar lista\n2) Eliminar todas las listas\n3) Volver");
        input_getEnteros(&option,"\nIngrese opcion: ","\nDato invalido",2);

        switch(option)
        {
            case 1 :
                printf("\n1) Empleados activos\n2) Empleados inactivos \n3) Sublista\n4) Lista filtrada\n5) Todas las listas");
                input_getEnteros(&list,"\nSeleccione lista: ","\nError",2);
                input_getLetras(verification,2,"\nATENCION!\nDesea vaciar lista? S/N\n","\nError.",2);
                if(list >= 1 && list <= 5 && !ll_isEmpty(pLinkedList[list]) && !strcasecmp("s",verification))
                {
                    if(!ll_clear(pLinkedList[list]))
                    {
                        printf("\nLista vaciada.");//BORRAR IF
                    }
                }
                break;
            case 2 :
                printf("\nATENCION! Las sublistas no se recuperan.");
                input_getLetras(verification,2,"\nDesea eliminar todas las listas? S/N\n","\nError.",2);
                if(!strcasecmp("s",verification))
                {
                    if(!ll_freeLinkedList(pLinkedList))
                    {
                        ll_initLinkedList(pLinkedList);
                        printf("\nListas eliminadas.");
                    }
                }
            case 3 :
                break;
        }
        retorno = 0;

    }
    return retorno;
}

/**
*\brief Se realiza un alta forzada
*\param pLinkedList Es la LinkedList para realizar el alta
*\param bufferName Es el nombre a cargar en el elemento
*\param bufferHorasTrabajadas Es la cantidad de horas trabajadas para cargar en el elemento
*\param bufferSueldo Es el sueldo para cargar en el elemento
*\return Retorna 0 si el array es diferente a NULL sino retorna -1
*/
int people_hardcode(void* pLinkedList,char *bufferName,char* bufferLastName,char* bufferIsEmpty,char* bufferSueldo)
{
    People* this = NULL;
    int retorno = -1;

    this = people_newConParametros("0",bufferName,bufferLastName,bufferIsEmpty,bufferSueldo);

    if(this != NULL)
    {
        people_show(this);
        ll_add(pLinkedList,this);
        retorno = 0;;
    }
    return retorno;
}

/////////////////////////////////////////////SETTERS & GETTERS///////////////////////////////////////////////////////////

/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/
int people_setId(People* this,int id)
{
    int retorno=-1;
    static int proximoId= 0;

    if(this!=NULL && id==0)//Se carga primer ID y en el ALTA
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(this!=NULL && id>proximoId)//Se comparan los ID al cargar del archivo
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    else if(this!=NULL && id<proximoId)
    {
        this->id=id;
        retorno = 0;
    }
    else if(this!=NULL && id > -1)
    {
        proximoId = 0;//Reset
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/
int people_getId(People* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int people_setNombre(People* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/
int people_getNombre(People* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



/**
*\brief Se setea el IsEmpty del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int people_setIsEmpty(People* this,int isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty == 0 && isValidIsEmpty(isEmpty))
    {
        this->isEmpty = isEmpty;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el IsEmpty del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/
int people_getIsEmpty(People* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        *isEmpty = this->isEmpty;
        retorno=0;
    }
    return retorno;
}





/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int people_setApellido(People* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidLastName(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/
int people_getApellido(People* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}
/**
*\brief Se setea el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/
int people_setSueldo(People* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL && isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/
int people_getSueldo(People* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Setea todos los campos del elemento
*\param this Es el elemento
*\param name Es el dato para setear el campo nombre
*\param hours Es el dato para setear el campo horas trabajadas
*\param salary Es el dato para setear el campo salario
*\return Retorna 0 si existe el elemento sino retorna -1
*/
int people_setAll(People* this,int id,char* name,char* lastName,int salary,int isEmpty)
{
    int retorno = -1;

    if(this != NULL)
    {
        if( !people_setId(this,id) &&
            !people_setNombre(this,name) &&
            !people_setApellido(this,lastName) &&
            !people_setSueldo(this,salary) &&
            !people_setIsEmpty(this,isEmpty))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Obtiene todos los campos del elemento
*\param this Es el elemento
*\param name Es el dato para obtener el campo nombre
*\param hours Es el dato para obtener el campo horas trabajadas
*\param salary Es el dato para obtener el campo salario
*\return Retorna 0 si existe el elemento sino retorna -1
*/
int people_getAll(People* this,int* id,char* name,char* lastName,int* salary,int* isEmpty)
{
    int retorno = -1;

    if(this != NULL)
    {
        people_getNombre(this,name);
        people_getSueldo(this,salary);
        people_getId(this,id);
        people_getIsEmpty(this,isEmpty);
        retorno = 0;
    }
    return retorno;
}
