#include <iostream>
#include "struct.h"
#include "lapangan.h"
#include "pelanggan.h"

void MenuGagal()
{
	cout << "DATA ANDA TELAH TERHAPUS, SILAHKAN ISI ULANG!\n\n";

	int input;

	cout << " -= APLIKASI SEWA LAPANGAN =- \n\n";
	cout << " Silahkan Pilih Lapangan : \n";
	cout << " 1. Lapangan A \n";
	cout << " 2. Lapangan B \n";
	cout << " 3. Lapangan C \n\n";
	cout << " Pilih Menu Lainya :\n";
	cout << " 4. Daftar Pelanggan\n\n";
	cout << " Pilih menu : ";
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
	else
	{
		DaftarPelanggan();
	}
}