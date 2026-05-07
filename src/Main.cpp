//
// Created by H on 29/04/2026.
//

#include "Main.h"

#include <iostream>
#include <map>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>

#include "Bug.h"
#include "LoadFile.h"
#include "SaveFile.h"

/*
 *  TODO:   Menu Items like
 *  TODO:               1. Load Data from file
 *  TODO:               2. Display all bugs
 *  TODO:               3. Find a bug given an id
 *  TODO:               4. Action "Tap" which causes all bugs to move and then fight/eat each other
 *  TODO:               5. Display Life history of all bugs (path taken)
 *  TODO:               6. Display all cells listing their bugs
 *  TODO:               7. Run simulation ("Tap" action every second)
 *  TODO:               8. Exit (Write Life history of all bugs to file)
 */

void menu();

void loadData(std::vector<Bug*> &bugs);

void displayAllBugs();

void displayByID();

void tapGlass();

void displayPathHistoryAllBugs();

void displayAllCells();

void runSimulation();

std::vector<Bug*> bugs;

std::map<std::pair<int,int>, std::vector<Bug*>> bugMap;

std::map<int, std::vector<std::string>> killMap;

void router(int choice);

int main() {

    // call menu
    int choice = -1;
    do {
        menu();
        std::cin >> choice;
        router(choice);

    } while (choice > 0 && choice < 9);


    return 0;
}


void menu() {
    std::cout << "+-------------------------------------+" << std::endl;
    std::cout << "|  Welcome to the Hopper World  |" << std::endl;
    std::cout << "+-------------------------------------+" << std::endl;
    std::cout << "| 1. Load Data from file              |" << std::endl;
    std::cout << "| 2. Display all bugs                 |" << std::endl;
    std::cout << "| 3. Display bug by ID                |" << std::endl;
    std::cout << "| 4. Tap the glass                    |" << std::endl;
    std::cout << "| 5. Display Life history of all bugs |" << std::endl;
    std::cout << "| 6. Display all cells                |" << std::endl;
    std::cout << "| 7. Run simulation                   |" << std::endl;
    std::cout << "| 8. Exit (writes history to file)    |" << std::endl;
    std::cout << "+-------------------------------------+" << std::endl;
    std::cout << "| Input:";

}

void saveFile();

void router(int choice) {
    switch (choice) {
        case 1:
            loadData(bugs);
            break;
        case 2:
            // nayem
            displayAllBugs();
            break;
        case 3:
            // nayem
            displayByID();
            break;
        case 4:
            tapGlass();
            break;
        case 5:
            displayPathHistoryAllBugs();
            break;
        case 6:
            displayAllCells();
            break;
        case 7:
            runSimulation();
            break;
        case 8:
            saveFile();
    }
}

void displayAllBugs() {

}

void displayByID() {

}

void fight();

void tapGlass() {
    for (int b = 0; b < bugs.size(); b++) {
        if (bugs[b]->getAlive()) {
            bugs[b]->move();
        }
    }
    fight();
    std::cout << "Cycle completed " << std::endl;

}

void fight() {
    // CELL POSITION : ALL BUGS ON THAT CELL
    std::map<std::pair<int, int>, std::vector<Bug*>> lookupBugs;

    for (int i = 0; i < bugs.size(); i++) {
        if (bugs[i]->getAlive()) {
            lookupBugs[bugs.at(i)->getPosition()].push_back(bugs.at(i));
        }
    }

        for (auto& entry : lookupBugs) {
            if (entry.second.size() > 1) {
                std::pair<Bug*, Bug*> fightingPair = {entry.second[0], entry.second[1]};

                for (int i = 0; i < 3; i++) {       // 3 rounds
                    const int firstDamage = std::rand() % 6;
                    const int secondDamage = std::rand() % 6;


                    fightingPair.first->dealDamage(firstDamage);
                    if (fightingPair.first->getHealth() <= 0) {
                        fightingPair.first->setAlive(false);

                        std::cout << fightingPair.first->getType() << " " << fightingPair.first->getID()
                              << " was killed by " << fightingPair.second->getType() << " " << fightingPair.second->getID() << std::endl;

                        killMap[fightingPair.first->getID()].push_back(fightingPair.second->getType() + " " + std::to_string(fightingPair.second->getID()));
                        break;
                    }


                    fightingPair.second->dealDamage(secondDamage);
                    if (fightingPair.second->getHealth() <= 0) {
                        fightingPair.second->setAlive(false);

                        std::cout << fightingPair.second->getType() << " " << fightingPair.second->getID()
                              << " was killed by " << fightingPair.first->getType() << " " << fightingPair.first->getID() << std::endl;

                        killMap[fightingPair.second->getID()].push_back(fightingPair.first->getType() + " " + std::to_string(fightingPair.first->getID()));
                        break;
                    }
                }
            }
        }
    }

void displayPathHistoryAllBugs() {

    for (Bug* b : bugs) {
        std::cout << b->getID() << " " << b->getType() << "  ";
        for (auto it = b->getPath().begin(); it != b->getPath().end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ->";
        }
        std::cout << std::endl;
    }

}

void displayAllCells() {
    bugMap.clear();
    for (int b = 0; b < bugs.size(); b++) {
        bugMap[bugs.at(b)->getPosition()].push_back(bugs.at(b));
    }

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            std::cout << "(" << x << "," << y << "): ";
            auto it = bugMap.find(std::make_pair(x, y));
            if (it == bugMap.end()) {
                std::cout << "empty" << std::endl;
            } else {
                for (Bug* b : it->second) {
                    std::cout << b->getType() << " " << b->getID() << "  ";
                }
                std::cout << std::endl;
            }
        }
    }
}

void runSimulation() {
    std::cout << "Starting simulation..." << std::endl;

    int aliveBugs = bugs.size();
    while (aliveBugs > 1) {
        tapGlass();

        aliveBugs = 0;
        for (Bug* b : bugs) {
            if (b->getAlive()) aliveBugs++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    for (Bug* b : bugs) {
        if (b->getAlive()) {
            std::cout << "Last bug standing: " << b->getType() << " " << b->getID() << std::endl;
        }
    }
}


