#include <iostream>

#include "ShapeManager.h"

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < size; ++i)
	{
		delete shapes[i];
	}

	delete[] shapes;
}

void ShapeManager::Draw() const
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "�����ϴ� ��� ������ �׸��ϴ�." << std::endl;
	std::cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�." << std::endl;
	std::cout << "��� " << size << "���� ������ �ֽ��ϴ�." << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << "[" << i << "] ";
		shapes[i]->Draw();
	}

	std::cout << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "�׸��� ����" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}
