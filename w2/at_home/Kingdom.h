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

#ifndef _244_KINGDOM_H_
#define _244_KINGDOM_H_

namespace sict{
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	void display(const Kingdom& pKingdom);
	void display(const Kingdom kingdoms[], size_t count);
}
#endif