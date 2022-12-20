#ifndef GARAGE_H
#define GARAGE_H
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include<cstddef>
#include <ostream>
#include <cstdlib>
#include "Vecteur.h"
#include "Modele.h"
#include "Voiture.h"
#include "Option.h"
#include "Employe.h"
#include "Client.h"



class Garage
{
private:
	Vecteur<Employe> employes;
	Vecteur<Client> clients;
	Vecteur<Modele> modeles;
	Vecteur<Option> options;
	static Garage Instance;
	
	Garage();
	Garage(const Garage &);
	Garage& operator=(const Garage&);

	static Voiture projetEnCours;
public:

	void ajouteModele(const Modele & m);
	void afficheModelesDisponibles() const;
	Modele getModele(int indice);

	void ajouteOption(const Option & o);
	void afficheOptionsDisponibles() const;
	Option getOption(int indice);

	void ajouteClient(string nom,string prenom,string gsm);
	void afficheClients() const;
	void supprimeClientParIndice(int ind);
	void supprimeClientParNumero(int num);
	
	void ajouteEmploye(string nom,string prenom,string login,string fonction);
	void afficheEmployes() const;
	void supprimeEmployeParIndice(int ind);
	void supprimeEmployeParNumero(int num);

	static Garage& getInstance();

	static Voiture& getProjetEnCours();
	static void resetProjetEnCours();

	void importeModeles(string);
	void importeOptions(string);

	Vecteur<Modele>& getModele();
	Vecteur<Option>& getOption();

};
#endif