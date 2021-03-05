#include "ErrorState.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
namespace AMA {
	ErrorState::ErrorState()
	{
		m_message = nullptr;
	}
	ErrorState::ErrorState(const char * errorMessage)
	{
		if (errorMessage == nullptr) {
			clear();
		}
		else {
			m_message = nullptr;
			ErrorState::message(errorMessage);
		}
	}
	ErrorState & ErrorState::operator=(const char * errorMessage)
	{
		clear();
		message(errorMessage);
		return *this;
	}
	ErrorState::~ErrorState()
	{
		delete[] m_message;
		m_message = nullptr;
	}
	void ErrorState::clear()
	{
		delete[] m_message;
		m_message = nullptr;
	}
	bool ErrorState::isClear() const
	{
		if (m_message == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void ErrorState::message(const char * str)
	{
		clear();
		m_message = new char[strlen(str) + 1];
		strcpy(m_message, str);
	}
	const char * ErrorState::message() const
	{
		return m_message;
	}
	std::ostream & operator<<(std::ostream& os, const ErrorState & err)
	{
		if (!err.isClear()) {
			os << err.m_message;
		}
		return os;
	}
}