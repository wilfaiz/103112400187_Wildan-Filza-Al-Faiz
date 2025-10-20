#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);
    P1 = alokasi(9);
    insertFirst(L, P1);
    P2 = alokasi(12);
    insertLast(L, P2);
    P3 = alokasi(8);
    insertLast(L, P3);
    P4 = alokasi(0);
    insertLast(L, P4);
    P5 = alokasi(2);
    insertLast(L, P5);
    printInfo(L);
    return 0;
}
