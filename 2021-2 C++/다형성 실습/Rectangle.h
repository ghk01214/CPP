#ifndef _RECTANGLE
#define _RECTANGLE

#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() : p1(), p2() {}
	Rectangle(const Point& a, const Point& b) : p1(a), p2(b) {}
	Rectangle(const Rectangle& other) : p1(other.p1), p2(other.p2) {}
	~Rectangle() {}
public:
	virtual void Draw() const override;
	Point GetP1() { return p1; }
	Point GetP2() { return p2; }
public:
	friend std::istream& operator>>(std::istream& is, Rectangle& r);

private:
	Point p1, p2;
};

#endif	// ! _RECTANGLE