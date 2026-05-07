//
// Created by H on 30/04/2026.
//

#ifndef BUGSPROJECT_HOPPER_H
#define BUGSPROJECT_HOPPER_H
#include <iostream>

#include "Bug.h"

// Similar to Crawler; just different hop length


class Hopper: public Bug {
    private:
        int hopLength;

    public:
        Hopper(int id, int x, int y, int dir, int health, int hopLength)
        : Bug(id, x, y, dir, health), hopLength(hopLength) {}

    void move() {
        while (isWayBlocked()) {
            currentDirection = direction(rand() % 4);
        }
        int newX = position.first;
        int newY = position.second;
        switch (currentDirection) {
            case NORTH:
                newY = std::max(0, position.second - hopLength);
                break;
            case EAST:
                newX = std::min(9, position.first + hopLength);
                break;
            case SOUTH:
                newY = std::min(9, position.second + hopLength);
                break;
            case WEST:
                newX = std::max(0, position.first - hopLength);
                break;
        }
        std::cout << "Hopper " << id << " moving from (" << position.first << ", " << position.second
                  << ") to (" << newX << ", " << newY << ")" << std::endl;
        position = {newX, newY};
        path.push_back(position);
    }

    bool isWayBlocked() {
        switch (currentDirection) {
            case NORTH:
                if (position.second == 0) {
                    std::cout << "Hopper " << id << " reached northern edge, changing direction." << std::endl;
                    return true;
                }
                break;
            case EAST:
                if (position.first == 9) {
                    std::cout << "Hopper " << id << " reached eastern edge, changing direction." << std::endl;
                    return true;
                }
                break;
            case SOUTH:
                if (position.second == 9) {
                    std::cout << "Hopper " << id << " reached southern edge, changing direction." << std::endl;
                    return true;
                }
                break;
            case WEST:
                if (position.first == 0) {
                    std::cout << "Hopper " << id << " reached western edge, changing direction." << std::endl;
                    return true;
                }
                break;
        }
        return false;
    }

    std::string getType() {
            return "Hopper";
        }

};


#endif //BUGSPROJECT_HOPPER_H