#ifndef _SHAPE_MANAGER
#define _SHAPE_MANAGER

#include "Shape.h"

class ShapeManager
{
public:
	explicit ShapeManager(int n) : size(0), capacity(n), shapes(new Shape*[capacity]) {}
	ShapeManager(const ShapeManager& s) = default;
	~ShapeManager();
public:
	void Insert(Shape* s) { shapes[size++] = s; };
	void Draw() const;

private:
	int size;
	int capacity;
	Shape** shapes;
};

#endif	// ! _SHAPE_MANAGER