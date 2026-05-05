//
// Created by H on 29/04/2026.
//

#include "LoadFile.h"

#include <iostream>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include <vector>

#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

/* TODO: Load Data from File
 * TODO:    +---------------------------+---------------------------------------------------------------------------+
 * TODO:    |   Type of Bug             |   ‘C’ for crawler, ‘H’ for Hopper                                         |
 * TODO:    |   ID for a bug            |   Unique integer ID value (e.g. 101,102,… etc.)                           |
 * TODO:    |   X coordinate            |   (X,Y) coordinate system where (0,0) is top left hand cell -             |
 * TODO:    |   Y coordinate            |   and X increased to right (East), and Y increases as we go down(South)   |
 * TODO:    |   Direction bug is facing |   Direction values : 1=North, 2=East, 3=South, 4=West (or use enum)       |
 * TODO:    |   Health of bug           |   Measure of bug health (1-20)                                            |
 * TODO:    |   Hop Length              |   Distance (length) of a hop that a Hopper bug can make.                  |
 * TODO:    |                           |   (This field is not present for a Crawler.)                              |
 * TODO:    +---------------------------+---------------------------------------------------------------------------+
 *
 *
 *      C;101;0;0;4;10
 *      H;102;9;0;1;8;2
 *      C;103;9;9;2;5
 */




void loadData(std::vector<Bug*> &bugs) {
    std::ifstream inputFile("bugs.txt");
    if (!inputFile) {
        std::cout << "Error opening bugs.txt" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> fields;

        while (std::getline(ss, token, ';')) {
            fields.push_back(token);
        }

        // TODO IF FIELDS EMPTY SKIP
        if (fields.empty()) continue;

        // TODO GO THROUGH ALL BUG FIELDS AND ASSIGN
        char type = fields[0][0];
        int id = std::stoi(fields[1]);
        int x = std::stoi(fields[2]);
        int y = std::stoi(fields[3]);
        int direction = std::stoi(fields[4]) - 1;
        int health = std::stoi(fields[5]);


        // TODO CHECK FOR TYPE AND ASSIGN CORRECT BUG TYPE
        if (type == 'C') {
            Crawler* crawler = new Crawler(id, x, y, direction, health);
            bugs.push_back(crawler);
        }
        else if (type == 'H') {
            int hopLength = std::stoi(fields[6]);
            Hopper* hopper = new Hopper(id, x, y, direction, health, hopLength);
            bugs.push_back(hopper);
        }
        else {
            std::cout << "invalid type!";
            continue;
        }

        // TODO SMALL DEBUG LINE AT THE END
        std::cout << type << " " << id << " " << x << " " << y << " " << direction << " " << health << std::endl;
    }
    inputFile.close();
}