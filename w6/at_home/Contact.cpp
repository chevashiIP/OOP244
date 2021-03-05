#include "Contact.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace sict {
	Contact::Contact()
	{
		name[0] = '\0';
		phoneNum = nullptr;
		noPhoneNum = 0;
	}
	Contact::Contact(const char* namestr, long long* phoneNumstr, int noPhoneNumstr)
	{
		if (isEmpty()==false) {
			strncpy(name, namestr, 19);
			noPhoneNum = noPhoneNumstr;
			if (noPhoneNum > 0) {
				long long *c = new long long[noPhoneNum];
				for (int i = 0; i < noPhoneNum; i++) {
					c[i] = phoneNumstr[i];
				}
				phoneNum = c;
			} else {
				phoneNum = nullptr;
			}
		}
		else {
			for (int i = 0; i < 21; i++) {
				name[i] = '\0';
			}
			phoneNum = nullptr;
			noPhoneNum = 0;
		}
	}
	Contact::~Contact()
	{
		delete[] phoneNum;
		phoneNum = nullptr;
	}
	bool Contact::isEmpty() const
	{
		bool ret = true;
		if (name[0] != '\0') {
			ret = false;
		}
		else if (phoneNum != nullptr) {
			ret = false;
		}
		return ret;
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
	Contact::Contact(const Contact& C){
		if (isEmpty() == false) {
			strncpy(name, C.name, 19);
			noPhoneNum = C.noPhoneNum;
			if (noPhoneNum > 0) {
				long long *c = new long long[noPhoneNum];
				for (int i = 0; i < noPhoneNum; i++) {
					c[i] = C.phoneNum[i];
				}
				phoneNum = c;
			} else {
				phoneNum = nullptr;
			}
		} else {
			for (int i = 0; i < 21; i++) {
				name[i] = '\0';
			}
			phoneNum = nullptr;
			noPhoneNum = 0;
		}
	}
	Contact & Contact::operator=(const Contact& C){
		// TODO: insert return statement here
		if (this != &C) {
			if (phoneNum != nullptr) {
				delete[] phoneNum;
				phoneNum = nullptr;
			}
			noPhoneNum = C.noPhoneNum;
			strncpy(name, C.name, 19);
			phoneNum = new long long[noPhoneNum];
			for (int i = 0; i < noPhoneNum; i++) {
				phoneNum[i] = C.phoneNum[i];
			}
		}
		return *this;
	}
	Contact & Contact::operator+=(const long long phoneNumber){
		// TODO: insert return statement here
		long long* temp;
		temp = new long long[noPhoneNum+1];
		for (int i = 0; i < noPhoneNum; i++) {
			temp[i] = phoneNum[i];
		}
		noPhoneNum++;
		if (phoneNum != nullptr) {
			delete[] phoneNum;
		}
		phoneNum = new long long[noPhoneNum];
		for (int g = 0; g < noPhoneNum; g++) {
			phoneNum[g] = temp[g];
		}
		phoneNum[noPhoneNum - 1] = phoneNumber;
		delete[] temp;
		return *this;
	}
}