#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5][5];
    int i;

    for(i=0;i<5;i++)
    {
        array[i]
        array[i][i] = i + 10;

    }

    for(i=0;i<5;i++)
    {
        printf("\n %p",&array[i]);
        printf(" -- %d",array[i][i]);
        printf(" -- %p",array[i]);
        printf(" -- %p",&array[i][i]);
    }


    return 0;
}
