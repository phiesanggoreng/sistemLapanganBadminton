#include <iostream>
#include "struct.h"
#include "menu.h"
#include "lapangan.h"
#define max 3

using namespace std;

pelanggan* tempata[max];
int topA = 0;
string margintittle(36, ' ');
string marginsub(50, ' ');
string margin(38, ' ');

bool isfullA()
{
    return topA == max;
}

bool isemptyA()
{
    return topA == 0;
}

void viewA()
{
    cout << marginsub << " -= LAPANGAN A =- \n";

    if (!isemptyA())
    {
        sortA();

        for (int i = 0; i < topA; i++)
        {
            cout << margin << " " << i + 1 << ". Nama      : " << tempata[i]->nama << endl;
            cout << margin << "    Tanggal   : " << tempata[i]->tanggal << endl;
            cout << margin << "    Telp      : " << tempata[i]->telp << endl;
            cout << margin << "    Waktu     : " << tempata[i]->waktu << endl;
            cout << margin << "    Harga     : " << tempata[i]->waktu * tempata[i]->harga << endl << endl;
        }
    }
    else
    {
        cout << margin << " LAPANGAN KOSONG!\n\n";
    }
    if (isfullA())
    {
        cout << margin << " LAPANGAN PENUH!!!\n\n";
    }
}

void berhasilA()
{
    char input;

    if (!isfullA())
    {
        pelanggan* node = new pelanggan();

        cout << endl;
        cout << margintittle << "+--------------------------------------------+\n";
        cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
        cout << margintittle << "+--------------------------------------------+\n\n"; 
        cout << marginsub << " -= LAPANGAN A =-\n\n";
        cout << margin << " Masukkan identitas penyewa\n\n";
        cout << margin << " Nama        : ";
        cin.ignore();

        getline(cin, node->nama);
        cout << margin << " Tanggal     : ";
        getline(cin, node->tanggal);
        cout << margin << " Telp        : ";
        getline(cin, node->telp);
        cout << margin << " Waktu (Jam) : ";
        cin >> node->waktu;
        cout << endl;
        cout << margin << " Data anda sudah tersimpan\n";

        cout << margin << " Apakah anda ingin mengubah data? (Y/N) : \n\n";
        cout << margin << " Jika tidak akan kembali ke menu utama\n";
        cout << margin << " Answer : ";
        cin >> input;

        if (input == 'Y' || input == 'y')
        {
            system("cls");
            MenuGagal();
        }
        else
        {
            tempata[topA] = node;
            topA++;
            cout << endl;
            system("cls");
            Menu();
        }
    }
    else
    {
        cout << margin << " LAPANGAN A PENUH!!!\n";

        cout << margin << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }
}

void updateA()
{
    cout << endl;
    cout << margintittle << "+--------------------------------------------+\n";
    cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle << "+--------------------------------------------+\n\n";
    
    if (isemptyA())
    {
        cout << margin << " DATA KOSONG!\n";
        return;
    }

    string carinama;
    cout << margin << " Masukkan nama penyewa yang ingin diubah : ";

    cin.ignore();
    getline(cin, carinama);

    pelanggan* pelangganToUpdate = searchingA(carinama);
    if (pelangganToUpdate)
    {
        cout << margin << " Masukkan data baru untuk " << carinama << ":\n";
        cout << margin << " Nama        : ";
        getline(cin, pelangganToUpdate->nama);
        cout << margin << " Tanggal     : ";
        getline(cin, pelangganToUpdate->tanggal);
        cout << margin << " Telp        : ";
        getline(cin, pelangganToUpdate->telp);
        cout << margin << " Waktu (Jam) : ";
        cin >> pelangganToUpdate->waktu;

        cout << margin << " Data berhasil diperbarui!\n";
    }
    else
    {
        cout << margin << "Penyewa tidak ditemukan!\n";
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

void hapusA()
{
    cout << endl;
    cout << margintittle << "+--------------------------------------------+\n";
    cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
    cout << margintittle << "+--------------------------------------------+\n\n";

    char input;
    if (!isemptyA())
    {
        delete tempata[0];
        for (int i = 0; i < topA - 1; i++)
        {
            tempata[i] = tempata[i + 1];
        }
        topA--;
    }
    else
    {
        cout << margin << " DATA KOSONG!" << endl;
        cout << margin << " Ingin Balik ke Menu? (Y)" << endl;
        cout << margin << " Answer : ";
        cin >> input;
        if (input == 'Y' || input == 'y')
        {
            system("cls");
            Menu();
        }
    }

    cout << margin <<" DATA TELAH TERHAPUS!!!\n";
    cout << margin << " Ingin Balik ke Menu? (Y)" << endl;
    cout << margin << " Answer : ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        system("cls");
        Menu();
    }
}

void LapanganA()
{
    berhasilA();
}

pelanggan* searchingA(const string carinama)
{
    if (isemptyA())
    {
        return nullptr;
    }

    for (int i = 0; i < topA; ++i)
    {
        if (tempata[i]->nama == carinama)
        {
            return tempata[i];
        }
    }
    return nullptr;

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

void sortA()
{
    if (isemptyA())
    {
        return;
    }
    for (int i = 0; i < topA - 1; i++)
    {
        for (int j = 0; j < topA - i - 1; j++)
        {
            if (tempata[j]->nama > tempata[j + 1]->nama)
            {
                pelanggan* temp = tempata[j];
                tempata[j] = tempata[j + 1];
                tempata[j + 1] = temp;
            }
        }
    }
}
