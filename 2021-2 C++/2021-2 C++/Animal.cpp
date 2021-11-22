#include <iostream>
#include <string>

#include "Animal.h"

void Animal::Move()
{
	std::cout << name << " 움직인다" << std::endl;
}

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void Dog::Move()
{
	std::cout << name << " 달린다" << std::endl;
}

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void Bird::Move()
{
	std::cout << name << " 난다" << std::endl;
}
