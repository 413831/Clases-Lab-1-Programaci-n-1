#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "person.h"

int main()
{
    int numero = 10;
    int* pNumero = NULL;
    int** pPuntero;
    int*** ppPuntero;
    Person* personitaUno = NULL;

    pNumero = &numero;

    pPuntero = &pNumero;

    ppPuntero = &pPuntero;

    printf("\nDIR MEM VALOR %p - VALOR %d",&numero,numero);
    printf("\n                    =              = ");
    printf("\n\nDIR 1 PUNT %p - VALOR %d  - DIR MEM VALOR %p",&pNumero,*pNumero,pNumero);
    printf("\n                    =              =                           =");
    printf("\n\nDIR 2 PUNT %p    - VALOR %d  - DIR 1 PUNT %p",&pPuntero,**pPuntero,pPuntero);
    printf("\n                    =              =                           =");
    printf("\n\nDIR 3 PUNT %p     - VALOR %d  - DIR 2 PUNT %p",&ppPuntero,***ppPuntero,ppPuntero);
    printf("\n                    =              =                           =");
    printf("\n\nDIR MEM VALOR %p -  %p -  %p",*pPuntero,**ppPuntero,&numero);

    limpiarMemoria();
    getchar();

    person_create(&personitaUno);//recibe direccion de memoria de puntero y retorna una direccion libre para puntero
    printf("\n\nDIR PERSONA %p",personitaUno);
    person_showArray(personitaUno);

    return 0;
}
