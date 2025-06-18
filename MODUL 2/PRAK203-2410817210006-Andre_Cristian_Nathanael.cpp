#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if ((R + 1) % n == F) {
        cout << "QUEUE PENUH" << endl;
    } else {
        cout << "Masukkan 1 Huruf : ";
        cin >> HURUF;
        if (F == -1) {
            F = 0;
            R = 0;
        } else {
            R = (R + 1) % n;
        }
        Q[R] = HURUF;
        cout << "Data '" << HURUF << "' berhasil dimasukkan ke queue." << endl;
    }
}

void DELETE() {
    if (F == -1) {
        cout << "QUEUE KOSONG" << endl;
    } else {
        cout << "Data '" << Q[F] << "' dihapus dari queue." << endl;
        if (F == R) {
            F = -1;
            R = -1;
        } else {
            F = (F + 1) % n;
        }
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "QUEUE KOSONG" << endl;
    } else {
        cout << "ISI QUEUE : ";
        int i = F;
        while (true) {
            cout << Q[i] << " ";
            if (i == R) break;
            i = (i + 1) % n;
        }
        cout << endl;
    }
}

int main() {
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "==================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        cout << "press any key to continue" << endl;
        getch();
        system("cls");

    } while (PIL < 4);
}