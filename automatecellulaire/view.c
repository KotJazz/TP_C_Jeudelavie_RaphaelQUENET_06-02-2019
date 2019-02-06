#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "automatecellulaire.h"

//DISPLAY
//PURPOSE : Display the plane on which the game of life is occuring.
//INPUT : The plane as a 2d array
//OUTPUT : Printed plane, environment info
void display(enum cell plane[SIZE][SIZE])
{
    //VAR
    int i;
    //i stands for increment.
    int j;
    //j is also a variable used for incrementation.
    //
    for(i=0;i<SIZE;i++)
    {
        if(i>0&&i<=SIZE)
            printf("\n");
        for(j=0;j<SIZE;j++)
        {
            if (plane[i][j]==alive)
            {
                printf("[#]");
            }
            else
            {
                printf("[-]");
            }
        }
    }
}
