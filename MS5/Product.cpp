#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include "iProduct.h"
using namespace std;

namespace AMA {
	//name function receives the reference of name and allocates enough memory to copy the reference to current m_name object
	void Product::name(const char* name)
	{
		if (name != nullptr)
		{
			int length = strlen(name);
			m_name = new char[length];
			for (int i = 0; i < length; ++i)
			{
				m_name[i] = name[i];
			}
			m_name[length] = '\0';
		} else if (name == nullptr){
			delete[] m_name;
			m_name = nullptr;
		}
	}

	const char * Product::name() const
	{
		return m_name;
	}
	const char * Product::sku() const
	{
		return m_sku;
	}
	const char * Product::unit() const
	{
		return m_unit;
	}
	bool Product::taxed() const
	{
		return m_taxed;
	}
	double Product::price() const
	{
		return m_price;
	}
	//returns cost of the product with/without taxes applied
	double Product::cost() const
	{
		double cost = m_price;
		if (m_taxed) {
			cost = m_price + (m_price * tax_rate);
		}
		return cost;
	}
	//receives the reference error string and applies to the message by calling message function from ErrorState
	void Product::message(const char * str)
	{
		this->m_error.message(str);
	}
	//return "is clear" if there's no errors
	bool Product::isClear() const
	{
		return m_error.isClear();
	}
	//default constructor.
	Product::Product(char type)
	{
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_quantity = 0;
		m_quantityNeeded = 0;
		m_price = 0.0;
		m_taxed = false;
	}
	//7 argument constructor that receives the data and allocates memory.
	Product::Product(const char * sku, const char * name, const char* unit, int quantity, bool taxed, double price, int quantityNeeded)
	{

		strncpy(m_sku, sku, max_sku_length);
		m_sku[max_sku_length] = '\0';
		Product::name(name);
		strncpy(m_unit, unit, max_unit_length);
		m_unit[max_unit_length] = '\0';
		m_quantity = quantity;
		m_taxed = taxed;
		m_price = price;
		m_quantityNeeded = quantityNeeded;
	}
	//copy constructor that copies the referenced object to current object.
	Product::Product(const Product & other)
	{
		*this = other;
	}
	//copy constructor replaces current object with the copy of referenced
	Product & Product::operator=(const Product & other)
	{
		if (this != &other)
		{
			m_type = other.m_type;
			strncpy(m_sku, other.sku(), max_sku_length);
			m_sku[strlen(other.m_sku)] = '\0';

			strncpy(m_unit, other.unit(), max_unit_length);
			m_unit[strlen(other.m_unit)] = '\0';

			name(other.m_name);

			m_quantity = other.m_quantity;
			m_quantityNeeded = other.m_quantityNeeded;
			m_price = other.m_price;
			m_taxed = other.m_taxed;
		}

		return *this;
	}

