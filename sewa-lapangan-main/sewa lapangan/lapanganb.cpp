#include <iostream>
#include "struct.h"
#include "menu.h"
#include "lapangan.h"
#define max 3

using namespace std;

pelanggan* tempatb[max];
int topB = 0;
string margintittle2(36, ' ');
string marginsub2(50, ' ');
string margin2(38, ' ');

bool isfullB()
{
    return topB == max;
}

bool isemptyB()
{
    return topB == 0;
}

void viewB()
{
    cout << endl;
    cout << marginsub2 << " -= LAPANGAN B =- \n";

    if (!isemptyB())
    {
        sortB();

        for (int i = 0; i < topB; i++)
        {
            cout << margin2 << " " << i + 1 << ". Nama      : " << tempatb[i]->nama << endl;
            cout << margin2 << "    Tanggal   : " << tempatb[i]->tanggal << endl;
            cout << margin2 << "    Telp      : " << tempatb[i]->telp << endl;
            cout << margin2 << "    Waktu     : " << tempatb[i]->waktu << endl;
            cout << margin2 << "    Harga     : " << tempatb[i]->waktu * tempatb[i]->harga << endl << endl;
        }
    }
    else
    {
        cout << margin2 << " LAPANGAN KOSONG!\n\n";
    }
    if (isfullB())
    {
        cout << margin2 << " LAPANGAN PENUH!!!\n\n";
    }
}

void berhasilB()
{

    char input;

    if (!isfullB())
    {
        pelanggan* node = new pelanggan();

        cout << endl;
        cout << margintittle2 << "+--------------------------------------------+\n";
        cout << margintittle2 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
        cout << margintittle2 << "+--------------------------------------------+\n\n";
        cout << marginsub2 << " -= LAPANGAN B =-\n";
        cout << margin2 << " Masukkan identitas penyewa\n\n";
        cout << margin2 << " Nama        : ";
        cin.ignore();

        getline(cin, node->nama);
        cout << margin2 << " Tanggal     : ";
        getline(cin, node->tanggal);
        cout << margin2 << " Telp        : ";
        getline(cin, node->telp);
        cout << margin2 << " Waktu (Jam) : ";
        cin >> node->waktu;
        cout << endl;
        cout << margin2 << " Data anda sudah tersimpan\n";

        cout << margin2 << " Apakah anda ingin mengubah data? (Y/N) : \n\n";
        cout << margin2 << " Jika tidak akan kembali ke menu utama\n";
        cout << margin2 << " Answer : ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            system("cls");
            MenuGagal();
        }
        else if (input == 'N' || input == 'n')
        {
            tempatb[topB] = node;
            topB++;
            cout << endl;
            system("cls");
            Menu();
        }
    }
    else
    {
        cout << margin2 << " LAPANGAN B PENUH!!!\n";

        cout << margin2 << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin2 << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }
}

void updateB()
{
    cout << endl;
    cout << margintittle2 << "+--------------------------------------------+\n";
    cout << margintittle2 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle2 << "+--------------------------------------------+\n\n";
    if (isemptyB())
    {
        cout << margin2 << " DATA KOSONG!\n";
        return;
    }

    string carinama;
    cout << margin2 << " Masukkan nama penyewa yang ingin diubah : ";

    cin.ignore();
    getline(cin, carinama);

    pelanggan* pelangganToUpdate = searchingB(carinama);
    if (pelangganToUpdate)
    {
        cout << margin2 << " Masukkan data baru untuk " << carinama << ":\n";
        cout << margin2 << " Nama        : ";
        getline(cin, pelangganToUpdate->nama);
        cout << margin2 << " Tanggal     : ";
        getline(cin, pelangganToUpdate->tanggal);
        cout << margin2 << " Telp        : ";
        getline(cin, pelangganToUpdate->telp);
        cout << margin2 << " Waktu (Jam) : ";
        cin >> pelangganToUpdate->waktu;

        cout << margin2 << " Data berhasil diperbarui!\n";
    }
    else
    {
        cout << margin2 << " Penyewa tidak ditemukan!\n";
    }

    char input;
    cout << margin2 << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin2 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void hapusB()
{
    cout << endl;
    cout << margintittle2 << "+--------------------------------------------+\n";
    cout << margintittle2 << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle2 << "+--------------------------------------------+\n\n";

    char input;
    if (!isemptyB())
    {
        delete tempatb[0];
        for (int i = 0; i < topB - 1; i++)
        {
            tempatb[i] = tempatb[i + 1];
        }
        topB--;
    }
    else
    {
        cout << margin2 << " DATA KOSONG!" << endl;
        cout << margin2 << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin2 << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }

    cout << margin2 << " DATA TELAH TERHAPUS!!!\n";
    cout << margin2 << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin2 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void LapanganB()
{
    berhasilB();
}

pelanggan* searchingB(const string carinama)
{
    if (isemptyB())
    {
        return nullptr;
    }

    for (int i = 0; i < topB; ++i)
    {
        if (tempatb[i]->nama == carinama)
        {
            return tempatb[i];
        }
    }
    return nullptr;

    char input;
    cout << margin2 << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin2 << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void sortB()
{
    if (isemptyB())
    {
        return;
    }
    for (int i = 0; i < topB - 1; i++)
    {
        for (int j = 0; j < topB - i - 1; j++)
        {
            if (tempatb[j]->nama > tempatb[j + 1]->nama)
            {
                pelanggan* temp = tempatb[j];
                tempatb[j] = tempatb[j + 1];
                tempatb[j + 1] = temp;
            }
        }
    }
}


