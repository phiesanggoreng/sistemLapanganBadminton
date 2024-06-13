#include <iostream>
#include "struct.h"
#include "menu.h"
#define max 5

using namespace std;

pelanggan* tempata[max];
int topA = 0;

bool isfullA() {
    return topA >= max;
}

bool isemptyA() {
    return topA == 0;
}

void viewA() {
    if (!isemptyA()) {
        cout << "-= LAPANGAN A =- \n";
        for (int i = topA - 1; i >= 0; i--) {
            cout << i + 1;
            cout << ". Nama      : " << tempata[i]->nama << endl;
            cout << "   Tanggal   : " << tempata[i]->tanggal << endl;
            cout << "   Telp      : " << tempata[i]->telp << endl;
            cout << "   Deskripsi : " << tempata[i]->deskripsi << endl << endl;
        }
    }
    cout << endl;
    if (isfullA()) {
        cout << "DATA PENUH!" << endl;
    }
}

void berhasilA() {
    if (!isfullA()) {
        pelanggan* tiga;

        tiga = new pelanggan();

        cout << " -= LAPANGAN A =-\n";
        cout << " Masukkan identitas penyewa\n\n";
        cout << " Nama      : ";
        cin >> tiga->nama;
        cout << " Tanggal   : ";
        cin >> tiga->tanggal;
        cout << " Telp      : ";
        cin >> tiga->telp;
        cout << " Deskripsi : ";
        cin >> tiga->deskripsi;
        cout << endl;
        cout << "Data anda sudah tersimpan" << endl;

        tempata[topA] = tiga;
        topA++;
        cout << endl;
    }
}

void tidakberhasilA() {
    if (!isemptyA()) {
        delete tempata[0];
        for (int i = 0; i < topA - 1; i++) {
            tempata[i] = tempata[i + 1];
        }
        topA--;
    }
    else {
        cout << "DATA KOSONG!" << endl;
    }
}

void LapanganA() {

queue:
    berhasilA();

    char input;
    cout << "Apakah anda ingin mengubah data? (Y/N): " << endl;
    cout << "Jika tidak akan kembali ke menu utama" << endl;
    cout << "Answer : ";
    cin >> input;

    if (input == 'Y' || input == 'y')
    {
        topA--;
        system("cls");
        MenuGagal();
    }
    else if (input == 'N' || input == 'n')
    {
        system("cls");
        Menu();
        goto queue;
    }
}