#pragma once
#include "Input.h"


class Image : public Input
{
	//La classe Image a pour but de stocker des images en noir et blanc, comprenant 28×28 pixels

private:
	double pixel[784]; // 28 * 28 pixels 

public:
	Image(int imageIndice);

	Image();

	~Image();

	double operator[](int indice);

	void lecture_label(int indice);

	void print_pixel();

	void set_one_pixel(int ind, double value);
};

