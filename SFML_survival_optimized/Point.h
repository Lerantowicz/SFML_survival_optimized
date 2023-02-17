#pragma once
class Point
{
public:
	Point();

	Point(int x, int y);

	Point(const Point& other);

	bool operator==(const Point& other);

	bool operator!=(const Point& other);

	Point operator+(const Point& other);

	Point operator-(const Point& other);

	Point& operator+=(const Point& other);

	Point& operator-=(const Point& other);


	int x;
	int y;

};

