#include <iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int * ptr = arr;

    for(int i = 0; i < 5; ++i){
        cout<<"elemen array ke-" <<i+1<<"menggunakan pointer" << *(ptr + 1) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen ke-" << "menggunakan indeks" << arr[i] << endl; 
    }
    return 0;
}   