#include <iostream>

#include "Dog.h"

Dog::Dog(std::string name) : name(name), age(0)
{
}

Dog::Dog(std::string name, int age) : name(name), age(age)
{

}

std::ostream& operator<<(std::ostream& os, const Dog& dog)
{
	os << dog.name << " " << dog.age;

	return os;
}

std::istream& operator>>(std::istream& is, Dog& dog)
{
	is >> dog.name >> dog.age;

	return is;
}
