#ifndef _244_CONTACT_H_
#define _244_CONTACT_H_

namespace sict {
	class Contact {
		char name[20];
		long long* phoneNum;
		int noPhoneNum;
		void makeEmpty();
	public:
		Contact();
		Contact(const char* namestr, long long* phoneNumbers, int noPhoneNumstr);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}



#endif
