/* This program utilises a cellular automaton */

/* Import libraries */
#include <stdio.h>
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
/* Probabilities of lightning (IGNITE)
  and growth (GROW) */
#define IGNITE 0.0004
#define GROW 0.004
/* Three main cell states */
typedef enum states{EMPTY, TREE, FIRE} states;
typedef enum bool{true, false} bool;
