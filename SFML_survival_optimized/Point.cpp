#include "Point.h"


Point::Point() : x(0), y(0)
{
	
}

Point::Point(int x, int y) : x(x), y(y)
{

}

Point::Point(const Point& other) : x(other.x), y(other.y)
{

}

bool Point::operator==(const Point& other)
{
	return (x == other.x && y == other.y);
}

bool Point::operator!=(const Point& other)
{
	return !(*this == other);
}

Point Point::operator+(const Point& other)
{
	return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(const Point& other)
{
	return Point(this->x - other.x, this->y - other.y);
}

Point& Point::operator+=(const Point& other)
{
	this->x = this->x + other.x;
	this->y = this->y + other.y;
	return *this;
}

Point& Point::operator-=(const Point& other)
{
	this->x = this->x - other.x;
	this->y = this->y - other.y;
	return *this;
}