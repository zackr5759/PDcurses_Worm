//
// Created by Zack on 5/10/2021.
//

#include "freePool.hpp"
freePool::freePool(const int &rows, const int &columns) {
    lastIndex = 0;
    pool.resize(rows * columns);
}

void freePool::remove(const int &index) {
    pool.at(index) = pool.back();
    lastIndex--;

}

void freePool::add(const int &row, const int &column){
    pool.at(lastIndex) = std::make_pair(row, column);
    lastIndex++;
}

std::pair<int, int> freePool::at(const int &index){
   return pool.at(index);
}