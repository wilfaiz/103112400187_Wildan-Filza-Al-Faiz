#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;     
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head) head = newNode; 
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; 
        temp->next = newNode;
    }
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current; 
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr; 
}

int main() {
    Node* head = nullptr;

    cout << "● LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << endl;

    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil1 << endl;
        cout << "Data node: " << hasil1->data << endl;
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << endl;

    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil2 << endl;
        cout << "Data node: " << hasil2->data << endl;
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}