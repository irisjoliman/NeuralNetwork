// NeuralNetwork_Dauphine_5A.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <string>


std::string * split(char delimiter, std::string str) {
	std::string result[5];
	for (int i = 0;i < 5;i++) {
		result[i] = str.substr(0, str.find(delimiter));
		str.erase(0, str.find(delimiter) + 1);
		std::cout << result[i] << std::endl;
	}

	return(result);
}


int main()
{
	std::cout << "Hello World!\n";
	std::string s = "5.1,3.5,1.4,0.2,Iris - setosa";
	split(',', s);

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
