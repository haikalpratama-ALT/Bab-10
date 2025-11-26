#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cari_sekuensial(int data[], int s, int cari) {
    bool ketemu = false;
    int i = 0;

    while ((i < s) && !ketemu) {
        ketemu = (data[i++] == cari);
    }

    return ketemu ? i : -i;
}

void bubble_sort(int data[], int s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int N = 1000;
    int A[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000 + 1;
    }

    bubble_sort(A, N);

    int terkecil = A[0];
    int terbesar = A[N - 1];

    int langkah_kecil = cari_sekuensial(A, N, terkecil);
    int langkah_besar = cari_sekuensial(A, N, terbesar);

    cout << "Data terkecil  : " << terkecil << endl;
    cout << "Langkah mencari data terkecil  : " << langkah_kecil << endl;

    cout << "Data terbesar : " << terbesar << endl;
    cout << "Langkah mencari data terbesar : " << langkah_besar << endl;

    return 0;
}

