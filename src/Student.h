//
// Created by john4 on 9/15/2025.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>

class Student {
private:
    std::string id;
    std::string name;
public:
    // constructors
    Student() : id(""), name("") {}
    Student(const std::string& n, std::string ID)
        : id(ID), name(n) {}

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }


};


#endif //PROJECT1_STUDENT_H