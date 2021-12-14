//-----------------------------------------------------------------------------
// 기말시험.cpp 
//
// 2021. 12. 13 월요일
//-----------------------------------------------------------------------------
// 컴퓨터에 살고 있는 Monster를 class로 모델링해서 다형성을 구현해 본다.
//-----------------------------------------------------------------------------
// 부모 클래스는 Monster이고  3종의 자식 Monster 클래스 가 있다.
//
// 자식 Monster는 다음과 같은 특수기를 발휘할 수 있다.
//
// TimeMonster		- mSec 만큼 cpu를 정지시킨다.
// MemoryMonster	- 할당한 num 개 바이트 메모리의 값을 1 증가 시킨다.
// ScreenMonster	- n개의 랜덤한 알파벳 문자를 화면에 출력한다.
//-----------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <fstream>
#include "TimeMonster.h"
#include "MemoryMonster.h"
#include "ScreenMonster.h"
using namespace std;

extern default_random_engine dre;

//--------
int main()
//--------
{
	// Monster를 생성할 때 이용할 랜덤값
	uniform_int_distribution<> uiTime(33, 999);
	uniform_int_distribution<> uiMemory(22, 50);
	uniform_int_distribution<> uiScreen(11, 66);

	uniform_int_distribution<> uiThree(0, 2);


	// 문제의 그림과 같이 프로젝트를 만들었다면 다음 코드가 문제없이 실행될 것이다. 실행시켜 보자.
	// [생성 예] 자식 Monster를 랜덤값으로 생성할 수 있다.
	{
		TimeMonster a(uiTime(dre));
		MemoryMonster b(uiMemory(dre));
		ScreenMonster c(uiScreen(dre));

		a.special();					// [1] : CPU 정지 - 406ms
		b.special();					// [2] : 값++
		c.special();					// [3] : 랜덤문자-- > iuwLVRTyDfxkNoMrvXfxJgDawrNynKOEJBQynddPBladNQuwwJLHlMMZDw
		c.special();					// [3] : 랜덤문자-- > UfjfBfmgWeesKhFFTbRxBjDMWyPolxtnBygEcSrwzgVxvNHZTBHsndnjnu

		b.show();						// 메모리 값 출력, MemoryMonster의 값은 따로 출력해 볼 수도 있다.
	}


	//-----------------------------------------------------------------
	// 파일 "소문자들.txt"에는 몇 개인지 모르는 소문자가 기록되어 있다.
	// 이 파일에 있는 'm'의 갯수만큼 Monster를 생성하여 관리하려 한다.
	//-----------------------------------------------------------------

	// [문제 1] "소문자들.txt"에 모두 몇 개의 'm'이 있는지 찾아 
	// 화면에 출력하는 코드를 작성하고 출력한 개수도 답안지에 적어라.		(20) (코드 15, 개수 5) 

	ifstream in{ "소문자들.txt" };
	int num{ };							// 'm'의 개수를 여기에 저장하자

	// 여기에 들어갈 'm'의 개수를 출력하는 코드를 답지에 적어라. (15점)
	// 출력한 개수도 답안지에 적어라. (5점)

	char c;
	while (in >> c)
	{
		if (c == 'm')
		{
			++num;
		}
	}

	cout << "\nm의 개수 : " << num << endl;

	//--------------------------------------------------------------------------------------
	// 파일에서 m의 개수를 읽는 방법을 모르면 num = 100 이라고 놓고 다음 문제를 풀어 나간다.
	//--------------------------------------------------------------------------------------

	cout << endl;
	cout << "관리하는 Monster 객체의 수 - " << num << endl;

	//--------------------------------------------------------
	// Monster class를 이용한 다형성 구현 프로그램을 작성한다.
	//--------------------------------------------------------

	// [문제 2] Monster 객체 num개를 관리할 수 있는 메모리를 만들어라.		(10)
	// (이 메모리를 사용하여 다형성을 구현할 것이다)

	// 여기에 들어갈 코드를 답지에 적어라. (10점)	

	Monster** monsters{ new Monster * [num] };

	// [문제 3] [문제 2]에서 만든 메모리를 다음과 같은 생성 규칙에 따라 Monster를 생성하여 채워라.	(20)

	//--------------------------------------------------------------------------------------
	// 생성 규칙
	//--------------------------------------------------------------------------------------
	// 값이 0, 1, 2인 주사위를 던진다. ( uiThree(dre)를 호출하면 됨 )
	//
	//		주사위의 값이 0 이면
	//			TimeMonster 
	//		주사위의 값이 1 이면
	//			MemoryMonster
	//		주사위의 값이 2 이면
	//			ScreenMonster
	// 
	//   를 main 함수 시작부분에 있는 [생성 예]와 같은 방법으로 생성한다.
	//
	// - 생성결과는 [문제 4]의 출력화면 예시를 참고하라,
	//--------------------------------------------------------------------------------------

	for (int i = 0; i < num; ++i) {
		int sel = uiThree(dre);

		// 여기에 들어갈 코드를 답지에 적으면 된다. (20점)	
		switch (sel)
		{
		case 0:
			monsters[i] = new TimeMonster(uiTime(dre));
			break;
		case 1:
			monsters[i] = new MemoryMonster(uiMemory(dre));
			break;
		case 2:
			monsters[i] = new ScreenMonster(uiScreen(dre));
			break;
		default:
			break;
		}
	}

	// [문제 4] special()을 호출하여 다형성이 구현됨을 확인하라.			(10)
	// - 다운받은 출력화면 예시를 참고하라,

	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "[문제 4] special() 멤버를 호출한 결과" << endl;
	cout << "-------------------------------------" << endl;

	// 여기에 들어갈 코드를 답지에 적어라. (10점)	

	for (int i = 0; i < num; ++i)
	{
		monsters[i]->special();
	}

	//--------------------------------------------------------------------------------
	// 전체 num개의 Monster 중 MemoryMonster는 확보한 메모리에 모두 1을 저장하고 있다.
	// MemoryMonster의 special 함수를 한 번 호출할 때 마다 저장된 값은 1 증가한다.
	//--------------------------------------------------------------------------------
	
	// [문제 5] num개의 Monster 중에서 MemoryMonster를 찾아 special 함수를 두 번 호출하라.	(20)

	cout << endl;
	cout << " - MemoryMonster라면 special 함수를 두 번 호출한다 -" << endl;
	cout << endl;

	// 여기에 들어갈 코드를 답지에 적어라. (20점)

	for (int i = 0; i < num; ++i)
	{
		if (dynamic_cast<MemoryMonster*>(monsters[i]))
		{
			monsters[i]->special();
			monsters[i]->special();
		}
	}

	// 관리하는 num개 Monster 중에서 MemoryMonster의 show() 멤버를 호출한 결과는 출력화면 예시를 참고하라.

	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "[문제 5] 이후 MemoryMonster의 show() 멤버를 호출한 결과" << endl;
	cout << "-------------------------------------------------------" << endl;

	// 여기에 있던 화면 출력 코드는 의도에 따라 보이지 않는다.


	// [문제 6] 관리하는 num개의 Monster 중 첫째 Monster를 지워 모두 num-1개의 Monster로 만들려고 한다.
	// 출력결과 예시와 같이 출력될 수 있도록 첫째 Monster를 지우고 메모리를 정리하라.		(30)

	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "[문제 6] 첫째 Monster를 삭제하고 나서 special() 멤버를 호출한 결과" << endl;
	cout << "------------------------------------------------------------------" << endl;



	// 여기에 들어갈 코드를 답지에 적어라. (30점)	

	delete *monsters;
	--num;

	for (int i = 0; i < num; ++i)
	{
		monsters[i] = monsters[i + 1];
		monsters[i]->special();
	}

	// 여기에 있던 화면 출력 코드는 의도에 따라 보이지 않는다.




	// [문제 7] 프로그램을 끝내기 전 [문제 2]에서 만든 메모리에 문제가 없도록 정리하라. (코드 10, 설명 10)
	// 해제하지 못한 메모리가 있는지 확인하여 한 바이트도 놓치지 않도록 하자.

	// 여기에 들어갈 코드를 답지에 적어라. (10점)	
	// 어떤 문제점이 있었는지 설명하라. (10점)

	for (int i = 0; i < num; ++i)
	{
		delete monsters[i];
	}

	delete[] monsters;

	cout << "\n해제하지 못 한 메모리가 있으면 아래에 해당 메모리의 내용이 출력된다." << endl;

	for (int i = 0; i < num; ++i)
	{
		if (monsters[i])
		{
			monsters[i]->special();
		}
	}
}


