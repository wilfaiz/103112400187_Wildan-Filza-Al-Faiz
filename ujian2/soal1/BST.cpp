#include "BST.h"

BinarySearchTree::BinarySearchTree() {
    createTree();
}

void BinarySearchTree::createTree() {
    root = NULL;
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

Node* BinarySearchTree::insert(Node* curr, string nama, float berat, string tier) {
    if (curr == NULL) {
        Node* newNode = new Node;
        newNode->namaMember = nama;
        newNode->beratBadan = berat;
        newNode->tierMember = tier;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (berat < curr->beratBadan)
        curr->left = insert(curr->left, nama, berat, tier);
    else
        curr->right = insert(curr->right, nama, berat, tier);

    return curr;
}

void BinarySearchTree::insertNode(string nama, float berat, string tier) {
    root = insert(root, nama, berat, tier);
}

void BinarySearchTree::inOrder(Node* curr) {
    if (curr != NULL) {
        inOrder(curr->left);
        cout << curr->beratBadan << " - ";
        inOrder(curr->right);
    }
}

void BinarySearchTree::inOrder() {
    cout << "Traversal InOrder : ";
    inOrder(root);
    cout << endl;
}

Node* BinarySearchTree::mostLeft(Node* curr) {
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

void BinarySearchTree::mostLeft() {
    Node* node = mostLeft(root);
    if (node)
        cout << "Node MostLeft : " << node->beratBadan << endl;
}

Node* BinarySearchTree::mostRight(Node* curr) {
    while (curr && curr->right != NULL)
        curr = curr->right;
    return curr;
}

void BinarySearchTree::mostRight() {
    Node* node = mostRight(root);
    if (node)
        cout << "Node MostRight : " << node->beratBadan << endl;
}

Node* BinarySearchTree::search(Node* curr, float berat, Node*& parent) {
    parent = NULL;
    while (curr != NULL && curr->beratBadan != berat) {
        parent = curr;
        if (berat < curr->beratBadan)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

void BinarySearchTree::searchByBeratBadan(float berat) {
    Node* parent;
    Node* curr = search(root, berat, parent);

    if (!curr) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    cout << "Data ditemukan di dalam BST!\n";
    cout << "--------------------------------\n";
    cout << "Nama Member : " << curr->namaMember << endl;
    cout << "Berat Badan : " << curr->beratBadan << endl;
    cout << "Tier Member : " << curr->tierMember << endl;

    cout << "--------------------------------\n";
    if (parent) {
        cout << "Data Parent\n";
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;
    }

    cout << "--------------------------------\n";
    if (curr->left) {
        cout << "Data Child Kiri\n";
        cout << "Nama Member : " << curr->left->namaMember << endl;
        cout << "Berat Badan : " << curr->left->beratBadan << endl;
        cout << "Tier Member : " << curr->left->tierMember << endl;
    }

    cout << "--------------------------------\n";
    if (curr->right) {
        cout << "Data Child Kanan\n";
        cout << "Nama Member : " << curr->right->namaMember << endl;
        cout << "Berat Badan : " << curr->right->beratBadan << endl;
        cout << "Tier Member : " << curr->right->tierMember << endl;
    }
}