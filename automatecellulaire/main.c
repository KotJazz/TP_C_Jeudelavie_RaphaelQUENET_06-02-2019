#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "automatecellulaire.h"

//MAIN
int main()
{
    enum cell buffer[SIZE][SIZE];//Buffer array to save the previous grid state.
    enum cell grid[SIZE][SIZE];//Modify the SIZE constant in order to modify the size of the plane.
    emptyfile();
    init(buffer);
    display(buffer);
    do
    {
        printf("\n");
        system("pause"); //Passage à la génération suivante
        system("cls");
        generation(buffer,grid,cptgen);
        display(grid);
        copyarray(grid,buffer);
        cptgen++;
    }while(cptgen<=MAXGEN);
    return 0;
}
