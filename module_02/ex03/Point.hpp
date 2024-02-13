#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed x;
    Fixed y;

public:
    Point();
    Point(float x, float y);
    Point(const Point& ref);
    ~Point();

    Point&	operator=(const Point& ref);

    float   getX(void);
    float   getY(void);
};

#endif
