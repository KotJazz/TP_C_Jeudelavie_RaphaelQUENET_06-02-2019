#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "automatecellulaire.h"

//GENERATION
//PURPOSE : Iteration of a single generation of the game of life.
//INPUT : Buffer and number of generations
//OUTPUT : Edited text file with info on the current generation
void generation(enum cell buffer[SIZE][SIZE],enum cell grid[SIZE][SIZE],int nGen)
{
    int i,j;
    int env;
    int nLiveCells;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            env=environmentinfo(buffer,i,j);
            if((buffer[i][j]==1)||(buffer[i][j]==3))
            {
                if ((env<2)||(env>3))
                {
                    death(grid,env,i,j);
                }
                else
                {
                    stasis(grid,env,i,j);
                }
            }
            else if (env==3)
            {
                birth(grid,env,i,j);
            }
        }
    }
    nLiveCells=cellcount(grid);
    editfile(nLiveCells,nGen);

}
//BIRTH
//PURPOSE : Give birth to a cell
//INPUT : Plane, number of surrounding cells, position
//OUTPUT :
void birth(enum cell grid[SIZE][SIZE],int nSurroundingLiveCells,int nI, int nJ)
{
    grid[nI][nJ]=alive;
}
//STASIS
//PURPOSE :
//INPUT :
//OUTPUT :
void stasis(enum cell grid[SIZE][SIZE],int nSurroundingLiveCells,int nI, int nJ)
{
    grid[nI][nJ]=alive;
}
//DEATH
//PURPOSE : KILLING A CELL WHEN THE CONDITIONS ARE MET
//INPUT : PLANE, NUMBER OF SURROUNDING CELLS, POSITION OF CELL
//OUTPUT : MODIFIED PLANE
void death(enum cell grid[SIZE][SIZE],int nSurroundingLiveCells,int nI, int nJ)
{
    grid[nI][nJ]=dead;
}

//EDITFILE
//PURPOSE : Editing the text file with generation info
//INPUT : Total living cells and number of generations
//OUTPUT : Edited text file
void editfile(int nLiveCells,int nGen)
{
    FILE * pData;
    pData=fopen("gendata.txt","a");
    fprintf(pData,"\nGENERATION NUMBER %d : %d living cells\n",nGen,nLiveCells);
    fclose(pData);
}
//EMPTYFILE
//PURPOSE : Empty the file before a new game
//INPUT : -
//OUTPUT : Emptied text file
void emptyfile()
{
    FILE * pData;
    pData=fopen("gendata.txt","w");
    fclose(pData);
}
//COPYARRAY
//PURPOSE : Copy an array into another
//INPUT : Buffer & grid
//OUTPUT : Reassigned buffer
void copyarray(enum cell grid[SIZE][SIZE],enum cell buffer[SIZE][SIZE])
{
    int i,j;//Incrementation
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            buffer[i][j]=grid[i][j];
        }
    }
}
