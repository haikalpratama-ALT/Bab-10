#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int cari_biner(int data[], int s, int cari) {
    int a, b, t, langkah;
    bool ketemu;

    a = 0;
    b = s - 1;
    langkah = 0;
    ketemu = false;

    do {
        t = (a + b) / 2;

        if (data[t] == cari) {
            ketemu = true;
        } else {
            if (data[t] > cari) {
                b = t - 1;
            } else {
                a = t + 1;
            }
        }
        langkah++;
    } while ((a <= b) && !(ketemu));

    return ketemu ? langkah : -1 * langkah;
}

int main() {
    const int N = 1000;
    int A[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000 + 1;
    }

    sort(A, A + N);

    cout << "Isi Array Setelah Diurutkan :  ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\t";
        if ((i + 1) % 20 == 0)
            cout << endl;
    }

    cout << "===============================================";

    int cari;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int hasil = cari_biner(A, N, cari);

    if (hasil > 0) {
        cout << "Data ditemukan!" << endl;
        cout << "Jumlah langkah pencarian = " << hasil << endl;
    } else {
        cout << "Data TIDAK ditemukan." << endl;
        cout << "Jumlah langkah pencarian = " << -hasil << endl;
    }

    return 0;
}

