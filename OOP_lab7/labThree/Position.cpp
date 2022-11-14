#include "Position.h"

void Position::setPosition(string position)
{
	this->position = position;
}

string Position::getPosition()
{
	return string(this->position);
}