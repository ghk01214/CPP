#ifndef _ANIMAL
#define _ANIMAL

class Animal	// �߻� Ŭ������ ����� -> ���� �����Լ��� �����
{
public:
	Animal() = default;
	Animal(std::string name) : name(name) {}
public:
	virtual void Move() const = 0;		// ���� �����Լ�

protected:
	std::string name;
};

//����������������������������������������������������������������������������������������������������

class Dog : public Animal
{
public:
	Dog() = default;
	Dog(std::string name) : Animal(name) {}
public:
	virtual void Move() const override final;		// final : �Ļ� Ŭ���� ����(���) ����
};

//����������������������������������������������������������������������������������������������������

class Bird : public Animal
{
public:
	Bird() = default;
	Bird(std::string name) : Animal(name) {}
public:
	virtual void Move() const override;
};

#endif // ! _ANIMAL