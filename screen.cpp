//
// Created by Zack on 5/10/2021.
//


#include "screen.hpp"
#include <iostream>
#include <curses.h>
#include <string>
Screen::Screen(const int &rows, const int &columns): pool(rows, columns){
    munchieLocation.first = -1;
    munchieLocation.second = -1;
    score = 0;
    move(0, 0);
    addstr(" Worm ");
    scoreSpace = columns - 12;
    if(scoreSpace < 6)
        scoreSpace = 6;
    move(0, scoreSpace);
    addstr("Score: 0");
    refresh();

    board.resize(rows);

    for(int i = 0; i < rows; i++){
        board[i].resize(columns);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(i == 0 || i == rows - 1 || j == 0 || j == columns - 1){
                board[i][j] = -1;
                mvaddch(i+1, j , '*');
            }else {
               pool.add(i, j);
               board[i][j] = pool.getIndex();
            }
        }
    }
    refresh();
}

int Screen::at(const int &row, const int &column){
        return board[row][column];
}

void Screen::placeWormPiece(const int &row, const int &column) {
    if (board[row][column] <= 2000)
        pool.at(board[row][column]) = pool.at(pool.getIndex());
    board[row][column] = -1;
}

void Screen::removeWormPiece(const int &row, const int &column) {
        board[row][column] = pool.getIndex();
        pool.at(board[row][column]) = std::make_pair(row, column);
}

void Screen::placeMunchie(){
    srand(time(0));
    int index = rand() % pool.getIndex();
    int munchieValue = rand() % 8 + 1;
    char temp = munchieValue + 48;  //ascii 0-9 to integer 0-9

    munchieLocation = pool.at(index);
    mvaddch(munchieLocation.first + 1, munchieLocation.second, temp);
    board[munchieLocation.first][munchieLocation.second] = 2000 + munchieValue;
    pool.remove(index);
    refresh();
}

void Screen::increaseScore(const int &value) {
    score += value;
    move(0, scoreSpace);
    addstr("Score: ");
    printw("%i",score);
    refresh();
}



