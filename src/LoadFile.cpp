//
// Created by H on 29/04/2026.
//

#include "LoadFile.h"

#include <iostream>
#include <fstream>
#include <iosfwd>

#include "Bug.h"

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

    inputFile.close();
    return 0;
}