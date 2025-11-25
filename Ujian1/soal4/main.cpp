#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    QueueEkspedisi queue;
    createQueue(queue);

    Paket p1 = {"123456", "Haryo", 14, "Semeru"};
    Paket p2 = {"234567", "Ale", 10, "Fortnite"};
    Paket p3 = {"345678", "Bedut", 7, "Natal"};
    Paket p4 = {"456789", "Furi", 16, "Lulu"};
    Paket p5 = {"567890", "Natan", 6, "Idan"};

    int choice;
    do {
        cout << "====ngebut Ekspres====\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "Pilihan Kamu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue(queue, p1);
                enqueue(queue, p2);
                enqueue(queue, p3);
                enqueue(queue, p4);
                enqueue(queue, p5);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                viewQueue(queue);
                break;

            case 4:
                cout << "Total Biaya Pengiriman: Rp " << totalBiayaPengiriman(queue) << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}