#include <iostream>

#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapeManager.h"

enum Menu
{
	triangle = 1,
	rectangle,
	circle,
	draw,
	quit = 0
};

int main()
{
	ShapeManager sm(100);

	while (true)
	{
		std::cout << "메뉴" << std::endl;
		std::cout << "1. 삼각형 추가" << std::endl;
		std::cout << "2. 사각형 추가" << std::endl;
		std::cout << "3. 원 추가" << std::endl;
		std::cout << "4. 전체 도형 그리기" << std::endl;
		std::cout << "0. 프로그램 종료" << std::endl;

		int menu;
		std::cin >> menu;

		switch (menu)
		{
		case triangle:
		{
			std::cout << "삼각형의 꼭지점 좌표 입력 : ";

			Point a, b, c;
			std::cin >> a >> b >> c;

			sm.Insert(new Triangle(a, b, c));
		}
		break;

		case rectangle:
		{
			std::cout << "사각형의 대각선 꼭지점 좌표 입력 : ";

			Point a, b;
			std::cin >> a >> b;

			sm.Insert(new Rectangle(a, b));
		}
		break;

		case circle:
		{
			std::cout << "원의 중심점 좌표와 반지름 길이 입력 :	";

			Point center;
			double radius;
			std::cin >> center >> radius;

			sm.Insert(new Circle(center, radius));
		}
		break;

		case draw:
		{
			sm.Draw();
		}
		break;

		case quit:
			return 0;

		default:
			break;
		}

		system("pause");
		system("cls");
	}
}