#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <iostream>
using namespace std;

class Exception
{
	protected :
		string message;
		

	public :
		Exception();
		Exception(const string&);
		Exception(const Exception&);
		~Exception();

		string getMessage()const;
		

		void setMessage(const string &);

		//void Affiche()const;

};
#endif