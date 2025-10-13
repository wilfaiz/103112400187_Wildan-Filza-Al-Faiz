#include <iostream>

using namespace std;

struct Mahasiswa{
    string nim;
    float nilai1;
    float nilai2;
};


//relasi dari fungsi inputMhs
void inputMHS(Mahasiswa &m) {
    cout << "input NIM:";
    cin >> m.nim;
    cout << "input nilai 1: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}
float rata2(Mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

int main(){
    Mahasiswa mhs;
    inputMHS(mhs);
    cout << "Rata-rata: " << rata2(mhs) << endl;
    return 0;
}