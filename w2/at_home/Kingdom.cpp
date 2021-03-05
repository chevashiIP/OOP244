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
namespace sict{
	void display(const Kingdom& pKingdom) {
		cout << pKingdom.m_name << ", " << "population " << pKingdom.m_population << endl;
	}

	void display(const Kingdom kingdoms[], size_t count) {
		int total = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (size_t i = 0; i < count; i++) {
			cout << i + 1 << ". " << kingdoms[i].m_name << ", population " << kingdoms[i].m_population << endl;
			total += kingdoms[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}
}