#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;


struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa& StackMHS);
bool isFull(StackMahasiswa& StackMHS);
void createStack(StackMahasiswa& StackMHS);
void Push(StackMahasiswa& StackMHS, Mahasiswa data);
void Pop(StackMahasiswa& StackMHS);
void Update(StackMahasiswa& StackMHS, int posisi, Mahasiswa data);
void View(StackMahasiswa& StackMHS);
void SearchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);
void SearchMahasiswa(StackMahasiswa& StackMHS, float NilaiMin, float NilaiMax);
void CalculateNilaiAkhir(Mahasiswa& mhs);


#endif