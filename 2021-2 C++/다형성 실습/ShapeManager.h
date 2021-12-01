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
	void RemoveByNumber(int num);
	void RemoveByShape(int type);
	void ReallocateMemory(int capa);
public:
	bool IsFull() { return size == capacity; }
	int GetSize() { return size; }
	int GetCapacity() { return capacity; }
	Shape* GetShape(int num) { return shapes[num]; }
public:
	friend std::ostream& operator<<(std::ostream& os, const Shape& s);

private:
	int size;
	int capacity;
	Shape** shapes;
};

#endif	// ! _SHAPE_MANAGER