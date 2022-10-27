```
  #####                                           #                       
 #     #   ##   #    # ######     ####  ######    #       # ###### ###### 
 #        #  #  ##  ## #         #    # #         #       # #      #      
 #  #### #    # # ## # #####     #    # #####     #       # #####  #####  
 #     # ###### #    # #         #    # #         #       # #      #      
 #     # #    # #    # #         #    # #         #       # #      #      
  #####  #    # #    # ######     ####  #         ####### # #      ###### 
                                                                          
```

A simple C implementation of [John Conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## Dependencies
This implementation uses [ncurses](https://invisible-island.net/ncurses/ncurses-intro.html) for screen manipulation. 

### Install on Linux

```
$ sudo apt install libncurses-dev
```

### Install on MacOS
 
```
$ brew install ncurses
```

## Getting started
The program can be build by using the [Makefile](./Makefile), which creates the executable `bin/gol`. To play, just type 

```
$ make
$ bin/gol
```
into your terminal.

