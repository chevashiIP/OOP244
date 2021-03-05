/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include "CRA_Account.h"


using namespace std;
using namespace sict;


namespace sict{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		int num = sin;
		int sum = 0;
		stack<int> digitstack;
		while (num > 0) {
			int digit = num%10;
			num = num / 10;
			digitstack.push(digit);
			sum = sum + digit;
		}
		if (sin >= min_sin && sin <= max_sin && strlen(familyName) != 0 && strlen(givenName) != 0 && sum % 10 == 0)
		{
			this->lastName = new char[(strlen(familyName))];
			this->firstName = new char[(strlen(givenName))];
			this->firstName = strncpy(firstName, givenName, sizeof(firstName));
			this->lastName = strncpy(lastName, familyName, sizeof(lastName));
			this->sin = sin;
			for (int i = 0; i < max_yrs; i++) {
				this->year[i] = 0;
				this->balance[i] = 0;
			}
		}
		else {
			this->sin = 0;
		}
	};
	void CRA_Account::display() const{
		if (0 != sin && nullptr != lastName && nullptr != firstName)
		{
			 cout << "Family Name: " << this->lastName <<  endl;
			 cout << "Given Name : " << this->firstName <<  endl;
			 cout << "CRA Account: " << this->sin <<  endl;
		}
		else
		{
			 cout << "Account object is empty!" <<  endl;
		};
		for (int i = 0; i < max_yrs; i++) {
			if (balance[i] > 2) {
				cout << "Year (" << this->year[i] << ") balance owing: " << fixed << setprecision(2) << this->balance[i] << endl;
			}
			else if (balance[i] < -2) {
				cout << "Year (" << this->year[i] << ") refund due: " << fixed << setprecision(2) << fabs(this->balance[i]) << endl;
			}
			else {
				cout << "Year (" << this->year[i] << ") No balance owing or refund due!" << endl;
			};
		}
	};

	bool CRA_Account::isEmpty() const{
		if ((0 == sin || sin <= sict::min_sin || sin >= sict::max_sin))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

	void CRA_Account::set(int year, double balance) {
			for (int i = 0; i < max_yrs; i++) {
					if(this->year[i] == 0){
						this->year[i] = year;
						this->balance[i] = balance;
						break;
					};
			};
	};
};
