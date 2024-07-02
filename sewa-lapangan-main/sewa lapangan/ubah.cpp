#include <iostream>
#include "struct.h"
#include "lapangan.h"
#include "menu.h"

using namespace std;

void ubah()
{
	string margintittle(36, ' ');
	string marginsub(50, ' ');
	string margin(38, ' ');
	string marginsub2(48, ' ');

	int inputs;
	char input;

	cout << endl;
	cout << margintittle << "+--------------------------------------------+\n";
	cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
	cout << margintittle << "+--------------------------------------------+\n\n";
	cout << marginsub2 << " -= MENU UBAH DATA =-\n\n";
	cout << margin << " Silahkan pilih lapangan :\n";
	cout << margin << " 1. Lapangan A\n";
	cout << margin << " 2. Lapangan B\n";
	cout << margin << " 3. lapangan C\n\n";
	cout << margin << " Pilih Menu : ";
	cin >> inputs;

	system("cls");

	if (inputs == 1) {
		updateA();
	}
	else if (inputs == 2) {
		updateB();
	}
	else if (inputs == 3) {
		updateC();
	}
	else {
		cout << endl;
		cout << margintittle << "+--------------------------------------------+\n";
		cout << margintittle << "|        -= APLIKASI SEWA LAPANGAN =-        |\n";
		cout << margintittle << "+--------------------------------------------+\n\n";
		cout << margin << " cuih salah input bos" << endl << endl;
	}

	cout << margin << " Ingin Balik ke Menu? (Y)" << endl;
	cout << margin << " Answer : ";
	cin >> input;
	if (input == 'Y' || input == 'y')
	{
		system("cls");
		Menu();
	}
	
}