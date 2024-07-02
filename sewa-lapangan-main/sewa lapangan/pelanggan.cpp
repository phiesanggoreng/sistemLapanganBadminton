#include <iostream>
#include "struct.h"
#include "pelanggan.h"
#include "menu.h"

void DaftarPelanggan()
{
	string margintittle(36, ' ');
	string marginsub(50, ' ');
	string margin(38, ' ');
	char input;

	cout << endl;
	cout << margintittle << "+--------------------------------------------+\n";
	cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
	cout << margintittle << "+--------------------------------------------+\n\n";

	viewA();
	viewB();
	viewC();

	cout << margin << " Apakah ingin balik ke menu awal ? (Y)\n";
	cout << margin << " Answer : ";
	cin >> input;

	if (input == 'Y' || input == 'y')
	{
		system("cls");
		Menu();
	}
}