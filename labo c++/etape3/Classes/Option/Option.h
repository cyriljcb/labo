#ifndef OPTION_H
#define OPTION_H
#include <string>
#include <iostream>
using namespace std;


class Option
{
	friend ostream& operator<<(ostream&, const Option&);
	friend istream& operator>>(istream&,Option&);

private:
	string code;
	string intitule;
	float prix;

public:
	Option();
	Option(const string &,const string &,float);
	Option(const Option &);
	~Option();

	string getCode()const;
	string getIntitule()const;
	float getPrix()const;


	void setCode(const string &);
	void setIntitule(const string &);
	void setPrix(float);




void Affiche()const;







};


#endif

