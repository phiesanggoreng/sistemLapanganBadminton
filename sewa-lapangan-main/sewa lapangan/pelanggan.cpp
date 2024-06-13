#include <iostream>
#include "struct.h"
#include "pelanggan.h"
#include "menu.h"

void DaftarPelanggan()
{
	viewA();
	viewB();
	view();

	char input;

	cout << " Apakah ingin balik ke menu awal ? (Y)\n";
	cout << " ";
	cin >> input;

	if (input == 'Y' || input == 'y')
	{
		system("cls");
		Menu();
	}
}