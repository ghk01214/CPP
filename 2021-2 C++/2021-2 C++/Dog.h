#ifndef _DOG
#define _DOG

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog() { name.resize(10); }
	Dog(std::string name);
	Dog(std::string name, int age);
public:
	void SetName(int i, int alph) { name[i] = alph; }
	void SetAge(int age) { this->age = age; }

	std::string GetName() const { return name; }
	int GetAge() const { return age; }
public:
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
	friend std::istream& operator>>(std::istream& is, Dog& dog);

private:
	std::string name;
	int age;
};

#endif // !_DOG