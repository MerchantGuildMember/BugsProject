//
// Created by H on 29/04/2026.
//

#ifndef BUGSPROJECT_BUG_H
#define BUGSPROJECT_BUG_H
#include <list>
#include <string>
#include <utility>

//      X  0    1    2    3    4    5    6    7    8    9
// Y
// 0      (0,0)(1,0)(2,0)(3,0)(4,0)(5,0)(6,0)(7,0)(8,0)(9,0)
// 1      (0,1)(1,1)(2,1)(3,1)(4,1)(5,1)(6,1)(7,1)(8,1)(9,1)
// 2      (0,2)(1,2)(2,2)(3,2)(4,2)(5,2)(6,2)(7,2)(8,2)(9,2)
// 3      (0,3)(1,3)(2,3)(3,3)(4,3)(5,3)(6,3)(7,3)(8,3)(9,3)
// 4      (0,4)(1,4)(2,4)(3,4)(4,4)(5,4)(6,4)(7,4)(8,4)(9,4)
// 5      (0,5)(1,5)(2,5)(3,5)(4,5)(5,5)(6,5)(7,5)(8,5)(9,5)
// 6      (0,6)(1,6)(2,6)(3,6)(4,6)(5,6)(6,6)(7,6)(8,6)(9,6)
// 7      (0,7)(1,7)(2,7)(3,7)(4,7)(5,7)(6,7)(7,7)(8,7)(9,7)
// 8      (0,8)(1,8)(2,8)(3,8)(4,8)(5,8)(6,8)(7,8)(8,8)(9,8)
// 9      (0,9)(1,9)(2,9)(3,9)(4,9)(5,9)(6,9)(7,9)(8,9)(9,9)
//
// NORTH edge: y == 0
// SOUTH edge: y == 9
// WEST edge:  x == 0
// EAST edge:  x == 9


class Bug {
    protected:
        int id;
        std::pair<int, int> position;
        enum direction {
            NORTH,
            EAST,
            SOUTH,
            WEST
        };
        direction currentDirection;
        int health;
        bool isAlive;
        std::list<std::pair<int, int>> path;

    Bug(int id, int x, int y, int dir, int health)
    : id(id), position(x, y), currentDirection(direction(dir)), health(health), isAlive(true) {}

    // getters
    public:
        int getID() { return id; }
        std::pair<int, int> getPosition() { return position; }
        int getX() { return position.first; }
        int getY() { return position.second; }
        virtual std::string getType() = 0;
        const std::list<std::pair<int, int>> getPath() const { return path; }
        int getHealth() { return health; }
        bool getAlive() { return isAlive; }
        void dealDamage(int n) { this->health = health - n; }
        void setAlive(bool b) { this->isAlive = b; }
        std::string getDirection() {
            switch (currentDirection) {
                case NORTH: return "North";
                case EAST:  return "East";
                case SOUTH: return "South";
                case WEST:  return "West";
                default:    return "Unknown";
            }
        }

    virtual void move() = 0;

    bool isWayBlocked() {
        return false;
    }
};


#endif //BUGSPROJECT_BUG_H