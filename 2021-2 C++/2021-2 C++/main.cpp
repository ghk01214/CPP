//━━━━━━━━━━━━━━━━━━━━━━━━
// 11월 15일 월요일 (11주 2일)
// 
// 1. 지난 시간 복습
// 2. class Dog를 파일에 저장하고 파일에서 읽어오기
//━━━━━━━━━━━━━━━━━━━━━━━━

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

#include "save.h"
#include "Dog.h"

// [문제] 파일 "개 1만마리.txt"에 Dog 객체 1만개가 기록되어 있다.
// 1. 정보를 읽어 화면에 출력하라
// 2. 이름 오름차순으로 정렬한 후 첫 원소를 출력
// 3. 나이 오름차순으로 정렬한 후 첫 원소를 출력

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> ucd('a', 'z');
std::uniform_int_distribution<int> uid(1, 10000);

int main()
{
	std::ifstream in("개 1만 마리.txt");

	Dog d;
	Dog* dogs{ new Dog[10000] };
	int i{};

	while (in >> dogs[i])
	{
		std::cout << dogs[i++] << std::endl;
	}

	std::cout << std::endl;

	std::sort(dogs, dogs + 10000, [](const Dog& a, const Dog& b)
		{
			return a.GetName() < b.GetName();
		});

	std::cout << "이름 정렬 : " << *dogs << std::endl;

	std::sort(dogs, dogs + 10000, [](const Dog& a, const Dog& b)
		{
			return a.GetAge() < b.GetAge();
		});

	std::cout << "나이 정렬 : " << *dogs << std::endl;

	delete[] dogs;

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11월 15일(월).txt");
}