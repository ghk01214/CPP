#include <iostream>

#include "Circle.h"

void Circle::Draw() const
{
	std::cout << "�� - �߽���(" << center.x << ", " << center.y << "), ������ " << rad << std::endl;
}
