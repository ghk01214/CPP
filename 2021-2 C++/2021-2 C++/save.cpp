#include "save.h"

void Save(std::vector<std::string> saveList, std::string saveDate)
{
	char c;

	std::cout << "\n����?" << std::endl;
	std::cin >> c;

	if (c == 'y')
	{
		std::ofstream out(saveDate, std::ios::app);
		//std::ofstream out2("2021-2 C++.txt", std::ios::app);
		std::ofstream out2("�߰���� ����2.txt", std::ios::app);

		//������ ����� �ð��� ǥ��
		time_t t{ std::time(nullptr) };

		//�ð� ��� ���� ����
		out.imbue(std::locale("korean"));

		out << "����������������������������������������" << std::endl;
		out << "����ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		out << "����������������������������������������" << std::endl;

		out2 << "����������������������������������������" << std::endl;
		out2 << "����ð�: " << std::put_time(localtime(&t), "%c %A") << std::endl;
		out2 << "����������������������������������������" << std::endl;

		for (const auto& fileName : saveList)
		{
			// � ������ �����ϴ��� ȭ�鿡 ���
			std::cout << "����: " << fileName << ", ũ��: " << std::filesystem::file_size(fileName) << std::endl;
			out << fileName << std::endl;

			std::ifstream in(fileName);

			//������ ���� �˷��ֱ� ���ؼ� char ���� �ƴ϶� int ������ �޾ƿ´�
			//int c;

			//while ((c = in.get()) != EOF)
			//{
			//	out.put(c);
			//}

			char ch;

			while (in >> std::noskipws >> ch)
			{
				out << ch;
				out2 << ch;
			}

			if (saveList.size() > 1)
			{
				out << std::endl << std::endl << "��������������������������������������������������������������������������������������" << std::endl << std::endl;
				out2 << std::endl << std::endl << "��������������������������������������������������������������������������������������" << std::endl << std::endl;
			}

			//in.close();
		}

		//RAII
		/*in.close();
		out.close();*/
	}
}