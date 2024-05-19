# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Mohammad Alfan Naraya - 2311102170</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian
 Queue adalah struktur data yang mengikuti prinsip First-In-First-Out (FIFO), yang berarti elemen pertama yang masuk ke dalam antrian akan menjadi elemen pertama yang keluar dari antrian. Queue dapat diibaratkan sebagai antrian di mana elemen-elemen baru ditambahkan di satu ujung antrian (rear) dan elemen-elemen yang sudah ada dikeluarkan di ujung lainnya (front). Queue mirip dengan antrian nyata yang sering kita temui dalam kehidupan sehari-hari.
 
 ### Prinsip FIFO pada Queue
 Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). 
 Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. 
 Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue.

 ### Jenis - Jenis Queue
 1. Simple Queue
 2. Circular Queue
 3. Priority Queue
 4. Double-Ended Queue (Dequeue). [2]

### Operasi - Operasi Dasar pada Queue
1. Enqueue: Menambahkan elemen ke akhir antrian
2. Dequeue: Menghapus elemen dari depan antrian
3. IsEmpty: Memeriksa apakah antrian kosong
4. IsFull: Memeriksa apakah antrian sudah penuh
5. Peek: Mendapatkan nilai bagian depan antrian tanpa menghapusnya
6. Initialize: Membuat antrian baru tanpa elemen data (kosong). [2]
   
## Guided 

### 1. Guided I

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
    return true; // =1
    } else {
    return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
    return true;
    } else {
    return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/b91d66bb-5ca2-41d3-b768-94d52d13e1bc)


Program ini memungkinkan pengguna untuk menambahkan (enqueue) dan mengurangi (dequeue) elemen dari antrian, serta melihat jumlah total elemen dalam antrian dan mengosongkan antrian. 
Program menggunakan array sebagai wadah untuk menyimpan elemen-elemen antrian, dengan batasan maksimal antrian yang telah ditetapkan sebelumnya. Selain itu, program juga memiliki fungsi untuk memeriksa apakah antrian penuh atau kosong.


## Unguided 

### 1. Unguided I

Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
// 2311102170
// Mohammad Alfan Naraya

#include <iostream>
using namespace std;

// Struktur node untuk menyimpan data antrian
struct Node {
  string data;
  Node* next;
};

// Deklarasi variabel awal
Node* head = NULL; // Penunjuk ke node head
Node* tail = NULL; // Penunjuk ke node tail

// Fungsi untuk memeriksa apakah queue penuh
bool isFull() {
  // Queue selalu tidak penuh karena linked list bersifat dinamis
  return false;
}

// Fungsi untuk memeriksa apakah queue kosong
bool isEmpty() {
  return head == NULL;
}

// Fungsi untuk menambahkan data ke queue
void enqueueAntrian(string data) {
  // Membuat node baru
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  // Menambahkan node baru ke akhir queue
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

// Fungsi untuk menghapus data dari queue
void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
    return;
  }

  // Menghapus node head
  Node* temp = head;
  head = head->next;
  delete temp;

  // Memperbarui tail jika queue menjadi kosong
  if (head == NULL) {
    tail = NULL;
  }
}

// Fungsi untuk menghitung jumlah data dalam queue
int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// Fungsi untuk membersihkan semua data dalam queue
void clearQueue() {
  while (head != NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  tail = NULL;
}

// Fungsi untuk menampilkan data dalam queue
void viewQueue() {
  cout << "Data antrian teller:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->data << endl;
    current = current->next;
    i++;
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/80842470-469a-4fba-abf9-6dda4e876d51)

Dalam program ini, setiap elemen dalam antrian direpresentasikan sebagai node dalam linked list. 
Terdapat empat fungsi utama yaitu enqueueAntrian untuk menambahkan elemen ke dalam antrian, dequeueAntrian untuk menghapus elemen dari depan antrian, countQueue untuk menghitung jumlah total elemen dalam antrian, dan clearQueue untuk mengosongkan seluruh antrian. 
Program juga memiliki fungsi viewQueue untuk menampilkan isi dari antrian.

### 1. Unguided II

Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
//2311102170
//Mohammad Alfan Naraya

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr; 
Mahasiswa* back = nullptr; 

void enqueueAntrian(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    if (front == nullptr) { 
        front = newNode;
        back = newNode;
    } else { 
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Mahasiswa* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != nullptr) {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Mahasiswa* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Andi", "2311102170");
    enqueueAntrian("Maya", "2311189987");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/0c0639b0-70f8-40cb-96f6-bec4aa263d2b)

Setiap elemen dalam antrian direpresentasikan sebagai node yang memiliki dua atribut: nama dan NIM mahasiswa. 
Program ini menyediakan fungsi-fungsi seperti enqueueAntrian untuk menambahkan elemen ke dalam antrian, dequeueAntrian untuk menghapus elemen dari depan antrian, countQueue untuk menghitung jumlah total elemen dalam antrian, dan clearQueue untuk mengosongkan seluruh antrian. 
Selain itu, terdapat fungsi viewQueue untuk menampilkan isi dari antrian, yang dalam hal ini adalah nama dan NIM mahasiswa.

## Kesimpulan
Pemahaman tentang struktur data queue menjadi kunci untuk mengoptimalkan efisiensi dan kinerja aplikasi. adalah struktur data yang mengatur elemen-elemen data dengan prinsip “First In, First Out” (FIFO), serupa dengan antrean di kehidupan sehari-hari.
Queue mempunyai beberapa kelebihan, salah satunya yaitu Operasi seperti penyisipan dan penghapusan dapat dilakukan dengan mudah karena mengikuti aturan masuk pertama keluar pertama. 
Namun, Queue juga mempunyai kekurangan, salah satunya Operasi seperti penyisipan dan penghapusan elemen dari tengah cenderung banyak memakan waktu.

## Referensi
[1] Riczky Pratama, "Queue: Pengenalan, Implementasi, Operasi Dasar, dan Aplikasi", 2023.https://medium.com/@furatamarizuki/queue-pengenalan-implementasi-operasi-dasar-dan-aplikasi-c5eed7e871a3

[2] Trivusi, "Struktur Data Queue: Pengertian, Jenis, dan Kegunaannya", 2023. https://www.trivusi.web.id/2022/07/struktur-data-queue.html
