#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H
#include "Exception.h"
#include <string>
#include <iostream>
using namespace std;

class PasswordException: public Exception
{
private: 
		int code;

public:
		PasswordException();
		PasswordException(const string &,int);
		PasswordException(const PasswordException &);
		~PasswordException();
		int getCode()const;

		void setCode(int);

		static const int INVALID_LENGTH;
		static const int ALPHA_MISSING;
		static const int DIGIT_MISSING;
		static const int NO_PASSWORD;

};
#endif