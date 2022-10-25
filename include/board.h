#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include <stdlib.h>
#include <stdio.h>
#include "cell.h"
#include "global.h"

void initializeBoard();
void printBoardCurrentState();
void setBoardNextState();

void setUpGlider();

int currentBoard[MAXROWS][MAXCOLUMNS];

#endif // GOL_BOARD_H
