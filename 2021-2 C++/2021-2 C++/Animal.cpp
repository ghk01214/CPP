#include <iostream>
#include <string>

#include "Animal.h"

void Animal::Move()
{
	std::cout << name << " �����δ�" << std::endl;
}

//����������������������������������������������������������������������������������������������������

void Dog::Move()
{
	std::cout << name << " �޸���" << std::endl;
}

//����������������������������������������������������������������������������������������������������

void Bird::Move()
{
	std::cout << name << " ����" << std::endl;
}
