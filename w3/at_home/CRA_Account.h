/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef _244_CRA_ACCOUNT_H_
#define _244_CRA_ACCOUNT_H_
#define max_yrs 4
using namespace std;


namespace sict{
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_name_length = 40;
	class CRA_Account
	{
		char* lastName;
		char* firstName;
		int sin;
		int year[max_yrs];
		double balance[max_yrs];
		int yearreturn;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void display() const;
		bool isEmpty() const;
		void set(int year, double balance);
	};

};
#endif