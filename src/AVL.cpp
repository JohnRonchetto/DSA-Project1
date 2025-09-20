//
// Created by john4 on 9/12/2025.
//

#include "AVL.h"
#include <iostream>

// Rotations
// LL case
AVL::Node * AVL::rotateRight(Node *n) {

    // (Should not happen)
    if (n == nullptr) {
        return n;
    }
    if (n->left == nullptr) {
        return n;
    }
    // grandChild == nullptr not a problem

    Node* grandChild = n->left->right;
    Node* newParent = n->left;
    newParent->right = n;
    n->left = grandChild;

    // update heights
    setHeight(n);
    setHeight(newParent);

    return newParent;

}

// RR case
AVL::Node * AVL::rotateLeft(Node *n) {

    // (should not happen)
    if (n == nullptr) {
        return n;
    }
    if (n->right == nullptr) {
        return n;
    }
    // grandChild == nullptr not a problem

    Node* grandchild = n->right->left;
    Node* newParent = n->right;
    newParent->left = n;
    n->right = grandchild;

    // update height
    setHeight(n);
    setHeight(newParent);

    return newParent;
}

// LR case
AVL::Node * AVL::rotateLeftRight(Node *n) {

    if (n == nullptr) {
        return n;
    }

    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

AVL::Node * AVL::rotateRightLeft(Node *n) {

    if (n == nullptr) {
        return n;
    }

    n->right = rotateRight(n->right);
    return rotateLeft(n);
}



AVL::Node* AVL::helperInsert(Node *helpRoot, std::string name, std::string id) {

    // Insertion by recursion
    if (helpRoot == nullptr) {
        return new Node(Student(name, id));
    } else if (id < helpRoot->data.getId()) {
        helpRoot->left = helperInsert(helpRoot->left, name, id);
    } else {
        helpRoot->right = helperInsert(helpRoot->right, name, id);
    }

    // update height
    setHeight(helpRoot);

    // right heavy
    if (getBalance(helpRoot) < -1) {
        // if right subtree left heavy -> RL case
        if (getBalance(helpRoot->right) > 0) {
            helpRoot = rotateRightLeft(helpRoot);
        }
        // else -> RR case
        else {
            helpRoot = rotateLeft(helpRoot);
        }
    }
    // left heavy
    else if (getBalance(helpRoot) > 1) {
        // if left subtree right heavy -> LR case
        if (getBalance(helpRoot->left) < 0) {
            helpRoot = rotateLeftRight(helpRoot);
        }
        // else -> LL case
        else {
            helpRoot = rotateRight(helpRoot);
        }
    }

    return helpRoot;;
}



void AVL::setHeight(Node *n) {
    if (n != nullptr) {

        int leftHeight = getHeight(n->left);
        int rightHeight = getHeight(n->right);

        if (leftHeight > rightHeight) {
            n->height = leftHeight + 1;
        } else {
            n->height = rightHeight + 1;
        }
    }
}

int AVL::getHeight(Node *n) {
    if (n == nullptr) {
        return 0;
    } else {
        return n->height;
    }

}

int AVL::getBalance(Node *n) {
    if (n == nullptr) {
        return 0;
    } else {
        return getHeight(n->left) - getHeight(n->right);
    }
}




void AVL::insert(std::string name, std::string id) {

    // check for duplicates
    if (search(id) != "unsuccessful") {
        std::cout << "unsuccessful" << std::endl;;
        return;
    }

    this->root = helperInsert(this->root, name, id);

    std::cout << "successful" << std::endl;
}

std::string AVL::search(std::string id) {
    return "unsuccessful";
}

std::vector<std::string> AVL::inorder() const {
    std::vector<std::string> inorder {"A", "B", "C"};

    return inorder;
}

bool AVL::remove(std::string id) {
    return true;
}
