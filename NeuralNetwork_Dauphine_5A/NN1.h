#pragma once
#include "Input.h"
#include "Perceptron.h"



class NN1
{
	/*
		La classe NN1 sert � repr�senter un r�seau de neurones. 
		Cette classe a pour membre l�ensemble des perceptrons qui 
		constituent le r�seau de neurones.
	*/
private:
	Perceptron * neural_network; // tab perceptron

public:
	// ajouter les param�tres
	NN1();

	NN1(int taille_input, int nbr_perceptron);

	~NN1();

	char evaluation(Input &inp);

	void apprentissage(Input &inp, double mu);

};

