#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cari_sekuensial(int data[], int s, int cari) {
    bool ketemu;
    int i = 0;

    ketemu = false;
    while ((i < s) && !(ketemu)) {
        ketemu = (data[i++] == cari);
    }

    if (ketemu) {
        return i;
    } else {
        return -1 * i;
    }
}

int main() {
    const int N = 1000;
    int A[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000 + 1;
    }

    cout << "Isi Array = ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << "\t";
        if ((i + 1) % 20 == 0)    
            cout << endl;
    }

    cout << "====================================";

    int cari;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int hasil = cari_sekuensial(A, N, cari);

    if (hasil > 0) {
        cout << "Data ditemukan pada posisi ke-" << hasil << endl;
    } else {
        cout << "Data TIDAK ditemukan.\n";
        cout << "Jumlah langkah pencarian = " << -hasil << endl;
    }

    return 0;
}

