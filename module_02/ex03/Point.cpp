#include <iostream>
#include <iomanip>

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float new_x, float new_y) : x(new_x), y(new_y) {}

Point::Point(const Point& ref)
{
    x = ref.x;
    y = ref.y;
}

Point::~Point() {}

Point&	Point::operator=(const Point& ref)
{
    if (this != &ref)
    {
        this->x = ref.x;
        this->y = ref.y;
    }
    return (*this);
}

float Point::getX(void) const
{
    return (x.toFloat());
}
float Point::getY(void) const
{
    return (y.toFloat());
}
