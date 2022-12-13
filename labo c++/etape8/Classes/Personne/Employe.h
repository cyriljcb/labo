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
		string fonction;

	public: 

		const static string VENDEUR;
		const static string ADMINISTRATIF;
		Employe();
		Employe(const string &, const string &,int, const string &,const string &);
		Employe(const Employe &);
		~Employe();

		string getLogin()const;
		void setLogin(string);
		string getMotDePasse()const;
		void setMotDePasse( string);
		string getFonction()const;
		void setFonction(string);

		Employe& operator=(const Employe&);
		string ToString()const;
		string Tuple()const;
		void ResetMotDePasse();



};
#endif