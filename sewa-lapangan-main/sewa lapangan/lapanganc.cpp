#include <iostream>
#include "struct.h"
#include "menu.h"
#define max 5

using namespace std;

pelanggan* tempat[max];
int top = 0;

bool isfull() {
    return top >= max;
}

bool isempty() {
    return top == 0;
}

void view() {
    cout << "-= LAPANGAN C =- \n";
    if (!isempty()) {
        for (int i = top - 1; i >= 0; i--) {
            cout << i + 1;
            cout << ". Nama      : " << tempat[i]->nama << endl; 
            cout << "   Tanggal   : " << tempat[i]->tanggal << endl;
            cout << "   Telp      : " << tempat[i]->telp << endl;
            cout << "   Deskripsi : " << tempat[i]->deskripsi << endl << endl;
        }
    }
    cout << endl;
    if (isfull()) {
        cout << "DATA PENUH!" << endl;
    }
}

void berhasil() {
    if (!isfull()) {
        pelanggan* tiga;
            
        tiga = new pelanggan();

        cout << " -= LAPANGAN C =-\n";
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

        tempat[top] = tiga;
        top++;
        cout << endl;
    }
}

void tidakberhasil() {
    if (!isempty()) {
        delete tempat[0];
        for (int i = 0; i < top - 1; i++) {
            tempat[i] = tempat[i + 1];
        }
        top--;
    }
    else {
        cout << "DATA KOSONG!" << endl;
    }
}

void LapanganC() {

queue:
    berhasil();

    char input;
    cout << "Apakah anda ingin mengubah data? (Y/N): " << endl;
    cout << "Jika tidak akan kembali ke menu utama" << endl;
    cout << "Answer : ";
    cin >> input;

    if (input == 'Y' || input == 'y') 
    {
        top--;
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