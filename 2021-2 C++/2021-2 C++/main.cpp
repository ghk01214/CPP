//━━━━━━━━━━━━━━━━━━━━━━━━
// 11월 29일 월요일 (13주 2일)
// 
// 1. 객체간의 관계 : 상속(inheritance)
//	1. 코드를 재사용한다.(STRING)
//	2. 다형성을 구현한다.
// 
// 함수의 정체(멤버 함수 포함)
//━━━━━━━━━━━━━━━━━━━━━━━━

#include <iostream>

#include "save.h"
#include "Dog.h"

// 원래 Dog인 객체만 움직이게 하고 싶다.
// Animal*를 Dog*로 변환하는 downcasting이다.
// 실시간에 type 정보를 확인하는 메커니즘을 이용한다.
// RTTI = Real Time Type Identification

int main()
{
	Dog a;
	Bird b;

	Animal* p[2];
	p[0] = &a;
	p[1] = &b;

	for (int i = 0; i < 2; ++i)
	{
		if (dynamic_cast<Dog*>(p[i]))
		{
			p[i]->Move();
		}
	}

	Save(std::vector<std::string>{ "main.cpp", "Animal.h", "Animal.cpp" }, "11월 29일(월).txt");
}