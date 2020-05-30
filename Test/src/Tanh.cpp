#include "Tanh.h"
#include <math.h>

Tanh::Tanh()
{
    //ctor
}

Tanh::~Tanh()
{
    //dtor
}

double Tanh::operator()(double nombre)
{
    return (exp(nombre)-exp(-nombre))/(exp(nombre)+exp(-nombre));
}

double Tanh::prim(double nombre)
{
    return 1-pow(tan(nombre),2);
}
