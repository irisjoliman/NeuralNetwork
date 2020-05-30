#ifndef SIGMOIDE_H
#define SIGMOIDE_H
#include"Fonction_activation.h"


class Sigmoide:public Fonction_activation
{
    public:
        Sigmoide();
        virtual ~Sigmoide();
        double operator()(double nombre);
        double prim(double nombre);
    protected:

    private:
};

#endif // SIGMOIDE_H
