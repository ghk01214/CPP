#include <iostream>
#include <string>

#include "Animal.h"

void Dog::Move() const
{
	std::cout << name << " �޸���" << std::endl;
}

//����������������������������������������������������������������������������������������������������

void Bird::Move() const
{
	std::cout << name << " ����" << std::endl;
}
