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
// Coder 2 works on code and report
// Coder 3 works on code and report
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h> // To catch SIGINT
#include <ncurses.h>


// global variables needed
unsigned char **grid;
unsigned char **copy;

// Create a space were the game develop
unsigned int Grid_rows;
unsigned int Grid_col;
unsigned int scenary;

// Flag that stops game if SIGINT (ctrl + C) is detected
static volatile int keepRunning = 1;

// Handles SIGINT flags to stop the execution of the game.
void intHandler(int dummy) {
    keepRunning = 0;
}

/**
 * Allocates dynamically in memory a grid of Grid_rows x Grid_col unsigned chars. 
 * These come initialized with a value of 0.
 *
 * @param None
 * @return `unsigned char**` - Pointer to the first value of the grid.
 */
unsigned char **initGrid(){

    unsigned char **newGrid;

    // Generate array of pointers (rows) which point at array of chars (cols)
    newGrid = (unsigned char **)calloc(Grid_rows, sizeof(unsigned char *));
    for (int i = 0; i < Grid_rows; i++) {
        newGrid[i] = (unsigned char *)calloc(Grid_col, sizeof(unsigned char));
    }

    return newGrid;
} 

// Initializes the grid with size Grid_rows x Grid_col with a minimum size
//  of 10 per axis.
void createGrid(){
    // Security minimum size to ensure no segmentation fault
    if(Grid_rows < 10){
        Grid_rows = 10;
    }
    if(Grid_col < 10){
        Grid_col = 10;
    }
    resize_term(Grid_rows, Grid_col); // Upload dims to ncurses

    grid = initGrid();
}


/**
 * Initializes the grid with the requested scenario, which is offset randomly.
 *
 * @param scenary `int` : Number of the desired scenario
 * @return None.
 */
void initial(int scenary){
    int i = 0;
    int j = 0;
    switch (scenary) {
        case 1: // The R-pentomio
            /*
            -XX
            XX-
            -X-
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
            ------X-
            XX------
            -X---XXX
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
            -X-----
            ---X---
            XX--XXX
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

/**
 * Computes the sum of alive neighbors of cell (x,y).
 *
 * @param x `int` X coordinate.
 * @param y `int` Y coordinate.
 * @return `int` - sum of alive neighbors of cell (x,y).
 */
int Neighbors(int x, int y) {
    int Num_neighbors = 0;
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            //If outside grid, skip (count as dead)
            if (i<0 || i>=Grid_rows || j<0 || j>=Grid_col){
                continue;
            }
            // Skip cell we're evaluating
            if(i == x && j == y){
                continue;
            }
            Num_neighbors += grid[i][j];
        }
    }
    return Num_neighbors;
}

// Update the state of all cells in the grid by 
// checking the 4 rules of Game of Life 
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
            // Reproduction
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
    for (int i=0; i<Grid_rows; i++){
      free(temp_grid[i]);
    }
    free(temp_grid);
}

// Prints the grid to terminal where 0s show as "-"
// and 1s show as "X".
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
    }
    refresh();
}

// Copies the current state of the grid onto global
//  variable 'copy' 
void copyGrid(){
    for (int i = 0; i < Grid_rows; i++) {
        for (int j = 0; j < Grid_col; j++) {
            copy[i][j] = grid[i][j];
        }
    }
}

// Function that prompts the user the dimensions of the
// grid as well as preferred scenario
void requestVars(){
    WINDOW *win = newwin(1000, 1000, 0, 0);                 
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
    wrefresh(win);

}

// Frees dynamically allocated memory in variables `copy` and `grid`
void freeVars(){
    // Free copy
    for (int i = 0; i< Grid_rows; i++){
        free(copy[i]);
    }
    free(copy);

    // Free main grid
    for (int i = 0; i< Grid_rows; i++){
         free(grid[i]);
    }
    free(grid);

}

/**
 * Performs all actions required to run the game.
 *
 * @param None
 * @return `int` - 0 if the simulation ended successfully, 1 otherwise.
 */
int play() {
    // Set SIGINT callback function
    signal(SIGINT, intHandler);

    // Create new ncurses window
    initscr();
    requestVars();

    // Customize window with requested scenery and dimensions
    createGrid();                       
    initial(scenary); 

    int loop = -1;
    copy = initGrid();

    // Game loop
    while (keepRunning) {
        loop++;
        printGrid();    // Plot the grid
        newGrid();      // Update the grid values 
        usleep(100000); // Sleep for 0.1 seconds

        // Compare if the grid is the same for every oscillator period        
        if(loop == 0){
            copyGrid();
        }
        else if(loop == 2 || loop == 3 || loop == 15){
            if (loop == 15){
                loop = -1;
            }

            int count = 0;

            // Count how many cells of 'grid' are equal to 'copy'
            for (int i = 0; i < Grid_rows; i++) {
                for (int j = 0; j < Grid_col; j++) {
                    if(copy[i][j] == grid[i][j]){
                        count++;
                    }
                }
            }
            
            //If all the grid values are the same then break the loop.
            if(count == Grid_rows*Grid_col){
                keepRunning=false;
            }
        }
    }

    freeVars();
    endwin();
    return 0;
}