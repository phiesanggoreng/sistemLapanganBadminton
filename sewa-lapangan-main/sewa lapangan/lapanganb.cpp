#include <iostream>
#include "struct.h"
#include "menu.h"
#define max 5

using namespace std;

pelanggan* tempatb[max];
int topB = 0;

bool isfullB() {
    return topB >= max;
}

bool isemptyB() {
    return topB == 0;
}

void viewB() {
    cout << "-= LAPANGAN B =- \n";
    if (!isemptyB()) {
        for (int i = topB - 1; i >= 0; i--) {
            cout << i + 1;
            cout << ". Nama      : " << tempatb[i]->nama << endl;
            cout << "   Tanggal   : " << tempatb[i]->tanggal << endl;
            cout << "   Telp      : " << tempatb[i]->telp << endl;
            cout << "   Deskripsi : " << tempatb[i]->deskripsi << endl << endl;
        }
    }
    cout << endl;
    if (isfullB()) {
        cout << "DATA PENUH!" << endl;
    }
}

void berhasilB() {
    if (!isfullB()) {
        pelanggan* tiga;

        tiga = new pelanggan();

        cout << " -= LAPANGAN B =-\n";
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

        tempatb[topB] = tiga;
        topB++;
        cout << endl;
    }
}

void tidakberhasilB() {
    if (!isemptyB()) {
        delete tempatb[0];
        for (int i = 0; i < topB - 1; i++) {
            tempatb[i] = tempatb[i + 1];
        }
        topB--;
    }
    else {
        cout << "DATA KOSONG!" << endl;
    }
}

void LapanganB() {

queue:
    berhasilB();

    char input;
    cout << "Apakah anda ingin mengubah data? (Y/N): " << endl;
    cout << "Jika tidak akan kembali ke menu utama" << endl;
    cout << "Answer : ";
    cin >> input;

    if (input == 'Y' || input == 'y')
    {
        topB--;
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