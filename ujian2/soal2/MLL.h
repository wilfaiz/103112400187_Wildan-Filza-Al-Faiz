#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct childNode {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    childNode* next;
    childNode* prev;
};

struct parentNode {
    string idGenre;
    string namaGenre;
    parentNode* next;
    parentNode* prev;
    childNode* firstChild;
    childNode* lastChild;
};

struct listParent {
    parentNode* first;
    parentNode* last;
};

void createListParent(listParent &LP);
parentNode* alokasiNodeParent(string id, string nama);
childNode* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void insertFirstParent(listParent &LP, parentNode* P);
void insertLastChild(parentNode* P, childNode* C);

void printStrukturMLL(listParent LP);
void hapusListChild(parentNode* P);
void deleteAfterParent(listParent &LP, string idPrev);

void searchFilmByRatingRange(listParent LP, float min, float max);

#endif
