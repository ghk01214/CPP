//������������������������������������������������
// 11�� 15�� ������ (11�� 2��)
// 
// 1. ���� �ð� ����
// 2. class Dog�� ���Ͽ� �����ϰ� ���Ͽ��� �о����
//������������������������������������������������

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

#include "save.h"
#include "Dog.h"

// [����] ���� "�� 1������.txt"�� Dog ��ü 1������ ��ϵǾ� �ִ�.
// 1. ������ �о� ȭ�鿡 ����϶�
// 2. �̸� ������������ ������ �� ù ���Ҹ� ���
// 3. ���� ������������ ������ �� ù ���Ҹ� ���

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> ucd('a', 'z');
std::uniform_int_distribution<int> uid(1, 10000);

int main()
{
	std::ifstream in("�� 1�� ����.txt");

	Dog d;
	Dog* dogs{ new Dog[10000] };
	int i{};

	while (in >> dogs[i])
	{
		std::cout << dogs[i++] << std::endl;
	}

	std::cout << std::endl;

	std::sort(dogs, dogs + 10000, [](const Dog& a, const Dog& b)
		{
			return a.GetName() < b.GetName();
		});

	std::cout << "�̸� ���� : " << *dogs << std::endl;

	std::sort(dogs, dogs + 10000, [](const Dog& a, const Dog& b)
		{
			return a.GetAge() < b.GetAge();
		});

	std::cout << "���� ���� : " << *dogs << std::endl;

	delete[] dogs;

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11�� 15��(��).txt");
}