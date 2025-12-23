#include "MLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    parentNode* G1 = alokasiNodeParent("G001", "Action");
    parentNode* G2 = alokasiNodeParent("G002", "Comedy");
    parentNode* G3 = alokasiNodeParent("G003", "Horror");
    parentNode* G4 = alokasiNodeParent("G004", "Romance");

    insertFirstParent(LP, G4);
    insertFirstParent(LP, G3);
    insertFirstParent(LP, G2);
    insertFirstParent(LP, G1);

    insertLastChild(G1, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    insertLastChild(G2, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(G2, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    insertLastChild(G3, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    insertLastChild(G4, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(G4, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);

    cout << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);

    cout << "\nDelete Parent G002\n";
    deleteAfterParent(LP, "G001");

    cout << endl;
    printStrukturMLL(LP);

    return 0;
}
