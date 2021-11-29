#include <iostream>

#include "Circle.h"

void Circle::Draw() const
{
	std::cout << "원 - 중심점(" << center.x << ", " << center.y << "), 반지름 " << rad << std::endl;
}
