#include "pch.h"
#include "Perceptron.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <iostream>

Perceptron::Perceptron()
{
}

Perceptron::Perceptron(int input_size, Fonction_activation * fnc_activation, char label)
{   
	this->fonction_activation = fnc_activation;
	this->poids = new double[input_size + 1];
	srand(time(NULL));
    for (int i=0; i<=input_size; i++)
    {
		this->poids[i] = ((float(rand()) / float(RAND_MAX)) * 2) - 1;
		//std::cout << this->poids[i] << std::endl;
    }
}

Perceptron::~Perceptron()
{
}

double Perceptron::get_poids(int indice)
{
    return this->poids[indice];
}

double Perceptron::forward(Input & input)
{
    double somme=poids[0];
	//std::cout << "poids0 : " << somme << std::endl;
	int i = 0;
	while (input[i] != -1) {
		//std::cout << "poids : " << i+1 << " = " << poids[i + 1] << std::endl;
		//std::cout << "desc : " << i << " = " << input[i] << std::endl;
		somme += poids[i+1] * input[i];
		i = i + 1;
	}
	//std::cout << "somme : " << somme << std::endl;
    return (*this->fonction_activation)(somme);
}

double Perceptron::calcul_delta(Input & input)
{
	double delta = 0;
	int i = 0;
	double somme = this->poids[0];
	double a_x = this->forward(input);
	char y_char = input.get_label();
	std::string y_str = std::to_string(y_char);
	double y = std::stod(y_str);

	while (input[i] != -1) {
		somme += this->poids[i + 1] * input[i];
		i = i + 1;
	}

	delta = (this->fonction_activation->prim(somme)) * (a_x - y);

	this->delta = delta;
	return this->delta;
}

double Perceptron::get_delta()
{
	return this->delta;
}

void Perceptron::backprop(Input & input, double mu)
{
	int i = 0;
	this->poids[0] = this->poids[0] - mu * this->get_delta();
	while (input[i] != -1) {
		this->poids[i+1] = this->poids[i+1] - mu * input[i] * this->get_delta();
		i = i + 1;
	}	
}
