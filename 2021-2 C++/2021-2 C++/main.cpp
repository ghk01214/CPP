//━━━━━━━━━━━━━━━━━━━━━━━━
// 11월 22일 월요일 (12주 2일)
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

// [문제] 

int main()
{
	Dog a{ "코코" };
	Bird b{ "삐약" };

	Animal* animals[2];

	animals[0] = (Animal*)(Dog*)&a;
	animals[1] = &b;

	for (int i = 0; i < 2; ++i)
	{
		animals[i]->Move();
	}

	Save(std::vector<std::string>{ "main.cpp", "Animal.h", "Animal.cpp" }, "11월 22일(월).txt");
}