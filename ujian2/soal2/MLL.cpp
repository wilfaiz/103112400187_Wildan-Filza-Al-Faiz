#include "MLL.h"

void createListParent(listParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

parentNode* alokasiNodeParent(string id, string nama) {
    parentNode* P = new parentNode;
    P->idGenre = id;
    P->namaGenre = nama;
    P->next = P->prev = NULL;
    P->firstChild = P->lastChild = NULL;
    return P;
}

childNode* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    childNode* C = new childNode;
    C->idFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = C->prev = NULL;
    return C;
}

void insertFirstParent(listParent &LP, parentNode* P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(parentNode* P, childNode* C) {
    if (P->firstChild == NULL) {
        P->firstChild = P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void printStrukturMLL(listParent LP) {
    parentNode* P = LP.first;
    int i = 1;

    while (P != NULL) {
        cout << "=== Parent " << i++ << " ===\n";
        cout << "ID Genre : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;

        childNode* C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << " - Child " << j++ << endl;
            cout << "   ID Film : " << C->idFilm << endl;
            cout << "   Judul Film : " << C->judulFilm << endl;
            cout << "   Durasi Film : " << C->durasiFilm << " menit\n";
            cout << "   Tahun Tayang : " << C->tahunTayang << endl;
            cout << "   Rating Film : " << C->ratingFilm << endl;
            cout << "============================\n";
            C = C->next;
        }
        P = P->next;
    }
}

void hapusListChild(parentNode* P) {
    childNode* C = P->firstChild;
    while (C != NULL) {
        childNode* temp = C;
        C = C->next;
        delete temp;
    }
    P->firstChild = P->lastChild = NULL;
}

void deleteAfterParent(listParent &LP, string idPrev) {
    parentNode* P = LP.first;

    while (P != NULL && P->idGenre != idPrev)
        P = P->next;

    if (P && P->next) {
        parentNode* del = P->next;
        hapusListChild(del);

        P->next = del->next;
        if (del->next)
            del->next->prev = P;
        else
            LP.last = P;

        delete del;
    }
}

void searchFilmByRatingRange(listParent LP, float min, float max) {
    parentNode* P = LP.first;
    int posParent = 1;

    while (P != NULL) {
        childNode* C = P->firstChild;
        int posChild = 1;

        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "Data Film ditemukan pada list child dari node parent Comedy pada posisi ke-1 !\n";
                cout << "--- Data Film (Child) ---\n";
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Posisi child : ke-" << posChild << endl;
                cout << "ID Film : " << C->idFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit\n";
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "============================\n";

                cout << "--- Data Genre (Parent) ---\n";
                cout << "ID Genre : " << P->idGenre << endl;
                cout << "Posisi parent : ke-" << posParent << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "============================\n";
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}