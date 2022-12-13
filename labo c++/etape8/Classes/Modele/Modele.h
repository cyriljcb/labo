#ifndef MODELE_H
#define MODELE_H
#include <iostream>
#include <string>
using namespace std;

enum Moteur { Essence, Diesel, Electrique, Hybride };

class Modele
{
	friend ostream& operator<<(ostream&, const Modele&);
	friend istream& operator>>(istream&,Modele&);
private:
	char *nom;
	int puissance;
	Moteur moteur;
	float prixDeBase; 

public:
	Modele();
	Modele(const char *, int , Moteur , float);
	Modele(const Modele &);
	~Modele();

	char* getNom()const;
	int getPuissance()const;
	Moteur getMoteur()const;
	float getPrixDeBase()const;

	void setNom(const char*);
	void setPuissance(int);
	void setMoteur(Moteur);
	void setPrixDeBase(float);

	void Affiche()const;
	void Save(ofstream &)const;
	void Load(ifstream &);

	Modele& operator=(const Modele& );
};




#endif