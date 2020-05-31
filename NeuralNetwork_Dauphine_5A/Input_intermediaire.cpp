#include "pch.h"
#include "Input_intermediaire.h"


Input_intermediaire::Input_intermediaire()
{
}

Input_intermediaire::Input_intermediaire(char label)
{
	this->set_label(label);
	this->val_intermediaires = std::vector<double>();
}


Input_intermediaire::~Input_intermediaire()
{
}

void Input_intermediaire::add(double value)
{
	this->val_intermediaires.push_back(value);
}

double Input_intermediaire::operator[](int indice)
{
	if (indice < this->val_intermediaires.size() && indice >=0) {
		return(this->val_intermediaires[indice]);
	}
	else {
		return(-1);
	}
}
