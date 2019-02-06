#ifndef AUTOMATECELLULAIRE_H_INCLUDED
#define AUTOMATECELLULAIRE_H_INCLUDED
//
//--------------------------------------------------------------------------
#define SIZE 20 //SIZE OF THE GRID
#define MAXGEN 50 //NUMBER OF GENERATION BEFORE THE GAME AUTOMATICALLY STOPS
//Size of the plane. Can be modified.
//--------------------------------------------------------------------------

#define RADIUS 3//Size of the square around a cell which will be checked in other to modify the state of said cell.
//TYPES
//enum cell{deadwasdead=0,alivewasdead=1,deadwasalive=2,alivewasalive=3};
enum cell{dead=0,alive=1};
//PROTOTYPES

//MODEL
int randgen(int,int);
void init(enum cell[SIZE][SIZE]);
int cellcount(enum cell[SIZE][SIZE]);
int environmentinfo(enum cell[SIZE][SIZE],int,int);
//VIEW
void display(enum cell[SIZE][SIZE]);
//CONTROLLER
void generation(enum cell[SIZE][SIZE],enum cell[SIZE][SIZE],int);
void birth(enum cell[SIZE][SIZE],int,int,int);
void death(enum cell[SIZE][SIZE],int,int,int);
void stasis(enum cell[SIZE][SIZE],int,int,int);
void editfile(int,int);
void emptyfile();
void copyarray(enum cell[SIZE][SIZE],enum cell[SIZE][SIZE]);

#endif // AUTOMATECELLULAIRE_H_INCLUDED
