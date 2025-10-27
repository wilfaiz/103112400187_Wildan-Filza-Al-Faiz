# <h1 align="center">Laporan Praktikum Modul 4 - Modul 4 Singly Linked List</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
Singly Linked List adalah struktur data dinamis yang terdiri dari node-node yang saling terhubung secara searah. Setiap node berisi dua bagian: data dan pointer yang menunjuk ke node berikutnya. Tidak seperti array, ukurannya fleksibel dan memudahkan penyisipan atau penghapusan elemen tanpa perlu menggeser data. Akses data dilakukan secara berurutan dari node awal (head) hingga akhir (null).
[1].

### A. Linked List dengan Pointer<br/>
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan.
### B. Singly Linked List<br/>
Singly linked list adalah struktur data berisi node-node yang saling terhubung satu arah lewat pointer next, di mana tiap node menyimpan data dan alamat node berikutnya.
### C. Delete<br/>
Adalah pengambilan atau penghapusan sebuah elemen pada awal list.
### D. Delete<br/>
Merupakan operasi dasar pada list yang digunakan untuk meng-update data yang ada di dalam list.
Dengan operasi update ini kita dapat meng-update data-data node yang ada di dalam list. Proses
update biasanya diawali dengan proses pencarian terhadap data yang akan di-update.
### E. Searching<br/>
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node
tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari
ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan
update akan lebih mudah.

## Guided 1

### 1. listbuah.cpp

```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
                 << ", Jumlah : " << nodeBantu->isidata.jumlah
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}


//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "
                 << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
Kode ini mengimplementasikan Single Linked List untuk data buah, dengan fitur lengkap: buat, tambah, hapus, tampilkan, dan ubah data.

### 2. listbuah.h

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H

#define Nil NULL
#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};

// ==== DEKLARASI / PROTOTYPE ====
bool isEmpty(linkedlist List);
void createList(linkedlist &List);

address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

void printList(linkedlist List);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// === Fungsi update data ===
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);

#endif
```
File ini berisi deklarasi struktur data dan fungsi untuk mengelola Linked List buah.

### 3. main.cpp

```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;


}
```
Program ini adalah contoh penggunaan linked list buah dari file listBuah.h dan listBuah.cpp.

## Guided 2

### 1.binary.cpp

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 10); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Kode ini membuat Linked List sederhana dan melakukan pencarian data dengan metode mirip binary search (meski bukan binary search murni karena linked list tidak bisa diakses langsung ke tengah).

### 2. linear.cpp
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Kode ini membuat linked list sederhana dan mencari data di dalamnya menggunakan linear search.

## Unguided 

### 1. Soal unguided 1

### main.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
};

void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    
    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    displayList(head);
    
    cout << "Mencari nilai: 40";
    
    Node* result = binarySearch(head, 40);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 40 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    cout << "Mencari nilai: 25";
    
    result = binarySearch(head, 25);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
    deleteList(head);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan5_Modul5/sssoal1.png)

penjelasan unguided 1 
Program ini membuat Linked List berisi angka berurutan, lalu melakukan pencarian data menggunakan metode mirip binary search, sambil menampilkan proses iterasi pencarian di layar.

### 2. Soal unguided 2

### main.cpp
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;     
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head) head = newNode; 
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next; 
        temp->next = newNode;
    }
}

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";
    while (current != nullptr) {
        cout << "Memeriksa node " << index << ": " << current->data;

        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!" << endl;
            return current; 
        } else {
            cout << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr; 
}

int main() {
    Node* head = nullptr;

    cout << "● LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << endl;

    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil1 << endl;
        cout << "Data node: " << hasil1->data << endl;
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari1 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << endl;

    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " DITEMUKAN pada linked list!" << endl;
        cout << "Alamat node: " << hasil2 << endl;
        cout << "Data node: " << hasil2->data << endl;
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << endl;
        else
            cout << "Node berikutnya: NULL" << endl;
    } else {
        cout << "\nHasil: Nilai " << cari2 << " TIDAK DITEMUKAN dalam linked list!" << endl;
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan5_Modul5/sssoal2.png)

penjelasan unguided 2
Program ini membuat linked list dan melakukan pencarian data menggunakan metode linear search, sambil menampilkan proses pencariannya.

## Kesimpulan
Singly Linked List memudahkan pengelolaan data secara dinamis dengan operasi seperti insert, delete, dan traversal. Struktur ini efisien karena tidak memerlukan pergeseran elemen saat menambah atau menghapus data, namun akses data harus dilakukan secara berurutan dari awal list.

## Referensi
[1] GeeksforGeeks. (2023). Linked List in C++ (Introduction). Diakses dari https://www.geeksforgeeks.org/linked-list-set-1-introduction/
<br>...
