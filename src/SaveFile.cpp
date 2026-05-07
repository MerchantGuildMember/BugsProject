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


}