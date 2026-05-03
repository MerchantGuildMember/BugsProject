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
            // https://stackoverflow.com/questions/2999012/generating-random-enums
            currentDirection = direction(rand() % 4);       // not sure if it'll work yet
        }
        switch (currentDirection) {
            // Depending on direction, adds +1 or -1 to which item in the pair.
            case NORTH: // If bug is facing NORTH, it will be going up towards 0 so decrement
                std::cout  << "Crawler " << id << " moving from " << position.first << ", " << position.second
                << " to " << position.first << ", " << position.second+1 << std::endl;
                position.second =- 1;
                break;

            case EAST:  // If bug is facing EAST, it will be going away from 0 so increment
                std::cout  << "Crawler " << id << " moving from " << position.first << ", " << position.second
                << " to " << position.first+1 << ", " << position.second << std::endl;
                position.first =+ 1;
                break;

            case SOUTH: // If bug is facing SOUTH, it will be going down away from 0 so increment
                std::cout  << "Crawler " << id << " moving from " << position.first << ", " << position.second
                << " to " << position.first << ", " << position.second-1 << std::endl;
                position.second =+ 1;
                break;

            case WEST:  // If bug is facing WEST, it will be going left towards 0 so decrement
                std::cout  << "Crawler " << id << " moving from " << position.first << ", " << position.second
                << " to " << position.first-1 << ", " << position.second << std::endl;
                position.first =- 1;
                break;

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