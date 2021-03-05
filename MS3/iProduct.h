#ifndef IPRODUCT_H
#define IPRODUCT_H

#include <iostream>
#include <fstream>

using namespace std;

namespace AMA{
	class iProduct {	
		public:
			virtual fstream& store(fstream& file, bool newLine = true) const = 0;
			virtual fstream& load(fstream& file) = 0;
			virtual ostream& write(ostream& os, bool linear) const = 0;
			virtual istream& read(istream& is) = 0;
			virtual bool operator==(const char*) const = 0;
			virtual double total_cost() const = 0;
			virtual const char* name() const = 0;
			virtual void quantity(int) = 0;
			virtual int qtyNeeded() const = 0;
			virtual int quantity() const = 0;
			virtual int operator+=(int) = 0;
			virtual bool operator>(const iProduct&) const = 0;
		};
		std::istream& operator>>(std::istream&, iProduct&);
		std::ostream& operator<<(std::ostream&, const iProduct&);
		double operator+=(double&, const iProduct&);
		iProduct* CreateProduct();
		iProduct* CreatePerishable();
}

#endif
