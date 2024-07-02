#include <iostream>
#include "struct.h"
#include "lapangan.h"
#include "pelanggan.h"

void MenuGagal()
{
	string margintittle(36, ' ');
	string marginsub(50, ' ');
	string margin(38, ' ');
	int input;
	
	cout << endl;
	cout << margintittle << "+--------------------------------------------+\n";
	cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
	cout << margintittle << "+--------------------------------------------+\n\n";
	cout << margin << " DATA ANDA TELAH TERHAPUS,\n";
	cout << margin << " SILAHKAN ISI ULANG!\n\n";
	cout << margin << " Silahkan Pilih Lapangan : \n";
	cout << margin << " 1. Lapangan A \n";
	cout << margin << " 2. Lapangan B \n";
	cout << margin << " 3. Lapangan C \n\n";
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
	else 
	{
		LapanganC();
	}
}