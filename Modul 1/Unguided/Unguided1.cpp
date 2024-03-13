#include <iostream>

// Fungsi untuk menjumlahkan dua bilangan bulat
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan riil
float kali(float x, float y) {
    return x * y;
}

int main() {
    int angka1 = 5;
    int angka2 = 3;
    float nilai1 = 2.5;
    float nilai2 = 4.0;

    // Menampilkan hasil penjumlahan dua bilangan bulat
    std::cout << "Hasil penjumlahan dari " << angka1 << " dan " << angka2 << " adalah: " << tambah(angka1, angka2) << std::endl;

    // Menampilkan hasil perkalian dua bilangan riil
    std::cout << "Hasil perkalian dari " << nilai1 << " dan " << nilai2 << " adalah: " << kali(nilai1, nilai2) << std::endl;

    return 0;
}
