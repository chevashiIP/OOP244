// TODO: header file guard
#ifndef _244_FRACTION_H_
#define _244_FRACTION_H_


// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int num;
		int denum;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int n, int d);
		void display() const;
		bool isEmpty() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator+=(const Fraction& rhs);
		Fraction operator*(const Fraction& rhs);
		bool operator==(const Fraction& rhs);
		bool operator!=(const Fraction& rhs);
	};
}

#endif