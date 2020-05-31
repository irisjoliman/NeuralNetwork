#pragma once
#include "Input.h"
#include "Perceptron.h"



class NN1
{
	/*
		La classe NN1 sert à représenter un réseau de neurones. 
		Cette classe a pour membre l’ensemble des perceptrons qui 
		constituent le réseau de neurones.
	*/
private:
	Perceptron * perceptron_list; // tab perceptron
	int nbr_perceptron;

public:
	// ajouter les paramètres
	NN1();

	NN1(int taille_input, Fonction_activation * fnc_activation, int nbr_perceptron);

	~NN1();

	char evaluation(Input & input);

	void apprentissage(Input &input, double mu);

};

