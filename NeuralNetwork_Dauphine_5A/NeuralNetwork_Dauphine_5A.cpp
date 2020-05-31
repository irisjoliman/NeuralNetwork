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
#include "NN1.h"
#include "NN2.h"
#include "Apprentissage.h"
#include "Fonction_activation.h"
#include <time.h>

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


static void test_partie3() {
	Sigmoide * f = new Sigmoide();
	NN1 * neural_network = new NN1(4, f, 3);
	Apprentissage<Iris, 150, NN1> app(neural_network);
	int K = 15000;
	double mu = 0.1;
	app.apprendre_base(K, mu);
	int evaluation = app.evaluer();

	std::cout << "evaluation : " << evaluation << std::endl;
}

static void test_partie4() {
	Sigmoide * f = new Sigmoide();
	NN2 * neural_network = new NN2(4, 3, 3, f);
	Apprentissage<Iris, 150, NN2> app(neural_network);
	int K = 15000;
	double mu = 0.1;
	app.apprendre_base(K, mu);
	int evaluation = app.evaluer();

	std::cout << "evaluation : " << evaluation << std::endl;
}

int main()
{
	srand(time(NULL));
	//test_partie2();
	//test_partie3();
	test_partie4();

	
	
	
	std::cout << "2000";
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
