#include "pch.h"
#include "Perceptron.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

Perceptron::Perceptron()
{
}


Perceptron::Perceptron(int input_size, Fonction_activation * fnc_activation, char label)
{   
	this->fonction_activation = fnc_activation;
	this->label = label;
	this->delta = 0;
	this->poids = (double *)malloc(input_size * sizeof(double));
    for (int i=0; i<=input_size; i++)
    {
		this->poids[i] = rand() % 2 -1;
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
    double somme=this->get_poids(0);
	//std::cout << "poids0 : " << somme << std::endl;
	int i = 0;
	while (input[i] != -1) {
		//std::cout << "poids : " << i+1 << " = " << poids[i + 1] << std::endl;
		//std::cout << "desc : " << i << " = " << input[i] << std::endl;
		double ptemp = this->get_poids(i+1);
		//std::cout << "poids0 : " << somme <
		somme += ptemp * input[i];
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
	int y_char = input.get_label();
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

char Perceptron::get_label()
{
	return this->label;
}

void Perceptron::backprop(Input & input, double mu)
{
	int i = 0;
	this->calcul_delta(input);
	this->poids[0] = this->poids[0] - mu * this->get_delta();
	//std::cout << "-------------EVALUATE--------------" << std::endl;
	while (input[i] != -1) {
		//std::cout << poids[i + 1] << std::endl;
		this->poids[i+1] = this->poids[i+1] - mu * input[i] * this->get_delta();
		i = i + 1;
	}	
	
	
}
