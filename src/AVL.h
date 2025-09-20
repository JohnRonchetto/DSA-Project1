

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

        // node constructor;
        Node(const Student& s): data(s), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root = nullptr;

    // rotations
    Node* rotateRight(Node* n);     // LL case
    Node* rotateLeft(Node* n);      // RR case
    Node* rotateLeftRight(Node* n); // LR case
    Node* rotateRightLeft(Node* n); // RL case

    // insert helper
    Node* helperInsert(Node* helpRoot, std::string name, std::string id);

    //
    void setHeight(Node* n);
    int getHeight(Node* n);


    int getBalance(Node* n);

public:
    // add later
    AVL() = default;
    ~AVL() = default;

    // Inserts and rotates
    void insert(std::string name, std::string id);

    std::string search(std::string id);


    // traversal
    std::vector<std::string> inorder() const;

    // remove by ID
    bool remove(std::string id);

};


#endif //PROJECT1_AVL_H
