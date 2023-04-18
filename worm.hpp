//
// Created by Zack on 5/10/2021.
//
// This data structure uses a vector of pairs to form a circular queue of size rows * columns for keeping track of the
// pieces of the worm. isGrowing is used as a bool to tell when the worm should delete its tail while head and tail
// keep our position in the circular queue.

#ifndef SCREENEXAMPLE_WORM_HPP
#define SCREENEXAMPLE_WORM_HPP
#include <vector>

class Worm {
public:
    Worm(const int &rows, const int &columns);
    void move(const char &direction);
    int &getGrowth(){return isGrowing;}
    std::pair<int, int> peekAhead(const char &direction);
    std::pair<int, int> getHead();
    std::pair<int, int> getTail();
private:
    std::vector<std::pair<int, int>> worm;
    int isGrowing;
    int head;
    int tail;
};

#endif //SCREENEXAMPLE_WORM_HPP
