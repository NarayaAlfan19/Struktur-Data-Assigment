#include <iostream>
using namespace std;

int arr[] = {1,4,2,5,6,7,8,9,10,15,14};
int cari = 15;
int i;
int panjangArray = sizeof(arr)/ sizeof(arr[0]);
bool ketemu = false;

int main (){
    for (i = 0;i<panjangArray;i++){
        if (arr[i] == cari){
            ketemu = true;
            break;
        } else{
            i++;
        }
    }

    cout << "panjang array : " << panjangArray << endl;
    cout << cari << " terdapat pada indeks ke-"<< arr[i];

    return 0;
}
