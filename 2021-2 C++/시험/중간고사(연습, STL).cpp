#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uixy{ -1000, 1000 };
std::uniform_int_distribution<> uihp{ 1, 100 };

int gid{ 0 };

class Dog
{
public:
	Dog() = default;
	Dog(std::string sName, int nHP) : id(sName), hp(nHP), x(uixy(dre)), y(uixy(dre)) {}

	void SetVal()
	{
		id = "dog" + std::to_string(gid++);
		hp = uihp(dre);
		x = uixy(dre);
		y = uixy(dre);
	}

	void SetHP(int val) { hp = val; }
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetHP() const { return hp; }

	void show() { std::cout << "Dog: " << id << ", hp: " << hp << std::endl; }
private:
	std::string id;
	int hp;
	int x;
	int y;
};

void damage(Dog& dog);

int main()
{
	{
		// [���� 1] id: "unknown", hp = -1�� �ǵ��� ��ü a�� �ʱ�ȭ�϶�.
		Dog a("unknown", -1);

		// [���� 2] ����ȭ��� ���� ��µǵ��� ����Լ� show�� ���α׷��϶�.
		// Dog: unknown, hp: -1
		a.show();

		// [���� 3] ���� ������ ������ ��ü�� �޸𸮸� �׷� �����϶�.
		Dog b{ a };

		// [���� 4] [���� 3]�� ������ ����� �Ǳ� ���� �ؾ� �� ���� �����ϰ� �ʿ��� �ڵ尡 �ִٸ� �����.
	}

	{
		// ���� ȭ�鿡 ǥ���Ϸ��� ���� ��ġ�� ��Ÿ�� ������ �־�� �Ѵ�.
		// ���� ���迡�� �� Dog ��ü�� 2���� ��ġ�� ��Ÿ���� ���� x, y�� �߰��Ͽ���.
		// ������ ���� 1000���� ���� ������ �� SetVal() �Լ��� ȣ���Ͽ�
		// ��ġ�� ������ ��� ��� ������ ���� �����Ͽ���.
		// - �� �ڵ� ������ ���� 1000�� ���� ����� ���� ���� ���� �ʱ�� ����.

		std::vector<Dog> dogs(1000);

		for (Dog& d : dogs)
		{
			d.SetVal();
		}

		std::cout << "[���� 5 �غ�]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}

		// [���� 5] �Լ� damage�� ���� ��ġ�� ����(0, 0��ǥ) ���� �Ÿ��� 100���� �۴ٸ�
		// ���� ü���� 0���� ����� �Լ��̴�.
		// ���� ����� ���� ��µǵ��� �Լ� damage�� �����ϰ� �����϶�.
		// ��ǥ�� (x, y)�� �� ���������� �Ÿ��� sqrt(x * x + y * y)�� ȣ���Ͽ� ����ϸ� �ȴ�.

		for (Dog& d : dogs)
		{
			damage(d);
		}

		std::cout << "[���� 5 ���]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}

		// [���� 6] �� ������ ����� ������ ���� hp���� 0�� ���� ã�� �� �� ����.
		// hp�� ������������ dogs�� ������ �� ����ϸ� ��� ���� hp ���� 0�� �Ǿ�����
		// ���� ������ �� ���� ���̴�.
		// qsort�� ����Ͽ� hp�� ������������ dogs�� �����϶�.

		// ���⿡�� qsort�� �����ϴ� �ڵ带 ���α׷��Ѵ�.
		std::sort(dogs.begin(), dogs.end(), [](const Dog& a, const Dog& b)
			{
				return a.GetHP() < b.GetHP();
			});

		std::cout << "[���� 6 ���]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}
	}

	// �� 1000�����δ� ���� ���� �ʴ´�.
	// ������ ���� �� 100000������ �����Ͽ� [���� 5]���� �ٽ� ������ ������ �Ѵ�.

	//Dog dogs[100000];

	// [���� 7] �� �ڵ��� �������� �����ϰ� �ذ� ����� �����϶�.
	// ���� ������ �޸� �ִ�ġ�� 1mb�ε� Dog�� �⺻ ũ��� 44����Ʈ�̹Ƿ� dogs�� ũ��� 4.4mb�� �ǹǷ� ������ �ִ�ũ�⸦ �Ѿ������.
	// �̸� �ذ��ϱ� ���ؼ��� dogs�� ���������� �ٲ��ָ�� �ȴ�.
}

void damage(Dog& dog)
{
	int x{ dog.GetX() };
	int y{ dog.GetY() };

	if (sqrt(x * x + y * y) < 100)
		dog.SetHP(0);
}