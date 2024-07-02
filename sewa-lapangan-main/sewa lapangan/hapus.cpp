#include <iostream>
#include "struct.h"
#include "lapangan.h"

using namespace std;

void hapus()
{
	int input;
	string margintittle(36, ' ');
	string marginsub(50, ' ');
	string margin(38, ' ');
	string marginsub2(48, ' ');

	cout << endl;
	cout << margintittle << "+--------------------------------------------+\n";
	cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
	cout << margintittle << "+--------------------------------------------+\n\n";
	cout << marginsub2 << " -= MENU HAPUS DATA =-\n\n";
	cout << margin << " Silahkan pilih lapangan :\n";
	cout << margin << " 1. Lapangan A\n";
	cout << margin << " 2. Lapangan B\n";
	cout << margin << " 3. lapangan C\n\n";
	cout << margin << " Pilih Menu : ";
	cin >> input;

	system("cls");

	if (input == 1)
	{
		hapusA();
	}
	else if (input == 2)
	{
		hapusB();
	}
	else if (input == 3)
	{
		hapusC();
	}

}