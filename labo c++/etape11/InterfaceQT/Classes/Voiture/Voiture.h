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
	string nomVoiture;
	Modele modele;
	Option * options[5]={0};
	int compV(const Voiture&)const;

public:
	Voiture();
	Voiture(string,const Modele &);
	Voiture(const Voiture &);
	~Voiture();

	void AjouteOption(const Option &);
	void RetireOption(string);

	string getNom()const;

	Modele getModele()const;
	float getPrix()const;


	void setNom(string);
	void setModele(const Modele &);

	/******surchage des opérateurs*******/

	Voiture& operator=(const Voiture&);
	Voiture operator+(const Option&)const;
	Voiture operator-(const Option&)const;
	Voiture operator-(string)const;
	int operator< (const Voiture&)const;
	int operator> (const Voiture&)const;
	int operator== (const Voiture&)const;
	Option* operator[](int);
	void Save();
	void Load(string);




	void Affiche()const;



};


#endif
