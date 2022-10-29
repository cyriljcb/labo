#ifndef VOITURE_H
#define VOITURE_H
#include <string>
#include <iostream>
#include "Modele.h"
#include "Option.h"
using namespace std;

class Voiture
{
private:
	int i;
	string nomVoiture;
	Modele modele;
	Option * options[5]={0};

public:
	Voiture();
	Voiture(const string &,const Modele &);
	Voiture(const Voiture &);
	~Voiture();

	void AjouteOption(const Option &);
	void RetireOption(string code);

	string getNom()const;

	Modele getModele()const;
	float getPrix();

	void setNom(const string &);
	void setModele(const Modele &);

	void Affiche()const;



};


#endif
