// Coder 1

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

#include "game.h"

/**
 * Executes the Game of Life from the local 'game.h' library.
 *
 * @param None
 * @return `int` - 0 if the simulation ended successfully, 1 otherwise.
 */
int main()
{
    play();
    return 0;
}