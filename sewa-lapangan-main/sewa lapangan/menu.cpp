#include <iostream>
#include "struct.h"
#include "lapangan.h"
#include "pelanggan.h"

void Menu()
{
	string margintittle(36, ' ');
	string marginsub(50, ' ');
	string margin(38, ' ');
	int input;

	cout << endl;
	cout << margintittle << "+--------------------------------------------+\n";
	cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
	cout << margintittle << "+--------------------------------------------+\n\n";
	cout << margin << " Silahkan Pilih Lapangan : \n";
	cout << margin << " 1. Lapangan A \n";
	cout << margin << " 2. Lapangan B \n";
	cout << margin << " 3. Lapangan C \n\n";
	cout << margin << " Pilih Menu Lainya :\n";
	cout << margin << " 4. Daftar Pelanggan\n";
	cout << margin << " 5. Ubah Data Pelanggan\n";
	cout << margin << " 6. Cari Data Pelanggan\n";
	cout << margin << " 7. Hapus Data Pelanggan\n\n";
	cout << margin << " Pilih menu : ";
	cin >> input;

	system("cls");

	if (input == 1)
	{
		LapanganA();
	}
	else if (input == 2)
	{
		LapanganB();
	}
	else if (input == 3)
	{
		LapanganC();
	}
	else if (input == 4)
	{
		DaftarPelanggan();
	}
	else if (input == 5)
	{
		ubah();
	}
	else if (input == 6)
	{
		searching();
	}
	else
	{
		hapus();
	}
}