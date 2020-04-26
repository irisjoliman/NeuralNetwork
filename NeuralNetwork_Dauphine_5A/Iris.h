#pragma once
#include "Input.h"
#include <string>


class Iris : public Input
{
private:
	double description[4];
public:

	Iris(int indiceFleur);
	~Iris();

	double operator[](int indice);

	std::string * split(char delimiter, std::string str);

	char associationIrisLabel(std::string str);
};

