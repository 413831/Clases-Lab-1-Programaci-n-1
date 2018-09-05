#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
*\brief Se limpia el buffer del teclado
*\param void
*\return void
*/

void limpiarMemoria()
{
    //__fpurge(stdin);
    fflush(stdin);
}

/**
*\brief Se limpia la pantalla
*\param void
*\return void
*/

void limpiarPantalla()
{
    //system("clear");
    system("cls");
}


/**
*\brief Se solicita ingresar un caracter al usuario
*\param caracterAuxiliar Puntero del caracter ingresado
*\param mensaje Mensaje que se muestra al usuario para ingresar caracter
*\return Retorna 0 si es correcto si es incorrecto retorna -1
*/
int getCaracter(char * caracterAuxiliar,char mensaje[50])
{
    limpiarMemoria();
    printf("%s",mensaje);
    scanf("%c",caracterAuxiliar);
    return 0;
}


/**
*\brief Mostrar
*   a) el mayor
*   b) el menor
*   c) cantidad de pares
*   d) suma total
*   e) promedio
*/

void mostrarInfoArray(int array[],int size)
{


    float promedio;
    int sumaTotal;
    int numeroMenor;
    int numeroMayor;
    int cantidadPares;
    int aprobados;
    int desaprobados;
    int alumnosFinales;

    printf("\n>>Listado de notas<<\n");
    cargarListado(array,size);

    promedio = promedioNotas(array,size);
    sumaTotal = retornarTotal(array,size);
    numeroMenor = retornarNumeroMenor(array,size);
    numeroMayor = retornarNumeroMayor(array,size);
    cantidadPares = retornarNumerosPares(array,size);


    aprobados = alumnosAprobadosDesaprobados(array,size,6,10);
    desaprobados = alumnosAprobadosDesaprobados(array,size,1,5);
    alumnosFinales = alumnosAprobadosDesaprobados(array,size,1,3);


    printf("\n\nEl promedio de las notas es: %.1f",promedio);
    printf("\nLa suma total de las notas es: %d",sumaTotal);
    printf("\nLa nota mayor es: %d",numeroMayor);
    printf("\nLa nota menor es: %d",numeroMenor);
    printf("\nLa cantidad de notas pares es: %d",cantidadPares);
    printf("\nLa cantidad de alumnos aprobados es: %d",aprobados);
    printf("\nLa cantidad de alumnos desaprobados es: %d",desaprobados);
    printf("\nLa cantidad de alumnos que rinden directo final es: %d",alumnosFinales);
    getchar();

}


int retornarNumeroMenor(int array[],int size)
{
    int menor;
    int i;

    for(i=0;i<size;i++)
    {
        if(i == 0 || array[i]<menor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento menor
        {
        menor = array[i];
        }
    }

    return menor;

}
int retornarNumeroMayor(int array[],int size)
{
    int mayor;
    int i;

    for(i=0;i<size;i++)
    {
        if(i == 0 || array[i]>mayor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento mayor
        {
        mayor = array[i];
        }
    }

    return mayor;
}

int retornarNumerosPares(int array[],int size)
{
    int contadorPares = 0;
    int i;

    for(i=size;i>=0;i--)
    {
        if(array[i] % 2 == 0)
        {
        contadorPares++;
        }
    }

    return contadorPares;

}


int retornarTotal(int array[],int size)
{
    int acumulador = 0;
    int i;

    for(i=0;i<size;i++)
    {

        acumulador = acumulador + array[i];
    }

    return acumulador;
}

float promedioNotas(int array[],int size)
{
    int suma;
    float promedio;
    suma = retornarTotal(array,size);
    promedio = suma / size;
    return promedio;
}

void cargarListado(int array[],int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("\nLa nota es: %d",array[i]);//Se muestran las notas cargadas

    }

}


int alumnosAprobadosDesaprobados(int array[],int size,int limiteInferior,int limiteSuperior)
{
    int i;
    int contadorNotas = 0;

    for(i=0;i<size;i++)
    {
        if(array [i]<=limiteSuperior && array [i]>=limiteInferior)
        {
        contadorNotas++;
        }
    }
    return contadorNotas;
}

/**
*\brief Crear un menú con 5 calculos para dos números ingresados por el usuario hasta que no quiera ingresar más
*\param void
*\return Retorna 0 si esta bien, sino retorna -1
*/

int menuNotasIngresadas(int array[],int size)
{
    char opcion;

    do
    {
        mostrarInfoArray(array,size);
        getchar();
        getCaracter(&opcion,"\n\nContinuar? S/N ");
            while(!(opcion == 'S' || opcion == 's' || opcion == 'N' || opcion == 'n'))
            {
            printf("Ingrese una opcion valida");
            limpiarMemoria();
            getCaracter(&opcion,"\n\nContinuar? S/N ");
            limpiarPantalla();
            }
        limpiarPantalla();

    }while(opcion == 'S' || opcion == 's');

    return 0;
}


