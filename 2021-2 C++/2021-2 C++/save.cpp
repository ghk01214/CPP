#include "save.h"

// google coding convention
void Save(std::string_view fileName, std::string_view saveDate)
{
	char c;

	std::cout << "\n저장?" << std::endl;
	std::cin >> c;

	if (c == 'y')
	{
		// 어떤 파일을 저장하는지 화면에 출력
		std::cout << "저장: " << fileName << ", 크기: " << std::filesystem::file_size(fileName) << std::endl;

		std::ofstream out(saveDate, std::ios::app);
		//std::ofstream out2("2021-2 C++.txt", std::ios::app);
		std::ifstream in(fileName);

		//파일을 기록한 시간도 표시
		time_t t{ std::time(nullptr) };

		//시간 기록 지역 변경
		out.imbue(std::locale("korean"));

		out << "━━━━━━━━━━━━━━━━━━━━" << std::endl;
		out << "저장시간: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		out << "━━━━━━━━━━━━━━━━━━━━" << std::endl;

		//out2 << "━━━━━━━━━━━━━━━━━━━━" << std::endl;
		//out2 << "저장시간: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		//out2 << "━━━━━━━━━━━━━━━━━━━━" << std::endl;

		//파일의 끝을 알려주기 위해서 char 형이 아니라 int 형으로 받아온다
		int c;

		//while ((c = in.get()) != EOF)
		//{
		//	out.put(c);
		//}

		char ch;

		while (in >> std::noskipws >> ch)
		{
			out << ch;
			//out2 << ch;
		}

		out << std::endl << std::endl;
		//out2 << std::endl << std::endl;

		//RAII
		/*in.close();
		out.close();*/
	}
}