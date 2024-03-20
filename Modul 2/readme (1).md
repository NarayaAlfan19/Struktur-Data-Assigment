# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Mohammad Alfan Naraya - 2311102170</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori
Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. 
Berikut ini adalah beberapa jenis array :
1) Array Satu Dimensi

  Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data
  dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap
  elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan
  untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada
  jumlah elemen dikurangi satu.

  Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {1, 2,
  3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk
  pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya
  hingga indeks 4 merujuk pada elemen kelima.
    
2) Array Dua Dimensi

  Array dua dimensi adalah variable yang terdiri dari kumpulan array
  satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
  Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks
  baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris,
  sementara indeks kolom menunjukkan posisi elemen dalam kolom.

3) Array Multidimensi

  Array multidimensi memiliki kesamaan dengan array satu dimensi dan
  dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
  digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
  array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
  empat dimensi, array lima dimensi, dan seterusnya.

4) Array Empat dimensi
  ```C++
int arr [3][2][4][4];
```

5) Array Lima Dimensi
  ```C++
int arr [2][4][4][3][3];
```
  
## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>

using namespace std;
// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/56372ea2-b34f-44da-8d7a-2197e5a9e732)

Program di atas adalah sebuah contoh program C++ yang mendemonstrasikan penggunaan array tiga dimensi. 
Program ini meminta pengguna untuk memasukkan nilai ke dalam array tiga dimensi dengan ukuran 2x3x3, kemudian mencetak nilai-nilai tersebut.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main (){
    int maks, a, i=1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array [a];
    cout << "Masukkan " << a << " angka\n";
    for (i=0;i < a;i++)
    {
        cout << "Array ke- " << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i=0;i < a;i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/66d71f70-ca86-4ba9-b9b9-8d7fad832280)

Program di atas adalah contoh program C++ yang bertujuan untuk mencari nilai maksimum dari sebuah array yang diinputkan pengguna.
Program meminta pengguna untuk memasukkan panjang array. Setelah panjang array dimasukkan, program membuat array dengan ukuran yang sesuai.
Selanjutnya, program meminta pengguna untuk memasukkan angka sebanyak panjang array yang telah ditentukan.
Program melakukan iterasi melalui setiap elemen array dan mencari nilai maksimum.
Ketika nilai maksimum ditemukan, program juga menyimpan lokasi (indeks) dimana nilai maksimum tersebut berada.
Setelah iterasi selesai, program mencetak nilai maksimum beserta lokasinya dalam array.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
<img width="361" alt="Screenshot 2024-03-19 193725" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/f15b4a54-0406-4e3f-b261-359615a42e13">


```C++
#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int b_170;
    // Meminta pengguna untuk memasukkan jumlah array
    cout << "Masukkan jumlah array: ";
    cin >> b_170;
    // Deklarasi array dengan ukuran b_169
    int arr[b_170];

    // Input array
    cout << "Masukkan " << b_170 << " angka\n";
    for (int a = 0; a < b_170; a++)
    {
        cout << "Array ke - " << a << ": ";
        cin >> arr[a];
    }
    cout << endl;

    // Output data array
    cout << "Data Array : ";
    for (int a = 0; a < b_170; a++)
    {
        cout << arr[a] << " ";
    }
    cout << endl;

    // Output nomor genap
    cout << "Nomor Genap : ";
    for (int a = 0; a < b_170; a++)
    {
        if (arr[a] % 2 == 0)
        {
            cout << arr[a] << ", ";
        }
    }
    cout << endl;

    // Output nomor ganjil
    cout << "Nomor Ganjil : ";
    for (int a = 0; a < b_170; a++)
    {
        if (arr[a] % 2 != 0)
        {
            cout << arr[a] << ", ";
        }
    }
}
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/1f275020-e770-4028-a695-4449ee834477)

Program di atas adalah contoh program C++ yang meminta pengguna untuk memasukkan sejumlah angka ke dalam array, 
 kemudian mencetak array tersebut serta memisahkan angka-genap dan angka-ganjil ke dalam dua kelompok terpisah.
 Program meminta pengguna untuk memasukkan jumlah angka yang akan dimasukkan ke dalam array. Setelah jumlah angka dimasukkan, program membuat array dengan ukuran sesuai input pengguna.
 Program meminta pengguna untuk memasukkan angka sejumlah yang telah ditentukan. Setelah semua angka dimasukkan, program mencetak seluruh isi array.
 Program kemudian mencetak angka-angka genap yang ada dalam array. Terakhir, program mencetak angka-angka ganjil yang ada dalam array.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
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

```
#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/88c9a04a-15b5-46fd-b70f-e03e12e32a01)

Program di atas adalah contoh program C++ yang memungkinkan pengguna untuk memasukkan elemen-elemen ke dalam array tiga dimensi dan kemudian menampilkan isi array tersebut. 
Program tersebut meminta pengguna untuk memasukkan ukuran untuk setiap dimensi dari array tiga dimensi, kemudian membuat array tersebut sesuai dengan ukuran yang dimasukkan. Selanjutnya, program meminta pengguna untuk memasukkan nilai-nilai elemen dan menampilkan kembali nilai-nilai elemen yang dimasukkan.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
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
    cout << "Pilih operasi yang ingin Anda lakukan (1/2/3): ";

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
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/f42d2cc2-987f-4d63-9077-047d683f3103)

Program di atas adalah sebuah program C++ sederhana yang memungkinkan pengguna untuk memasukkan elemen-elemen ke dalam sebuah array, kemudian memilih opsi untuk mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen tersebut.
Program meminta pengguna untuk memasukkan jumlah elemen array.
Setelah jumlah elemen array ditentukan, program mendeklarasikan array dengan ukuran yang sesuai.
Pengguna diminta untuk memasukkan nilai-nilai elemen array melalui looping.
Setelah semua elemen dimasukkan, program menampilkan menu yang berisi pilihan operasi yang dapat dilakukan, yaitu mencari nilai maksimum, minimum, atau rata-rata.
Pengguna diminta untuk memilih salah satu dari pilihan tersebut.
Program melakukan operasi sesuai pilihan pengguna menggunakan switch case.
Hasil operasi ditampilkan ke layar.


## Kesimpulan
Array merupakan struktur data yang fundamental dalam pemrograman, dan penting untuk dipelajari sebelum memahami struktur data lainnya.
Ada beberapa jenis array yang umum digunakan. Pertama, array satu dimensi adalah kumpulan data dengan tipe yang sama yang disusun dalam satu baris
Setiap elemen memiliki indeks yang dimulai dari 0 hingga jumlah elemen dikurangi satu. Kemudian, array dua dimensi adalah kumpulan array satu dimensi yang disusun dalam baris dan kolom.
Setiap elemen dalam array dua dimensi memiliki dua indeks: indeks baris dan indeks kolom. erakhir, array multidimensi memperluas konsep array dengan menyediakan dimensi lebih dari dua atau lebih dari dua indeks, seperti array tiga dimensi, empat dimensi, dan seterusnya.
Pemahaman yang baik tentang jenis-jenis array ini akan membantu dalam mengorganisir dan mengelola data dengan lebih efisien dalam pengembangan perangkat lunak.
Dengan menguasai konsep-konsep dasar array, pemrogram dapat membangun fondasi yang kuat untuk mempelajari struktur data yang lebih kompleks.

## Referensi
[1] Asisten Praktikum, "Modul 2 Array", Learning Management System, 2024.
