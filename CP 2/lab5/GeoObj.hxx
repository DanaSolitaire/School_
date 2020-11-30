#pragma once
#include <string>

namespace geoobjns
{
	struct coord
	{
		size_t numofDims;
		double* dimValuePtr;

		coord(size_t NOD)
		{
			numofDims = NOD;
			dimValuePtr = new double[numofDims];
		}
	};
}
class GeoObj
{
public:
	GeoObj(const std::string& NAMEIN = std::string());
	virtual ~GeoObj(); // not necessary
	void setName(const std::string& NAMEIN);
	std::string& getName() const;
	// makes Virtual Function getArea which makes Geoobj abstract
	virtual double getArea() const  = 0;
private:
	std::string name;

};

