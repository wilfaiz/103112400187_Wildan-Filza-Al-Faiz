#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa& StackMHS) {
    return (StackMHS.Top == -1);
}

bool isFull(StackMahasiswa& StackMHS) {
    return (StackMHS.Top == MAX - 1);
}

void createStack(StackMahasiswa& StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa& StackMHS, Mahasiswa data) {
    if (!isFull(StackMHS)) {
        StackMHS.Top++;
        StackMHS.dataMahasiswa[StackMHS.Top] = data;
    } else {
        cout << "stack penuh" << endl;
    }
}

void Pop(StackMahasiswa& StackMHS) {
    if (!isEmpty(StackMHS)) {
        StackMHS.Top--;
    } else {
        cout << "stack kosong" << endl;
    }
}

void Update(StackMahasiswa& StackMHS, int posisi, Mahasiswa data) {
    if (posisi >= 0 && posisi <= StackMHS.Top) {
        StackMHS.dataMahasiswa[posisi] = data;
    } else {
        cout << "posisi tidak valid" << endl;
    }
}

void View(StackMahasiswa& StackMHS) {
    if (!isEmpty(StackMHS)) {
        for (int i = 0; i <= StackMHS.Top; i++) {
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << endl;
            cout << "NIM: " << StackMHS.dataMahasiswa[i].NIM << endl;
            cout << "Nilai Tugas: " << StackMHS.dataMahasiswa[i].NilaiTugas << endl;
            cout << "Nilai UTS: " << StackMHS.dataMahasiswa[i].NilaiUTS << endl;
            cout << "Nilai UAS: " << StackMHS.dataMahasiswa[i].NilaiUAS << endl;
            cout << "Nilai Akhir: " << StackMHS.dataMahasiswa[i].NilaiAkhir << endl;
            cout << "-----------------------------" << endl;
        }
    } else {
        cout << "stack kosong" << endl;
    }
}

void CalculateNilaiAkhir(Mahasiswa& data) {
    data.NilaiAkhir = (0.2 * data.NilaiTugas) + (0.4 * data.NilaiUTS) + (0.4 * data.NilaiUAS);
}

void SearchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    bool found = false;
    for (int i = 0; i <= StackMHS.Top; i++) {
        if (StackMHS.dataMahasiswa[i].NilaiAkhir >= NilaiAkhirMin && StackMHS.dataMahasiswa[i].NilaiAkhir <= NilaiAkhirMax) {
            found = true;
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", Nilai Akhir: " << StackMHS.dataMahasiswa[i].NilaiAkhir << endl;
        }
    }
    if (!found) {
        cout << "tidak ditemukan" << endl;
    }
}

void SearchMahasiswa(StackMahasiswa& StackMHS, float NilaiMin, float NilaiMax) {
    bool found = false;
    for (int i = 0; i <= StackMHS.Top; i++) {
        if (StackMHS.dataMahasiswa[i].NilaiTugas >= NilaiMin && StackMHS.dataMahasiswa[i].NilaiTugas <= NilaiMax) {
            found = true;
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << ", Nilai Tugas: " << StackMHS.dataMahasiswa[i].NilaiTugas << endl;
        }
    }
    if (!found) {
        cout << "tidak ditemukan" << endl;
    }
}