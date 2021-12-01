#include <iostream>
#include <random>
#include <fstream>

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
	erase,
	save,
	load,
	quit = 0
};

std::default_random_engine dre(std::random_device{}());
std::uniform_real_distribution<double> uid(0.0, 20.0);

int main()
{
	ShapeManager sm(100);

	while (true)
	{
		if (sm.IsFull())
		{
			sm.ReallocateMemory(sm.GetCapacity() * 2);
		}

		std::cout << "메뉴" << std::endl;
		std::cout << "1. 삼각형 추가" << std::endl;
		std::cout << "2. 사각형 추가" << std::endl;
		std::cout << "3. 원 추가" << std::endl;
		std::cout << "4. 전체 도형 그리기" << std::endl;
		std::cout << "5. 도형 지우기" << std::endl;
		std::cout << "6. 파일에 저장" << std::endl;
		std::cout << "7. 파일에서 읽어오기" << std::endl;
		std::cout << "0. 프로그램 종료" << std::endl;
		std::cout << "실행할 메뉴를 선택 : ";

		int menu;
		std::cin >> menu;

		switch (menu)
		{
		case triangle:
		{
			sm.Insert(new Triangle(Point(uid(dre), uid(dre)),
				Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));

			std::cout << "삼각형의 추가 성공" << std::endl;
		}
		break;

		case rectangle:
		{
			sm.Insert(new Rectangle(Point(uid(dre), uid(dre)), Point(uid(dre), uid(dre))));
			
			std::cout << "사각형의 추가 성공" << std::endl;
		}
		break;

		case circle:
		{
			sm.Insert(new Circle(Point(uid(dre), uid(dre)), uid(dre)));

			std::cout << "원 추가 성공" << std::endl;
		}
		break;

		case draw:
		{
			sm.Draw();
		}
		break;
		
		case erase:
		{
			system("cls");

			std::cout << "1. 도형 번호를 이용해 삭제" << std::endl;
			std::cout << "2. 도형 종류를 이용해 삭제" << std::endl << std::endl;
			std::cout << "실행할 메뉴를 선택 : ";

			int rem;
			std::cin >> rem;

			switch (rem)
			{
			case 1:
			{
				std::cout << "\n삭제할 도형의 번호 입력 : " << std::endl;

				int num;
				std::cin >> num;

				sm.RemoveByNumber(num);
				std::cout << "삭제 성공" << std::endl;
			}
			break;

			case 2:
			{
				std::cout << "\n1. 삼각형" << std::endl;
				std::cout << "2. 사각형" << std::endl;
				std::cout << "3. 원" << std::endl;
				std::cout << "삭제할 도형의 종류 선택:";

				int type;
				std::cin >> type;

				sm.RemoveByShape(type);

				std::cout << "삭제 성공" << std::endl;
			}
			break;
			}
		}
		break;

		case save:
		{
			std::ofstream out("도형 목록.txt");

			if (!out)
			{
				std::cout << "파일 쓰기 에러" << std::endl;
				break;
			}

			for (int i = 0; i < sm.GetSize(); ++i)
			{
				out << sm.GetShape(i) << std::endl;
			}
		}
		break;

		case load:
		{
			std::ifstream in("도형 목록.txt");

			if (!in)
			{
				std::cout << "파일 읽기 에러" << std::endl;
				break;
			}

			std::string type;
			in >> type;

			if (type == "삼각형")
			{
				Triangle* tri{ new Triangle };
				in >> *tri;

				sm.Insert(tri);
			}
			else if (type == "사각형")
			{
				Rectangle* rect{ new Rectangle };
				in >> *rect;

				sm.Insert(rect);
			}
			else if (type == "원")
			{
				Circle* cir{ new Circle };
				in >> *cir;

				sm.Insert(cir);
			}
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