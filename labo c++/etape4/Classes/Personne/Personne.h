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
		Persone();
		Personne(string&, string&);
		Personne(const Personne&);
		~Personne();

		string getNom()const;
		string getPrenom()const;

		void setNom(string &);
		void setPrenom(string &);

		Personne& operator=(const Personne&);

}