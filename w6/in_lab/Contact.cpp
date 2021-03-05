#include "Contact.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace sict {
	void Contact::makeEmpty()
	{
		strcpy(name, "");
		phoneNum = nullptr;
		noPhoneNum = -1;

	}
	Contact::Contact()
	{
		makeEmpty();
	}
	Contact::Contact(const char* namestr, long long* phoneNumstr, int noPhoneNumstr)
	{

		if (namestr == nullptr || namestr[0] == '\0') {
			makeEmpty();
		}
		else {
			strncpy(name, namestr, 20);
		}
		if (phoneNumstr != nullptr && noPhoneNumstr != 0) {
			noPhoneNum = noPhoneNumstr;
			phoneNum = new long long(noPhoneNumstr);
			for (int a = 0; a < noPhoneNumstr; a++) {
				phoneNum[a] = phoneNumstr[a];
			}

		}
	}
	Contact::~Contact()
	{
		delete[] phoneNum;
	}
	bool Contact::isEmpty() const
	{
		return((name[0] == '\0' || (strcmp(name, "") == 0 && noPhoneNum == 0)));
	}
	void Contact::display() const
	{
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			int n = strlen(name);
			if (n <= 21) {
				cout << name << endl;
			}
			else
			{
				for (int i = 0; i < 19; i++) {
					cout << name[i];
				}
				cout << endl;
			}
			for (int i = 0; i < noPhoneNum; i++) {
				if (10000000000 <= phoneNum[i] && phoneNum[i] <= 999999999999) {
					cout << "(+" << phoneNum[i] / 10000000000 << ") "
						<< phoneNum[i] % 10000000000 / 10000000 << " "
						<< phoneNum[i] % 10000000 / 10000 << "-"
						<< phoneNum[i] % 10000000 % 10000 << endl;
				}
			}
		}
	}
}