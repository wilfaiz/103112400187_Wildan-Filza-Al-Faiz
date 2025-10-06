# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
Menurut Suryanto (2023), C++ merupakan salah satu bahasa pemrograman yang banyak digunakan dalam dunia akademik maupun praktis karena mendukung pemrograman prosedural maupun berorientasi objek. Dalam penggunaannya, terdapat berbagai konsep dasar yang penting dipahami, di antaranya array dan pointer. Array adalah struktur data yang digunakan untuk menyimpan sekumpulan data dengan tipe yang sama dalam satu variabel. Setiap elemen array dapat diakses melalui indeks yang dimulai dari 0 hingga ukuran array dikurangi satu. Array mempermudah penyimpanan dan pengolahan banyak data dengan tipe yang sama, sehingga mereka efektif dalam penggunaan memori dan pemanggilan data.Pointer adalah variabel unik yang menyimpan alamat memori untuk variabel lain. Dengan menggunakan alamat yang ditunjuk, program dapat mengakses dan mengubah data secara tidak langsung. Karena nama array sebenarnya mewakili alamat elemen pertama dalam array, pointer sangat penting untuk mengelola array. Oleh karena itu, elemen dapat diakses melalui aritmatika pointer dan indeks, yang keduanya memberikan hasil yang sama.[1].

### A. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama.
Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen.
### B. Pointer<br/>
variabel khusus yang menyimpan alamat memori dari variabel lain, bukan nilai data secara langsung. Dalam bahasa pemrograman seperti C atau C++, setiap variabel disimpan di suatu lokasi di memori komputer, dan lokasi itu memiliki alamat. Nah, pointer berfungsi untuk menunjuk ke alamat tersebut.
### B. Fungsi<br/>
Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan:
1. Program menjadi terstruktur, sehingga mudah dipahami dan mudah dikembangkan. Program
dibagi menjadi beberapa modul yang kecil.
2. Dapat mengurangi pengulangan kode (duplikasi kode) sehingga menghemat ukuran program.
Pada umumnya fungsi memerlukan masukan yang dinamakan sebagai parameter. Masukan ini
selanjutnya diolah oleh fungsi. Hasil akhir fungsi berupa sebuah nilai (nilai balik fungsi).
### B. Prosedur<br/>
Dalam bahasa pemrograman C++, prosedur adalah istilah yang sering digunakan untuk merujuk pada
fungsi yang tidak mengembalikan nilai. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void.
Fungsi-fungsi ini melakukan tugas tertentu tetapi tidak memberikan nilai balik (return value) kepada
pemanggilnya. Sebaliknya, fungsi yang mengembalikan nilai, seperti int atau double, memberikan
hasil yang dapat digunakan lebih lanjut dalam program.

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; 1 <5; i++) {
        cin >> arr[1];
    }
    int j = 0;
    while(j , 5){
        cout << "isi indeks ke-" << j << " : " <<arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini digunakan untuk menginput dan menampilkan isi array dengan menggunakan loop for untuk input dan loop while untuk output

### 2. Array2D

```C++
#include <iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] ={
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] ={
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // penjumlahan matrik 2x2
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanhasil(arrC);

    cout << endl;

    // perkalian matrik 2x2
    for (int i = 0; i < 2; i++){ // perulangan baris arrA
        for (int j = 0; j < 2; j++){ // perulangan kolom 
            for (int k = 0; k < 2; k++){ // perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanhasil(arrD);
    return 0;
}
```
Program di atas berfungsi untuk menampilkan hasil penjumlahan dan perkalian dua matriks berukuran 2x2

### 3. array N pointer

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int * ptr = arr;

    for(int i = 0; i < 5; ++i){
        cout<<"elemen array ke-" <<i+1<<"menggunakan pointer" << *(ptr + 1) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen ke-" << "menggunakan indeks" << arr[i] << endl; 
    }
    return 0;
}
```
Program di atas bertujuan untuk menampilkan isi array dengan dua cara: Menggunakan pointer, dan Menggunakan indeks array biasa

### 4. Call by pointer

```C++
#include <iostream>
using namespace std;

