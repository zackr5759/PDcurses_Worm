//
// Created by Zack on 5/10/2021.
//
// This data structure uses a 2D vector, the freePool and some small variables to handle on screen events for the worm
// game in tandem with the worm class. I decided to use freePool inside of screen because they are so interconnected
// in how we use them for the worm game.

#ifndef SCREENEXAMPLE_SCREEN_HPP
#define SCREENEXAMPLE_SCREEN_HPP
#include <vector>
#include "freePool.hpp"

class Screen {
public:
    Screen(const int &rows, const int &columns);
    int at(const int &row, const int &column);
    void placeWormPiece(const int &row, const int &column);
    void removeWormPiece(const int &row, const int &column);
    freePool &getPool(){return pool;}
    void placeMunchie();
    void increaseScore(const int &value);
    int getScore(){return score;}
private:
    std::vector<std::vector<int>> board;
    freePool pool;
    std::pair<int, int> munchieLocation;
    int scoreSpace;
    int score;

};


#endif //SCREENEXAMPLE_SCREEN_HPP
