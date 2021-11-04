#ifndef _DOG
#define _DOG

class Dog
{
public:
	Dog();
	Dog(std::string name);
	Dog(std::string name, double speed);
public:
	// °üÂûÀ» À§ÇØ ÀÛ¼º
	Dog(const Dog& other);
public:
	void SetName(std::string n) { name = n; }
	void SetSpeed(double s) { speed = s; }

	double GetSpeed() { return speed; }
public:
	void bark() { std::cout << "¿Ğ¿Ğ" << std::endl; }
public:
	friend std::ostream& operator<<(std::ostream& os, const Dog& d);

private:
	std::string name;
	double speed; 
};

#endif // !_DOG