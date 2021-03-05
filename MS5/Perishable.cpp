#include<iostream>
#include <cstring>
#include <iomanip>

#include "Perishable.h"


using namespace std;

namespace AMA {
	Perishable::Perishable() : Product('P')
	{
		m_error.clear();
	}
	//Adds a date of expire to fail.
	std::fstream & Perishable::store(std::fstream& file, bool newLine) const
	{
		Product::store(file, false);
		file << ",";
		file << m_expire;
		if (newLine == true)
		{
			file << '\n';
		}
		return file;
	}
	//adds to load function ability to read the date of expire
	std::fstream & Perishable::load(std::fstream & file)
	{
		Product::load(file);
		m_expire.read(file);
		file.ignore();
		return file;

	}
	//add expiry date in console output
	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		Product::write(os, linear);
		if (isClear() && !isEmpty())
		{
			if (linear)
				m_expire.write(os);
			else
			{
				os << "\n Expiry date: ";
				m_expire.write(os);
			}
		}
		return os;
	}
	//read the date of expire for perishable product, checks for errors and is good, adds the expire date to object.
	std::istream & Perishable::read(std::istream & is)
	{
		is.clear();
		Product::read(is);
		if (m_error.isClear()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			m_expire.read(is);
		}

		if (m_expire.errCode() == CIN_FAILED) {
			m_error.clear();
			m_error.message("Invalid Date Entry");
		}
		if (m_expire.errCode() == YEAR_ERROR) {
			m_error.message("Invalid Year in Date Entry");
		}
		if (m_expire.errCode() == MON_ERROR) {
			m_error.clear();
			m_error.message("Invalid Month in Date Entry");
		}
		if (m_expire.errCode() == DAY_ERROR) {
			m_error.clear();
			m_error.message("Invalid Day in Date Entry");
		}
		if (m_expire.errCode()) {
			is.setstate(std::ios::failbit);
		}
		if (m_expire.errCode() != CIN_FAILED && m_expire.errCode() != YEAR_ERROR && m_expire.errCode() != MON_ERROR && m_expire.errCode() != DAY_ERROR) {
			m_error.clear(); 
		}

		return is;

	}
	const Date & Perishable::expiry() const
	{
		return m_expire;
	}
}