#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include "Intervenant.h"
using namespace std;

class Client: public Intervenant
{
	friend ostream& operator<<(ostream&, const Client&);

	private: 
		string gsm;
	public: 

		Client();
		Client(const string &, const string&, int ,const string &);
		Client(const Client&);
		~Client();

		string getGsm()const;
		void setGsm(string);

		Client& operator= (const Client&);
		string ToString()const;
		string Tuple()const;


};
#endif