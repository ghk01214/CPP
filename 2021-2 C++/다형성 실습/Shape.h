#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
public:
	virtual void Draw() const = 0;
};

#endif	// ! _SHAPE_H