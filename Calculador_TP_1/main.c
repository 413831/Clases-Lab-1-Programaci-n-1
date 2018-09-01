#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"

/*
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
    a) Calcular la suma (A+B)
    b) Calcular la resta (A-B)
    c) Calcular la division (A/B)
    d) Calcular la multiplicacion (A*B)
    e) Calcular el factorial (A!)
4. Informar resultados
    a) “El resultado de A+B es: r”
    b) “El resultado de A-B es: r”
    c) “El resultado de A/B es: r” o “No es posible dividir por cero”
    d) “El resultado de A*B es: r”
    e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/


int main()
{
    int numeroUno;
    int numeroDos;
    char operacion;
    //int * pResultado;
    int resultado;

    /*do        //Construccion del menú
    {}while();
    */


    printf("Ingrese los numeros para realizar la operacion\n");
    printf("\nSuma (+)\nResta (-)\nMultiplicación(*)\nDivisión(/)\nFactorial(!n)\n");

    getNumero(&numeroUno);
    getCaracter(&operacion,"Elija una opción ");

    switch(operacion)
    {
        case '+' :
        {
        getNumero(&numeroDos);
        resultado = funcionSuma(numeroUno,numeroDos);
        printf("\nEl resultado de la suma %d + %d = %d",numeroUno,numeroDos,resultado);
        return 0;
        break;
        }
        case '-' :
        {
        getNumero(&numeroDos);
        resultado = funcionResta(numeroUno,numeroDos);
        printf("\nEl resultado de la resta %d - %d = %d",numeroUno,numeroDos,resultado);
        return 0;
        break;
        }
        case '*' :
        {
        getNumero(&numeroDos);
        resultado = funcionMultiplicar(numeroUno,numeroDos);
        printf("\nEl resultado de la multiplicación %d * %d = %d",numeroUno,numeroDos,resultado);
        return 0;
        break;
        }
        case '/' :
        {
        getNumero(&numeroDos);
        resultado = funcionDividir(numeroUno,numeroDos);
        printf("\nEl resultado de la división %d / %d = %d",numeroUno,numeroDos,resultado);
        return 0;
        break;
        }
        //case 'n!' :
        {
        break;
        }
        default :
        {

        }




    }



}
