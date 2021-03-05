// TODO: add file header comments here

// TODO: add your headers here
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		makeEmpty();
	};

	void Passenger::makeEmpty() {
		m_name[0] = 0;
		m_destination[0] = 0;
	};

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char name[], const char destination[]) {
		if (name != nullptr && name[0] != '\0' &&
			destination != nullptr && destination[0] != '\0') {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
		} else {
			makeEmpty();
		}
	};
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return(m_name[0] == '\0' &&
			m_destination[0] == '\0'
			);
	};
	// TODO: implement display query here
	void Passenger::display() const {
		if (false == isEmpty()) {
			cout << m_name << " - " << m_destination << endl;
		} else {
			cout << "No passenger!" << endl;
		};
	};
}
