#pragma once
#include "Input.h"
#include <string>


class Iris : public Input
{
	// La classe Iris a pour but de stocker la (courte) description de fleurs sous la forme d’un tableau de 4 réels

private:
	double description[4];
public:

	Iris(int indiceFleur);

	Iris();

	~Iris();

	double operator[](int indice);

	std::string * split(char delimiter, std::string str);

	char associationIrisLabel(std::string str);
};

