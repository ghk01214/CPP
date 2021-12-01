#include <iostream>

#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapeManager.h"

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < size; ++i)
	{
		delete shapes[i];
	}

	delete[] shapes;
}

void ShapeManager::Draw() const
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "관리하는 모든 도형을 그립니다." << std::endl;
	std::cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << std::endl;
	std::cout << "모두 " << size << "개의 도형이 있습니다." << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << "[" << i << "] ";
		shapes[i]->Draw();
	}

	std::cout << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "그리기 종료" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void ShapeManager::RemoveByNumber(int num)
{
	delete shapes[num];

	for (int i = num; i < size; ++i)
	{
		shapes[i] = shapes[i + 1];
	}

	--size;
}

void ShapeManager::RemoveByShape(int type)
{
	switch (type)
	{
	case 1:
	{
		for (int i = 0; i < size; ++i)
		{
			if (dynamic_cast<Triangle*>(shapes[i]))
			{
				delete shapes[i];

				for (int j = i; j < size - 1; ++j)
				{
					shapes[j] = shapes[j + 1];
				}

				--size;
			}
		}
	}
	break;

	case 2:
	{
		for (int i = 0; i < size; ++i)
		{
			if (dynamic_cast<Rectangle*>(shapes[i]))
			{
				delete shapes[i];

				for (int j = i; j < size - 1; ++j)
				{
					shapes[j] = shapes[j + 1];
				}

				--size;
			}
		}
	}
	break;

	case 3:
	{
		for (int i = 0; i < size; ++i)
		{
			if (dynamic_cast<Circle*>(shapes[i]))
			{
				delete shapes[i];

				for (int j = i; j < size - 1; ++j)
				{
					shapes[j] = shapes[j + 1];
				}

				--size;
			}
		}
	}
	break;
	}
}

void ShapeManager::ReallocateMemory(int cap)
{
	capacity = cap;

	Shape** temp{ new Shape * [capacity] };
	temp = std::move(shapes);

	delete[] shapes;

	shapes = new Shape * [capacity];
	shapes = std::move(shapes);

	delete[] temp;
}

std::ostream& operator<<(std::ostream& os, const Shape& s)
{
	if (auto temp = dynamic_cast<Triangle*>(const_cast<Shape*>(&s)))
	{
		os << "삼각형 " << "(" << temp->GetP1().x << ", " << temp->GetP1().y << "), ("
			<< temp->GetP2().x << ", " << temp->GetP2().y << "), ("
			<< temp->GetP3().x << ", " << temp->GetP3().y << ")";
	}
	else if (auto temp = dynamic_cast<Rectangle*>(const_cast<Shape*>(&s)))
	{
		os << "사각형 " << "(" << temp->GetP1().x << ", " << temp->GetP1().y << "), ("
			<< temp->GetP2().x << ", " << temp->GetP2().y << ")";
	}
	else if (auto temp = dynamic_cast<Circle*>(const_cast<Shape*>(&s)))
	{
		os << "원 " << "(" << temp->GetCenter().x << ", " << temp->GetCenter().y << "), "
			<< temp->GetRadius();
	}

	return os;
}
