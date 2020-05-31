#include "pch.h"
#include "NN1.h"
#include <iostream>
#include <string>
#include <fstream>


NN1::NN1()
{
}

NN1::NN1(int taille_input, Fonction_activation * fnc_activation, int nbr_perceptron)
{
	if (taille_input != 4 && taille_input != 784) {
		throw std::string("Erreur dans la sélection de la taille d'input");
	}
	else {
		if (nbr_perceptron != 10 && nbr_perceptron != 3) {
			throw std::string("Erreur dans le nombre de catégorie");
		}
		else {
			this->nbr_perceptron = nbr_perceptron;
			this->perceptron_list = new Perceptron[nbr_perceptron];
			for (int i = 0; i < nbr_perceptron; i++) {
				Perceptron p = Perceptron(taille_input, fnc_activation, i);
				this->perceptron_list[i] = p;
			}
		}
	}
}


NN1::~NN1()
{
}

char NN1::evaluation(Input & input)
{
	double max = 0;
	int indice_max = 0;
	for (int i = 0; i < this->nbr_perceptron; i++) {
		double valeur = this->perceptron_list[i].forward(input);
		if (valeur > max) {
			max = valeur;
			indice_max = i;
		}
	}
	return(std::to_string(indice_max)[0]);
}

void NN1::apprentissage(Input & input, double mu)
{
	for (int i = 0; i < this->nbr_perceptron; i++) {
		this->perceptron_list[i].backprop(input, mu);
	}
}
