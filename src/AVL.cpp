//
// Created by john4 on 9/12/2025.
//

#include "AVL.h"
#include <iostream>


// Rotations
// LL case
AVL::Node * AVL::rotateRight(Node* n) {

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
AVL::Node * AVL::rotateLeft(Node* n) {

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
AVL::Node * AVL::rotateLeftRight(Node* n) {

    if (n == nullptr) {
        return n;
    }

    n->left = rotateLeft(n->left);
    return rotateRight(n);
}

// RL case
AVL::Node * AVL::rotateRightLeft(Node* n) {

    if (n == nullptr) {
        return n;
    }

    n->right = rotateRight(n->right);
    return rotateLeft(n);
}


// Helper functions for main methods
void AVL::setHeight(Node* n) {
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

int AVL::getHeight(Node* n) {
    if (n == nullptr) {
        return 0;
    } else {
        return n->height;
    }

}

int AVL::getBalance(Node* n) {
    if (n == nullptr) {
        return 0;
    } else {
        return getHeight(n->left) - getHeight(n->right);
    }
}

AVL::Node * AVL::leftmost(Node* n) {
    if (n == nullptr) {
        return nullptr;
    }

    while (n->left != nullptr) {
        n = n->left;
    }

    return n;
}

void AVL::inorderH(Node* n, std::vector<std::string>& v) const {
    if (n == nullptr) {
        return;
    }

    inorderH(n->left, v);
    v.push_back(n->data.getName());
    inorderH(n->right, v);
}

void AVL::preorderH(Node* n, std::vector<std::string>& v) const {
    if (n == nullptr) {
        return;
    }

    v.push_back(n->data.getName());
    preorderH(n->left, v);
    preorderH(n->right, v);
}

void AVL::postorderH(Node* n, std::vector<std::string>& v) const {
    if (n == nullptr) {
        return;
    }

    postorderH(n->left, v);
    postorderH(n->right, v);
    v.push_back(n->data.getName());
}

void AVL::printH(const std::vector<std::string>& v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}


void AVL::destroy(Node* n) {
    if (n != nullptr) {
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
}


// INSERT
AVL::Node* AVL::helperInsert(Node* helpRoot, const std::string& name, const std::string& id) {

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

void AVL::insert(const std::string& name, const std::string& id) {

    // check for duplicates
    if (helperSearch(id) != nullptr) {
        std::cout << "unsuccessful" << std::endl;;
        return;
    }

    this->root = helperInsert(this->root, name, id);

    std::cout << "successful" << std::endl;
}


// REMOVE
AVL::Node * AVL::helperRemove(Node* helpRoot, const std::string &id) {
    if (helpRoot == nullptr) {
        return nullptr;
    }

    if (id < helpRoot->data.getId()) {
        helpRoot->left = helperRemove(helpRoot->left, id);
    } else if (id > helpRoot->data.getId()) {
        helpRoot->right = helperRemove(helpRoot->right, id);
    } else {
        // node to remove found
        // 4 cases: 0, 1l, 1r, or 2 child

        // 0 childs
        if (helpRoot->left == nullptr && helpRoot->right == nullptr) {
            delete helpRoot;
            return nullptr;
        }

        // 1 right child
        if (helpRoot->left == nullptr && helpRoot->right != nullptr) {
            Node* replace =  helpRoot->right;
            delete helpRoot;
            return replace;
        }

        // 1 left child
        if (helpRoot->left != nullptr && helpRoot->right == nullptr) {
            Node* replace =  helpRoot->left;
            delete helpRoot;
            return replace;
        }

        // 2 children -> replace with inorder successor
        Node* replace = leftmost(helpRoot->right);
        helpRoot->data = replace->data;
        helpRoot->right = helperRemove(helpRoot->right, replace->data.getId());

    }

    // (optional rotation)
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

    return helpRoot;
}

void AVL::remove(const std::string& id) {
    if (helperSearch(id) == nullptr ) {
        std::cout << "unsuccessful" << std::endl;;
        return;
    }

    this->root = helperRemove(root, id);

    std::cout << "successful" << std::endl;
}


// Search by ID
AVL::Node * AVL::helperSearch(const std::string &id) const {
    Node* cur = root;

    while (cur != nullptr) {
        if (id < cur->data.getId()) {
            cur = cur->left;
        } else if (id > cur->data.getId()) {
            cur = cur->right;
        } else {
            // found
            return cur;
        }
    }

    return nullptr;
}

void AVL::searchID(const std::string& id) {
    Node* n = helperSearch(id);

    if (n != nullptr) {
        std::cout << n->data.getName() << std::endl;
    } else {
        std::cout << "unsuccessful" << std::endl;
    }
}


void AVL::printInorder() const {
    printH(inorder());
}

void AVL::printPreorder() const {
    printH(preorder());
}

void AVL::printPostorder() const {
    printH(postorder());
}

std::vector<std::string> AVL::inorder() const {
    std::vector<std::string> names;
    inorderH(root, names);
    return names;
}

std::vector<std::string> AVL::preorder() const {
    std::vector<std::string> names;
    preorderH(root, names);
    return names;
}

std::vector<std::string> AVL::postorder() const {
    std::vector<std::string> names;
    postorderH(root, names);
    return names;
}


// destructor
AVL::~AVL() {
    destroy(root);
}

