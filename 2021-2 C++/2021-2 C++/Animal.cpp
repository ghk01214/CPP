#include <iostream>
#include <string>

#include "Animal.h"

void Dog::Move() const
{
	std::cout << name << " 달린다" << std::endl;
}

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void Bird::Move() const
{
	std::cout << name << " 난다" << std::endl;
}
