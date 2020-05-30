#pragma once
#include"Fonction_activation.h"


class Sigmoide: public Fonction_activation
{
    public:
        Sigmoide();

        ~Sigmoide();

        double operator()(double nombre);

        double prim(double nombre);
};
