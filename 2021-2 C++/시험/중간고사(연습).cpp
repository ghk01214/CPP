#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <random>

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
		char buf[10];
		id = std::string("dog") + itoa(gid++, buf, 10);
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
		// [문제 1] id: "unknown", hp = -1이 되도록 객체 a를 초기화하라.
		Dog a("unknown", -1);

		// [문제 2] 실행화면과 같이 출력되도록 멤버함수 show를 프로그램하라.
		// Dog: unknown, hp: -1
		a.show();

		// [문제 3] 다음 문장의 동작을 객체의 메모리를 그려 설명하라.
		Dog b{ a };

		// [문제 4] [문제 3]의 동작이 제대로 되기 위해 해야 할 일을 설명하고 필요한 코드가 있다면 적어라.
	}

	{
		// 개를 화면에 표현하려면 개의 위치를 나타낼 변수가 있어야 한다.
		// 게임 세계에서 각 Dog 객체의 2차원 위치를 나타내는 변수 x, y를 추가하였다.
		// 다음과 같이 1000마리 개를 생성한 후 SetVal() 함수를 호출하여
		// 위치를 포함한 모든 멤버 변수의 값을 설정하였다.
		// - 이 코드 블럭에서 숫자 1000을 직접 사용한 것은 문제 삼지 않기로 하자.

		Dog dogs[1000];

		for (int i = 0; i < 1000; ++i)
		{
			dogs[i].SetVal();
		}

		std::cout << "[문제 5 준비]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}

		// [문제 5] 함수 damage는 개의 위치와 원점(0, 0좌표) 간의 거리가 100보다 작다면
		// 개의 체력을 0으로 만드는 함수이다.
		// 실행 결과와 같이 출력되도록 함수 damage를 선언하고 정의하라.
		// 좌표가 (x, y)일 때 원점에서의 거리는 sqrt(x * x + y * y)를 호출하여 계산하면 된다.

		for (int i = 0; i < 1000; ++i)
		{
			damage(dogs[i]);
		}

		std::cout << "[문제 5 결과]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}

		// [문제 6] 위 문제의 결과를 관찰해 보면 hp값이 0인 개를 찾아 볼 수 없다.
		// hp값 오름차순으로 dogs를 정렬한 후 출력하면 어느 개가 hp 값이 0이 되었는지
		// 쉽게 관찰할 수 있을 것이다.
		// qsort를 사용하여 hp값 오름차순으로 dogs를 정렬하라.

		// 여기에서 qsort로 정렬하는 코드를 프로그램한다.
		qsort(dogs, 1000, sizeof(Dog), [](const void* a, const void* b)
			{
				int num1{ reinterpret_cast<Dog*>(const_cast<void*>(a))->GetHP() };
				int num2{ reinterpret_cast<Dog*>(const_cast<void*>(b))->GetHP() };
				// int num1{ (int)(((Dog*)a)->GetHP()) };
				// int num2{ (int)(((Dog*)b)->GetHP()) };

				return num1 - num2;
			});

		std::cout << "[문제 6 결과]" << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			dogs[i].show();
		}
	}

	// 개 1000마리로는 성에 차지 않는다.
	// 다음과 같이 개 100000마리를 생성하여 [문제 5]부터 다시 실행해 보려고 한다.

	//Dog dogs[100000];

	// [문제 7] 위 코드의 문제점을 설명하고 해결 방법을 제시하라.
	// 스택 영역은 메모리 최대치가 1mb인데 Dog의 기본 크기는 44바이트이므로 dogs의 크기는 4.4mb가 되므로 스택의 최대크기를 넘어버린다.
	// 이를 해결하기 위해서는 dogs를 전역변수로 바꿔주면ㅓ 된다.
}

void damage(Dog& dog)
{
	int x{ dog.GetX() };
	int y{ dog.GetY() };

	if (sqrt(x * x + y * y) < 100)
		dog.SetHP(0);
}