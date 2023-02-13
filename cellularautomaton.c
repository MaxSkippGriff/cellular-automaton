/*

This program utilises a cellular automaton.

It's very simple and mainly designed to write
in C again -- it's been a while!

*/

/* Import libraries */
#include <stdio.h>
#include <cellular.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>

/* Board dimensions */
#define ROWS 30
#define COLS 80
/* Number of generations of model */
#define GENERATIONS 1000
/* Suspends execution for microsecond intervals */
#define SLOW 100000
/* Probabilities of death (IGNITE) and growth (GROW) */
#define DEATH 0.0004
#define GROW 0.004
/* Three main cell states */
typedef enum states{EMPTY, GROWTH, DEATH} states;
typedef enum bool{true, false} bool;


int main(void) {
	int i;
	int board[ROWS][COLS]={0};
	initialiseboard(board);
  srand(time(NULL));
  /* Generate growth on board for 1000 gen cycles */
	for (i=1; i<=GENERATIONS; i++) {
		growth(board);
		/* Suspends execution for intervals - i.e., slow visuals */
		usleep(SLOW);
	}
	return 0;
}

/* Create an empty board with dimensions 30 by 80 */
void initialiseboard(int board[ROWS][COLS]) {
	int i, j;
	for (i= 0; i<ROWS; i++) {
		for (j=0; j<COLS; j++) {
			board[i][j]=EMPTY;
		}
	}
}

/* Populate board with random growth cells */
void growth(int board[ROWS][COLS]) {
	int i, j;
	for (i=0; i<ROWS; i++) {
		for (j=0; j<COLS; j++) {
			if (board[i][j]==EMPTY) {
        /* Generate growth in num of cells according to probs */
				if (growthprob()==true) {
					board[i][j]=GROWTH;
				}
			}
		}
	}
}
/* Generates the probability of growth */
bool growthprob(void) {
	if ((double)rand()/RAND_MAX<DEATH) {
		return true;
	}
	return false;
}
