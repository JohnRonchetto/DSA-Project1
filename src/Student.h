//
// Created by john4 on 9/15/2025.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>

class Student {
private:
    int UFID;
    std::string name;
public:
    // constructors
    Student() : UFID(0), name("") {}
    Student(const std::string& n, int id)
        : UFID(id), name(n) {}

    // Getters
    int getUFID() const { return UFID; }
    std::string getName() const { return name; }

    // Setters
    void setUFID(int id) { UFID = id; }
    void setName(const std::string& n) { name = n; }

};


#endif //PROJECT1_STUDENT_H