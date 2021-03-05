#ifndef ERRORSTATE_H
#define ERRORSTATE_H
#include <iostream>

namespace AMA {
	class ErrorState {
		char* m_message;
	public:
		ErrorState();
		explicit ErrorState(const char* errorMessage);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		ErrorState& operator=(const char* errorMessage);
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
		friend  std::ostream& operator<<(std::ostream& os, const ErrorState& err);
	};
	std::ostream& operator<<(std::ostream& cout, const ErrorState& err);
}

#endif
