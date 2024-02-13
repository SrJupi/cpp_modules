#include <iostream>
#include <iomanip>

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float new_x, float new_y) : x(new_x), y(new_y) {}

Point::Point(const Point& ref)
{
    *this=ref;
}

Point::~Point() {}

Point&	Point::operator=(const Point& ref)
{
    if (this != &ref)
        *this=ref;
    return (*this);
}

float Point::getX(void)
{
    return (x.toFloat());
}
float Point::getY(void)
{
    return (y.toFloat());
}
