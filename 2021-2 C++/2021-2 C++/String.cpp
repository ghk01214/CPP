#include <iostream>

#include "String.h"

String::String(const char* str) : num(strlen(str))
{
	p = new char[num];
	memcpy(p, str, num);

	std::cout << "생성자(const char*) - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;
}

String::~String()
{
	std::cout << "소멸자 - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;

	delete[] p;
}

String::String(const String& other) : num(other.num), p(new char[num])
{
	memcpy(p, other.p, num);

	std::cout << "복사생성자(const String&) - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;
}

String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = new char[num];

	memcpy(p, other.p, num);

	std::cout << "복사 할당연산자 - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;

	return *this;
}

String::String(String&& other) noexcept : num(other.num), p(other.p)
{
	other.num = 0;
	other.p = nullptr;

	std::cout << "이동생성자(String&&) - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;
}

String& String::operator=(String&& other) noexcept
{
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;

	std::cout << "이동 할당연산자 - 갯수 : " << num << ", 주소 : " << static_cast<void*>(p) << std::endl;

	return *this;
}

void String::show()
{
	for (int i = 0; i < num; ++i)
	{
		std::cout << p[i];
	}

	std::cout << std::endl;
}

String String::operator+(const String& rhs) const
{
	String temp;

	temp.num = num + rhs.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.num; ++i)
	{
		os << s.p[i];
	}

	return os;
}
