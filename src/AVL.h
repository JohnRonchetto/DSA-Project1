

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
    void setHeight(Node* n);           // 1 based index
    static int getHeight(Node* n);
    static int getBalance(Node* n);    // (left - right) height
    static Node* leftmost(Node* n);    // for inorder successor

    // helpers for traversal
    void inorderH(Node* n, std::vector<std::string>& v)   const;
    void preorderH(Node* n, std::vector<std::string>& v)  const;
    void postorderH(Node* n, std::vector<std::string>& v) const;
    // print helper
    static void printH(const std::vector<std::string>& v);


    void destroy(Node* n);             // recursive function for destructor



public:

    AVL() : root(nullptr) {}
    ~AVL();

    // Inserts and prints successful/unsuccessful
    void insert(const std::string& name, const std::string& id);
    // removes and prints successful/unsuccessful
    void remove(const std::string& id);
    // search by ID and prints successful/unsuccessful
    void searchID(const std::string& id);

    // main print methods
    void printInorder()  const;
    void printPreorder() const;
    void printPostorder() const;

    // traversals for testing
    std::vector<std::string> inorder()   const;
    std::vector<std::string> preorder()  const;
    std::vector<std::string> postorder() const;

    void searchName(const std::string& name);
    void printLevelCount() const;
    void removeInorder(int N);



};


#endif //PROJECT1_AVL_H