	//store function writes data in file with seperation of commas.
	std::fstream & Product::store(std::fstream & file, bool newLine) const
	{
		file << m_type << ',' << m_sku << ',' << m_name << ',' << m_unit << ',' << m_taxed << ',' << m_price << ',' << m_quantity << ',' << m_quantityNeeded;
			if (newLine) {
				file << std::endl;
			}
		return file;
	}
	//load function is loading data from the file, ignoring commas.
	std::fstream & Product::load(std::fstream & file)
	{
		char sku[max_sku_length];
		char name[max_name_length];
		char unit[max_unit_length];
		double price;
		int quantity;
		int quantityNeeded;
		char taxed;
		bool tempTaxed;

		if (file.is_open())
		{
			file.getline(sku, max_sku_length, ',');
			sku[strlen(sku)] = '\0';

			file.getline(name, max_name_length, ',');
			name[strlen(name)] = '\0';

			file.getline(unit, max_unit_length, ',');
			unit[strlen(unit)] = '\0';

			file >> taxed;

			if (taxed == '1') {
				tempTaxed = true;
			}
			else if (taxed == '0') {
				tempTaxed = false;
			}

			file.ignore();

			file >> price;
			file.ignore();

			file >> quantity;
			file.ignore();

			file >> quantityNeeded;
			file.ignore();

			*this = Product(sku, name, unit, quantity, tempTaxed, price, quantityNeeded);
		}

		return file;

	}
	//write function displays the data in linear or non-linear way
	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		if (m_error.isClear()) {
			if (linear) {
				
				os << std::setw(7) << std::left << Product::m_sku << "|";
				os << std::setw(20) << std::left << Product::m_name << "|";
				os << std::setw(7) << std::fixed << std::right << std::setprecision(2) << Product::cost() << "|";
				os << std::setw(4) << std::right << Product::m_quantity << "|";
				os << std::setw(10) << std::left << Product::m_unit << "|";
				os << std::setw(4) << std::right << Product::m_quantityNeeded << "|";

			}
			else {
				os << " Sku: " << Product::m_sku << std::endl;
				os << " Name (no spaces): " << Product::m_name << std::endl;
				os << " Price: " << std::fixed << Product::m_price << std::endl;
				os << " Price after tax: ";
				if (Product::taxed()) {
					os << std::fixed << Product::cost() << std::endl;
				}
				else {
					os << " N/A" << std::endl;
				}
				os << " Quantity on Hand: " << Product::m_quantity << " " << Product::unit() << std::endl;
				os << " Quantity needed: " << Product::m_quantityNeeded	;

			} 
		}
		else {
			os << m_error.message();
		}
		return os;
	}
	//read function accepts user input and checks for errors in taxed, price, quantity and quantityneeded for acceptable data. If data is not acceptable display the error message.
	std::istream & Product::read(std::istream & is)
	{
		

		char taxed;
		char * names = new char[max_name_length + 1];

		std::cout << " Sku: ";
		is >> m_sku;

		std::cout << " Name (no spaces): ";
		is >> names;
		name(names);

		std::cout << " Unit: ";
		is >> m_unit;

		std::cout << " Taxed? (y/n): ";
		is >> taxed;
		if (taxed == 'y' || taxed == 'Y') {
			m_taxed = true;
		}
		else if (taxed == 'n' || taxed == 'N') {
			m_taxed = false;
		}
		else {
			is.setstate(std::ios::failbit);
			m_error.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) {
			std::cout << " Price: ";
			is >> m_price;
			if (is.fail()) {
				m_error.message("Invalid Price Entry");
			}
		}
		if (!is.fail()) {
			std::cout << " Quantity on hand: ";
			is >> m_quantity;
			if (is.fail()) {
				m_error.message("Invalid Quantity Entry");
			}
		}
		if (!is.fail()) {
			std::cout << " Quantity needed: ";
			is >> m_quantityNeeded;
			cin.ignore();
			if (is.fail()) {
				m_error.message("Invalid Quantity Needed Entry");
			}
		}
		if (!is.fail())
		{
			m_error.clear();
		}
		return is;
	}
	bool Product::operator==(const char * sku) const
	{
		return !strcmp(m_sku, sku);
	}
	//returns taxed or non-taxed total of prroduct
	double Product::total_cost() const
	{
		double total = m_price * m_quantity;
		if (m_taxed) {
			total += ((m_price* m_quantity) * tax_rate);
		}
		return total;
	}
	void Product::quantity(int quantity)
	{
		m_quantity = quantity;
	}
	char Product::type() const
	{
		return m_type;
	}
	//return true if objects is in safe empty space
	bool Product::isEmpty() const
	{
		if (m_sku[0] == '\0' && m_type == '\0' && m_name == nullptr && m_unit == '\0' && m_price == 0 && m_quantityNeeded == 0 && m_quantity == 0 && m_taxed == false) {
			return true;
		}
		return false;
	}
	int Product::qtyNeeded() const
	{
		return m_quantityNeeded;
	}
	int Product::quantity() const
	{
		return m_quantity;
	}
	//return true if current sku is greater than reference
	bool Product::operator>(const char * sku) const
	{
		if (m_sku > sku) {
			return true;
		}
		else {
			return false;
		}
	}
	//return true if current object is bigger than the reference
	bool Product::operator>(const iProduct & other) const
	{
		if (m_name > other.name()) {
			return true;
		}
		else {
			return false;
		}
	}
	//adds items to already existed quantity
	int Product::operator+=(int quantity)
	{
		if (quantity > 0) {
			m_quantity += quantity;
		}
		return m_quantity;
	}
	//return os to write with true/false linear option
	std::ostream & operator<<(std::ostream & os, const iProduct & other)
	{
		return other.write(os, true);
	}
	//returns is to read function
	std::istream & operator>>(std::istream & is, iProduct & other)
	{
		return other.read(is);
	}
	
	double operator+=(double & cost, const iProduct & other)
	{
		return (cost + other.total_cost());
	}
	//destructor
	Product::~Product()
	{
		delete[] m_name;
	}
}