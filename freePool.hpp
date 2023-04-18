//
// Created by Zack on 5/10/2021.
//
// This is a simple class of a vector of integer pairs for tracking what cells in the screen class are free to have
// a munchie generated inside. Whenever an element is removed from the list, it is done so by copying the last element
// to the deleted element so that the lastIndex will always send us to a usable index for adding other elements.

#ifndef SCREENEXAMPLE_FREEPOOL_HPP
#define SCREENEXAMPLE_FREEPOOL_HPP
#include <vector>

class freePool {
    public:
        freePool(const int &rows, const int &columns);
        int getIndex(){return lastIndex;}
        void remove(const int &index);
        void add(const int &row, const int &column);
        int size(){return pool.size();}
        std::pair<int, int> at(const int &index);
    private:
        int  lastIndex;
        std::vector<std::pair<int, int>> pool;
};


#endif //SCREENEXAMPLE_FREEPOOL_HPP
