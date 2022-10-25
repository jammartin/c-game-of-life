#ifndef GOL_CELL_H
#define GOL_CELL_H

#include "global.h"

int aliveNeighbors(int board[MAXROWS][MAXCOLUMNS], int row, int column);
int aliveNeighborsInRow(int board[MAXROWS][MAXCOLUMNS], int testRow, int row, int column);

#endif // GOL_CELL_H
