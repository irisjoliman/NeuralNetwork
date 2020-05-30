#include "pch.h"
#include "Tanh.h"
#include <math.h>

Tanh::Tanh()
{
}

Tanh::~Tanh()
{
}

double Tanh::operator()(double nombre)
{
    return (exp(nombre) - exp(-nombre)) / (exp(nombre) + exp(-nombre));
}

double Tanh::prim(double nombre)
{
    return 1-pow((*this)(nombre),2);
}

