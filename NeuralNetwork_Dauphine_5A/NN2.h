#pragma once
#include "Perceptron.h"
#include "Perceptron_cachee.h"
#include "Fonction_activation.h"
#include "Input.h"


class NN2
{
private:
	Perceptron * perceptron_list;
	Perceptron_cachee * perceptron_cachee_list;
	int nbr_perceptron;
	int nbr_perceptron_cachee;

public:
	NN2();

	NN2(int taille_input, int nbr_cat, int nbr_perceptron_c, Fonction_activation * f);

	~NN2();

	char evaluation(Input & input);

	void apprentissage(Input & input, double mu);


};

