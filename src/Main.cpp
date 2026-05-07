//
// Created by H on 29/04/2026.
//

#include "Main.h"

#include <iostream>
#include <map>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
std::map<int, std::string> eatenByMap; // victim id -> "Type ID" of killer

void router(int choice);

int main() {
    std::srand(std::time(nullptr));

    // call menu
    int choice = -1;
    do {
        menu();
        std::cin >> choice;
        router(choice);

    } while (choice > 0 && choice < 9);


    for (Bug* b : bugs) delete b;
    bugs.clear();

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
    if (bugs.empty()) {
        std::cout << "No bugs loaded." << std::endl;
        return;
    }
    for (Bug* b : bugs) {
        std::cout << b->getID() << " " << b->getType()
                  << " (" << b->getX() << "," << b->getY() << ")"
                  << " Health: " << b->getHealth()
                  << " Direction: " << b->getDirection();
        if (b->getHopLength() > 0) std::cout << " HopLength: " << b->getHopLength();
        std::cout << " Status: " << (b->getAlive() ? "Alive" : "Dead") << std::endl;
    }
}

void displayByID() {
    int searchID;
    std::cout << "Enter bug ID: ";
    std::cin >> searchID;

    for (Bug* b : bugs) {
        if (b->getID() == searchID) {
            std::cout << b->getID() << " " << b->getType()
                      << " (" << b->getX() << "," << b->getY() << ")"
                      << " Health: " << b->getHealth()
                      << " Direction: " << b->getDirection();
            if (b->getHopLength() > 0) std::cout << " HopLength: " << b->getHopLength();
            std::cout << " Status: " << (b->getAlive() ? "Alive" : "Dead") << std::endl;
            return;
        }
    }
    std::cout << "Bug " << searchID << " not found." << std::endl;
}

void fight();

void tapGlass() {
    // pick a random alive bug to freeze this round
    std::vector<int> aliveIndices;
    for (int b = 0; b < bugs.size(); b++) {
        if (bugs[b]->getAlive()) aliveIndices.push_back(b);
    }
    if (aliveIndices.empty()) return;
    int frozenIndex = aliveIndices[std::rand() % aliveIndices.size()];
    std::cout << "Frozen this round: " << bugs[frozenIndex]->getType() << " " << bugs[frozenIndex]->getID() << std::endl;

    for (int b = 0; b < bugs.size(); b++) {
        if (bugs[b]->getAlive() && b != frozenIndex) {
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
        auto& cell = entry.second;
        for (int i = 0; i + 1 < (int)cell.size(); i += 2) {
            Bug* first  = cell[i];
            Bug* second = cell[i + 1];

            for (int r = 0; r < 3; r++) {
                first->dealDamage(std::rand() % 6);
                if (first->getHealth() <= 0) {
                    first->setAlive(false);
                    std::string killerStr = second->getType() + " " + std::to_string(second->getID());
                    std::cout << first->getType() << " " << first->getID() << " was killed by " << killerStr << std::endl;
                    killMap[second->getID()].push_back(first->getType() + " " + std::to_string(first->getID()));
                    eatenByMap[first->getID()] = killerStr;
                    break;
                }
                second->dealDamage(std::rand() % 6);
                if (second->getHealth() <= 0) {
                    second->setAlive(false);
                    std::string killerStr = first->getType() + " " + std::to_string(first->getID());
                    std::cout << second->getType() << " " << second->getID() << " was killed by " << killerStr << std::endl;
                    killMap[first->getID()].push_back(second->getType() + " " + std::to_string(second->getID()));
                    eatenByMap[second->getID()] = killerStr;
                    break;
                }
            }
        }
    }
}

void displayPathHistoryAllBugs() {
    for (Bug* b : bugs) {
        std::cout << b->getID() << " " << b->getType() << " Path: ";
        for (auto it = b->getPath().begin(); it != b->getPath().end(); ++it) {
            std::cout << "(" << it->first << "," << it->second << ")";
            if (std::next(it) != b->getPath().end()) std::cout << " -> ";
        }
        if (b->getAlive()) {
            std::cout << " Alive!";
        } else {
            auto it = eatenByMap.find(b->getID());
            if (it != eatenByMap.end())
                std::cout << " Eaten by " << it->second;
            else
                std::cout << " Dead";
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


