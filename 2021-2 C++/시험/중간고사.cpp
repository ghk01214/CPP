#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	std::ifstream in{ "시험1.dat" };

	enum { count = 1000000 };
	std::vector<int> num(count);

	if (!in)
	{
		std::cout << "파일 열기 실패" << std::endl;

		return 0;
	}

	__int64 sum{};

	for (int i = 0; i < count; ++i)
	{
		in >> num[i];
		sum += num[i];
	}

	int max{ num[0] };

	for (int i = 0; i < count; ++i)
	{
		if (num[i] > max)
			max = num[i];
	}
	
	std::cout << "평균 값 : " << static_cast<long double>(sum) / count << std::endl;
	std::cout << "최대 값 : " << max << std::endl;

	//delete[] num;
}