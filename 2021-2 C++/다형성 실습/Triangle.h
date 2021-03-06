#ifndef _TRIANGLE
#define _TRIANGLE

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle() : p1(), p2(), p3() {}
	Triangle(const Point& a, const Point& b, const Point& c) : p1(a), p2(b), p3(c) {}
	Triangle(const Triangle& other) : p1(other.p1), p2(other.p2), p3(other.p3) {}
	~Triangle() {}
public:
	virtual void Draw() const override;
public:
	Point GetP1() { return p1; }
	Point GetP2() { return p2; }
	Point GetP3() { return p3; }
public:
	friend std::istream& operator>>(std::istream& is, Triangle& tri);

private:
	Point p1, p2, p3;
};

#endif	// ! _TRIANGLE