#include <iostream>

#include "Triangle.h"

void Triangle::Draw() const
{
	std::cout << "»ï°¢Çü - (" << p1.x << ", " << p1.y << "), ("
							  << p2.x << ", " << p2.y << "), ("
							  << p3.x << ", " << p3.y << ")" << std::endl;
}
