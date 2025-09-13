//
// Created by john4 on 9/12/2025.
//

#ifndef PROJECT1_AVL_H
#define PROJECT1_AVL_H
#include <string>


class AVL {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;
    AVL::Node* helperInsert(Node* helpRoot, int key);
    void helperInorder(Node* helpRoot);







public:
    void inorder();
    void insert(int key);

    // This function will test name and UFID
    // if valid insert in tree and return true
    // else don't insert and return false
    bool insert(const std::string& name, const std::string& id);
};


#endif //PROJECT1_AVL_H
