#include "helpers.h"
#include <regex>
#include <limits>
#include <iostream>


std::string parseCommand(const std::string& command, std::string &name, std::string &id, int &nth) {
    name = "";
    id = "";
    nth = -1;

    // commands
    const std::regex cInsert(R"RX(^\s*insert\s+"([A-Za-z][A-Za-z ]*)"\s+(\d{8})\s*$)RX");
    const std::regex cRemove(R"RX(^\s*remove\s+(\d{8})\s*$)RX");
    const std::regex cSearchID(R"RX(^\s*search\s+(\d{8})\s*$)RX");
    const std::regex cSearchName(R"RX(^\s*search\s+"([A-Za-z][A-Za-z ]*)"\s*$)RX");
    const std::regex cPrintInorder(R"RX(^\s*printInorder\s*$)RX");
    const std::regex cPrintPreorder(R"RX(^\s*printPreorder\s*$)RX");
    const std::regex cPrintPostorder(R"RX(^\s*printPostorder\s*$)RX");
    const std::regex cPrintLevelCount(R"RX(^\s*printLevelCount\s*$)RX");
    const std::regex cRemoveInorder(R"RX(^\s*removeInorder\s+(\d+)\s*$)RX");

    std::smatch m;

    if (std::regex_match(command, m, cInsert)) {
        name = m[1].str();
        id = m[2].str();
        return "insert";
    }
    if (std::regex_match(command, m, cRemove)) {
        id = m[1].str();
        return "remove";
    }
    if (std::regex_match(command, m, cSearchID)) {
        id = m[1].str();
        return "searchID";
    }
    if (std::regex_match(command, m, cSearchName)) {
        name = m[1].str();
        return "searchName";
    }
    if (std::regex_match(command, m, cPrintInorder)) {
        return "printInorder";
    }
    if (std::regex_match(command, m, cPrintPreorder)) {
        return "printPreorder";
    }
    if (std::regex_match(command, m, cPrintPostorder)) {
        return "printPostorder";
    }
    if (std::regex_match(command, m, cPrintLevelCount)) {
        return "printLevelCount";
    }
    if (std::regex_match(command, m, cRemoveInorder)) {
        try {
            long long k = std::stoll(m[1].str());
            if (k < 0 || k > std::numeric_limits<int>::max()) {
                return "unsuccessful";
            }
            nth = static_cast<int>(k);
            return "removeInorder";
        } catch (...) {
            return "unsuccessful";
        }
    }

    return "unsuccessful";
}

bool verifyCommand(const std::string& command, AVL &tree) {
    std::string name, id;
    int nth = -1;

    const std::string comm = parseCommand(command, name, id, nth);

    if (comm == "insert") {
        tree.insert(name, id);
        return true;
    }
    if (comm == "remove") {
        tree.remove(id);
        return true;
    }
    if (comm == "searchID") {
        tree.searchID(id);
        return true;
    }
    if (comm == "searchName") {
        tree.searchName(name);
        return true;
    }
    if (comm == "printInorder") {
        tree.printInorder();
        return true;
    }
    if (comm == "printPreorder") {
        tree.printPreorder();
        return true;
    }
    if (comm == "printPostorder") {
        tree.printPostorder();
        return true;
    }
    if (comm == "printLevelCount") {
        tree.printLevelCount();
        return true;
    }
    if (comm == "removeInorder") {
        tree.removeInorder(nth);
        return true;
    }

    return false;
}
