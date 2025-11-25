#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    StackMahasiswa StackMHS;
    createStack(StackMHS);

    Mahasiswa mhs1 = {"Imey", "11111", 75.7, 82.1, 65.5, 0};
    Mahasiswa mhs2 = {"Haryo", "22222", 87.4, 88.9, 81.9, 0};
    Mahasiswa mhs3 = {"Jopan", "33333", 92.3, 88.8, 82.4, 0};
    Mahasiswa mhs4 = {"Kepin", "44444", 95.5, 85.5, 90.5, 0};
    Mahasiswa mhs5 = {"Rama", "55555", 77.7, 65.4, 79.9, 0};
    Mahasiswa mhs6 = {"Ale", "66666", 99.9, 93.6, 87.3, 0};

    CalculateNilaiAkhir(mhs1);
    CalculateNilaiAkhir(mhs2);
    CalculateNilaiAkhir(mhs3);
    CalculateNilaiAkhir(mhs4);
    CalculateNilaiAkhir(mhs5);
    CalculateNilaiAkhir(mhs6);

    Push(StackMHS, mhs1);
    Push(StackMHS, mhs2);
    Push(StackMHS, mhs3);
    Push(StackMHS, mhs4);
    Push(StackMHS, mhs5);
    Push(StackMHS, mhs6);

    cout << "menampilakn stack:" << endl;
    View(StackMHS);

    Pop(StackMHS);

    cout << "stack setelah Pop:" << endl;
    View(StackMHS);

    Mahasiswa mhs7 = {"putang", "77777", 99.9, 88.8, 77.7, 0};
    CalculateNilaiAkhir(mhs7);
    Update(StackMHS, 2, mhs7);

    cout << "Stack after Update:" << endl;
    View(StackMHS);

    cout << "Search for students with NilaiAkhir between 85.5 and 95.5:" << endl;
    SearchNilaiAkhir(StackMHS, 85.5, 95.5);

    return 0;
}
