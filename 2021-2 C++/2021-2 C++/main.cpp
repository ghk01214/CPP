//━━━━━━━━━━━━━━━━━━━━━━━━
// 10월 13일 수요일 (7주 1일)
// 
// 멤버변수가 private이여야 하는 이유를 살펴볼 수 있는 클래스를 작성하면서
// Object Oriented Programming의 개념을 엿본다.
//━━━━━━━━━━━━━━━━━━━━━━━━

#include <iostream>
#include "save.h"

// [문제] main의 코드가 문제없이 실행되도록 class를 정의하고 모든 관찰 메세지를 출력하라

class Dragon
{
public:
	Dragon();
	~Dragon();
	Dragon(const Dragon& other);
	Dragon& operator=(const Dragon& other);
};

Dragon::Dragon()
{
	std::cout << "디폴트 생성자" << std::endl;
}

Dragon::~Dragon()
{
	std::cout << "소멸자"
}

Dragon::Dragon(const Dragon& other)
{
	std::cout << "복사생성자" << std::endl;


}

Dragon& Dragon::operator=(const Dragon& other)
{
	std::cout << "할당연산자" << std::endl;
}

int main()
{
	Dragon a;
	Dragon b{ a };

	a = b;

	Save("main.cpp", "10월 13일(수).txt");
}


