#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define SIZE 50



int main()
{
    char myString[SIZE];

    strncpy(myString, "Pepe", SIZE);

    printf("%s",myString);
    return 0;
}
