//������������������������������������������������
// 11�� 22�� ������ (12�� 2��)
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

// [����] 

int main()
{
	Dog a{ "����" };
	Bird b{ "�߾�" };

	Animal* animals[2];

	animals[0] = (Animal*)(Dog*)&a;
	animals[1] = &b;

	for (int i = 0; i < 2; ++i)
	{
		animals[i]->Move();
	}

	Save(std::vector<std::string>{ "main.cpp", "Animal.h", "Animal.cpp" }, "11�� 22��(��).txt");
}