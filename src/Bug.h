//
// Created by H on 29/04/2026.
//

#ifndef BUGSPROJECT_BUG_H
#define BUGSPROJECT_BUG_H
#include <list>
#include <utility>


class Bug {
    protected:
        int id;
        std::pair<int, int> coordinates;
        enum direction {
            NORTH,
            EAST,
            SOUTH,
            WEST
        };
        int health;
        bool isAlive;
        std::list<std::pair<int, int>> path;

    virtual void move() {

    }

    bool isWayBlocked() {
        return false;
    }
};


#endif //BUGSPROJECT_BUG_H