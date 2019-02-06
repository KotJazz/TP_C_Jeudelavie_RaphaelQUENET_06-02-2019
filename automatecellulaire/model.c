#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "automatecellulaire.h"

//INIT
//PURPOSE : Initialize the 2d array in which the game of life is occuring.
//INPUT : The buffer as a 2d array
//OUTPUT : Initialized array
void init(enum cell buffer[SIZE][SIZE])
{
    //VAR
    int i;
    //i stands for increment.
    int j;
    //j is also a variable used for incrementation.
    //
    srand(time(0)); //srand uses the current time as a seed for RNG (random number generation)
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            buffer[i][j]=randgen(dead,alive);
        }
    }
}

//RANDGEN
//PURPOSE : Generating a random number
//INPUT : Upper and lower boundaries
//OUTPUT : Randomly generated number
int randgen(int lower, int upper)
{
        int num = (rand() % (upper - lower + 1)) + lower; //Generates a random number within set boundaries
        return num;
}
//ENVIRONMENTINFO
//PURPOSE : Give the number of living cells around the one being targeted.
//INPUT : Buffer & position
//OUTPUT : Number of living cells around the targetted one.
int environmentinfo(enum cell buffer[SIZE][SIZE],int posX,int posY)
{
    int i,j,nStartX,nStartY,nEndX,nEndY;
    int nSurroundingLiveCells=0;
    if(posX-1<0)
    {
        nStartX=posX;
    }
    else
    {
        nStartX=posX-1;
    }
    if(posY-1<0)
    {
        nStartY=posY;
    }
    else
    {
        nStartY=posY-1;
    }
    if(posX+1>SIZE-1)
    {
        nEndX=posX;
    }
    else
    {
        nEndX=posX+1;
    }
    if(posY+1>SIZE-1)
    {
        nEndY=posY;
    }
    else
    {
        nEndY=posY+1;
    }
    for(i=nStartX;i<=nEndX;i++)
    {
        for(j=nStartY;j<=nEndY;j++)
        {
            if((buffer[i][j]==alive)&&((i!=posX)||(j!=posY)))
            {
                nSurroundingLiveCells++;
            }
        }
    }
    return nSurroundingLiveCells;
}
//CELLCOUNT
//PURPOSE : COUNT THE LIVING CELLS
//INPUT : BUFFER
//OUTPUT : NUMBER OF LIVING CELLS AS INTEGER
int cellcount(enum cell buffer[SIZE][SIZE])
{
        //VAR
    int i;
    //i stands for increment.
    int j;
    //j is also a variable used for incrementation.
    int nLiveCells;
    //
    for(i=0;i<SIZE;i++)
    {
        if(i>0&&i<=SIZE)
        for(j=0;j<SIZE;j++)
        {
            if (buffer[i][j]==alive)
            {
                nLiveCells++;
            }
        }
    }
    return nLiveCells;
}
