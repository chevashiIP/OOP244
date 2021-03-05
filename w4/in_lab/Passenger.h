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
		void makeEmpty();
	public:
		Passenger();
		Passenger(const char* name, const char* dest);
		bool isEmpty() const;
		void display() const;
	};

};

#endif