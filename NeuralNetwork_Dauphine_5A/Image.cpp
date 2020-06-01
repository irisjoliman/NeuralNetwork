#include "pch.h"
#include "Image.h"
#include <fstream> 
#include <string>
#include <iostream>
#include <exception>



Image::Image(int imageIndice)
{
	if (imageIndice <= 59999 && imageIndice >= 0) {
		std::string path_file = "C:..\\data\\MNIST_training\\";
		this->lecture_label(imageIndice);
		unsigned char grey_level;
		try {
			std::string pathFile = path_file + "training" + std::to_string(imageIndice);
			std::ifstream inputFile(pathFile, std::ios::in | std::ios::binary);
			int i = 0;
			if (inputFile.is_open()) {
				inputFile.seekg(1078 * sizeof(char));
				for (i = 0 ;i < 784; i++) {
					inputFile.read((char *)&grey_level, sizeof(unsigned char));
					std::string value = std::to_string(grey_level);
					this->pixel[i] = std::stod(value);
					//std::cout << std::to_string(static_cast<unsigned>(grey_level))<< "; ";
				}
				inputFile.close();
			}
			else {
				std::cout << "impossible d'ouvrir le fichier" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	else {
		throw "Invalid parameter : imageIndice";
	}
}

Image::Image() {

}

Image::~Image()
{
}

double Image::operator[](int indice)
{
	if (indice >= 0 && indice <= 784) {
		return(this->pixel[indice]);
	}
	else {
		return(-1);
	}
}

void Image::lecture_label(int indice) {
	std::string path_file = "C:..\\data\\train-labels.idx1-ubyte";
	int nbrbefore = 8;
	char label;
	char before;
	typedef char *octets;
	if (indice <= 59999 && indice >= 0) {
		try {
			std::ifstream inputFile(path_file, std::ios::in | std::ios::binary);
			if (inputFile.is_open()) {

				inputFile.seekg((8 + indice) * sizeof(char));
				inputFile.read((char *)&label, sizeof(char));
				inputFile.close();
			}
			else {
				std::cout << "impossible d'ouvrir le fichier" << std::endl;
			}

			//std::cout << "The label is :" << static_cast<unsigned>(label) << std::endl;
			this->set_label(std::to_string(static_cast<unsigned>(label))[0]);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	else {
		throw "Invalid parameter : imageIndice";
	}
}


void Image::print_pixel()
{
	std::cout << "Affichage des pixels" << std::endl;
	for (int i = 0; i < 784; i++) {
		std::cout << this->pixel[i] <<std::endl;
	}
}

void Image::set_one_pixel(int ind, double value)
{
	this->pixel[ind] = value;
}


