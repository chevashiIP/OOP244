#ifndef PRODUCT_H
#define PRODUCT_H

#include "iostream"
#include "ErrorState.h"
#include "iProduct.h"

#define max_sku_length 7
#define max_name_length 75
#define max_unit_length 10
#define tax_rate 0.13


namespace AMA {
	class Product : public iProduct {
		char m_type;
		char m_sku[max_sku_length + 1];
		char m_unit[max_unit_length + 1];
		char* m_name;
		int m_quantity;
		int m_quantityNeeded;
		double m_price;
		bool m_taxed ;
	protected:
		ErrorState m_error;
		void name(const char* );
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
		
	public:
		Product(char type = 'N');
		Product(const char *, const char *, const char* , int quantity = 0, bool taxed = false, double price = 0.0, int quantityNeeded = 0);
		Product(const Product& other);
		Product& operator=(const Product& other);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		char type() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
	iProduct* CreateProduct();
}


#endif // !PRODUCT_H

