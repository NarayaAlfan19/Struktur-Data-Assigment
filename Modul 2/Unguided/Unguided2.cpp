#include <iostream>

using namespace std;

int main() {
    int size1, size2, size3;

    // Meminta pengguna untuk memasukkan ukuran elemen
    cout << "Masukkan ukuran elemen array tiga dimensi:" << endl;
    cout << "Ukuran dimensi 1: ";
    cin >> size1;
    cout << "Ukuran dimensi 2: ";
    cin >> size2;
    cout << "Ukuran dimensi 3: ";
    cin >> size3;

    // Membuat array tiga dimensi sesuai dengan ukuran yang dimasukkan oleh pengguna
    int arr[size1][size2][size3];

    // Meminta pengguna untuk memasukkan nilai-nilai elemen
    cout << "Masukkan nilai-nilai elemen array:" << endl;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Menampilkan nilai-nilai elemen yang dimasukkan
    cout << "Nilai-nilai elemen array yang dimasukkan:" << endl;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }

    return 0;
}
