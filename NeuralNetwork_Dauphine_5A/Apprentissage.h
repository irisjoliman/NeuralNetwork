#pragma once
#include "Input.h"
#include "NN1.h"

template <class T, int size> class Apprentissage
{
private: 
	NN1 * perceptron;
public:
	Apprentissage(NN1 & neural_network);
	
	void apprendre_base(int K, double mu);

	int evaluer();

};

