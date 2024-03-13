# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Mohammad Alfan Naraya - 2311102170</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Tipe data adalah suatu memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Adapun jenis tipe data dan penjelasannya yang terdapat pada bahasa C++ :

1. Tipe data Primitif
   Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Dalam C++, terdapat 7 tipe data yang termasuk tipe data primitif, yaitu: int, float, double, boolean, char, void dan wide_character.

2. Tipe data Abstrak
   Tipe Data Abstrak (ADT) adalah tipe (atau kelas) untuk objek yang perilakunya ditentukan oleh sekumpulan nilai dan serangkaian operasi. Definisi ADT hanya menyebutkan operasi apa yang akan dilakukan tetapi tidak menyebutkan bagaimana operasi tersebut akan dilaksanakan. Itu tidak menentukan bagaimana data akan diatur dalam memori dan algoritma apa yang akan digunakan untuk mengimplementasikan operasi. Disebut “abstrak” karena memberikan pandangan yang tidak bergantung pada implementasi.

3. Tipe data Koleksi
   Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Contoh tipe data koleksi
   
     a). Array
  
     b). Vector
  
     c). Map

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i,e, +, -, *, /
    cin >> op;
    // it allows user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user center +
    case '+':
        cout << num1 + num2;
        break;
    // if user center -
    case '-':
        cout << num1 - num2;
        break;
    // if user center *
    case '*':
        cout << num1 * num2;
        break;
    // if user center /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +,-,* or /,
    // error message will be display
    
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/eb29a959-f6e6-4873-bf36-6522b8a16c8b)

Program ini adalah kalkulator sederhana yang meminta pengguna untuk memasukkan operator matematika dan dua operand numerik. Setelah pengguna memasukkan operator dan operand, program menggunakan sebuah pernyataan switch untuk mengecek operator yang dimasukkan pengguna. Berdasarkan operator tersebut, program akan melakukan operasi yang sesuai (penjumlahan, pengurangan, perkalian, atau pembagian) pada dua operand yang dimasukkan, dan kemudian mencetak hasilnya. Jika operator yang dimasukkan tidak sesuai dengan yang diharapkan (+, -, *, /), maka program akan mencetak pesan kesalahan.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
//Struct
struct Mahasiswa
{
const char *name;
const char *address;
int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
mhs1.name = "Dian";
mhs1.address = "Mataram";
mhs1.age = 22;
mhs2.name = "Bambang";
mhs2.address = "Surabaya";
mhs2.age = 23;
// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/b6c75dc2-efb0-4b11-8451-40d42024c979)

Program dalam bahasa C++ yang menggunakan struktur (struct) untuk menyimpan informasi tentang mahasiswa.
Program ini menggunakan struktur Mahasiswa untuk menyimpan informasi tentang dua mahasiswa. Setelah mendeklarasikan struktur dan variabel struktur untuk masing-masing mahasiswa, program mengisi nilai ke dalam variabel struktur dan mencetak informasi masing-masing mahasiswa menggunakan fungsi printf. Akhirnya, program mengembalikan nilai 0.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/f4c4fda0-13cc-4b16-a7a7-d0a9e298e023)

Array nilai dengan panjang 5 elemen (indeks 0 sampai 4) dideklarasikan dan diinisialisasi dengan nilai-nilai tertentu. Setelah array diinisialisasi, program mencetak isi array menggunakan pernyataan cout. Setiap elemen array dicetak satu per satu dengan menyertakan indeksnya.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
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
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/51608be8-295a-4bf1-948f-42d544627fca)

Program ini memiliki dua fungsi: tambah() dan kali().
Fungsi tambah() menerima dua parameter bertipe int, menjumlahkannya, dan mengembalikan hasil penjumlahan.
Fungsi kali() menerima dua parameter bertipe float, mengalikannya, dan mengembalikan hasil perkalian.
Di dalam fungsi main(), terdapat inisialisasi variabel angka1, angka2, nilai1, dan nilai2.
Program kemudian mencetak hasil penjumlahan dua bilangan bulat dan hasil perkalian dua bilangan riil menggunakan fungsi yang telah didefinisikan sebelumnya.

