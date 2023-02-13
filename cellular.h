#include <stdio.h>
#include <stdlib.h>
/* Initialises board with empty cells */
void initialiseboard(int board[ROWS][COLS]);
/* Initiates tree growth phase */
void treegrowth(int board[ROWS][COLS]);
/* Generates tree growth according to 'GROW' */
bool growthprob(void);
/* Prints the forest fire board */
void display(int board[ROWS][COLS]);
