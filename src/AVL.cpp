//
// Created by john4 on 9/12/2025.
//

#include "AVL.h"
#include <iostream>


AVL::Node * AVL::helperInsert(Node *helpRoot, int key) {

    if (helpRoot == nullptr) {
        return new Node(key);
    } else if (key < helpRoot->val) {
        helpRoot->left = helperInsert(helpRoot->left, key);
    } else {
        helpRoot->right = helperInsert(helpRoot->right, key);
    }

    return helpRoot;
}


void AVL::helperInorder(Node *helpRoot) {

    if(helpRoot == nullptr) {
        std::cout << "";
    } else {
        helperInorder(helpRoot->left);
        std::cout << helpRoot->val << " ";
        helperInorder(helpRoot->right);
    }
}

void AVL::inorder() {
    helperInorder(this->root);
}

void AVL::insert(int key) {
    this->root = helperInsert(this->root, key);
}
