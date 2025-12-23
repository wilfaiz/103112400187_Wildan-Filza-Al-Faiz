#include "BST.h"

int main() {
    BinarySearchTree bst;

    bst.insertNode("Rizkina Azizah", 60, "Basic");
    bst.insertNode("Hakan Ismail", 50, "Bronze");
    bst.insertNode("Olivia Saevali", 65, "Silver");
    bst.insertNode("Felix Pedrosa", 47, "Gold");
    bst.insertNode("Gamel Al Ghifari", 56, "Platinum");
    bst.insertNode("Hanif Al Faiz", 70, "Basic");
    bst.insertNode("Mutiara Fauziah", 52, "Bronze");
    bst.insertNode("Davi Ilyas", 68, "Silver");
    bst.insertNode("Abbad Mubarak", 81, "Gold");

    cout << endl;
    bst.inOrder();

    cout << endl;
    bst.mostLeft();
    bst.mostRight();

    cout << endl;
    bst.searchByBeratBadan(70);

    return 0;
}