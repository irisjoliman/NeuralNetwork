#ifndef FONCTION_ACTIVATION_H
#define FONCTION_ACTIVATION_H


class Fonction_activation
{
    public:
        virtual double operator()(double nombre)=0;
        virtual double prim(double nombre)=0;
    protected:

    private:
};

#endif // FONCTION_ACTIVATION_H
