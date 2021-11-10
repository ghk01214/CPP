//������������������������������������������������
// 11�� 03�� ������ (10�� 1��)
// 
// class�� �� ģ�غ���.
//������������������������������������������������

#include <iostream>
#include <vector>
#include <random>

#include "save.h"
#include "Dog.h"

// [����] Dog ���������� ���� �����ϴ� ������ ������� �Ѵ�.
// 1. class Dog�� �ڵ��غ���
// ������� - �̸�, �ӵ�
// ����Լ� - �޸��� 
// class Dog ��ü 10���� ������
// �� ��ü�� �̸��� �ӵ��� ���� ������ �����϶�.
// �ӵ��� �ʼ� 20000 ~ 50000 ������ �����϶�.
// ���ָ� �����ϰ� 1�� ����ø��� �� ��ü�� �޸� �Ÿ��� ����ϰ� 1km�� ���� �޸��� Dog ��ü�� ����϶�.

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_real_distribution<> urd(20000, 50000);

int main()
{
	Dog dogs[10];

	for (int i = 0; i < std::size(dogs); ++i)
	{
		dogs[i].SetName("Dog " + std::to_string(i) + "ȣ");
		dogs[i].SetSpeed(urd(dre) / 3600);
	}

	for (const Dog& dog : dogs)
	{
		std::cout << dog << std::endl;
	}

	std::cout << "Ű�� ������ ���ָ� ����";
	
	char c;
	std::cin >> c;

	double distance[10]{};
	bool break_loop{ false };

	while (true)
	{
		for (int i = 0; i < std::size(dogs); ++i)
		{
			distance[i] += dogs[i].GetSpeed();
		}

		for (int i = 0; i < std::size(dogs); ++i)
		{
			if (distance[i] >= 1000)
			{
				std::cout << "��¼� ���� : " << dogs[i] << std::endl;
				
				break_loop = true;
			}
		}

		if (break_loop)
			break;
	}

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11�� 08��(��).txt");
}