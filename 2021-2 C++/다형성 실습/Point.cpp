#include <iostream>

#include "Point.h"

std::istream& operator>>(std::istream& is, Point& p)
{
	is >> p.x >> p.y;

	return is;
}