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

    float   getX(void) const;
    float   getY(void) const;
};

bool	bsp (Point const a, Point const b, Point const c, Point const point);

#endif
