// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		denum = -1;
	};
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d > 0) {
			num = n;
			denum = d;
			reduce();
		}
		else {
			denum = -1;
			num = -1;
		};
	};
	// TODO: implement the max query
	int Fraction::max() const {
		return (num >= denum) ? num : denum;
	};
	// TODO: implement the min query
	int Fraction::min() const {
		return (num >= denum) ? denum : num;
	};
	// gcd returns the greatest common divisor of num and denum
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denuminator
		int mx = max();  // max of numerator and denuminator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int tmpnum = gcd();
		num /= tmpnum;
		denum /= tmpnum;
	};
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()){
			cout << "no fraction stored";
		}
		else {
			if (denum == 1) {
				cout << num;
			}
			else {
				cout << num << "/" << denum;
			}
		}
	};
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const{
		return denum == -1;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction temp;
		if (isEmpty() || rhs.isEmpty()){
			Fraction();
		}
		else {
			temp.num = (num * rhs.denum) + (denum * rhs.num);
			temp.denum = denum * rhs.denum;
		}
		return temp;
	}

	
	//overloading *
	Fraction Fraction::operator*(const Fraction& rhs)
	{
		Fraction temp(num * rhs.num, denum * rhs.denum);
		return temp;

	}

	//overloading ==
	bool Fraction::operator==(const Fraction& g)
	{
		return (num == g.num && denum == g.denum);
	}

	//overloading !=
	bool Fraction::operator!=(const Fraction& rhs) {
		bool Return = true;
		if (isEmpty() ||
			rhs.isEmpty() ||
			num*rhs.denum == rhs.num * denum)
			Return = false;
		return Return;
	}

	//overloading +=
	Fraction Fraction::operator+=(const Fraction& rhs)
	{
		num = num *rhs.denum + rhs.num * denum;
		denum = denum * rhs.denum;
		reduce();
		return*this;

	}

};
