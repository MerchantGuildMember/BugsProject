//
// Created by H on 29/04/2026.
//

#include "Main.h"

#include <iostream>
#include <ostream>
#include <vector>

#include "Bug.h"
#include "LoadFile.h"

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

// initialise a 2d vector with 100 grid boxes @ 10 x 10 with a value of 'E' to indicate emptiness.
std::vector<std::vector<char>> cells(10, std::vector<char>(10, 'E'));

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
            // nayem
            tapGlass();
            break;
        case 5:
            displayPathHistoryAllBugs();
            break;
        case 6:
            displayAllCells();
            break;
        case 7:
            // nayem
            runSimulation();
            break;
        case 8:
            exit(0);
            break;


    }
}

void displayAllBugs() {

}

void displayByID() {

}

void tapGlass() {

}

void displayPathHistoryAllBugs() {

}

void displayAllCells() {
    std::cout << "Displaying all cells..." << std::endl;

    // make X and Y coords + values for easier valuing later on
    for (int i = 0; i < cells.size(); i++) {
        for (int j = 0; j < cells[i].size(); j++) {
            std::cout << cells[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

void runSimulation() {

}


