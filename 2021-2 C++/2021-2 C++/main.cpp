//������������������������������������������������
// 11�� 29�� ������ (13�� 2��)
// 
// 1. ��ü���� ���� : ���(inheritance)
//	1. �ڵ带 �����Ѵ�.(STRING)
//	2. �������� �����Ѵ�.
// 
// �Լ��� ��ü(��� �Լ� ����)
//������������������������������������������������

#include <iostream>

#include "save.h"
#include "Dog.h"

// ���� Dog�� ��ü�� �����̰� �ϰ� �ʹ�.
// Animal*�� Dog*�� ��ȯ�ϴ� downcasting�̴�.
// �ǽð��� type ������ Ȯ���ϴ� ��Ŀ������ �̿��Ѵ�.
// RTTI = Real Time Type Identification

int main()
{
	Dog a;
	Bird b;

	Animal* p[2];
	p[0] = &a;
	p[1] = &b;

	for (int i = 0; i < 2; ++i)
	{
		if (dynamic_cast<Dog*>(p[i]))
		{
			p[i]->Move();
		}
	}

	Save(std::vector<std::string>{ "main.cpp", "Animal.h", "Animal.cpp" }, "11�� 29��(��).txt");
}