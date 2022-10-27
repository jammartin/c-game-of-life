#ifndef GOL_CELL_H
#define GOL_CELL_H

#include "global.h"

int aliveNeighbors(int **board, int row, int column);
int aliveNeighborsInRow(int **board, int testRow, int row, int column);

#endif // GOL_CELL_H
