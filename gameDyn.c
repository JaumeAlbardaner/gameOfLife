///////////////////////////////////////////////////////////////////////////////////////////////////////////
// GAME EXPLANATION
// It consists of a grid of cells which, based on a few mathematical rules, can live, die or multiply. 
// Depending on the initial conditions, the cells form various patterns throughout the course of the game.
//
// Each cell with one or no neighbors dies, as if by solitude.
// Each cell with four or more neighbors dies, as if by overpopulation.
// Each cell with two or three neighbors survives.
// Each dead cell with exactly three neighbors becomes a live cell.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Team-work Strategy
// Coder 1 works on repository and code
// Coder 2 works on code
// Coder 3 works on report
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h> // To catch SIGINT
#include <ncurses.h>


// global variables needed
unsigned char **grid;

// Create a space were the game develop
unsigned int Grid_rows;
unsigned int Grid_col;
unsigned int scenary;


// Flag that stops game if SIGINT is detected
static volatile int keepRunning = 1;

void intHandler(int dummy) {
    keepRunning = 0;
}

unsigned char **initGrid(){

    unsigned char **newGrid;

    // Allocate memory for the matrix and set to 0
    newGrid = (unsigned char **)calloc(Grid_rows, sizeof(unsigned char *));
    for (int i = 0; i < Grid_rows; i++) {
        newGrid[i] = (unsigned char *)calloc(Grid_col, sizeof(unsigned char));
    }

    return newGrid;
} 


void createGrid(int Grid_rows, int Grid_col){
    //TODO: Set a minimum for each dimension
    // Ask for dimention
    /*printf("Enter number of rows: "); 
    scanf("%d", &Grid_rows);
    printf("Enter number of columns: ");
    scanf("%d", &Grid_col);*/

    resize_term(Grid_rows, Grid_col);

    grid = initGrid();
}


// Set initial conditions
void initial(int scenary){
    /*printf("Select scenary: "); 
    scanf("%d", &scenary);*/
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
            //If outside grid, skip
            if (i<0 || i>=Grid_rows || j<0 || j>=Grid_col){
                continue;
            }
            // Skip cell we're evaluating
            if(i == x && j == y){
                continue;
            }
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
            // Under-population
            if(neighbors <= 1){
                temp_grid[i][j] = 0;
            }
            // Overpopulation
            else if(neighbors >= 4){
                temp_grid[i][j] = 0;
            }
            // Survives
            else if(neighbors==2){
                temp_grid[i][j] = grid[i][j];
            }
            else if(neighbors==3){
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

    // Free calloc after use
    free(temp_grid);
}

// To have a better experience at the moment of visualize the grid, we will create
// a function that show us the grid but instead of showing us 0 will show a blank
// space and intead of 1 will present a "X"
void printGrid(){
    clear();
    for (int i = 0; i < Grid_rows; i++) {
        for (int j = 0; j < Grid_col; j++) {
            move(i, j);
            if(grid[i][j] == 1){
                printw("X");
            } else {
                printw("-");
            };
        }
        // printf  ("\n");
    }
    refresh();
}
#define MENU_COUNT 3
int main() {
    signal(SIGINT, intHandler);

    initscr();    
    // Create a new window
    WINDOW *win = newwin(1000, 1000, 0, 0);
    // Write some text to the window
    mvwprintw(win, 0, 0, "Introduce number of rows: ");
    wscanw(win, "%d", &Grid_rows);
    mvwprintw(win, 1, 0, "Introduce number of Columns: ");
    wscanw(win, "%d", &Grid_col);
    mvwprintw(win, 2, 0, "Select scenary: ");
    mvwprintw(win, 3, 3, "[1] R-pentomio");
    mvwprintw(win, 4, 3, "[2] Diehard");
    mvwprintw(win, 5, 3, "[3] Acorn");
    mvwprintw(win, 6, 3, "[4] Random\n");
    wscanw(win, "%d", &scenary); 
    wrefresh(win); // Display the window

    createGrid(Grid_rows,Grid_col);
    initial(scenary);
 
    // Keep running until ctrl+C (SIGINT)
    while (keepRunning) {
        printGrid();
        newGrid();
        usleep(100000); // Sleep for 1 second
    }
    free(grid);
    endwin();
    // printf("Caught SIGINT\n");
    return 0;
}