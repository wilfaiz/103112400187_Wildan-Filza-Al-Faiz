# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. Operator Aritmatika<br/>
operator aritmatika adalah simbol atau tanda dalam pemrograman yang digunakan untuk melakukan operasi perhitungan matematika pada data berupa angka

### B. Perulangan dan percabangan<br/>
Perulangan (looping) adalah proses menjalankan sebuah blok kode secara berulang-ulang selama kondisi tertentu masih terpenuhi. Dalam C++ (dan banyak bahasa pemrograman lain), perulangan digunakan supaya program tidak perlu menulis kode yang sama berkali-kali. Percabangan adalah struktur kendali dalam pemrograman yang digunakan untuk menentukan alur program berdasarkan kondisi tertentu. Dengan percabangan, program bisa mengambil keputusan berbeda sesuai input atau situasi

## Guided 

### 1. Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl ;
    cout << "pengurangan :" << angka1 - angka2 << endl ;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" <<  angka1 / angka2 << endl;
}
```
menjelaskan operator aritmatika

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1,angka2 ;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

if (angka1 < angka2){
    cout << angka1 << "kurang dari " << angka2 << endl;
}else {
    cout << angka1 << "lebih dari" << angka2 << endl;
}

if (angka1 == angka2) {
    cout << angka1 << "sama dengan" << angka2 << endl;
}else if (angka1 != angka2) {
    cout << "angka berbeda" << endl;
}

int pilihan ;
cout << "menu" << endl;
cout << "1. pengjumlahan" << endl;
cout << "2. pengurangan " << endl;
cout << "masukan pilihan: " << endl;
cin >> pilihan ;

switch (pilihan) {
    case 1 :
    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << endl;
    break;
    case 2 :
    cout << "pengurangan : " << angka1 + angka2 << endl;
    cout << endl;
    break;
    default :
    cout << "pilihan salah" << endl;
}
    return 0;
}
```
program ini menjelaskan contoh percabangan (if, if-else) dan switch-case serta operasi aritmatika sederhana (penjumlahan/pengurangan)

### 3. Perulangan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukan angka 1 :";
    cin >> angka1;

    for (int i = 0; i < angka1; i++) {
        cout << i << "-"; 
    }
    cout << endl;
    int j = 10;
    while (j > angka1){
        cout << j << "-";
        j--;
    }
    cout << endl;
    int k = 10;
    do {
        cout << k << "-";
    } while (k < angka1);

    return 0 ;
}
```
program ini mencontohkan tiga jenis perulangan (for, while, do while) dengan pola cetak angka berbeda.

## Unguided 

### 1.  Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float angka1, angka2;
    cout << "masukakn angka pertama : ";
    cin >> angka1;
    cout << "masukan angka kedua : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan1_Modul1/sssoal1.png)

penjelasan unguided 1 
1.Input → Program meminta pengguna memasukkan dua buah angka (angka1 dan angka2).

2.Proses → Program melakukan empat operasi aritmatika dasar: penjumlahan, pengurangan, perkalian, dan pembagian.

3.Output → Hasil dari setiap operasi ditampilkan ke layar.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukan angka (0-100) : " ; 
    cin >> angka;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) cout << "0 : nol ";
    else if (angka == 10 ) cout << "10 : sepuluh ";
    else if (angka == 11) cout << "11 : sebelas ";
    else if (angka < 10) cout << angka << " : " << satuan[angka] << " ";
    else if (angka < 20) cout << angka << " : " << satuan[angka - 10] << " belas ";
    else if (angka < 100){
        int puluhan = angka / 10;
        int sisa = angka % 10;
        cout << angka << " : " << satuan[puluhan] << " puluh ";
        if (sisa != 0) cout << satuan[sisa] << " ";
    }
    else if (angka == 100) cout << "100 : seratus ";
    else cout << "Angka di luar jangkauan" << endl;
return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan1_Modul1/sssoal2.png)

penjelasan unguided 2
Input → Pengguna diminta memasukkan sebuah angka antara 0 sampai 100
Array satuan → Menyimpan kata untuk angka 0 sampai 9 (nol sampai sembilan)
Proses pengecekan (if-else):
Jika 0, ditampilkan "nol"
Jika 10, ditampilkan "sepuluh"
Jika 11, ditampilkan "sebelas"
Jika <10, langsung ambil dari array satuan
Jika <20, ditampilkan dengan format "... belas"
Jika <100, angka dipisahkan jadi puluhan dan satuan, lalu ditampilkan misalnya "tiga puluh lima"
Jika 100, ditampilkan "seratus"
Jika di luar 0–100, muncul pesan "Angka di luar jangkauan"
Output → Menampilkan angka yang dimasukkan beserta bentuk teksnya

### 3.  Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;

    cout << "Output:\n";
    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        if (i > 0) {
            for (int j = i; j >= 1; j--) cout << j << " ";
            cout << "* ";
            for (int j = 1; j <= i; j++) cout << j << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan1_Modul1/sssoal2.png)

penjelasan unguided 3
Input → Pengguna memasukkan sebuah angka n.
Contoh: n = 4
Perulangan for (int i = n; i >= 0; i--)
Perulangan ini berjalan dari n turun ke 0
Setiap i merepresentasikan baris ke berapa yang sedang dicetak
Spasi Awal (for (int s = 0; s < n - i; s++ ))
Digunakan untuk menggeser pola ke kanan agar membentuk segitiga simetris
Jika i > 0:
Cetak angka menurun dari i sampai 1 → for (int j = i; j >= 1; j--)
Cetak bintang * di tengah
Cetak angka menaik dari 1 sampai i → for (int j = 1; j <= i; j++)
Jika i == 0:
Hanya mencetak sebuah bintang *
Output → Pola segitiga simetris dengan bintang di tengah

## Kesimpulan
Soal 1 (Operasi Aritmatika)
Program digunakan untuk menghitung penjumlahan, pengurangan, perkalian, dan pembagian dari dua angka yang dimasukkan pengguna
Soal 2 (Konversi Angka ke Teks)
Program mengubah angka antara 0–100 menjadi bentuk kata dalam bahasa Indonesia, misalnya 15 → lima belas, 42 → empat puluh dua
Soal 3 (Pola Angka & Bintang)
Program mencetak pola berbentuk segitiga dengan kombinasi angka menurun–menaik yang dipisahkan oleh simbol *

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
