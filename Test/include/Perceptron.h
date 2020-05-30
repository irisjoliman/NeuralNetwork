#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "Input.h"

class Perceptron
{
    public:
        Perceptron(int input_size, char fct, char label);
        virtual ~Perceptron();
        double getPoids(int indice);
        double forward(Input input);
        void CalculDelta(Input& input);
        double getDelta();
        void Perceptron::BackProp
    protected:

    private:
        double poids[10];
        Fonction_activation *fonction_activation;
        char label;
        double delta;
};

#endif // PERCEPTRON_H
