//━━━━━━━━━━━━━━━━━━━━━━━━
// 11월 03일 수요일 (10주 1일)
// 
// class와 더 친해보자.
//━━━━━━━━━━━━━━━━━━━━━━━━

#include <iostream>
#include <vector>
#include <random>

#include "save.h"
#include "Dog.h"

// [문제] Dog 여러마리가 서로 경주하는 게임을 만들려고 한다.
// 1. class Dog를 코딩해보자
// 멤버변수 - 이름, 속도
// 멤버함수 - 달린다 
// class Dog 객체 10개를 만들어라
// 각 객체의 이름과 속도를 랜덤 값으로 생성하라.
// 속도는 초속 20000 ~ 50000 값으로 설정하라.
// 경주를 시작하고 1초 경과시마다 각 객체가 달린 거리를 계산하고 1km를 먼저 달리는 Dog 객체를 출력하라.

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_real_distribution<> urd(20000, 50000);

int main()
{
	Dog dogs[10];

	for (int i = 0; i < std::size(dogs); ++i)
	{
		dogs[i].SetName("Dog " + std::to_string(i) + "호");
		dogs[i].SetSpeed(urd(dre) / 3600);
	}

	for (const Dog& dog : dogs)
	{
		std::cout << dog << std::endl;
	}

	std::cout << "키를 누르면 경주를 시작";
	
	char c;
	std::cin >> c;

	double distance[10]{};
	bool break_loop{ false };

	while (true)
	{
		for (int i = 0; i < std::size(dogs); ++i)
		{
			distance[i] += dogs[i].GetSpeed();
		}

		for (int i = 0; i < std::size(dogs); ++i)
		{
			if (distance[i] >= 1000)
			{
				std::cout << "결승선 도착 : " << dogs[i] << std::endl;
				
				break_loop = true;
			}
		}

		if (break_loop)
			break;
	}

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11월 08일(월).txt");
}