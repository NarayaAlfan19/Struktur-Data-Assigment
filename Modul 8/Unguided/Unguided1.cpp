//Mohammad Alfan Naraya
//2311102170

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool binarySearch(const string& arr, char target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    string kalimat;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    string sorted_kalimat = kalimat;
    sort(sorted_kalimat.begin(), sorted_kalimat.end());

    cout << "Kalimat yang diurutkan: " << sorted_kalimat << endl;

    if (binarySearch(sorted_kalimat, target)) {
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}