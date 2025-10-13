# <h1 align="center">Laporan Praktikum Modul 3 - Modul 3 ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
Program menggunakan Abstract Data Type (ADT), yaitu pendekatan untuk memisahkan definisi tipe data dari operasi yang dapat dilakukan terhadapnya. Dalam hal ini, struct Mahasiswa berfungsi sebagai ADT yang menyimpan data NIM dan nilai. Fungsi inputMHS() dan rata2() adalah operasi atau primitif yang bekerja terhadap tipe data tersebut. Konsep ini mendukung modular programming, di mana data dan fungsinya dipisah menggunakan file header (.h) dan implementasi (.cpp) agar program lebih terstruktur, mudah dipahami, dan mudah dikembangkan.
[1].

### A. Abstract Data type(ADT)<br/>
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK.

## Guided 

### 1. 

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

//relasi dari fungsi inputMhs
void inputMHS(Mahasiswa &m) {
    cout << "input NIM:";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

//relasi dari fungsi rata2
float rata2(Mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2;

}
```
Fungsi inputMHS() digunakan untuk meminta input NIM dan dua nilai dari pengguna lalu menyimpannya ke dalam struct Mahasiswa melalui referensi. Fungsi rata2() menghitung dan mengembalikan nilai rata-rata dari nilai1 dan nilai2 yang ada di dalam struct tersebut.

### 2.

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

// definisi tipe (struct) 
struct Mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

// deklarasi primitif (fungsi)
void inputMHS(Mahasiswa &m);
float rata2(Mahasiswa m);

#endif
```
Header file ini mendefinisikan struct `Mahasiswa` untuk menyimpan NIM dan dua nilai. Selain itu, file ini juga mendeklarasikan dua fungsi, yaitu `inputMHS()` untuk mengisi data mahasiswa dan `rata2()` untuk menghitung rata-rata nilai. File ini berfungsi sebagai deklarasi agar bisa digunakan di file utama.


### 3.

```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    Mahasiswa mhs;

    inputMHS(mhs);
    cout << "Rata - rata nilai adalah : " << rata2(mhs) << endl;

    system("pause");
    return 0;
}
```
Program ini memanggil fungsi inputMHS() untuk mengisi data mahasiswa, lalu menghitung dan menampilkan rata-rata nilai menggunakan fungsi rata2(). Fungsi system("pause") digunakan untuk menahan layar agar tidak langsung tertutup setelah program selesai.

### 4.

```C++
#include <iostream>
using namespace std;

struct node{
    float data;
    node* next;

}; 

struct list{
    node* first;

};

void buatList(list &L){
    L.first = NULL;
    
}

node* buatElemen(float X){
    node* elm = new node;
    elm -> data = X;
    elm -> next = NULL;
    return elm;
}
void insertAscending( list &L, node* elm){
    if (L.first == NULL || elm -> data < L.first -> data ){
        elm -> next = L.first;
        L.first = elm;

    }
    else{
        node* before = L.first;
        node* after = L.first -> next;
        while(after != NULL && elm -> data > after -> data){
            before = after;
            after = after -> next;
        }
        elm -> next = after;
        before -> next = elm;
    }
}

void tampilList(list L){
    node* p = L.first;
    while(p != NULL){
        cout << p -> data << " -> ";
        p = p -> next;
    }
    cout << "NULL " << endl;
}

int main(){
    list L;
    buatList(L);

    node* satu = buatElemen(10.5);
    node* dua = buatElemen(12.0);
    node* tiga =  buatElemen(20.9);
    node* empat = buatElemen(25.1);

    satu -> next = dua;
    dua -> next = tiga;
    tiga -> next = empat;

    L.first = satu;
    
    cout << "isi list : " << endl;
    tampilList(L);

    float X;
    cout << "Masukan nilai : ";
    cin >>  X;

    node* elm = buatElemen(X);
    insertAscending(L, elm );
    cout << "List setelah ditambah : " << endl;
    tampilList(L);
    return 0;
}
```
Program ini membentuk linked list bertipe float, menginisialisasi list kosong, lalu menambahkan elemen baru secara ascending menggunakan fungsi insertAscending(). Beberapa node awal dibuat dan disambungkan manual, kemudian user memasukkan nilai baru yang akan disisipkan sesuai urutan. Terakhir, program menampilkan isi list sebelum dan sesudah penambahan elemen.

### 5.
```C++
#include <iostream>

using namespace std;

struct Mahasiswa{
    string nim;
    float nilai1;
    float nilai2;
};


//relasi dari fungsi inputMhs
void inputMHS(Mahasiswa &m) {
    cout << "input NIM:";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}
float rata2(Mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

int main(){
    Mahasiswa mhs;
    inputMHS(mhs);
    cout << "Rata-rata: " << rata2(mhs) << endl;
    return 0;

}
```
Program ini mendefinisikan struct Mahasiswa untuk menyimpan NIM dan dua nilai. Fungsi inputMHS() digunakan untuk mengisi data mahasiswa melalui input pengguna, sedangkan fungsi rata2() menghitung rata-rata dari dua nilai tersebut. Di fungsi main(), data dimasukkan lalu hasil rata-rata ditampilkan. Program ini secara ringkas menginput data mahasiswa dan menampilkan nilai rata-ratanya.

## Unguided 

### 1.  Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    string nama, nim;
    float uts, uas, tugas;
    int n;

    cout << "Jumlah mahasiswa (maks 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: "; cin >> nama;
        cout << "NIM : "; cin >> nim;
        cout << "UTS : "; cin >> uts;
        cout << "UAS : "; cin >> uas;
        cout << "Tugas: "; cin >> tugas;

        cout << "Nilai Akhir: " << hitungNilaiAkhir(uts, uas, tugas) << endl;
    }
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan3_Modul3/sssoal1.png)

