//Mohammad Alfan Naraya
//2311102170

#include <iostream>
#include <string>

using namespace std;

int hitungVokal(const string& kalimat) {
    int count = 0;
    for (char c : kalimat) {
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int vocalCount = hitungVokal(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat: " << vocalCount << endl;

    return 0;
}