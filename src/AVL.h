

#ifndef PROJECT1_AVL_H
#define PROJECT1_AVL_H
#include "Student.h"
#include <string>
#include <vector>


class AVL {
private:
    struct Node {
        Student data;
        Node* left;
        Node* right;
        int height;

        Node(const Student& s): data(s), left(nullptr), right(nullptr), height(0) {}
    };

    Node* root = nullptr;

    // rotations
    Node* rotateRight(Node* x);     // LL case
    Node* rotateLeft(Node* x);      // RR case
    Node* rotateLeftRight(Node* x); // LR case
    Node* rotateRightLeft(Node* x); // RL case

public:
    // add later
    AVL() = default;
    ~AVL() = default;

    // this will insert, and rotate as needed
    void insert(const Student& s);

    // traversal
    std::vector<std::string> inorder() const;

};


#endif //PROJECT1_AVL_H
