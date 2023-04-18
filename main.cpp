// 5/11/2021 Zachary Robinson
//  This program consists of a main game loop and several data structures to be used to play the classic game snake or
//  worm.The screen class initializes the graphics and is then used in tandem with the freePool class to keep track of
//  the game board, and score. The worm class keeps track of the worm's position and finally, we use the curses library
//  to display our game board and worm to the screen.
#include<curses.h>
#include "getChar.hpp"
#include <string>
#include <iostream>
#include "screen.hpp"
#include "worm.hpp"

void startup( void );
void terminate( void );

int main(int argc,char *argv[])
{
    if(argc != 3){
        std::cout << "usage: " << argv[0] << " 9-25(rows) 9-80(columns);" << std::endl;
        exit(1);
    }

    int rows = std::stoi(argv[1]);
    int columns = std::stoi(argv[2]);

    if((rows < 9 || rows > 25) || (columns < 9 || columns > 80)){
        std::cout << "Rows or columns out of bounds, please enter: (9-25) (9-80)" << std::endl;
    }

    startup();
    Screen screen(rows, columns);
    Worm worm(rows, columns);

    screen.placeWormPiece(worm.getHead().first, worm.getHead().second);
    screen.placeMunchie();

    char lastValidInput = -1;
    char c;
    int x = 0;
    while((c = getChar())){ //Recieve user input, this is the game loop
        if(c == 'h' || c == 'j' || c == 'k' || c == 'l'){
            lastValidInput = c;
        }
        if(lastValidInput != -1) {
            //Set target equal to the value found in the specified screen cell
            int target = screen.at(worm.peekAhead(lastValidInput).first, worm.peekAhead(lastValidInput).second);
            if (target == -1) {     //target is either the borders or the worm
                terminate();
                std::cout << "The worm died since it ran into something!" << std::endl;
                std::cout << "Your final score was: " << screen.getScore() << std::endl;
                return 0;
            }
            if (target > 2000) {    //target is a munchie
                int value = screen.at(worm.peekAhead(lastValidInput).first,
                                      worm.peekAhead(lastValidInput).second);
                value -= 2000;
                worm.getGrowth() += value;
                screen.increaseScore(value);
                screen.placeMunchie();
            }
            if(worm.getGrowth() == 0)
                screen.removeWormPiece(worm.getTail().first, worm.getTail().second);
            worm.move(lastValidInput);
            screen.placeWormPiece(worm.getHead().first, worm.getHead().second);
        }
    }

}

void startup( void )
{
     initscr();	 /* activate the curses */
     curs_set(0);/* do not display the cursor */
     clear();	 /* clear the screen that curses provides */
     noecho();	 /* prevent the input chars to be echoed to the screen */
     cbreak();	 /* change the stty so that characters are delivered to the
		    program as they are typed--no need to hit the return key!*/
}

void terminate( void )
{
     mvcur( 0, COLS - 1, LINES - 1, 0 );
     clear();
     refresh();
     endwin();
}
