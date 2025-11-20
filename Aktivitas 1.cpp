#include <iostream>
#include <cstdlib>
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
	int s;
	cout << "Masukkan jumlah data: ";
	cin >> s;
	int nilai[s];
	for (int i = 0; i < s; i++) {
	cout << "Masukkan nilai data ke-" << i + 1 << ": ";
	cin >> nilai[i];
}
	int a;
	cout << "Masukkan data yang ingin dicari";
	cin >> a;
	cout << cari_sekuensial(nilai, s, a)<< "kali pencarian";
	return 0;
} 

