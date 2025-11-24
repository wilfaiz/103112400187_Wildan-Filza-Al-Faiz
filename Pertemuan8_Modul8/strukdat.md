# <h1 align="center">Laporan Praktikum Modul 8 - Modul 8 Doubly</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
Struktur data adalah metode untuk menyusun dan menyimpan data dalam komputer sehingga data dapat diakses, diproses, dan dimodifikasi dengan efisien. Dengan menggunakan struktur data yang tepat, pengelolaan informasi menjadi lebih teratur, proses pencarian atau perubahan data menjadi lebih cepat, dan kinerja program secara keseluruhan dapat meningkat. Struktur data juga membantu menggambarkan hubungan antar data, sehingga memudahkan pengembang dalam menangani kebutuhan aplikasi yang kompleks.
[1].

### A. Queue <br/>
Queue atau antrean adalah struktur data linier yang menyusun elemen secara berurutan dengan aturan First In, First Out (FIFO). Artinya, data yang masuk lebih dulu akan diproses atau dikeluarkan lebih dahulu. Struktur ini banyak digunakan dalam berbagai sistem karena mampu menangani aliran tugas secara teratur dan efisien. Dalam konteks komputasi, queue berperan penting dalam penjadwalan proses, pengelolaan pesan, sistem antrian tugas, hingga manajemen sumber daya yang membutuhkan urutan layanan yang teratur.


## Guided 1

### 1. main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```

### 2. queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

### 3. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
```
Program ini menggunakan struktur data Queue berbasis linked list, di mana setiap elemen disimpan dalam node yang berisi data dan pointer ke node berikutnya. Queue dikelola dengan dua pointer: head untuk elemen terdepan dan tail untuk elemen terakhir. Fungsi utama yang disediakan meliputi inisialisasi queue, pengecekan kondisi kosong, penambahan elemen (enqueue), dan penghapusan elemen (dequeue). Program juga menyediakan fitur tambahan seperti memperbarui nilai pada posisi tertentu, menampilkan seluruh isi antrian, serta mencari data dalam queue. Pada fungsi main, program menambahkan lima elemen awal, menampilkan isi queue, menghapus dua elemen terdepan, melakukan pembaruan nilai, dan mencari data tertentu.


## Guided 2

### 1. main.cpp

```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```

### 2. queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

### 3. queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
Program ini membuat Circular Queue berbasis array tetap. Queue menyimpan head, tail, dan count untuk mengatur posisi elemen. createQueue menginisialisasi, isEmpty/isFull memeriksa kondisi, enqueue menambah data dengan perputaran indeks, dan dequeue menghapus elemen dari depan. printInfo menampilkan isi queue. Fungsi main hanya mendemonstrasikan penambahan, penghapusan, dan perputaran elemen pada circular queue.

## Unguided 
### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file“queue.h”.Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;

}
bool isEmptyQueue(Queue Q){
    return (Q.head == 0);
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE);
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfo(Queue Q) {
    int H, T;

    // Konversi posisi HEAD & TAIL ke format tugas (0 → -1 untuk kosong)
    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   // HEAD selalu = 1 → ditampilkan sebagai 0
        T = Q.tail - 1;   // TAIL = jumlah elemen → ditampilkan indeks terakhir
    }

    // Cetak HEAD - TAIL
    cout << H << "  -  " << T << "  |  ";

    // Tampilkan isi queue
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### Output Unguided 1 :
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan8_Modul8/sssoal1.png)

penjelasan unguided 1 
Program ini membuat Queue berbasis array dengan head dan tail sebagai penanda posisi. Enqueue menambah data di belakang, sedangkan dequeue menghapus data depan dengan menggeser elemen ke kiri. Queue dianggap kosong ketika head dan tail = 0. Program mendemonstrasikan proses enqueue, dequeue, dan menampilkan isi queue setelah setiap operasi.


### 2. Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return Q.tail < Q.head;
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE - 1);
}
void enqueue(Queue &Q, infotype x){
   
   if(!isFullQueue(Q)){
    Q.tail++;
    Q.info[Q.tail] = x;
   }else{
        cout << "queue penuh \n";
   }
    
    
}
infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head++;

        // reset ketika kosong
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;
   
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### Output Unguided 2 :
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan8_Modul8/sssoal2.png)

penjelasan unguided 2
Program ini membuat queue linear berbasis array dengan dua indeks: head dan tail. Enqueue menambah data di posisi tail selama belum penuh, sedangkan dequeue mengambil elemen di head lalu menggeser indeks. Jika head melewati tail, queue di-reset menjadi kosong. Fungsi printInfo menampilkan posisi head–tail dan isi antrian. Program utama hanya mendemonstrasikan proses enqueue dan dequeue secara berurutan.


### 3. soal 3

### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```

### queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return(Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return((Q.tail + 1) % MAX_QUEUE == Q.head);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return temp;
}
void printInfo(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;
    }
    cout << endl;
}
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### Output Unguided 3 :
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan8_Modul8/sssoal3.png)

penjelasan unguided 3
Program ini mengimplementasikan Circular Queue dengan array dan indeks yang berputar menggunakan modulus. Queue dianggap kosong jika head dan tail = -1, dan penuh jika posisi tail berikutnya bertemu head. Enqueue menambah elemen dengan memajukan tail secara circular, sedangkan dequeue mengambil elemen di head dan memajukannya. Jika setelah dequeue head = tail, queue direset menjadi kosong. Fungsi printInfo menampilkan posisi indeks serta isi queue secara sirkular. Program utama hanya mendemonstrasikan beberapa operasi enqueue–dequeue untuk menunjukkan pergerakan indeks tanpa perlu menggeser data.


## Kesimpulan
Struktur data berperan penting dalam pemrograman karena membantu mengatur dan menyimpan data agar dapat diproses secara efisien. Salah satu yang paling banyak digunakan adalah queue, yang bekerja dengan prinsip FIFO, di mana elemen yang masuk pertama akan keluar lebih dulu. Queue digunakan dalam berbagai sistem seperti penjadwalan proses, pengelolaan antrean tugas, dan pemrosesan pesan. Terdapat beberapa variasi queue—misalnya Linear Queue, Circular Queue, Priority Queue, dan Deque—yang dapat dipilih sesuai kebutuhan aplikasi. Dengan memahami karakteristiknya, programmer dapat menentukan tipe antrean yang paling tepat untuk meningkatkan kinerja program.

[1]GeeksforGeeks — Queue Data Structure
Link: https://www.geeksforgeeks.org/queue-data-structure/
[2]Programiz — Queue Data Structure
Link: https://www.programiz.com/dsa/queue
<br>...
