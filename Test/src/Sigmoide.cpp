#include "Sigmoide.h"
#include <math.h>

Sigmoide::Sigmoide()
{
    //ctor
}

Sigmoide::~Sigmoide()
{
    //dtor
}

double Sigmoide::operator()(double nombre)
{
    return 1/(1+exp(-nombre));
}

double Sigmoide::prim(double nombre)
{
    return (1/(1+exp(-nombre)))*(1-(1/(1+exp(-nombre))));
}
