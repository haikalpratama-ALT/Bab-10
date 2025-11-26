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

int binarySearch(int A[], int N, int cari) {
    int a = 0, b = N - 1, langkah = 0;
    bool ketemu = false;

    while (a <= b && !ketemu) {
        int t = (a + b) / 2;

        if (A[t] == cari) {
            ketemu = true;
        } else if (A[t] > cari) {
            b = t - 1;
        } else {
            a = t + 1;
        }
        langkah++;
    }

    return ketemu ? langkah : -langkah;
}

int main() {
    const int N = 1000;
    int A[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000; 
    }

    bubbleSort(A, N);

    int terkecil = A[0];
    int terbesar = A[N - 1];

    int langkahKecil = binarySearch(A, N, terkecil);
    int langkahBesar = binarySearch(A, N, terbesar);

    cout << "Data terkecil  : " << terkecil << endl;
    cout << "Langkah mencari data terkecil  : " << langkahKecil << endl;

    cout << "Data terbesar : " << terbesar << endl;
    cout << "Langkah mencari data terbesar : " << langkahBesar << endl;


    return 0;
}

