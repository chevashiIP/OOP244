/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Description
// Workshop 2 OOP244 at_home
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array
	Kingdom *pKingdom = nullptr;
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		// add code to accept user input for Kingdom i
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element
	count = count + 1;
	Kingdom* memKingdom;
	memKingdom = new Kingdom[count];
	for (int i = 0; i < count - 1; i++) {
		memKingdom[i] = pKingdom[i];
	};
	delete[] pKingdom;
	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n";

	cout << "Kingdom #" << count << ": " << endl;
	read(memKingdom[count - 1]);
	cout << "==========\n" << endl;
	display(memKingdom, count);
	cout << endl;
	delete[] memKingdom;
	return 0;
}
void read(Kingdom& pkingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(pkingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << pkingdom.m_name << ": ";
	cin >> pkingdom.m_population;
	cin.ignore(2000, '\n');
}