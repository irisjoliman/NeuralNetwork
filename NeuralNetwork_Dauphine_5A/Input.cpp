#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

char Input::get_label() {
	return(this->label - 48);
}

void Input::set_label(char lab) {
	this->label = lab;
}
