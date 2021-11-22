#ifndef _ANIMAL
#define _ANIMAL

class Animal
{
public:
	Animal() = default;
	Animal(std::string name) : name(name) {}
public:
	virtual void Move();

protected:
	std::string name;
};

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收

class Dog : public Animal
{
public:
	Dog() = default;
	Dog(std::string name) : Animal(name) {}
public:
	void Move();
};

//收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收

class Bird : public Animal
{
public:
	Bird() = default;
	Bird(std::string name) : Animal(name) {}
public:
	void Move();
};

#endif // ! _ANIMAL