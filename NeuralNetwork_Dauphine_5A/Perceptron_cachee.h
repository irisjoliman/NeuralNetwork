#pragma once
#include "Perceptron.h"
#include <vector>
#include <iostream>
#include "Fonction_activation.h"

class Perceptron_cachee :
	public Perceptron
{
private:
	std::vector<Perceptron> perceptrons;

public:
	Perceptron_cachee();
	Perceptron_cachee(int input_size, Fonction_activation * fnc_activation, char label, std::vector<Perceptron> & vect);

	~Perceptron_cachee();

	double calcul_delta(Input & input);

	void backprop(Input & input, double mu);
};

