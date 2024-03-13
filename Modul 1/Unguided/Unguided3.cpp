#include <iostream>
#include <map>

int main() {
    // Membuat map yang menyimpan pasangan (kunci, nilai) dengan kunci bertipe string dan nilai bertipe int
    std::map<std::string, int> data;

    // Memasukkan data ke dalam map
    data["Zacky"] = 25;
    data["Nara"] = 30;
    data["Gates"] = 35;

    // Mengakses dan menampilkan nilai dari kunci "Alice"
    std::cout << "Umur Nara: " << data["Nara"] << std::endl;

    return 0;
}
