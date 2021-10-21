//������������������������������������������������
// 10�� 13�� ������ (7�� 1��)
// 
// ��������� private�̿��� �ϴ� ������ ���캼 �� �ִ� Ŭ������ �ۼ��ϸ鼭
// Object Oriented Programming�� ������ ������.
//������������������������������������������������

#include <iostream>
#include "save.h"

// [����] main�� �ڵ尡 �������� ����ǵ��� class�� �����ϰ� ��� ���� �޼����� ����϶�

class Dragon
{
public:
	Dragon();
	~Dragon();
	Dragon(const Dragon& other);
	Dragon& operator=(const Dragon& other);
};

Dragon::Dragon()
{
	std::cout << "����Ʈ ������" << std::endl;
}

Dragon::~Dragon()
{
	std::cout << "�Ҹ���"
}

Dragon::Dragon(const Dragon& other)
{
	std::cout << "���������" << std::endl;


}

Dragon& Dragon::operator=(const Dragon& other)
{
	std::cout << "�Ҵ翬����" << std::endl;
}

int main()
{
	Dragon a;
	Dragon b{ a };

	a = b;

	Save("main.cpp", "10�� 13��(��).txt");
}


