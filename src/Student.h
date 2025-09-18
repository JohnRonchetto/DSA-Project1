//
// Created by john4 on 9/15/2025.
//

#ifndef PROJECT1_STUDENT_H
#define PROJECT1_STUDENT_H

#include <string>

class Student {
private:
    std::string UFID;
    std::string name;
public:
    // constructors
    Student() : UFID(""), name("") {}
    Student(const std::string& n, std::string id)
        : UFID(id), name(n) {}

    // Getters
    std::string getUFID() const { return UFID; }
    std::string getName() const { return name; }

    // Setters
    void setUFID(std::string id) { UFID = id; }
    void setName(const std::string& n) { name = n; }

};


#endif //PROJECT1_STUDENT_H