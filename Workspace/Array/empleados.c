#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


/**
*\brief Se reciben los datos del array edad y sueldo para calcular suma total de sueldos y promedio. Se muestran resultados.
*\param pEdad Puntero de variable edad donde se recibe y guarda el dato
*\param pSueldo Puntero de variable sueldo donde se recibe y guarda el dato
*\param pSumaTotal Puntero de variable suma total de sueldos donde se recibe y guarda el dato
*\param pPromedio Puntero de variable promedio donde se guarda el dato
*\param Puntero de variable donde se recibe el limite del array
*\return Retorna 0 si es correcto si es incorrecto retorna -1
*/


int empleadosSueldo(int* pEdad,float* pSueldo,float* pSumaTotal,float* pPromedio,int size)
{
    int legajo;
    float totalSueldo = 0;
    int i;
    int cantidadLegajos;

     for(i=0;i<size;i++)//Muestro los datos
    {
        legajo = i;
        legajo++;
        cantidadLegajos++;
        totalSueldo = totalSueldo + pSueldo[i];
        printf("\nLegajo Nº: %d",legajo);
        printf("\n\nLa edad ingresada es: %d",pEdad[i]);
        printf("\nEl sueldo es: %f",pSueldo[i]);
    }

    *pSumaTotal = totalSueldo;
    *pPromedio = totalSueldo / legajo;

    return 0;
}

/**
*\brief Realizar una carga secuencial en un array de numeros
*\param *pEdad Puntero de variable edad por el cual se recibe y retorna dato edad
*\param *pSueldo Puntero de variable sueldo por el cual se recibe y retorna dato sueldo
*\param size Tamaño del array
*\return
*/



int cargaSecuencial(int* pEdad,float* pSueldo,int size)
{
    int i;

      for(i=0;i<size;i++)//Cargo los datos de edad y sueldos de cada legajo
    {
        printf("\nIngrese edad para legajo Nº%d: ",i+1);
        scanf("%d",&pEdad[i]);
        printf("\nIngrese sueldo para legajo Nº%d: ",i+1);
        scanf("%f",&pSueldo[i]);
    }
    return 0;
}


/**
*\brief Realizar una carga aleatoria en un array de numeros
*\param *pEdad Puntero de variable edad por el cual se recibe y retorna dato edad
*\param *pSueldo Puntero de variable sueldo por el cual se recibe y retorna dato sueldo
*\param size Tamaño del array
*\return
*/


int cargaAleatoria(int* pEdad,float* pSueldo,int size)
{

}
