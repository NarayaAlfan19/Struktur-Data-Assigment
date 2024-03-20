#include <iostream>
#include <limits>

using namespace std;

int main() {
    int size;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size;

    // Membuat array dengan ukuran yang dimasukkan oleh pengguna
    int arr[size];

    // Meminta pengguna untuk memasukkan nilai-nilai array
    cout << "Masukkan nilai-nilai array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Menampilkan menu
    cout << "\nMenu:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Hitung nilai rata-rata\n";
    cout << "Pilih operasi yang ingin Anda lakukan : ";

    int choice;
    cin >> choice;

    // Mencari nilai maksimum
    if (choice == 1) {
        int max = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        cout << "Nilai maksimum: " << max << endl;
    }
    // Mencari nilai minimum
    else if (choice == 2) {
        int min = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        cout << "Nilai minimum: " << min << endl;
    }
    // Menghitung nilai rata-rata
    else if (choice == 3) {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        double average = static_cast<double>(sum) / size;
        cout << "Nilai rata-rata: " << average << endl;
    }
    // Jika pilihan tidak valid
    else {
        cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}
