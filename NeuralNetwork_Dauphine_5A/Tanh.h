#pragma once
#include"Fonction_activation.h"

class Tanh: public Fonction_activation
{
    public:
        Tanh();

        ~Tanh();

        double operator()(double nombre);

        double prim(double nombre);
};

