#pragma once
#include "Input.h"
#include "Fonction_activation.h"

class Perceptron
{
	

protected:
	double * poids;
	Fonction_activation * fonction_activation;
	double delta; // stocke la valeur de 𝛿𝑘−1
	char label;

public:

		Perceptron();
        Perceptron(int input_size, Fonction_activation * fnc_activation, char label);
        ~Perceptron();

        double get_poids(int indice);

        double forward(Input & input);

        double calcul_delta(Input & input);

        double get_delta();

		char get_label();

        void backprop(Input & input, double mu);
};
