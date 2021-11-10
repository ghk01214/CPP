#ifndef _DOG
#define _DOG

class Dog
{
public:
	Dog() = default;
	Dog(std::string name);
	Dog(std::string name, int age);
public:
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
	friend std::istream& operator>>(std::istream& is, Dog& dog);

private:
	std::string name;
	int age;
};

#endif // !_DOG