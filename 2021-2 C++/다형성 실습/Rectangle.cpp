#include <iostream>

#include "Rectangle.h"

void Rectangle::Draw() const
{
	std::cout << "사각형 - (" << p1.x << ", " << p1.y << "), ("
							  << p2.x << ", " << p2.y << ")" << std::endl;
}

std::istream& operator>>(std::istream& is, Rectangle& r)
{
	is >> r.p1 >> r.p2;

	return is;
}
