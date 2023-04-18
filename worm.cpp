//
// Created by Zack on 5/10/2021.
//

#include "worm.hpp"
#include <curses.h>
Worm::Worm(const int &rows, const int &columns){
    isGrowing = 0;
    worm.resize(rows * columns);
    worm.at(0).first = rows/2 ;
    worm.at(0).second = (columns - 1)/2;
    mvaddch((rows/2) + 1, (columns - 1)/2, '@');
    head = 1;
    tail = 0;
    refresh();
}

void Worm::move(const char &direction) {
    mvaddch( worm.at(head - 1).first + 1, worm.at(head - 1).second, 'o');   //replace old head with a body piece
    switch(direction) {
        case 'h':   //left
            worm.at(head).first = worm.at(head - 1).first;
            worm.at(head).second = worm.at(head - 1).second - 1;
            break;
        case 'j':   //down
            worm.at(head).first = worm.at(head - 1).first + 1;
            worm.at(head).second = worm.at(head - 1).second;
            break;
        case 'k':   //up
            worm.at(head).first = worm.at(head - 1).first - 1;
            worm.at(head).second = worm.at(head - 1).second;
            break;
        case 'l':   //right
            worm.at(head).first = worm.at(head - 1).first;
            worm.at(head).second = worm.at(head - 1).second + 1;
            break;
    }
    mvaddch( worm.at(head).first + 1, worm.at(head).second, '@');   //place new head
    if(!isGrowing) {
        mvaddch(worm.at(tail).first + 1, worm.at(tail).second, ' ');   //remove old tail if not growing
        tail++;                                                         //increment tail if not growing
        if(tail == worm.size())
            tail = 0;
    }else {
        isGrowing--;
    }
    head++;
    if(head == worm.size())
        head = 0;
    refresh();

}

std::pair<int, int> Worm::peekAhead(const char &direction) {
    int x,y;
    switch(direction) {
        case 'h':   //left
            x = worm.at(head - 1).first;
            y = worm.at(head - 1).second - 1;
            break;
        case 'j':   //down
            x = worm.at(head - 1).first + 1;
            y = worm.at(head - 1).second;
            break;
        case 'k':   //up
            x = worm.at(head - 1).first - 1;
            y = worm.at(head - 1).second;
            break;
        case 'l':   //right
            x = worm.at(head - 1).first;
            y = worm.at(head - 1).second + 1;
            break;
    }
    return std::make_pair(x, y);
}

std::pair<int, int> Worm::getHead() {
    return worm.at(head - 1);
}

std::pair<int, int> Worm::getTail() {
    return worm.at(tail);
}