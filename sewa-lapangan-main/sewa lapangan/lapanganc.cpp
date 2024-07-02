#include <iostream>
#include "struct.h"
#include "menu.h"
#include "lapangan.h"
#define max 3

using namespace std;

pelanggan* tempatc[max];
int topC = 0;
string margintittle3(36, ' ');
string marginsub3(50, ' ');
string margin3(38, ' ');

bool isfull() 
{
    return topC == max;
}

bool isempty() 
{
    return topC == 0;
}

void viewC() 
{
    cout << endl;
    cout << marginsub3 << " -= LAPANGAN C =- \n";

    if (!isempty())
    {
        sortC();  

        for (int i = 0; i < topC; i++) 
        { 
            cout << margin3 << " " << i + 1 << ". Nama      : " << tempatc[i]->nama << endl;
            cout << margin3 << "    Tanggal   : " << tempatc[i]->tanggal << endl;
            cout << margin3 << "    Telp      : " << tempatc[i]->telp << endl;
            cout << margin3 << "    Waktu     : " << tempatc[i]->waktu << endl;
            cout << margin3 << "    Harga     : " << tempatc[i]->waktu * tempatc[i]->harga << endl << endl;
        }
    }
    else 
    {
        cout << margin3 << " LAPANGAN KOSONG!\n\n";
    }
    if (isfull()) 
    {
        cout << margin3 << " LAPANGAN PENUH!!!\n\n";
    }
}

void berhasil() 
{

    char input;

    if (!isfull()) 
    {
        pelanggan* node = new pelanggan();

        cout << endl;
        cout << margintittle3 << "+--------------------------------------------+\n";
        cout << margintittle3 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
        cout << margintittle3 << "+--------------------------------------------+\n\n";
        cout << marginsub3 << " -= LAPANGAN C =-\n";
        cout << margin3 << " Masukkan identitas penyewa\n\n";
        cout << margin3 << " Nama        : ";
        cin.ignore();
        getline(cin, node->nama);
        cout << margin3 << " Tanggal     : ";
        getline(cin, node->tanggal);
        cout << margin3 << " Telp        : ";
        getline(cin, node->telp);
        cout << margin3 << " Waktu (Jam) : ";
        cin >> node->waktu;
        cout << endl; 
        cout << margin3 << " Data anda sudah tersimpan\n";

        cout << margin3 << " Apakah anda ingin mengubah data? (Y/N) : \n\n";
        cout << margin3 << " Jika tidak akan kembali ke menu utama\n";
        cout << margin3 << " Answer : ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            system("cls");
            MenuGagal();
        }
        else if (input == 'N' || input == 'n')
        {
            tempatc[topC] = node;
            topC++;
            cout << endl;
            system("cls");
            Menu();
        }
    }
    else 
    {
        cout << margin3 << " LAPANGAN C PENUH!!!\n";

        cout << margin3 << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin3 << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }
}

void updateC()
{
    cout << endl;
    cout << margintittle3 << "+--------------------------------------------+\n";
    cout << margintittle3 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle3 << "+--------------------------------------------+\n\n";

    if (isempty())
    {
        cout << margin3 << " DATA KOSONG!\n";
        return;
    }

    string carinama;
    cout << margin3 << " Masukkan nama penyewa yang ingin diubah: ";
    cin.ignore();
    getline(cin, carinama);

    pelanggan* pelangganToUpdate = searchingC(carinama);
    if (pelangganToUpdate)
    {
        cout << margin3 << " Masukkan data baru untuk " << carinama << ":\n";
        cout << margin3 << " Nama        : ";
        getline(cin, pelangganToUpdate->nama);
        cout << margin3 << " Tanggal     : ";
        getline(cin, pelangganToUpdate->tanggal);
        cout << margin3 << " Telp        : ";
        getline(cin, pelangganToUpdate->telp);
        cout << margin3 << " Waktu (Jam) : ";
        cin >> pelangganToUpdate->waktu;

        cout << margin3 << " Data berhasil diperbarui!\n";
    }
    else
    {
        cout << margin3 << " Penyewa tidak ditemukan!\n";
    }

    char input;
    cout << margin3 << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin3 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void hapusC() 
{
    cout << endl;
    cout << margintittle3 << "+--------------------------------------------+\n";
    cout << margintittle3 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle3 << "+--------------------------------------------+\n\n";

    char input;
    if (!isempty()) 
    {
        delete tempatc[0];
        for (int i = 0; i < topC - 1; i++) 
        {
            tempatc[i] = tempatc[i + 1];
        }
        topC--;
    }
    else 
    {
        cout << margin3 << " DATA KOSONG!" << endl;
        cout << margin3 << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin3 << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }

    cout << margin3 << " DATA TELAH TERHAPUS!!!\n\n";
    cout << margin3 << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin3 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void LapanganC() 
{
    berhasil();   
}

pelanggan* searchingC(const string carinama) 
{
    if (isempty()) 
    {
        return nullptr;
    }

    for (int i = 0; i < topC; ++i) 
    {
        if (tempatc[i]->nama == carinama) 
        {
            return tempatc[i];
        }
    }
    return nullptr;

    char input;
    cout << margin3 << " Balik ke Menu? (Y)" << endl;
    cout << margin3 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void sortC()
{
    if (isempty())
    {
        return;
    }
    for (int i = 0; i < topC - 1; i++) 
    {
        for (int j = 0; j < topC - i - 1; j++) 
        {
            if (tempatc[j]->nama > tempatc[j + 1]->nama) 
            {
                pelanggan* temp = tempatc[j];
                tempatc[j] = tempatc[j + 1];
                tempatc[j + 1] = temp;
            }
        }
    }
}

