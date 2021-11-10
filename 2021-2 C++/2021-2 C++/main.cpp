//������������������������������������������������
// 11�� 10�� ������ (11�� 1��)
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

// [����] Dog 10000 ��ü�� �����Ͽ� ���� "�� 1�� ����.txt"�� ����Ѵ�.
// name�� ������ ���ĺ� �ҹ��ڸ� ����ϰ� 10���ڷ� �����Ѵ�.
// age�� [1, 10000] ������ ������ ������ ������.
// ���Ͽ��� 1�� ���� ������ �о� �ʿ��� ������ �ڵ��� ����.

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<char> ucd(97, 122);
std::uniform_int_distribution<int> uid(1, 10000);

int main()
{
	std::ofstream in("�� 1�� ����.txt");

	for (int i = 0; i < 10000; ++i)
	{
		Dog a{ ucd(dre), uid(dre) };
	}

	Save(std::vector<std::string>{"main.cpp", "Dog.h", "Dog.cpp"}, "11�� 10��(��).txt");
}