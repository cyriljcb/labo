#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H
#include "Exception.h"
#include <string>
#include <iostream>
using namespace std;

class OptionException: public Exception
{
public:
		
		OptionException(const string &);
		OptionException(const OptionException &);
		~OptionException();

};
#endif