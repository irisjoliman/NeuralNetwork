#pragma once

class Fonction_activation
{
    public:
        virtual double operator()(double nombre)=0;
        virtual double prim(double nombre)=0;
};
