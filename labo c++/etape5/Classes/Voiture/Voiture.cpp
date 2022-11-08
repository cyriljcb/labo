#include "Voiture.h"
#include "OptionException.h"
#include <iostream>
#include<cstddef>
#include <ostream>
#include <string>
#include <string.h>

using namespace std;


/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/


/********constructeur par défaut****************/

Voiture::Voiture()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Voiture"<<endl;
	#endif

	nomVoiture = "voiture sans nom";
	

}

/********constructeur par initialisation*******/
Voiture::Voiture(const string & nomV,const Modele & modele)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Voiture"<<endl;
	#endif

	setNom(nomV);
	setModele(modele); 

	
}



/********constructeur par copie****************/
Voiture::Voiture (const Voiture &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Voiture"<<endl;
	#endif

	setNom(source.getNom());
	setModele(source.getModele());
	for(int i=0;i<5;i++)
	{
		if(source.options[i]!=NULL)
		{
			
			options[i]= new Option(*source.options[i]);
		}
		else


		{
			
			options[i] = NULL;
		}
	}

}


/*******destructeur****************************/

Voiture::~Voiture()
{
	#ifdef DEBUG
		cout <<"destructeur de Voiture"<<endl;
	#endif

	for(unsigned long i =0; i<(sizeof(options)/sizeof(options[0]));i++)
	{
		if (options[i]!=NULL)
			delete options[i];
	}

}







/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Voiture::getNom()const
{

	return nomVoiture;

}

Modele Voiture::getModele()const
{

	return modele;
}


/*********SETTERS***********************/


void Voiture::setNom (const string & n)
{
	nomVoiture = n;
}

void Voiture::setModele(const Modele & m)
{
	modele.setNom(m.getNom());
	modele.setPuissance(m.getPuissance());
	modele.setMoteur(m.getMoteur());
	modele.setPrixDeBase(m.getPrixDeBase());
}




/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/


void Voiture::Affiche()const
{
	int nb_options = 0;
	Voiture v(*this);
	cout << "Nom de la voiture:" << nomVoiture<<endl;
	modele.Affiche(); 

	for (unsigned long i = 0; i < (sizeof(options)/sizeof(options[0])); i++)
    {
        if (options[i] != NULL)
            nb_options++;
    }

    cout << "Nombre total d'options : " << nb_options << endl;

    for (unsigned long i = 0; i < (sizeof(options) / sizeof(options[0])); i++)
    { 
       	if (options[i] != NULL)
                   options[i]->Affiche();
    }

    cout << "prix total de la voiture avec les options : "<<v.getPrix()<<"f"<<endl;

}


void Voiture::AjouteOption(const Option & opt)
{
	int cpt;
	unsigned long i=0;
    cpt =0;
	while(i<6&&cpt==0)
	{

		if(options[i]==NULL && i<5)
		{
		
			options[i]=new Option (opt);
			cpt=1;		
		}
		i++;
	}

	if(i==6&&options[4]!=NULL)
		throw OptionException("tableau d'options plein");

		
	
}

void Voiture::RetireOption(string code)
{
	unsigned long i=0;

	for(i=0;i<5;i++)
	{
		if(options[i]!=NULL && (options[i]->getCode() == code))
		{
			delete options[i];
			options[i]=NULL;
			
		}

	}
	if(options[i]->getCode() != code) 
		throw OptionException("l'option à supprimer n'est pas présente");
}

float Voiture::getPrix()const
{
	float prix_total = modele.getPrixDeBase();

	for(int i = 0; i < 5;i++)
	{

		if(options[i] != NULL)
			{
				prix_total += options[i]->getPrix();

			}
		
	}
	if(prix_total<0)
		{
			prix_total = 0;
		}

	return prix_total;

}


/****************************************************************************/
/***** surcharge des opérateurs**********************************************/
/****************************************************************************/

Voiture& Voiture::operator=(const Voiture& v1)
{
	int i,a;
	
	setNom(v1.getNom());
	setModele(v1.getModele());
	for(i=0;i<5;i++)
	{
		if(options[i]!= NULL)
			delete options[i];
	}
	
	for(i = 0;i<5;i++)
	{
		if(v1.options[i]!=NULL)
		{
			options[i]= new Option(*v1.options[i]);	
		}
		else
		{
			options[i]=NULL;
		}
	}

	return (*this);
}

Voiture Voiture::operator+(const Option& o1)const
{
	
	Voiture v(*this);
	
	v.AjouteOption(o1);	
	return v;
}


Voiture operator+(const Option& o1,const Voiture& v1)
{
	return v1 + o1;
}

Voiture Voiture::operator-(string code)const
{
	
	Voiture v(*this);
	v.RetireOption(code);	
	return v;
}
Voiture Voiture::operator-(const Option& o1)const
{
	
	Voiture v(*this);
	v.RetireOption(o1.getCode());
	return v;
}

int Voiture::operator<(const Voiture& v1) const
{
	return compV(v1)==-1;
}
int Voiture::operator>(const Voiture& v1) const
{
	return compV(v1)==1;
}
int Voiture::operator==(const Voiture& v1)const
{
	return compV(v1)==0;
}
int Voiture::compV(const Voiture& v1)const
{
	Voiture v(*this);
	if(v.getPrix()< v1.getPrix())
		return -1;
	if(v.getPrix()> v1.getPrix())
		return 1;
	return 0;
}

ostream& operator<< (ostream& s, const Voiture& v1)
{	
    s<<"Nom de la voiture : "<< v1.getNom()<<endl;
    v1.getModele();
    v1.modele.Affiche();
    for(int i = 0; i<5;i++)
    {
    	if (v1.options[i] != NULL)
                   v1.options[i]->Affiche();
    }

	return s;
}

Option* Voiture::operator[](int i)
{
	return options[i];

}
