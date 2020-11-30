#include "GeoObj.hxx"


GeoObj::GeoObj(const std::string & NAMEIN)
{
	name = NAMEIN;
}

GeoObj::~GeoObj()
{

}

void GeoObj::setName(const std::string & NAMEIN)
{
	name = NAMEIN;
}

std::string & GeoObj::getName() const
{
	return name;
	// TODO: insert return statement here
}
