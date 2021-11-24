#ifndef _ANIMAL
#define _ANIMAL

class Animal	// 추상 클래스로 만든다 -> 순수 가상함수를 만든다
{
public:
	Animal() = default;
	Animal(std::string name) : name(name) {}
public:
	virtual void Move() = 0;		// 순수 가상함수

protected:
	std::string name;
};

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

class Dog : public Animal
{
public:
	Dog() = default;
	Dog(std::string name) : Animal(name) {}
public:
	virtual void Move();
};

//━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

class Bird : public Animal
{
public:
	Bird() = default;
	Bird(std::string name) : Animal(name) {}
public:
	virtual void Move();
};

#endif // ! _ANIMAL