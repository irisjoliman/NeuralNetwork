#pragma once
class Input
{

private:
	//Le label d’un input indique à quelle famille il appartient. C’est cette famille que devra reconnaitre plus tard le réseau de neurones.
	char label;

public:
	Input();
	~Input();
	//Constructeur & destructeur virtuels ? recherche à faire

	char get_label();
	
	virtual double operator[](int indice) = 0;

	void set_label(char lab);

};

