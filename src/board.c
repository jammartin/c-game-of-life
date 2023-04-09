#include "../include/board.h"

// to be allocated depending on screen size
int **currentBoard;

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

void setUpGun() {
    // left block
    currentBoard[5][1] = 1;
    currentBoard[5][2] = 1;
    currentBoard[6][1] = 1;
    currentBoard[6][2] = 1;
    // bird's head
    currentBoard[5][11] = 1;
    currentBoard[6][11] = 1;
    currentBoard[7][11] = 1;
    currentBoard[4][12] = 1;
    currentBoard[8][12] = 1;
    currentBoard[3][13] = 1;
    currentBoard[9][13] = 1;
    currentBoard[3][14] = 1;
    currentBoard[9][14] = 1;
    // eye
    currentBoard[6][15] = 1;
    // beak
    currentBoard[4][16] = 1;
    currentBoard[8][16] = 1;
    currentBoard[5][17] = 1;
    currentBoard[6][17] = 1;
    currentBoard[7][17] = 1;
    currentBoard[6][18] = 1;
    // ominos object
    currentBoard[3][21] = 1;
    currentBoard[4][21] = 1;
    currentBoard[5][21] = 1;
    currentBoard[3][22] = 1;
    currentBoard[4][22] = 1;
    currentBoard[5][22] = 1;
    currentBoard[2][23] = 1;
    currentBoard[6][23] = 1;
    currentBoard[1][25] = 1;
    currentBoard[2][25] = 1;
    currentBoard[6][25] = 1;
    currentBoard[7][25] = 1;
    // right block
    currentBoard[3][35] = 1;
    currentBoard[4][35] = 1;
    currentBoard[3][36] = 1;
    currentBoard[4][36] = 1;
    
}

void setUpBomb(){
    currentBoard[1+MAXROWS/2][0+MAXCOLUMNS/2] = 1;
    currentBoard[0+MAXROWS/2][1+MAXCOLUMNS/2] = 1;
    currentBoard[1+MAXROWS/2][2+MAXCOLUMNS/2] = 1;
    currentBoard[3+MAXROWS/2][2+MAXCOLUMNS/2] = 1;
    currentBoard[4+MAXROWS/2][2+MAXCOLUMNS/2] = 1;
    currentBoard[4+MAXROWS/2][3+MAXCOLUMNS/2] = 1;
    currentBoard[5+MAXROWS/2][3+MAXCOLUMNS/2] = 1;
    currentBoard[3+MAXROWS/2][5+MAXCOLUMNS/2] = 1;
    currentBoard[2+MAXROWS/2][7+MAXCOLUMNS/2] = 1;
    currentBoard[1+MAXROWS/2][7+MAXCOLUMNS/2] = 1;
    currentBoard[3+MAXROWS/2][9+MAXCOLUMNS/2] = 1;
    currentBoard[4+MAXROWS/2][10+MAXCOLUMNS/2] = 1;
    currentBoard[3+MAXROWS/2][12+MAXCOLUMNS/2] = 1;
    currentBoard[2+MAXROWS/2][12+MAXCOLUMNS/2] = 1;
    currentBoard[0+MAXROWS/2][13+MAXCOLUMNS/2] = 1;
    currentBoard[0+MAXROWS/2][14+MAXCOLUMNS/2] = 1;
    currentBoard[1+MAXROWS/2][14+MAXCOLUMNS/2] = 1;
}

void destroyBoard(){
    for (int i=0; i<MAXROWS; i++){
	free(currentBoard[i]); 
    }
    free(currentBoard);
}
