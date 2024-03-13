#include <iostream>

// Definisi class Manusia
class Manusia {
private:
    std::string nama;
    int umur;

public:
    // Konstruktor
    Manusia(std::string n, int u) : nama(n), umur(u) {}

    // Metode untuk menampilkan informasi manusia
    void tampilkanInfo() {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Umur: " << umur << std::endl;
    }
};

int main() {
    // Membuat objek manusia
    Manusia orang("AlfanNaraya", 19);

    // Memanggil metode untuk menampilkan informasi manusia
    orang.tampilkanInfo();

    return 0;
}