Kesimpulan Tipe Data Primitif:<br/>
Tipe data primitif merupakan tipe data dasar yang tersedia di dalam bahasa pemrograman.
Tipe data primitif dalam C++ seperti int dan float digunakan untuk merepresentasikan bilangan bulat dan bilangan riil.
Penggunaan tipe data primitif sangat penting dalam pemrograman karena mereka menyediakan representasi dasar untuk data yang akan diolah oleh program.
Program-program yang efisien biasanya menggunakan tipe data primitif untuk menyimpan dan memanipulasi data, karena penggunaan tipe data primitif memungkinkan penggunaan memori yang lebih efisien.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
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
```
#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/c6c9effe-82e1-4e08-845c-3d8c0ab880d7)

program di atas merupakan sebuah class bernama Manusia.
Class Manusia memiliki dua data anggota: nama dan umur.
Ada satu konstruktor yang digunakan untuk menginisialisasi objek Manusia.
Terdapat satu metode tampilkanInfo() yang digunakan untuk menampilkan informasi tentang manusia.
Di dalam fungsi main(), kita membuat objek orang dari class Manusia, kemudian memanggil metode tampilkanInfo() untuk menampilkan informasi tentang objek tersebut.

A. Fungsi dari Class<br/>
Class adalah struktur data yang dapat digunakan untuk menyimpan data dan fungsi-fungsi terkait dalam satu unit. Dalam class, variabel-variabel (biasanya disebut sebagai data anggota) dan fungsi-fungsi (biasanya disebut sebagai metode) dikombinasikan bersama. Class adalah konsep dasar dalam pemrograman berorientasi objek (OOP).

B. Fungsi dari Struct<br/>
Struct dalam C++ hampir sama dengan class, tetapi secara default semua anggotanya adalah publik (berbeda dengan class yang defaultnya adalah privat). Struct digunakan untuk mengelompokkan sejumlah variabel dengan berbagai tipe data menjadi satu unit. Struct juga dapat memiliki fungsi-fungsi, tetapi biasanya digunakan hanya untuk menyimpan data.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
#include <map>

int main() {
    // Membuat map yang menyimpan pasangan (kunci, nilai) dengan kunci bertipe string dan nilai bertipe int
    std::map<std::string, int> data;

    // Memasukkan data ke dalam map
    data["Zacky"] = 42;
    data["Nara"] = 19;
    data["Gates"] = 42;

    // Mengakses dan menampilkan nilai dari kunci "Nara"
    std::cout << "Umur Nara: " << data["Nara"] << std::endl;

    return 0;
}
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/05570059-8328-451f-aa83-bb3267447668)

Program ini menggunakan std::map, yang merupakan struktur data di C++ yang menyimpan pasangan kunci-nilai.
Dalam program ini, kita membuat map data yang menyimpan pasangan (kunci, nilai), di mana kunci bertipe std::string dan nilai bertipe int.
Data dimasukkan ke dalam map menggunakan sintaks data["kunci"] = nilai.
Untuk mengakses nilai dari map, kita menggunakan kunci seperti data["kunci"].

## Perbedaan Array dengan Map
1.Penyimpanan Data:

Array:

Elemen dalam array disimpan berdasarkan indeks numerik berurutan, dimulai dari 0.
Setiap elemen memiliki indeks unik yang digunakan untuk mengaksesnya.
Array ideal untuk menyimpan data yang memiliki urutan atau hubungan tertentu.

Map:

Elemen dalam map disimpan sebagai pasangan key-value.
Key dapat berupa string, number, atau tipe data lain yang bersifat unik dan digunakan untuk mengakses value terkait.
Map ideal untuk menyimpan data yang tidak memiliki urutan khusus, tetapi perlu diakses berdasarkan nilai unik (key).

2. Pengaksesan Data:

Array:

Elemen diakses menggunakan indeks numeriknya.
Program perlu mengetahui indeks yang valid untuk mengakses elemen tertentu.

Map:

Elemen diakses menggunakan key uniknya.
Program dapat langsung mengakses elemen berdasarkan key tanpa perlu mengetahui urutannya.

3. Penggunaan Umum:

Array:

Digunakan untuk menyimpan koleksi data yang berurutan, seperti daftar nama, nilai ujian, atau koordinat.
Cocok untuk iterasi (pengulangan) berurutan melalui elemen.

Map:

Digunakan untuk menyimpan data yang perlu diakses berdasarkan pengenal unik, seperti informasi pengguna (key: username, value: object berisi detail pengguna), atau preferensi pengaturan (key: setting name, value: setting value).
Memungkinkan pencarian elemen yang cepat dan efisien berdasarkan key.

4. Urutan:

Array:

Elemen dalam array memiliki urutan yang jelas berdasarkan indeksnya.
Urutan ini dapat diubah atau dimanipulasi selama program berjalan.

Map:

Elemen dalam map tidak memiliki urutan bawaan.
Iterasi melalui elemen map mungkin tidak mengikuti urutan tertentu tergantung pada implementasi map tersebut.

## Kesimpulan
Tipe data dalam bahasa pemrograman C++ merupahan instruksi yang memungkinkan programmer menyimpan dan mengelola berbagai jenis nilai dalam program. Ada tipe data dasar seperti angka, karakter, dan boolean, serta tipe data turunan seperti array dan pointer untuk pengelolaan data yang lebih kompleks. Programmer juga dapat membuat tipe data khusus menggunakan struktur atau kelas. Meskipun tipe data dalam C++ bersifat statis dan harus ditentukan secara eksplisit, ini membantu meningkatkan keamanan dan kinerja program. Dengan berbagai pilihan tipe data ini, programmer dapat membuat program C++ yang efisien dan kuat untuk berbagai kebutuhan pengembangan perangkat lunak.

## Referensi
[1] Nugroho, Lukito Edi. "Pemrograman Dasar: Algoritma dan Struktur Data dengan C/C++." Penerbit Informatika, 2017.

[2] Kadir, Abdul. "Dasar Pemrograman: Struktur Data dan Algoritma." Penerbit Andi, 2019.

