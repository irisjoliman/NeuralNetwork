#include "Perceptron.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Perceptron::Perceptron(int input_size, Fonction_activation *fct, char label)
{   double poids_aleatoire;
    //ctor
    for (int i=0; i<input_size;i++)
    {
        this->fonction_activation=fct;
        poids_aleatoire=rand();
        if(rand()>.5)poids_aleatoire=poids_aleatoire*-1;
        this->poids[i]=poids_aleatoire;
    }
}

Perceptron::~Perceptron()
{
    //dtor
}

double Perceptron::getPoids(int indice)
{
    return this->poids[indice];
}

double Perceptron::forward(Input& input)
{
    double somme=poids[0];
    for(int i=1;i<sizeof(input);i++)
        somme+=poids[i]*input[i];
    return this->fonction_activation(somme);
}

void Perceptron::CalculDelta(Input& input)
{
    this->delta=0;
    for(int i=0;i<sizeof(input);i++)
        this->delta+=this->fonction_activation.prim(poids[i]*input[i])*this->fonction_activation(0);
}

double Perceptron::getDelta()
{
    return this->delta;
}

void Perceptron::BackProp(Input& input, double gradient)
{
    for(int i=0;i<sizeof(input);i++)
        if (i==0)
        {
            this->poids[i]=this->poids[i]-gradient*this->CalculDelta();
        }
        else this->poids[i]=this->poids[i]-gradient*i*this->CalculDelta();
}
