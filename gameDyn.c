///////////////////////////////////////////////////////////////////////////////////////////////////////////
// GAME EXPLANATION
// It consists of a grid of cells which, based on a few mathematical rules, can live, die or multiply. 
// Depending on the initial conditions, the cells form various patterns throughout the course of the game.
//
// Each cell with one or no neighbors dies, as if by solitude.
// Each cell with four or more neighbors dies, as if by overpopulation.
// Each cell with two or three neighbors survives.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Team-work Strategy
// Set everything as functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>


// global variables needed
unsigned char **grid;

// Create a space were the game develop
unsigned int Grid_rows;
unsigned int Grid_col;

unsigned char **initGrid(){

    unsigned char **newGrid;

    // Allocate memory for the matrix and set to 0
    newGrid = (unsigned char **)calloc(Grid_rows, sizeof(unsigned char *));
    for (int i = 0; i < Grid_rows; i++) {
        newGrid[i] = (unsigned char *)calloc(Grid_col, sizeof(unsigned char));
    }

    return newGrid;
} 


void createGrid(){
    //TODO: Set a minimum for each dimension
    // Ask for dimention
    printf("Enter number of rows: "); 
    scanf("%d", &Grid_rows);
    printf("Enter number of columns: ");
    scanf("%d", &Grid_col);

    grid = initGrid();
}


// Set initial conditions
void initial(){
    unsigned int scenary = 4;
    printf("Select scenary: "); 
    scanf("%d", &scenary);
    int i = 0;
    int j = 0;
    switch (scenary) {
        case 1: // The R-pentomio
            /*
             XX
            XX
             X
            */
            srand(time(NULL));
            i = rand() % (Grid_rows-3) +1; //1;
            j = rand() % (Grid_col-3) +1;  //1;
            
            grid[i+1][j] = 1;
            grid[i][j+1] = 1;
            grid[i][j+2] = 1;
            grid[i+1][j+1] = 1;
            grid[i+2][j+1] = 1;
        break;
        case 2: // Diehard
            /*
                  X 
            XX
             X   XXX
            */
            srand(time(NULL));
            i = rand() % (Grid_rows-3) +1; //1;
            j = rand() % (Grid_col-8) +1;  //1;
            grid[i+1][j] = 1;
            grid[i+1][j+1] = 1;
            grid[i+2][j+1] = 1;
            grid[i][j+6] = 1;
            grid[i+2][j+5] = 1;
            grid[i+2][j+6] = 1;
            grid[i+2][j+7] = 1;
        break;
        case 3: //Acorn
            /*
             X
               X
            XX  XXX
            */
            srand(time(NULL));
            i = rand() % (Grid_rows-3) +1; //1;
            j = rand() % (Grid_col-7) +1;  //1;
            grid[i][j+1] = 1;
            grid[i+2][j] = 1;
            grid[i+2][j+1] = 1;
            grid[i+1][j+3] = 1;
            grid[i+2][j+4] = 1;
            grid[i+2][j+5] = 1;
            grid[i+2][j+6] = 1;
        break;
        case 4: //Random
            srand(time(NULL));
            for (int i = 0; i < Grid_rows; i++) {
                for (int j = 0; j < Grid_col; j++) {
                    grid[i][j] += rand() % 2; 
                }
            }
        break;
    }
}

// All the game is based on counting how many neighbors we have, thats why we will
// create a function that will count the number of neighbors in each interaction
int Neighbors(int x, int y) {
    int Num_neighbors = 0;
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            //If outside grid, skip - Kuntaro
            if ((i<0 || i>=Grid_rows) && (j<0 || j>=Grid_col)){
                continue;
            }
            printf("X");
            Num_neighbors += grid[i][j]; // add one if is 1 (neighbor)
        }
    }
    return Num_neighbors;
}

//Update the grid for each map
void newGrid(){
    unsigned char **temp_grid = initGrid();
    for (int i = 0; i < Grid_rows; i++) {
        for (int j = 0; j < Grid_col; j++) {
            int neighbors = Neighbors(i,j);
            // Solitude
            if(neighbors <= 1){
                temp_grid[i][j] = 0;
            }
            // Overpopulation
            else if(neighbors >= 4){
                temp_grid[i][j] = 0;
            }
            // Survives
            else {
                temp_grid[i][j] = 1;
            }
        }
    }
    // Copy temporary grid to original one
    for (int i = 0; i < Grid_rows; i++) {
        for (int j = 0; j < Grid_col; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

// To have a better experience at the moment of visualize the grid, we will create
// a function that show us the grid but instead of showing us 0 will show a blank
// space and intead of 1 will present a "X"
void printGrid(){
    for (int i = 0; i < Grid_rows; i++) {
        for (int j = 0; j < Grid_col; j++) {
            if(grid[i][j] == 1){
                printf("X");
            } else {
                printf(" ");
            };
        }
        printf("\n");
    }
    refresh();
}

int main() {

    createGrid();
    initial();
    return 0;
    //initscr();
    //printGrid(grid1);
    while (1) {
        system("clear"); //"cls" or "clear"
        printGrid();
        newGrid();
        usleep(1000000); // Sleep for 1 second
    }
    return 0;
}