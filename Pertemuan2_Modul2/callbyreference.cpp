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