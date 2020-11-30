#pragma once
#include  "GeoObj.hxx"

namespace geoobjns
{
	class GeoObj2D : public GeoObj
	{
	public:
		GeoObj2D(std::string NAMEIN, coord VERTEXIN);
		virtual ~GeoObj2D();
		virtual double getArea() const = 0;
		void setCoord(const coord& COORDIN);
		const coord& getCoord() const;
	private:
		coord vertex;
	};
}


