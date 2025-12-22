# <h1 align="center">Laporan Praktikum</h1>
<p align="center">Wildan Filza Al Faiz - 103112400187</p>

## Dasar Teori
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh
sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda
dan Common Lab merupakan node (vertec). Jalan yang menghubungkan tempat Kost dan Common
Lab merupakan garis penghubung antara keduanya (edge).

### A. Representasi Graph<br/>
Pada dasarnya representasi dari graph berarah sama dengan graph tak-berarah. Perbedaannya
apabila graph tak-berarah terdapat node A dan node B yang terhubung, secara otomatis terbentuk
panah bolak balik dari A ke B dan B ke A. Pada Graph berarah node A terhubung dengan node B, belum
tentu node B terhubung dengan node A.

### B. Representasi Graph<br/>
Diberikan urutan partial dari elemen suatu himpunan, dikehendaki agar elemen yang terurut parsial
tersebut mempunyai keterurutan linear. Contoh dari keterurutan parsial banyak dijumpai dalam
kehidupan sehari-hari, misalnya:
1. Dalam suatu kurikulum, suatu mata pelajaran mempunyai prerequisite mata pelajaran lain.
Urutan linear adalah urutan untuk seluruh mata pelajaran dalamkurikulum
2. Dalam suatu proyek, suatu pekerjaan harus dikerjakan lebih dulu dari pekerjaan lain misalnya
membuat fondasi harus sebelum dinding, membuat dinding harus sebelum pintu. Namun
pintu dapat dikerjakan bersamaan dengan jendela, dsb
3. Dalam sebuah program Pascal, pemanggilan prosedur harus sedemikian rupa, sehingga
peletakan prosedur pada teks program harus seuai dengan urutan (partial) pemanggilan.
Dalam pembuatan tabel pada basis data, tabel yang di-refer oleh tabel lain harus dideklarasikan
terlebih dulu. Jika suatu aplikasi terdiri dari banyak tabel, maka urutan pembuatan tabel harus sesuai
dengan definisinya

## Guided 1

### 1. graph_edge.cpp

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd   = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // insert first
        pStart->firstEdge = newEdge;
    }
}
```

### 2. graph_init.cpp

```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X); 
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

```

### 3. graph_print.cpp

```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;  
        }
        cout << endl;
        P = P->next;
    }
}
```

### 4. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

// prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
adrNode findNode(Graph G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

```
### 5. main.cpp

```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph G;   
    createGraph(G);

    // menambahkan Node
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // menghubungkan Node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}

```
Kode program C++ tersebut berfungsi untuk membuat dan menampilkan sebuah graph sederhana. Program dimulai dengan mendeklarasikan sebuah variabel graph `G` lalu menginisialisasinya menggunakan fungsi `createGraph`. Setelah itu, program menambahkan empat node ke dalam graph, yaitu node A, B, C, dan D, menggunakan fungsi `insertNode`. Selanjutnya, node-node tersebut dihubungkan satu sama lain melalui fungsi `connectNode`, di mana A terhubung ke B dan C, serta B dan C masing-masing terhubung ke D. Setelah seluruh node dan hubungan terbentuk, program mencetak isi graph ke layar menggunakan fungsi `printGraph`, sehingga struktur graph yang telah dibuat dapat dilihat.

## Unguided 
### 1. Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.
### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);

    ConnectNode(C, F);
    ConnectNode(C, Gg);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List:\n";
    PrintInfoGraph(G);

    cout << "\nDFS: ";
    PrintDFS(G, A);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "\nBFS: ";
    PrintBFS(G, A);

    return 0;
}
```

### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef int integer;

typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    integer visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
```
### graph.cpp
```C++
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

void PrintBFS(Graph &G, adrNode N) {
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```

### Output Unguided 1 :
##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/wilfaiz/103112400187_Wildan-Filza-Al-Faiz/blob/main/Pertemuan14_Modul14/ssoutput.png)

penjelasan unguided 1 
Program ini membuat sebuah graph dengan node A sampai H, menghubungkannya sesuai struktur yang ditentukan, lalu menampilkan graph dalam bentuk adjacency list. Setelah itu, program melakukan penelusuran DFS dan BFS mulai dari node A, dengan me-reset status kunjungan node di antara kedua proses tersebut.

## Kesimpulan
Praktikum ini menunjukkan bahwa struktur data Graph dapat diimplementasikan menggunakan ADT dengan representasi adjacency list serta mampu melakukan penelusuran DFS dan BFS secara efektif untuk menjelajahi seluruh node dalam graph.

[1] GeeksforGeeks — Graph Data Structure
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/

[2] GeeksforGeeks — Depth First Search (DFS)
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

[3] GeeksforGeeks — Breadth First Search (BFS)
https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
<br>
