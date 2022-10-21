#include "Voiture.h"
#include <iostream>
#include<cstddef>
#include <ostream>
#include <string>

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

const string Voiture::getNom()const
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
	cout << "Nom de la voiture:" << nomVoiture<<endl;
	modele.Affiche(); 

	for (unsigned long i = 0; i < (sizeof(options)/sizeof(options[0])); i++)
    {
        if (options[i] != NULL)
            nb_options++;
    }

    cout << "Nombre total d'options : " << nb_options << endl;

    for (unsigned long i = 0; i < (sizeof(options) / sizeof(options[0])); i++)
        if (options[i] != NULL)
            options[i]->Affiche();

}


void Voiture::AjouteOption(const Option & opt)
{
	
	unsigned long i=0;
	/*while(i<(sizeof(options)/sizeof(options[0]))&&options[i]!=NULL)
		i++;


	if(i<(sizeof(options)/sizeof(options[0])))
		options[i]=new Option (opt);*/
	for(i=0;i<5;i++)
	{
		if(options[i]==NULL)
		{
			options[i]=new Option (opt);
			i=5;
		}
	}
	
	
}

void Voiture::RetireOption(string code)
{
	unsigned long i=0;

	while(i<(sizeof(options)/sizeof(options[0])) && options[i] != NULL && options[i]->getCode() != code)
		i++;

	if (i<(sizeof(options)/sizeof(options[0]))&& options[i] != NULL && options[i]->getCode() == code)
	{
		delete options[i];
		options[i] = NULL;
	}


}

float Voiture::getPrix()
{
	float prix_total = modele.getPrixDeBase();

	for(unsigned long i = 0; i < sizeof(options)/sizeof(options [0]);i++)
	{

		if(options[i] != NULL)
			prix_total += options[i]->getPrix();
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
	for(i = 0;i<5;i++)
	{
		if(v1.options[i]!=NULL)
		{
			options[i]= new Option(*v1.options[i]);	
		}
		else
		{
			options[i] = NULL;
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

