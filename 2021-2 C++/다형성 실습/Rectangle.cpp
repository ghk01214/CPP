#include <iostream>

#include "Rectangle.h"

void Rectangle::Draw() const
{
	std::cout << "�簢�� - (" << p1.x << ", " << p1.y << "), ("
							  << p2.x << ", " << p2.y << ")" << std::endl;
}
