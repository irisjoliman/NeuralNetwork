// NeuralNetwork_Dauphine_5A.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "Image.h"
#include "Iris.h"
#include <string>
#include "Perceptron.h"
#include "Tanh.h"
#include "Sigmoide.h"


static void test_partie1() {
	Image i = Image(900);
	std::cout << i.get_label() << std::endl;
	std::cout << "0";
	//Iris i = Iris(3);
}

static void test_partie2() {
	Tanh * t = new Tanh();
	Sigmoide * s = new Sigmoide();
	Iris i = Iris(60);
	Perceptron p1 = Perceptron(4, t, '1');
	Perceptron p2 = Perceptron(4, s, '1');

	/*std::cout << " 1 test tanh function : " << p1.forward(i) << std::endl;
	std::cout << " 2 test phi function : " << p2.forward(i) << std::endl;*/
	
	p1.calcul_delta(i);
	p2.calcul_delta(i);

	//std::cout << " 1 delta : " << p1.get_delta() << std::endl;
	//std::cout << " 2 delta : " << p2.get_delta() << std::endl; 


	p1.backprop(i, 0.1);
	p2.backprop(i, 0.1);
	for (int i = 0; i < 5; i++) {
		std::cout << " w1 : " << i << " = " << p1.get_poids(i) << std::endl;
		std::cout << " w2 : " << i << " = " << p2.get_poids(i) << std::endl;
	}
}

int main()
{
	test_partie2();
	std::cout << "0";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
