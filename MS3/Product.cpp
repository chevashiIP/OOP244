#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Product.h"
using namespace std;

namespace AMA {
	void Product::name(const char* name)
	{
		if (nullptr != name) {
			m_name = new char[max_name_length + 1];
			strcpy(m_name, name);
		}
		else {
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
	double Product::cost() const
	{
		double cost = m_price;
		if (m_taxed) {
			cost = m_price + (m_price * tax_rate);
		}
		return cost;
	}
	void Product::message(const char * str)
	{
		this->m_error.message(str);
	}
	bool Product::isClear() const
	{
		return m_error.isClear();
	}
	Product::Product()
	{
		m_type = '\0';
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_quantity = 0;
		m_quantityNeeded = 0;
		m_price = 0;
		m_taxed = false;
	}
	Product::Product(const char * sku, const char * name, const char* unit, int quantity, bool taxed, double price, int quantityNeeded)
	{
		strcpy(m_sku, sku);
		m_name = new char(strlen(name) + 1);
		strcpy(m_name, name);
		strcpy(m_unit, unit);
		m_quantity = quantity;
		m_taxed = taxed;
		m_price = price;
		m_quantityNeeded = quantityNeeded;
	}
	Product::Product(const Product & other)
	{
		if (!other.isEmpty()) {
			strncpy(m_sku, other.m_sku, max_sku_length + 1);
			m_name = new char(strlen(other.m_name) + 1);
			strcpy(m_name, other.m_name);
			strcpy(m_unit, other.m_unit);
			m_quantity = other.m_quantity;
			m_taxed = other.m_taxed;
			m_price = other.m_price;
			m_quantityNeeded = other.m_quantityNeeded;
		}
	}
	Product & Product::operator=(const Product & other)
	{
		if (this != &other) {
			strncpy(m_sku, other.m_sku, max_sku_length + 1);
			strcpy(m_name, other.m_name);
			strcpy(m_unit, other.m_unit);
			m_quantity = other.m_quantity;
			m_taxed = other.m_taxed;
			m_price = other.m_price;
			m_quantityNeeded = other.m_quantityNeeded;
		}
		return *this;
	}

	Product::~Product()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	std::fstream & Product::store(std::fstream & file, bool newLine) const
	{
		if (file.is_open()) {
			file << m_type << ","
				<< Product::sku() << ","
				<< Product::name() << ","
				<< Product::taxed() << ","
				<< Product::price() << ","
				<< Product::quantity() << ","
				<< Product::unit() << ","
				<< Product::qtyNeeded();
			if (newLine) {
				file << std::endl;
			}

		}
		return file;
	}
	std::fstream & Product::load(std::fstream & file)
	{
		Product temp;
		if (file.is_open()) {
			std::cout << "Sku: ";
			std::cin >> temp.m_sku;
			std::cout << std::endl << "Name: ";
			std::cin >> temp.m_name;
			std::cout << std::endl << "Unit: ";
			std::cin >> temp.m_unit;
			std::cout << std::endl << "Taxed: ";
			std::cin >> temp.m_taxed;
			std::cout << std::endl << "Price: ";
			std::cin >> temp.m_price;
			std::cout << std::endl << "Quantity on hand: ";
			std::cin >> temp.m_quantity;
			std::cout << std::endl << "Quantity Needed: ";
			std::cin >> temp.m_quantityNeeded;
		}
		else {
			std::cout << "File is not open";
		}
		*this = temp;
		return file;
	}
	std::ostream & Product::write(std::ostream & os, bool linear) const
	{
		if (m_error.isClear()) {
			if (linear) {
				// os.setf(std::ios::left);
				os << std::setw(7) << std::left << Product::sku() << "|";
				os << std::setw(20) << std::left << Product::name() << "|";
				os << std::setw(7) << std::fixed << std::right << std::setprecision(2) << Product::cost() << "|";
				os << std::setw(4) << std::right << Product::quantity() << "|";
				os << std::setw(10) << std::left << Product::unit() << "|";
				os << std::setw(4) << std::right << Product::qtyNeeded() << "|";

			}
			else {
				os << "Sku: " << Product::sku() << std::endl;
				os << "Name: " << Product::name() << std::endl;
				os << "Price: " << std::fixed << Product::price() << std::endl;
				os << "Price after tax: ";
				if (Product::taxed()) {
					os << std::fixed << Product::cost() << std::endl;
				}
				else {
					os << "N/A" << std::endl;
				}
				os << "Quantity On Hand: " << Product::quantity() << " " << Product::unit() << std::endl;
				os << "Quantity Needed: " << Product::qtyNeeded();

			}
		}
		else {
			os << m_error.message();
		}
		return os;
	}
	std::istream & Product::read(std::istream & is)
	{
		char temp_tax;
		double temp_price;
		int temp_inventory;
		int temp_qtyNeed;
		bool valid = false;
		std::cout << " Sku: ";
		is >> m_sku;
		std::cout << " Name (no spaces): ";
		is >> m_name;
		std::cout << " Unit: ";
		is >> m_unit;
		std::cout << " Taxed? (y/n): ";
		is >> temp_tax;
		std::cout << " Price: ";
		is >> temp_price;
		std::cout << " Quantity on hand: ";
		is >> temp_inventory;
		std::cout << " Quantity needed: ";
		is >> temp_qtyNeed;

		if (temp_tax == 'y' || temp_tax == 'Y') {
			m_taxed = true;
			valid = true;
		}
		if (temp_tax == 'n' || temp_tax == 'N') {
			m_taxed = false;
			valid = true;
		}
		if (!valid) {
			is.std::istream::setstate(std::ios::failbit);
			m_error.ErrorState::message("Only(Y)es or (N)o are acceptable");
		}

		if (0 > temp_price) {
			is.std::istream::setstate(std::ios::failbit);
			m_error.ErrorState::message("Invalid Price Entry");
		}
		else {
			m_price = temp_price;
		}

		if (0 > temp_inventory) {
			is.std::istream::fail();
			m_error.ErrorState::message("Invalid Quantity Entry");
		}
		else {
			m_quantity = temp_inventory;
		}

		if (0 > temp_qtyNeed) {
			is.std::istream::fail();
			m_error.ErrorState::message("Invalid Quantity Needed Entry");
		}
		else {
			m_quantityNeeded = temp_qtyNeed;
		}

		return is;
	}
	bool Product::operator==(const char * sku) const
	{
		return !strcmp(m_sku, sku);
	}
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
	bool Product::operator>(const char * sku) const
	{
		if (m_sku > sku) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Product::operator>(const Product & other) const
	{
		if (m_name > other.name()) {
			return true;
		}
		else {
			return false;
		}
	}
	int Product::operator+=(int quantity)
	{
		if (quantity > 0) {
			m_quantity += quantity;
		}
		return m_quantity;
	}
	std::ostream & operator<<(std::ostream & os, const Product & other)
	{
		other.write(os, true);
		return os;
	}
	std::istream & operator>>(std::istream & is, Product & other)
	{
		other.read(is);
		return is;
	}
	double operator+=(double & cost, const Product & other)
	{
		return (cost + other.total_cost());
	}
}