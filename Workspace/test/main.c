#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad = 5;
    int* pEdad;
    pEdad = &edad;
    *pEdad = 8;
    printf("\n%d",edad);
    printf("\n%d",*pEdad);
    return 0;
}
