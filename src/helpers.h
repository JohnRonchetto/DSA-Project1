//
// Created by john4 on 9/13/2025.
//


#ifndef PROJECT1_HELPERS_H
#define PROJECT1_HELPERS_H

#include <string>
#include "AVL.h"

// eliminates whitespaces before and after
std::string trim(const std::string& s);

// Takes in one line at the time along with dummy name, id, and nth (for removeIorder(N))
// Verifies that input is correct and assigns name, id, and nth, which are then used in main/test.cpp
// Returns command type
std::string parseCommand(const std::string& command, std::string& name, std::string& id, int& nth);

// For Catch testing and main
bool verifyCommand(const std::string& line, AVL& tree);


#endif //PROJECT1_HELPERS_H