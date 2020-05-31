#pragma once
#include "Input.h"
#include <vector>
#include <iostream>

class Input_intermediaire : public Input
{
private : 
	std::vector<double> val_intermediaires;
public:
	Input_intermediaire();

	Input_intermediaire(char  label);

	~Input_intermediaire();

	void add(double value);

	double operator[](int indice);
};

