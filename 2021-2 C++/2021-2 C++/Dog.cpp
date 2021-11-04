#include <iostream>
#include <string>

#include "Dog.h"

Dog::Dog() : name("�̸��� �����"), speed(0)
{
	bark();
}

Dog::Dog(std::string name) : name(name)
{
	bark();
}

Dog::Dog(std::string name, double speed) : name(name), speed(speed)
{
	bark();
}

Dog::Dog(const Dog& other) : name(other.name), speed(other.speed)
{
	bark();
}

std::ostream& operator<<(std::ostream& os, const Dog& d)
{
	os << d.name << ", �ӵ� : " << d.speed;

	return os;
}