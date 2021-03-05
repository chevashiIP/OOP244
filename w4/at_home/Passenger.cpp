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
	
	const char * Passenger::name() const
	{
		return m_name;
	}

	void Passenger::makeEmpty() {
		m_name[0] = 0;
		m_destination[0] = 0;
		departureDay = 0;
		departureMonth = 0;
		departureYear = 0;
	};

	// TODO: implement the constructor with 2 parameters here

	Passenger::Passenger(const char* namestr, const char* destinationstr) {
		if (m_name != nullptr && m_name[0] != '\0' &&
			m_destination != nullptr && m_destination[0] != '\0') {
			strcpy(m_name, namestr);
			strcpy(m_destination, destinationstr);
			departureDay = 1;
			departureMonth = 7;
			departureYear = 2017;
		}
		else {
			makeEmpty();
		}
	};

	Passenger::Passenger(const char* namestr, const char* deststr, int year, int month, int day) {
		if (namestr != nullptr && namestr[0] != '\0' &&
			deststr != nullptr && deststr[0] != '\0' &&
			(year >= 2017 && year <= 2020) &&
			(month >= 1 && month <= 12) &&
			(day >= 1 && day <= 31)) {
			strcpy(m_name, namestr);
			strcpy(m_destination, deststr);
			departureDay = day;
			departureMonth = month;
			departureYear = year;
		}
		else
			makeEmpty();
	}

	bool Passenger::canTravelWith(const Passenger& another) const
	{
		// return true if 
		return (std::strcmp(this->m_destination, another.m_destination) == 0) // destinations are the same
			&& this->departureYear == another.departureYear // and the year is the same 
			&& this->departureMonth == another.departureMonth // and the month is the same
			&& this->departureDay == another.departureDay; // and the day is the same

										 // ie. return false if even one of these conditions do not hold        
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return(m_name[0] == '\0' &&
			m_destination[0] == '\0'&&
			departureDay == '\0' &&
			departureMonth == '\0' &&
			departureYear == '\0');
	};
	// TODO: implement display query here
	void Passenger::display() const {
		if (false == isEmpty()) {
			cout << m_name << " - " << m_destination << " on ";
			cout << this->departureYear << "/";
			cout << '0' << this->departureMonth << "/";
			cout << this->departureDay << endl;
		} else {
			cout << "No passenger!" << endl;
		};
	};
}
