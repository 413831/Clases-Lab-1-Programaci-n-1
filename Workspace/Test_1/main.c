#include <stdio.h>
#include <stdlib.h>

int main()
{char nombre[50];
char localidad[50];

printf("Ingrese su nombre ");
scanf("%s",nombre);
fflush(stdin);

printf("\nIngrese su localidad ");
scanf("%s",nombre);
fflush(stdin);

printf("\nUsted es %s y es de la localidad de %s",nombre,localidad);


    return 0;
}
