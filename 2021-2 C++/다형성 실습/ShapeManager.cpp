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
	std::cout << "관리하는 모든 도형을 그립니다." << std::endl;
	std::cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다." << std::endl;
	std::cout << "모두 " << size << "개의 도형이 있습니다." << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << "[" << i << "] ";
		shapes[i]->Draw();
	}

	std::cout << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "그리기 종료" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}
