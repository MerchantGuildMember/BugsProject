//
// Created by H on 30/04/2026.
//

#ifndef BUGSPROJECT_CRAWLER_H
#define BUGSPROJECT_CRAWLER_H
#include <iostream>

#include "Bug.h"


class Crawler: public Bug {

    void move() {
        while (isWayBlocked()) {

        }
    }

    bool isWayBlocked() {
        switch (currentDirection) {
            case NORTH:
                break;
            case EAST:

                break;
            case SOUTH:

                break;
            case WEST:
                if (position.first == 0) {
                    std::cout  << "Crawler " << id << " reached western edge, changing direction." << std::endl;
                    // https://stackoverflow.com/questions/2999012/generating-random-enums
                    currentDirection = direction(rand() % 4);       // not sure if it'll work yet
                    
                }
                break;
        }

        return false;
    }

};


#endif //BUGSPROJECT_CRAWLER_H