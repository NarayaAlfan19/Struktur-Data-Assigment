#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* back;
    int size;
    const int maksimalQueue = 5; // Maksimal antrian

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    bool isFull() { // Pengecekan antrian penuh atau tidak
        return size == maksimalQueue;
    }

    bool isEmpty() { // Antriannya kosong atau tidak
        return size == 0;
    }

    void enqueueAntrian(string nama, string nim) { // Fungsi menambahkan antrian
        if (isFull()) {
            cout << "Antrian penuh" << endl;
        } else {
            Node* newNode = new Node();
            newNode->nama = nama;
            newNode->nim = nim;
            newNode->next = nullptr;
            if (isEmpty()) {
                front = newNode;
                back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
            size++;
        }
    }

    void dequeueAntrian() { // Fungsi mengurangi antrian
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            if (isEmpty()) {
                back = nullptr;
            }
        }
    }

    int countQueue() { // Fungsi menghitung banyak antrian
        return size;
    }

    void clearQueue() { // Fungsi menghapus semua antrian
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() { // Fungsi melihat antrian
        cout << "Data antrian mahasiswa:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            index++;
        }
        for (int i = index; i <= maksimalQueue; i++) {
            cout << i << ". (tidak ada)" << endl;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueueAntrian("Andi", "2311102170");
    queue.enqueueAntrian("Maya", "2311109876");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
