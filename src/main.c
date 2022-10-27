#include <unistd.h>
#include <curses.h>

#include "global.h"
#include "board.h"

int MAXROWS;
int MAXCOLUMNS;

const unsigned int SLEEP_TIME = 50*1000;

#define SS_ROWS 9
#define SS_COLS 73

const char START_SCREEN[SS_ROWS][SS_COLS] =
    {" #####                                           #                      ",
     "#     #   ##   #    # ######     ####  ######    #       # ###### ######", 
     "#        #  #  ##  ## #         #    # #         #       # #      #     ", 
     "#  #### #    # # ## # #####     #    # #####     #       # #####  ##### ",
     "#     # ###### #    # #         #    # #         #       # #      #     ",
     "#     # #    # #    # #         #    # #         #       # #      #     ", 
     " #####  #    # #    # ######     ####  #         ####### # #      ######",
     "",
     "           Choose a seed: <[1] random> <[2] glider> <[3] gun>"};

int main() {
    
    // initialize curses
    initscr();
    cbreak(); // disable line buffering and one character as input at a time
    noecho(); // do not write input back to the screen
    clear(); // probably unneccessary
    
    // initialize board and allocate a grid the size of the screen
    initializeBoard();

    int validOption = false;
    do {
	// print statement from ncurses
	int ssi = MAXROWS/2-SS_ROWS/2; // vertical position of start screen
	int ssj = MAXCOLUMNS/2-SS_COLS/2; // horizontal position of start screen
	ssj = ssj < 0 ? 0 : ssj; // avoid error is screen is not wide enough to fit start screen
	for(int i=ssi; i<ssi+SS_ROWS; i++){
	    mvaddstr(i, ssj, START_SCREEN[i-ssi]);
	}
	refresh();
    
	// get user input
	char usrInp = getch();
    
	switch(atoi(&usrInp)) {
	case 1:
	    setUpRandom();
	    validOption = true;
	    break;
	case 2:
	    setUpGlider();
	    validOption = true;
	    break;
	case 3:
	    setUpGun();
	    validOption = true;
	    break;
	default:
	    mvaddstr(ssi+SS_ROWS+1, ssj+SS_COLS/2-15, "INVALID OPTION. CHOOSE AGAIN!");
	    validOption = false;
	}
    } while (!validOption);

    // dont't interrupt program when no user input is provided to getch()
    nodelay(stdscr, true);
    
    while(true) {
	printBoardCurrentState();
	setBoardNextState();
	usleep(SLEEP_TIME);
	if (getch()!=ERR) break; // exit when a key is pressed
    }

    destroyBoard();
    endwin(); 
    return 0;
}
