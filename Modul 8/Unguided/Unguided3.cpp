//Mohammad Alfan Naraya
//2311102170

#include <iostream>

using namespace std;

int hitungAngka(const int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    
    int count = hitungAngka(data, size, target);

    
    cout << "Jumlah angka " << target << " dalam array: " << count << endl;

    return 0;
}