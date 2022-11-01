#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <string>
#include <iostream>
#include "Intervenant.h"
using namespace std;

class Employe: public Intervenant

{
	friend ostream& operator<<(ostream&,const Employe&);

	private: 
		string login;
		string* motDePasse;

	public: 

		Employe();
		Employe(const string &, const string &,int, const string &);
		Employe(const Employe &);
		~Employe();

		string getLogin()const;
		void setLogin(const string&);
		string getMotDePasse()const;
		void setMotDePasse(const string &);

		Employe& operator=(const Employe&);
		string ToString()const;
		string Tuple()const;



};
#endif