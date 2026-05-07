//
// Created by H on 29/04/2026.
//

#include "SaveFile.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include "Bug.h"

extern std::vector<Bug*> bugs;
extern std::map<int, std::vector<std::string>> killMap;

void saveFile() {
    // generate filename with timestamp
    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);
    char timestamp[32];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", t);
    std::string filename = "bugs_life_history_" + std::string(timestamp) + ".out";

    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error writing to file." << std::endl;
        return;
    }

    // BUGS section
    file << "=== Bugs ===\n";
    for (Bug* b : bugs) {
        file << b->getID() << " " << b->getType()
             << " (" << b->getX() << "," << b->getY() << ")"
             << " Health: " << b->getHealth()
             << " Status: " << (b->getAlive() ? "Alive" : "Dead")
             << "\n";
    }

    // MOVEMENT section
    file << "\n=== Movement ===\n";
    for (Bug* b : bugs) {
        file << b->getType() << " " << b->getID() << ": ";
        for (auto it = b->getPath().begin(); it != b->getPath().end(); ++it) {
            file << "(" << it->first << "," << it->second << ")";
            if (std::next(it) != b->getPath().end()) file << " -> ";
        }
        file << "\n";
    }

    // KILLS section
    file << "\n=== Kills ===\n";
    std::cout << "Life history written to " << filename << std::endl;
    file.close();
}