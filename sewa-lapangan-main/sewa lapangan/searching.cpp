#include <iostream>
#include <cstdlib>
#include "struct.h"
#include "lapangan.h"
#include "menu.h"

using namespace std;
 
void searching() {
    string margintittle(36, ' ');
    string marginsub(50, ' ');
    string margin(38, ' ');
    
    string carinama;
    cin.ignore();

    cout << endl;
    cout << margintittle << "+--------------------------------------------+\n";
    cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle << "+--------------------------------------------+\n\n";
    cout << margin << " Masukkan Nama yang ingin dicari : ";
    getline(cin, carinama);

    cout << endl;

    pelanggan* resultA = searchingA(carinama);
    pelanggan* resultB = searchingB(carinama);
    pelanggan* resultC = searchingC(carinama);

    if (resultA != nullptr) {
        cout << margin << " Data ditemukan : -= LAPANGAN A =-\n";
        cout << margin << " Nama        : " << resultA->nama << "\n";
        cout << margin << " Tanggal     : " << resultA->tanggal << "\n";
        cout << margin << " Telp        : " << resultA->telp << "\n";
        cout << margin << " Waktu (Jam) : " << resultA->waktu << "\n";
        cout << margin << " Harga       : " << resultA->waktu * resultA->harga << "\n\n";
    }
    else if (resultB != nullptr) {
        cout << margin << " Data ditemukan : -= LAPANGAN B =-\n";
        cout << margin << " Nama        : " << resultB->nama << "\n";
        cout << margin << " Tanggal     : " << resultB->tanggal << "\n";
        cout << margin << " Telp        : " << resultB->telp << "\n";
        cout << margin << " Waktu (Jam) : " << resultB->waktu << "\n";
        cout << margin << " Harga       : " << resultB->waktu * resultB->harga << "\n\n";
    }
    else if (resultC != nullptr) {
        cout << margin << " Data ditemukan : -= LAPANGAN C =-\n";
        cout << margin << " Nama        : " << resultC->nama << "\n";
        cout << margin << " Tanggal     : " << resultC->tanggal << "\n";
        cout << margin << " Telp        : " << resultC->telp << "\n";
        cout << margin << " Waktu (Jam) : " << resultC->waktu << "\n";
        cout << margin << " Harga       : " << resultC->waktu * resultC->harga << "\n\n";
    }
    else 
    {
        cout << margin << " Data tidak ditemukan di Lapangan A / B!\n";
    }

    char input;

    cout << margin << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}
