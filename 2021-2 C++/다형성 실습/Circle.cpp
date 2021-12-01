#include <iostream>

#include "Circle.h"

void Circle::Draw() const
{
	std::cout << "원 - 중심점(" << center.x << ", " << center.y << "), 반지름 " << rad << std::endl;
}

std::istream& operator>>(std::istream& is, Circle& c)
{
	is >> c.center >> c.rad;

	return is;
}
