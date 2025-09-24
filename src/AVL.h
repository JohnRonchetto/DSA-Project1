

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

    // actually inserts and rotates as needed
    Node* helperInsert(Node* helpRoot, const std::string& name, const std::string& id);
    // actually removes (also rotates)
    Node* helperRemove(Node* helpRoot, const std::string& id);
    // search node with id
    Node* helperSearch(const std::string& id) const;

    // helper functions
    void setHeight(Node* n);    // 1 based index
    static int getHeight(Node* n);
    static int getBalance(Node* n);    // (left - right) height
    static Node* leftmost(Node* n);    // for inorder successor


public:
    // add later
    AVL() = default;
    ~AVL() = default;

    // Inserts and prints successful/unsuccessful
    void insert(const std::string& name, const std::string& id);

    // removes and prints successful/unsuccessful
    void remove(const std::string& id);

    // search by ID and prints successful/unsuccessful
    void search(const std::string& id);

    // traversal
    std::vector<std::string> inorder() const;


};


#endif //PROJECT1_AVL_H
