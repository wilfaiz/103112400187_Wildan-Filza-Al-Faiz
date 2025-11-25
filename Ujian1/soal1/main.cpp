#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(string nama) {
    Node* baru = new Node{nama, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
}

void deleteNama(string target) {
    if (head == nullptr) {
        cout << "List kosong\n";
        return;
    }

    if (head->nama == target) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->nama != target) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Nama tidak ditemukan\n";
    } else {
        Node* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
    }
}

void viewList() {
    Node* temp = head;
    if (!temp) {
        cout << "List kosong\n";
        return;
    }
    while (temp != nullptr) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hitungGenap() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->nama.length() % 2 == 0)
            count++;
        temp = temp->next;
    }

    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                deleteNama(nama);
                break;

            case 3:
                viewList();
                break;

            case 4:
                hitungGenap();
                break;

            case 0:
                break;

            default:
                cout << "Menu tidak valid\n";
        }

    } while (menu != 0);

    return 0;
}