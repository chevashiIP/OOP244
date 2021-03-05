// TODO: add file header comments here
// TODO: add header file guard here
#ifndef _244_PASSENGER_H_
#define _244_PASSENGER_H_
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
	private:
		char m_name[33];
		char m_destination[33];
		int departureYear;
		int departureMonth;
		int departureDay;
	public:
		const char* name() const;
		void makeEmpty();
		Passenger();
		Passenger(const char* namestr, const char* destinationstr);
		Passenger(const char* namestr, const char* destinationstr, int year, int month, int day);
		bool canTravelWith(const Passenger& ) const;
		bool isEmpty() const;
		void display() const;
	};

};

#endif