//
// Zigzagger: moves 1 unit forward, then rotates 90 degrees clockwise after each move.
// Behaviour is distinct from Crawler (random on block) and Hopper (multi-unit jump).
//

#ifndef BUGSPROJECT_ZIGZAGGER_H
#define BUGSPROJECT_ZIGZAGGER_H
#include <iostream>
#include "Bug.h"

class Zigzagger : public Bug {
    public:
        Zigzagger(int id, int x, int y, int dir, int health)
        : Bug(id, x, y, dir, health) {}

    void move() {
        // if blocked, rotate clockwise until unblocked
        while (isWayBlocked()) {
            currentDirection = direction((currentDirection + 1) % 4);
        }

        switch (currentDirection) {
            case NORTH:
                std::cout << "Zigzagger " << id << " moving from (" << position.first << "," << position.second
                          << ") to (" << position.first << "," << position.second - 1 << ")" << std::endl;
                position.second -= 1;
                break;
            case EAST:
                std::cout << "Zigzagger " << id << " moving from (" << position.first << "," << position.second
                          << ") to (" << position.first + 1 << "," << position.second << ")" << std::endl;
                position.first += 1;
                break;
            case SOUTH:
                std::cout << "Zigzagger " << id << " moving from (" << position.first << "," << position.second
                          << ") to (" << position.first << "," << position.second + 1 << ")" << std::endl;
                position.second += 1;
                break;
            case WEST:
                std::cout << "Zigzagger " << id << " moving from (" << position.first << "," << position.second
                          << ") to (" << position.first - 1 << "," << position.second << ")" << std::endl;
                position.first -= 1;
                break;
        }

        // rotate 90 degrees clockwise after every move
        currentDirection = direction((currentDirection + 1) % 4);
        path.push_back(position);
    }

    bool isWayBlocked() {
        switch (currentDirection) {
            case NORTH: return position.second == 0;
            case EAST:  return position.first  == 9;
            case SOUTH: return position.second == 9;
            case WEST:  return position.first  == 0;
        }
        return false;
    }

    std::string getType() { return "Zigzagger"; }
};

#endif //BUGSPROJECT_ZIGZAGGER_H
