/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Description
// Workshop 2 OOP244 in_lab
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {

	void display(struct Kingdom kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
		// TODO:definition for display(...) 
}