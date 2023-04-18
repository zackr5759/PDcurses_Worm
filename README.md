# PDcurses_Worm

A c++ project to use the PDcurses library to draw on the console to play a game of snake/worm.
The easiest way to play is to have PDcurses installed on a Linux/Unix system and navigate to the worm folder in a terminal.
Type "make game.x" and the c++ files will be compiled into the game.x file.
Type "./game.x 9 10" to start a game with dimensions 9 height and 10 length, these values can go up to 25 and 80 respectively. 

Surprisingly, this simple game has some data structure challenges in the form of keeping track of valid locations to put the next number for the worm to eat onto the board. You can't randomly select a position as the game must update the next spot to go on a set time interval and the random selection process could take more time than we have available if it keeps selecting occupied positions. 
