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

    numeroUno = getNumero(&numeroUno);
    getCaracter(&operacion);
    numeroDos = getNumero(&numeroDos);

     resultado = funcionSuma(numeroUno,numeroDos);
        printf("El resultado de la suma %d + %d es: %d",numeroUno,numeroDos,resultado);


    switch(operacion)
    {
        case '+' :
        {
        resultado = funcionSuma(numeroUno,numeroDos);
        printf("El resultado de la suma %d + %d es: %d",numeroUno,numeroDos,resultado);
        return 0;
        break;
        }
        case '-' :
        {
        break;
        }
        case '*' :
        {
        break;
        }
        case '/' :
        {
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
