#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
#include <iostream>
using namespace std;

class Personne
{
	friend ostream& operator<<(ostream&, const Personne&);
	friend istream& operator>>(istream&,Personne&);

	protected :
		string nom;
		string prenom;

	public :
		Personne();
		Personne(const string&,const string&);
		Personne(const Personne&);
		~Personne();

		string getNom()const;
		string getPrenom()const;

		void setNom(const string &);
		void setPrenom(const string &);

		Personne& operator=(const Personne&);

		void Affiche()const;

};
#endif