#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertAkhir(int nilai) {
    Node* baru = new Node{nilai, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteAkhir() {
    if (tail == nullptr) {
        cout << "List kosong\n";
        return;
    }

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void viewDepan() {
    Node* temp = head;
    if (!temp) {
        cout << "List kosong\n";
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main() {
    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view depan, 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertAkhir(nilai);
                break;

            case 2:
                deleteAkhir();
                break;

            case 3:
                viewDepan();
                break;

            case 4:
                reverseList();
                cout << "List setelah di-reverse: ";
                viewDepan();
                break;

            case 0:
                break;

            default:
                cout << "Menu tidak valid\n";
        }

    } while (menu != 0);

    return 0;
}
