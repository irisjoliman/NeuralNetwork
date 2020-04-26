#include "pch.h"
#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

char Input::get_label() {
	return(this->label);
}

void Input::set_label(char lab) {
	this->label = lab;
}
