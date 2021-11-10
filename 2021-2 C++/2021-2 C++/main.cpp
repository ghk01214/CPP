//━━━━━━━━━━━━━━━━━━━━━━━━
// 11월 10일 수요일 (11주 1일)
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

// [문제] Dog 10000 객체를 생성하여 파일 "개 1만 마리.txt"에 기록한다.
// name은 랜덤한 알파벳 소문자만 사용하고 10글자로 고정한다.
// age는 [1, 10000] 사이의 랜덤한 값으로 만들자.
// 파일에서 1만 마리 정보를 읽어 필요한 내용을 코딩해 본다.

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<char> ucd(97, 122);
std::uniform_int_distribution<int> uid(1, 10000);

int main()
{
	std::ofstream in("개 1만 마리.txt");

	for (int i = 0; i < 10000; ++i)
	{
		Dog a{ ucd(dre), uid(dre) };
	}

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11월 10일(수).txt");
}