#include "Pen.h"


Pen::Pen(const std::string& givenColor)
	:color(givenColor)
{
}

Pen::~Pen()
{
}

void Pen::setColor(const std::string& givenColor)
{
	color = givenColor;
}

const std::string& Pen::getColor(const std::string& givenColor)
{
	return color;
}

const std::string & Pen::getName()
{
	return "Pen";
}

void Pen::activate()
{
	on = true;
}

void Pen::deactivate()
{
	on = false;
}