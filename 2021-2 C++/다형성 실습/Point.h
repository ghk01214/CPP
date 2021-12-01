#ifndef _POINT
#define _POINT

struct Point
{
public:
	Point() : x(0.0), y(0.0) {}
	Point(double a, double b) : x(a), y(b) {}
	Point(const Point&) = default;

	friend std::istream& operator>>(std::istream& is, Point& p);

public:
	double x, y;
};

#endif // ! _POINT