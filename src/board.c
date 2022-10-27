#include "../include/board.h"

void initializeBoard() {
    // get max rows and collumns from ncurses
    MAXROWS = LINES-1;
    MAXCOLUMNS = COLS;

    // allocate memory for board
    currentBoard = (int**)malloc(MAXROWS * sizeof(int*));
    for (int i=0; i<MAXROWS; i++){
	currentBoard[i] = (int*)malloc(MAXCOLUMNS*sizeof(int));
    }
}

void printBoardCurrentState() {
    clear(); // clear screen

    for (int i = 0; i < MAXROWS; i++) {
	for (int j = 0; j < MAXCOLUMNS; j++) {
	    if(currentBoard[i][j]) {
		mvaddch(i, j, ACS_BLOCK);
	    } else {
		mvaddch(i, j, '.');
	    }
	}
    }
    mvaddstr(MAXROWS, MAXCOLUMNS/2-11, "PRESS ANY KEY TO QUIT");
    refresh();
}

void setBoardNextState() {
    int nextBoard[MAXROWS][MAXCOLUMNS];

    for (int i = 0; i < MAXROWS; i++) {
	for (int j = 0; j < MAXCOLUMNS; j++) {
	    int neighbors = 0;

	    neighbors = aliveNeighbors(currentBoard, i, j);

     	   // Condensed rules from
	   // https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
	   if ((currentBoard[i][j] && neighbors == 2) || neighbors == 3) {
	       nextBoard[i][j] = 1; // rules 1 & 2
	   } else {
	       nextBoard[i][j] = 0; // rule 3
	   }
	}
    }

    for (int i = 0; i < MAXROWS; i++) {
	for (int j = 0; j < MAXCOLUMNS; j++) {
	    currentBoard[i][j] = nextBoard[i][j];
	}
    }
    
}

void setUpRandom() {
    for (int i = 0; i < MAXROWS; i++) {
	for (int j = 0; j < MAXCOLUMNS; j++) {
	    // see https://stackoverflow.com/a/21579744/6208997
	    currentBoard[i][j] = rand() & 1;
	}
    }
}

void setUpGlider() {
    for (int i = 0; i < MAXROWS; i++) {
	for (int j = 0; j < MAXCOLUMNS; j++) {
	    currentBoard[i][j] = 0;
	}
    }

    currentBoard[0][1] = 1;
    currentBoard[1][2] = 1;
    currentBoard[2][0] = 1;
    currentBoard[2][1] = 1;
    currentBoard[2][2] = 1;
}

void destroyBoard(){
    for (int i=0; i<MAXROWS; i++){
	free(currentBoard[i]); 
    }
    free(currentBoard);
}
