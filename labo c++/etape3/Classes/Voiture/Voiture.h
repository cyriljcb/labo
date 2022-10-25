#ifndef VOITURE_H
#define VOITURE_H
#include <string>
#include <iostream>
#include "Modele.h"
#include "Option.h"
using namespace std;

class Voiture
{

friend Voiture operator+ (const Option&,const Voiture&);
friend ostream& operator<<(ostream&, const Voiture&);

private:
	int i;
	string nomVoiture;
	Modele modele;
	Option * options[5]={0};
	int compV(Voiture&)const;

public:
	Voiture();
	Voiture(const string &,const Modele &);
	Voiture(const Voiture &);
	~Voiture();

	void AjouteOption(const Option &);
	void RetireOption(string);

	const string getNom()const;

	Modele getModele()const;
	float getPrix();


	void setNom(const string &);
	void setModele(const Modele &);

	/******surchage des opérateurs*******/

	Voiture& operator=(const Voiture&);
	Voiture operator+(const Option&)const;
	Voiture operator-(const Option&)const;
	Voiture operator-(string)const;
	int operator< (Voiture&)const;
	int operator> (Voiture&)const;
	int operator== (Voiture&)const;
	Option* operator[](int);




	void Affiche()const;



};


#endif
