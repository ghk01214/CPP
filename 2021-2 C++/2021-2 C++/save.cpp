#include "save.h"

// google coding convention
void Save(std::string_view fileName, std::string_view saveDate)
{
	char c;

	std::cout << "\n����?" << std::endl;
	std::cin >> c;

	if (c == 'y')
	{
		// � ������ �����ϴ��� ȭ�鿡 ���
		std::cout << "����: " << fileName << ", ũ��: " << std::filesystem::file_size(fileName) << std::endl;

		std::ofstream out(saveDate, std::ios::app);
		//std::ofstream out2("2021-2 C++.txt", std::ios::app);
		std::ifstream in(fileName);

		//������ ����� �ð��� ǥ��
		time_t t{ std::time(nullptr) };

		//�ð� ��� ���� ����
		out.imbue(std::locale("korean"));

		out << "����������������������������������������" << std::endl;
		out << "����ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		out << "����������������������������������������" << std::endl;

		//out2 << "����������������������������������������" << std::endl;
		//out2 << "����ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		//out2 << "����������������������������������������" << std::endl;

		//������ ���� �˷��ֱ� ���ؼ� char ���� �ƴ϶� int ������ �޾ƿ´�
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