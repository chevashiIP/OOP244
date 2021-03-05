
#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_
  //
	int Date::compValue() const {
		return year * 372 + month * 31 + day;
	}
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	Date::Date(){
		MakeEmpty();
		nowErrorCode = NO_ERROR;
	}
	void Date::MakeEmpty() {
		year = 0;
		month = 0;
		day = 0;
	}
	Date::Date(int yer, int mon, int da){
		if ((mon < 1 || mon>12) || (da<1 || da>mdays(mon, yer) || (yer<min_year || yer>max_year))){
			MakeEmpty();
		} else {
			year = yer;
			month = mon;
			day = da;
			nowErrorCode = NO_ERROR;
		}
	}
	void Date::errCode(int errorCode) {
		nowErrorCode = errorCode;
	}
	int Date::errCode() const {
		return nowErrorCode;
	}
	bool Date::bad() const {
		if (nowErrorCode != 0) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator==(const Date & rhs) const{
		if (compValue() == rhs.compValue()) {
			return true; 
		} else {
			return false;
		}
	}
	bool Date::operator!=(const Date & rhs) const{
		if (compValue()!= rhs.compValue()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator<(const Date & rhs) const{
		if (compValue() < rhs.compValue()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator>(const Date & rhs) const{
		if (compValue() > rhs.compValue()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator<=(const Date & rhs) const{
		if (compValue() <= rhs.compValue()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Date::operator>=(const Date & rhs) const{
		if (compValue() >= rhs.compValue()) {
			return true;
		}
		else {
			return false;
		}
	}
	std::istream & Date::read(std::istream& istr){
		char slash;
		istr >> year >> slash >> month >> slash >> day;
		if (istr.fail()){
			MakeEmpty();
			errCode(CIN_FAILED);
		} else if (year > max_year || year < min_year) {
			MakeEmpty();
			errCode(YEAR_ERROR);
		} else if (1 > month || month > 12){
			MakeEmpty();
			errCode(MON_ERROR);
		} else if (day > mdays(month, year) || day < 1){
			MakeEmpty();
			errCode(DAY_ERROR);
		} else {
			errCode(NO_ERROR);
		}
		return istr;
	}
	std::ostream & Date::write(std::ostream& ostr) const{
		ostr << setfill(' ');
		ostr << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day;
		ostr << setfill(' ');
		return ostr;
	}
	//read
	std::istream & operator>>(std::istream& istr, Date& d) {
		return d.read(istr);
	}
	//write
	std::ostream & operator<<(std::ostream& ostr, const Date& d){
		return d.write(ostr);
	}
}
