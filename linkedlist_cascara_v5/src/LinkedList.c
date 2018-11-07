#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;//variable auxiliar
    int i;

    if(this != NULL && ll_len(this) > 0 && nodeIndex < ll_len(this) && nodeIndex >= 0)
    {
        pNode = this->pFirstNode;//primer nodo
        for(i=0;i!=nodeIndex;i++)
        {   //posicion i
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = (Node*)malloc(sizeof(Node)*1);//variable auxiliar
    Node* currentNode;
    Node* previousNode;
    static int contador = 0;

    if(this!= NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )
    {
        contador++;
        printf("\n----------------------\n TEST %d\n",contador);
        printf("\n\n DIR LINKEDLIST %p",this);
        printf("\n SIZE LINKEDLIST: %d",ll_len(this));
        printf("\n INDEX %d",nodeIndex);
        printf("\n NEW NODE %p",newNode);
        printf("\n ELEMENT %p",pElement);

        if(this->pFirstNode == NULL && nodeIndex == 0 )//Primer nodo
        {
            //El Tempranero
            this->pFirstNode = newNode;//Se reemplaza NULL por el NUEVO NODO
            newNode->pElement = pElement;//Se carga el elemento

            this->size = ll_len(this) + 1;//Se incrementa en 1 el size
            printf("\n NODE ADDED (1) %p",newNode);
            printf("\n NODE MOVED %p",newNode->pNextNode);
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex == 0)//Nodo al comienzo
        {
            //El Correcto
            previousNode = this->pFirstNode;//Se el primer nodo en variable auxiliar
            this->pFirstNode = newNode;//Se enlaza NUEVO NODO al comienzo de la LinkedList

            newNode->pNextNode = previousNode;//Se MUEVE primer nodo al siguiente del NUEVO NODO
            newNode->pElement = pElement;

            this->size = ll_len(this) + 1;
            printf("\n NODE ADDED (1) %p",newNode);
            printf("\n NODE MOVED %p",newNode->pNextNode);
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex > 0 && nodeIndex < ll_len(this))//Medio
        {
            //El Sanguchito
            currentNode = getNode(this,nodeIndex);//Get del NODO a reemplazar
            previousNode = getNode(this,nodeIndex-1);//Get del NODO anterior al que reemplazo

            newNode->pNextNode = currentNode;//Muevo el NODO del INDICE al siguiente del NUEVO NODO
            newNode->pElement = pElement;//Asigno elemento
            previousNode->pNextNode = newNode;//Asigno al NODO ANTERIOR el NUEVO NODO como siguiente

            this->size = ll_len(this) + 1;
            printf("\n NODE ADDED (2) %p",newNode);
            printf("\n NODE MOVED %p",currentNode);
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && nodeIndex==ll_len(this))//Nodo al final
        {
            //El Colado
            currentNode = getNode(this,nodeIndex -1 );
            currentNode->pNextNode = newNode;

            newNode->pElement = pElement;
       //     newNode->pNextNode = NULL;

            this->size = ll_len(this) + 1;
            printf("\n NODE ADDED (3) %p",newNode);
            printf("\n NODE MOVED %p",currentNode);
            returnAux = 0;
        }

    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{


    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL)
    {
        if(!addNode(this,len,pElement))
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = (Node*)malloc(sizeof(Node)*1);

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0 )
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = (Node*)malloc(sizeof(Node)*1);

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0 )
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode;
    Node* currentNode;
    Node* previousNode;

    if(this!= NULL && index >= 0 && index < ll_len(this) )
    {

        if(this->pFirstNode != NULL && index == 0)//Nodo al comienzo
        {
            //El Correcto
            auxNode = this->pFirstNode ;//Se el primer nodo en variable auxiliar
            this->pFirstNode = auxNode->pNextNode;
            free(auxNode);

            this->size = ll_len(this) - 1;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && index > 0 && index < ll_len(this))//Medio
        {
            //El Sanguchito
            currentNode = getNode(this,index);//Get del NODO a reemplazar
            previousNode = getNode(this,index-1);//Get del NODO anterior al que reemplazo
            previousNode->pNextNode = currentNode->pNextNode;

            free(currentNode);

            this->size = ll_len(this) - 1;
            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && index ==ll_len(this))//Nodo al final
        {
            //El Colado
            currentNode = getNode(this,index - 1 );
            free(currentNode);

            this->size = ll_len(this) - 1;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            ll_remove(this,i);

        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    Node* auxNode;

    if(this != NULL)
    {
        for(index=0;index<ll_len(this);index++)
        {
            auxNode = getNode(this,index);
            if(auxNode->pElement == pElement)
            {
                returnAux = index;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && this->pFirstNode != NULL)
    {
        returnAux = 0;
    }
    else if(this != NULL && this->pFirstNode == NULL)
    {
        returnAux = 1;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        if(!addNode(this,index,pElement))
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this,pElement) == -1)
        {
            returnAux = 0;
        }
        else if(ll_indexOf(this,pElement) >= 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int index;
    void* auxElement;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(index=0;index<ll_len(this2);index++)
        {
            auxElement=ll_get(this2,index);

            if(!ll_contains(this,auxElement))
            {
                returnAux = 0;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;


    for(from;from<to;from++)
    {
        ll_get(this,from);

    }



    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

