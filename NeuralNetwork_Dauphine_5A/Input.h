#pragma once
class Input
{

private:
	//Le label d�un input indique � quelle famille il appartient. C�est cette famille que devra reconnaitre plus tard le r�seau de neurones.
	char label;

public:
	Input();
	~Input();
	//Constructeur & destructeur virtuels ? recherche � faire

	char get_label();
	
	virtual double operator[](int indice) = 0;

	void set_label(char lab);

};

