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
