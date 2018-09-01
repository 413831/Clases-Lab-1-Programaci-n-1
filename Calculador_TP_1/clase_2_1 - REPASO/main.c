#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int division(float numero1, float numero2, float* resultado);

int main()
{
    float resultado, num1 = 10, num2 = 0;

    if (!division(num1, num2, &resultado)) {
        printf("Division exitosa: %f", resultado);
    } else {
        printf("No se puede dividir por 0");
    }

    return 0;
}

int division(float numero1, float numero2, float* resultado){
    int retorno = -1;

    if(numero2 != 0) {
        *resultado = numero1/numero2;
        retorno = 0;
    }

    return retorno;

}