penjelasan unguided 1 
Program ini **menghitung nilai akhir mahasiswa** dengan rumus:
**30% UTS + 40% UAS + 30% Tugas**, lalu **mengulang input sesuai jumlah mahasiswa** yang dimasukkan pengguna (maks 10).


### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

typedef struct {
    string namaPel;
    string kodePel;
} pelajaran;

pelajaran create_pelajaran(string nama, string kode);

void tampil_pelajaran(pelajaran p);

#endif
```

```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string nama, string kode) {
    pelajaran p;
    p.namaPel = nama;
    p.kodePel = kode;
    return p;
}

void tampil_pelajaran(pelajaran p) {
    cout << "Nama Pelajaran : " << p.namaPel << endl;
    cout << "Kode Pelajaran : " << p.kodePel << endl;
}
```

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel, kodePel;

    cout << "Masukkan nama pelajaran : ";
    getline(cin, namaPel);
    cout << "Masukkan kode pelajaran : ";
    cin >> kodePel;

    pelajaran p = create_pelajaran(namaPel, kodePel);

    cout << "\nData Pelajaran:\n";
    tampil_pelajaran(p);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan3_Modul3/sssoal2.png)

penjelasan unguided 2
Header pelajaran.h: Mendefinisikan struct pelajaran dan deklarasi fungsi.
File implementasi: Mengisi fungsi create_pelajaran dan tampil_pelajaran.
Main.cpp: Input data pelajaran, buat objek dengan create_pelajaran, lalu tampilkan dengan tampil_pelajaran.

### 3.  Buatlah program dengan ketentuan : 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer -fungsi/prosedur yang menampilkan isi sebuah array integer 2D fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu -fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer

```C++
#include <iostream>
using namespace std;

struct Pelajaran {
    string namaPel;
    string kodePel;
};

Pelajaran createPelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaPel = nama;
    p.kodePel = kode;
    return p;
}

void tampilPelajaran(Pelajaran p) {
    cout << "Nama Pelajaran : " << p.namaPel << endl;
    cout << "Kode Pelajaran : " << p.kodePel << endl;
}

int main() {
    const int MAX = 5;
    Pelajaran daftarPelajaran[MAX];
    Pelajaran *ptr;
    int n;

    cout << "Masukkan jumlah pelajaran (maks 5): ";
    cin >> n;
    cin.ignore();

    if (n > MAX) {
        cout << "Jumlah pelajaran melebihi batas!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string nama, kode;
        cout << "\nPelajaran ke-" << i + 1 << endl;
        cout << "Masukkan nama pelajaran : ";
        getline(cin, nama);
        cout << "Masukkan kode pelajaran : ";
        getline(cin, kode);

        daftarPelajaran[i] = createPelajaran(nama, kode);
    }

    cout << "\n=== DATA SEMUA PELAJARAN ===\n";
    ptr = daftarPelajaran;
    for (int i = 0; i < n; i++) {
        cout << "Data Pelajaran ke-" << i + 1 << endl;
        tampilPelajaran(*(ptr + i));
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan3_Modul3/sssoal3.png)

penjelasan unguided 3
Program ini membuat struct **Pelajaran**, mengisi data pelajaran berdasarkan input pengguna (maksimal 5), menyimpannya dalam array, lalu menampilkan semua data menggunakan **pointer** ke array tersebut.


## Kesimpulan
ADT menekankan pemodelan data dari sisi operasi dan konsep, bukan detail implementasi, sehingga struktur data lebih terorganisir dan mudah dikelola.

## Referensi
[1] Anita Sindar, R. M. S. (2019). Struktur Data dan Algoritma dengan C++. CV. AA. Rizky.
(Sudah Anda pakai di [1] – tetap boleh dicantumkan sebagai dasar teori ADT & struct)
<br>...
