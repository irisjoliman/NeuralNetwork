#include "pch.h"
#include "Apprentissage.h"
#include <stdlib.h>

template<class T, int size>
Apprentissage<T, size>::Apprentissage(NN1 & neural_network)
{
}

template<class T, int size>
void Apprentissage<T, size>::apprendre_base(int K, double mu)
{
	if (K >= 1) {
		for (int i = 0; i < K; i++) {
			int rand_number = rand() % size;
			// Appliquer l'algorithme sur l'input
		}
	}
	else {
		throw "Paramètre K invalide.";
	}
}

template<class T, int size>
int Apprentissage<T, size>::evaluer()
{
	return 0;
}



