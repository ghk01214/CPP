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
		std::cout << "�޴�" << std::endl;
		std::cout << "1. �ﰢ�� �߰�" << std::endl;
		std::cout << "2. �簢�� �߰�" << std::endl;
		std::cout << "3. �� �߰�" << std::endl;
		std::cout << "4. ��ü ���� �׸���" << std::endl;
		std::cout << "0. ���α׷� ����" << std::endl;

		int menu;
		std::cin >> menu;

		switch (menu)
		{
		case triangle:
		{
			std::cout << "�ﰢ���� ������ ��ǥ �Է� : ";

			Point a, b, c;
			std::cin >> a >> b >> c;

			sm.Insert(new Triangle(a, b, c));
		}
		break;

		case rectangle:
		{
			std::cout << "�簢���� �밢�� ������ ��ǥ �Է� : ";

			Point a, b;
			std::cin >> a >> b;

			sm.Insert(new Rectangle(a, b));
		}
		break;

		case circle:
		{
			std::cout << "���� �߽��� ��ǥ�� ������ ���� �Է� :	";

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