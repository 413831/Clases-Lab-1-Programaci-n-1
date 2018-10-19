#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"

#define QTY_PERSON 5

/** MEMORIA DINAMICA Y PUNTEROS
*>> Creacion de un array de punteros de estructuras
*>> Se almacenan direcciones de memorias no contiguas optimizando espacio del programa
*>> Uso de setters y getters
*>> Punteros a funciones
*>> Introduccion a OOP (object-oriented programming) en C
*/

int funcion(void)//"funcion" representa a una direccion de memoria
{
    return 7;
}

//funcion() llama a lo que contiene la direccion

void funcionPerson(Person array[],int size)
{

}

void funcionRecibeF(int (*pepe)(void))//Se arma la funcion dentro del argumento y se pasa su direccion
{
    pepe();
    printf("puntero desde funcion: %p\n",pepe);
    printf("puntero desde funcion: %d\n",pepe());
}

int main()
{
    Person* arrayPersonitas[QTY_PERSON];//Array de punteros de la estructura
    Person* auxPersonita = NULL;
    char auxName[20];
    char auxLastName[20];
    int auxAge;
    char auxAdress[30];
    int index;

    person_init(arrayPersonitas,QTY_PERSON);//Inicializo el array

    //ALTA// (ejemplo setters)
    //Primero se busca lugar libre en el array
    index = person_searchEmpty(arrayPersonitas,QTY_PERSON);
    //Segundo se reserva lugar en memoria para el nuevo elemento
    person_constructor(&auxPersonita);//Paso direccion de memoria de auxiliar persona
    //Tercero seteo los campos
    if(!input_getLetras(auxName,30,"\nIngrese nombre: ","\nError dato invalido",2) &&
    !input_getLetras(auxLastName,30,"\nIngrese apellido: ","\nError dato invalido",2) &&
    !input_getNumeros(&auxAge,3,"\nIngrese edad: ","\nError dato invalido",0,99,2) &&
    !input_getAlfanumerico(auxAdress,30,"\nIngrese direccion: ","\nError dato invalido",2))
    {
        person_setName(auxPersonita,auxName);
        person_setLastName(auxPersonita,auxLastName);
        person_setAge(auxPersonita,auxAge);
        person_setAdress(auxPersonita,auxAdress);
    }
    //Cuarto inserto el nuevo elemento en el array y libero memoria del auxiliar
    arrayPersonitas[index] = auxPersonita;
    person_destructor(auxPersonita);
///////////////////////////////////////
    //MOSTRAR// (ejemplo getters)
    //Se muestran campos del elemento en posición index del array
    printf("\nVersion 1\nLa posta");
    getchar();
    index = 0;
    person_getName(*(arrayPersonitas+index),auxName);
    person_getlastName(*(arrayPersonitas+index),auxLastName);
    person_getAge(*(arrayPersonitas+index),&auxAge);
    person_getAdress(*(arrayPersonitas+index),auxAdress);

    printf("\nNOMBRE -- %s",auxName);
    printf("\nAPELLIDO -- %s",auxLastName);
    printf("\nEDAD -- %d",auxAge);
    printf("\nDIRECCION -- %s",auxAdress);

    printf("\nVersion 2\nLa vieja");
    getchar();
    index = 0;
    person_showArray(*(arrayPersonitas+index));

    return 0;
}
