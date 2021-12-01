#include <iostream>

#include "Triangle.h"

void Triangle::Draw() const
{
	std::cout << "삼각형 - (" << p1.x << ", " << p1.y << "), ("
							  << p2.x << ", " << p2.y << "), ("
							  << p3.x << ", " << p3.y << ")" << std::endl;
}

std::istream& operator>>(std::istream& is, Triangle& tri)
{
	is >> tri.p1 >> tri.p2 >> tri.p3;

	return is;
}
