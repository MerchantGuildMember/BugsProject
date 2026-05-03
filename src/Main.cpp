//
// Created by H on 29/04/2026.
//

#include "Main.h"

#include <iostream>
#include <ostream>

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

int main() {

    std::cout << "Hello World!" << std::endl;

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
}
