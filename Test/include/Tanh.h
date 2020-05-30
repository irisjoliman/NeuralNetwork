#ifndef TANH_H
#define TANH_H
#include"Fonction_activation.h"

class Tanh: public Fonction_activation
{
    public:
        Tanh();
        virtual ~Tanh();
        double operator()(double nombre);
        double prim(double nombre);
    protected:

    private:

};

#endif // TANH_H
