#include "pch.h"
#include "Iris.h"
#include <fstream> 
#include <string>
#include <iostream>

/* Format input: 5.1,3.5,1.4,0.2,Iris-setosa   */

std::string path = "C:\\Users\\irisj\\Documents\\Dauphine\\C++\\Project\\iris_training";

Iris::Iris(int indiceFleur) :Input()
{
	std::string pathFile = path + "iris" + std::to_string(indiceFleur);
	std::ifstream inputFile(pathFile, std::ifstream::in);
	std::string descriptionString = "";

	if (inputFile) {
		inputFile >> descriptionString;
	}
	std::string * desctabchar = this->split(',', descriptionString);
	this->set_label(associationIrisLabel(desctabchar[4]));

	for (int i = 0; i < 4; i++) {
		this->description[i] = std::stod(desctabchar[i]);
	}
}


Iris::~Iris()
{
}

double Iris::operator[](int indice)
{
	if (indice >= 0 && indice <= 3) {
		return(this->description[indice]);
	}
	else {
		return(-1);
	}
}

char Iris::associationIrisLabel(std::string str) {
	if (str == "Iris-setosa") {
		return('0');
	}
	else if (str == "Iris-virginica") {
		return('1');
	}
	else if (str == "Iris-versicolor") {
		return('2');
	}
}

std::string * Iris::split(char delimiter, std::string str) {
	std::string result[5];
	for (int i = 0;i < 5;i++) {
		result[i] = str.substr(0, str.find(delimiter));
		str.erase(0, str.find(delimiter) + 1);
		std::cout << result[i] << std::endl;
	}
	return(result);
}



