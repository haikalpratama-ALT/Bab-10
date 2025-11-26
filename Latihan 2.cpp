#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int A[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

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
        } else if (data[t] > cari) {
            b = t - 1;
        } else {
            a = t + 1;
        }
        langkah++;

    } while ((a <= b) && !(ketemu));

    return ketemu ? langkah : -langkah;
}

int main() {
    const int N = 1000;
    int A[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000 + 1;
    }

    bubbleSort(A, N);

    cout << "Isi Array Setelah Diurutkan:\n";
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\t";
        if ((i + 1) % 20 == 0) cout << endl;
    }

    cout << "\n===============================================\n";

    int cari;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int hasil = cari_biner(A, N, cari);

    if (hasil > 0) {
        cout << "Data ditemukan\n";
        cout << "Jumlah langkah pencarian = " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan\n";
        cout << "Jumlah langkah pencarian = " << -hasil << endl;
    }

    return 0;
}