void ubahNilai(int *ptr){
    *ptr = 20;
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah: " << x << endl;

    ubahNilai(&x);
    cout << "nilai setelah diubah: " << x << endl;

    return 0;
}
```
Program di atas berfungsi untuk menunjukkan bagaimana pointer dapat digunakan untuk mengubah nilai variabel dari dalam fungsi di C++.

### 5. call by reference

```C++
#include <iostream>
using namespace std;

void ubahNilai(int& ref){
    ref = 20;
    }
    int main(){
        int x = 10;
        cout << "nilai sebelum diubah: " << x << endl;

        ubahNilai(x);
        cout << "nilai setelah diubah: " << x << endl;
        
    return 0;
}
```
Program di atas berfungsi untuk menunjukkan cara mengubah nilai variabel melalui reference (referensi) dalam C++

### 5. function peocedure

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "Total Jumlah : " << totalJumlah << endl;

    int totalkali = 1;
    for (int i = 0; i < ukuran; i++){
        totalkali *= arr[i];
    }
    cout << "Total Perkalian : " << totalkali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "Masukan angka ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program di atas digunakan untuk menunjukkan cara mengubah nilai variabel melalui reference (referensi) dalam C++

## Unguided 

### 1.  Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dankaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case

```C++
#include <iostream>
using namespace std;

const int N = 3;

void tampilMatriks(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurangMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int B[N][N] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int C[N][N];
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---\n";
        cout << "1. Penjumlahan matriks\n";
        cout << "2. Pengurangan matriks\n";
        cout << "3. Perkalian matriks\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            jumlahMatriks(A, B, C);
            cout << "\nHasil Penjumlahan Matriks:\n";
            tampilMatriks(C);
            break;
        case 2:
            kurangMatriks(A, B, C);
            cout << "\nHasil Pengurangan Matriks:\n";
            tampilMatriks(C);
            break;
        case 3:
            kaliMatriks(A, B, C);
            cout << "\nHasil Perkalian Matriks:\n";
            tampilMatriks(C);
            break;
        case 4:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan2_Modul2/sssoal1.png)

penjelasan unguided 1 
Program di atas adalah program operasi matriks 3×3 menggunakan C++ yang menyediakan menu untuk penjumlahan, pengurangan, dan perkalian matriks.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut: 1. Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0).2. Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar. 3. Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 4. Cetak nilai luas ke layar. 5. Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar. 6. Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.

```C++
#include <iostream>
using namespace std;

int main() {
    int P = 10;
    int L = 5;
    int luas = 0;

    int *ptrPanjang = &P;
    int *ptrLebar = &L;

    cout << "Nilai awal: " << endl;
    
    cout << "Panjang : " << P << endl;
    cout << "Lebar : " << L << endl;

    luas = (*ptrPanjang) * (*ptrLebar);

    cout << "Hasil Perhitungan:" << endl;

    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang = " << 2 * ((*ptrPanjang) + (*ptrLebar)) << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    
    cout << "Nilai Setelah Dirubah Melalui Pointer:" << endl;

    cout << "Panjang Baru : " << P << endl;
    cout << "Lebar Baru : " << L << endl;
    cout << "Luas Baru : " << luas << endl;
    cout << "Keliling Baru = " << 2 * ((*ptrPanjang) + (*ptrLebar)) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan2_Modul2/sssoal2.png)

penjelasan unguided 2
Program di atas menggunakan pointer untuk menghitung dan memanipulasi nilai panjang (P) dan lebar (L) dari sebuah persegi panjang.

## Kesimpulan
Pada praktikum modul 1 ini, dipelajari dasar-dasar pemrograman C++ yang mencakup penggunaan operator aritmatika, struktur percabangan (if-else dan switch-case), serta perulangan (for, while, dan do-while). Selain itu, terdapat juga latihan unguided yang memberikan pengalaman praktis, seperti mengimplementasikan operasi aritmatika dengan tipe data float, mengonversi angka menjadi bentuk kata, serta membuat pola yang memadukan angka dan simbol.

## Referensi
[1] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY. melalui [text](https://books.google.co.id/books?hl=id&lr=&id=GP_ADwAAQBAJ&oi=fnd&pg=PA23&dq=array+dan+pointer+c%2B%2B&ots=86j8UqYNhQ&sig=je7tw6LColi81EUfcykxZf1sM2A&redir_esc=y#v=onepage&q=array%20dan%20pointer%20c%2B%2B&f=false)
<br>...
