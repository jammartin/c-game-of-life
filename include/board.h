#ifndef GOL_BOARD_H
#define GOL_BOARD_H

#include <curses.h>
#include <stdlib.h>

#include "global.h"
#include "cell.h"

void initializeBoard();
void printBoardCurrentState();
void setBoardNextState();

void setUpGlider();
void setUpRandom();
void setUpGun();
void setUpBomb();

void destroyBoard();

#endif // GOL_BOARD_H
