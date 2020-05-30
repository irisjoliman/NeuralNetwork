#include "pch.h"
#include "Sigmoide.h"
#include <math.h>

Sigmoide::Sigmoide()
{
}

Sigmoide::~Sigmoide()
{
}

double Sigmoide::operator()(double nombre)
{
    return(1 / (1 + exp(-nombre)));
}

double Sigmoide::prim(double nombre)
{
    return ((*this)(nombre)*(1- (*this)(nombre)));
}

