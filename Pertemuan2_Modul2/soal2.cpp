
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
