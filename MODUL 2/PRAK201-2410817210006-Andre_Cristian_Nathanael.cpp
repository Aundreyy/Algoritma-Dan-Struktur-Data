#include <iostream>
using namespace std;

#define max 10

struct Stack {
    int atas;
    int data[max];
};

Stack Tumpuk;

int kosong()
{
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh()
{
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data)
{
    if (kosong() == 1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else if (!penuh())
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
    else
        cout << "Tumpukan Penuh\n";
}

void hapus()
{
    if (kosong() == 0)
    {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }
    else
        cout << "Data Kosong\n";
}

void tampil()
{
    if (kosong() == 0)
    {
        for (int i = Tumpuk.atas; i >= 0; i--)
        {
            cout << "Tumpukan Ke " << i << " = "
                 << Tumpuk.data[i] << endl;
        }
    }
    else
        cout << "Tumpukan Kosong\n";
}

void bersih()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !\n";
}

void menu()
{
    int pilihan, angka;

    do {
        cout << "\n====== MENU STACK ======\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Tampilkan Stack\n";
        cout << "4. Bersihkan Stack\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "Masukkan Angka: ";
                cin >> angka;
                input(angka);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Program Selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);
}

int main()
{
    Tumpuk.atas = -1;
    menu();
    return 0;
}