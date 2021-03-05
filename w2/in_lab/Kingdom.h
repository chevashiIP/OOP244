/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef _244_KINGDOM_H_
#define _244_KINGDOM_H_


// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		public:
			char m_name[32];
			long int m_population;
	};

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(struct Kingdom kingdom);


}

#endif