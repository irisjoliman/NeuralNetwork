#pragma once
#include "Input.h"


class Image : public Input
{
	//La classe Image a pour but de stocker des images en noir et blanc, comprenant 28×28 pixels

private:
	char pixel;

public:
	Image(int imageIndice);
	~Image();

	double operator[](int indice);
};

