#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* curr, string nama, float berat, string tier);
    void inOrder(Node* curr);
    Node* mostLeft(Node* curr);
    Node* mostRight(Node* curr);
    Node* search(Node* curr, float berat, Node*& parent);

public:
    BinarySearchTree();

    void createTree();
    bool isEmpty();
    void insertNode(string nama, float berat, string tier);
    void inOrder();
    void mostLeft();
    void mostRight();
    void searchByBeratBadan(float berat);
};

#endif