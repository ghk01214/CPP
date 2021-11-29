#ifndef _CIRCLE
#define _CIRCLE

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle() : center(), rad(0.0) {}
	Circle(const Point& c, int r) : center(c), rad(r) {}
	Circle(const Circle& other) : center(other.center), rad(other.rad) {}
	~Circle() {}
public:
	virtual void Draw() const override;

private:
	Point center;
	double rad;
};

#endif // ! _CIRCLE