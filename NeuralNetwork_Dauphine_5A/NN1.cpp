#include "pch.h"
#include "NN1.h"
#include <iostream>


NN1::NN1()
{
}

NN1::NN1(int taille_input, int nbr_perceptron)
{
	if (taille_input != 4 || taille_input != 784) {
		throw std::string("Erreur dans la s�lection de la taille d'input");
	}
	else {
		/*if (nbr_perceptron != 10 || nbr_perceptron != 3) {
			throw std::string("Erreur dans le nombre de cat�gorie");
		}
		else {
			Perceptron * 
		}*/
	}
	
}


NN1::~NN1()
{
}

char NN1::evaluation(Input &inp)
{
	/*� Une fonction evaluation qui prend en param�tre un Input (de pr�f�rence une r�f�rence), et
qui renvoie son label (char dont la valeur est comprise entre 0 et ?? - 1) �valu� en
recherchant la plus grande valeur retourn�e par un des perceptrons.*/
	return 0;
}

void NN1::apprentissage(Input &inp, double mu)
{
	/*Une fonction apprentissage qui prend en param�tre un Input et un double (correspondant au
pas de gradient ??) et qui va appliquer l�algorithme d�apprentissage pour cet input. Chaque
perceptron du r�seau de neurones appliquera son propre algorithme d�apprentissage qui
d�pendra de la cat�gorie qui lui est associ�e.*/
}
