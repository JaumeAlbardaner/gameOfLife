// Coder 1

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONTENTS OF THIS FILE
// Library that contains the names and descriptions of the functions
// used in `game.c`.
///////////////////////////////////////////////////////////////////////////////////////////////////////////


// Handles SIGINT flags to stop the execution of the game.
void intHandler(int dummy);

/**
 * Allocates dynamically in memory a grid of Grid_rows x Grid_col unsigned chars. 
 * These come initialized with a value of 0.
 *
 * @param None
 * @return `unsigned char**` - Pointer to the first value of the grid.
 */
unsigned char **initGrid();

// Initializes the grid with size Grid_rows x Grid_col with a minimum size
//  of 10 per axis.
void createGrid();

/**
 * Initializes the grid with the requested scenario, which is offset randomly.
 *
 * @param scenary `int` : Number of the desired scenario
 * @return None.
 */
void initial(int scenary);

/**
 * Computes the sum of alive neighbors of cell (x,y).
 *
 * @param x `int` X coordinate.
 * @param y `int` Y coordinate.
 * @return `int` - sum of alive neighbors of cell (x,y).
 */
int Neighbors(int x, int y);

// Update the state of all cells in the grid by 
// checking the 4 rules of Game of Life 
void newGrid();

// Prints the grid to terminal where 0s show as "-"
// and 1s show as "X".
void printGrid();

// Copies the current state of the grid onto global
//  variable 'copy' 
void copyGrid();

// Function that prompts the user the dimensions of the
// grid as well as preferred scenario
void requestVars();

// Frees dynamically allocated memory in variables `copy` and `grid`
void freeVars();

/**
 * Performs all actions required to run the game.
 *
 * @param None
 * @return `int` - 0 if the simulation ended successfully, 1 otherwise.
 */
int play();