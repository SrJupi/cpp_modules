#include "Point.hpp"

static int	orientation(Point const t1, Point const t2, Point const p)
{
	float val = (t2.getY() - t1.getY()) * (p.getX() - t2.getX()) - (t2.getX() - t1.getX()) * (p.getY() - t2.getY());
	if (val == 0)
		return 0;
	return (val > 0) ? 1 : 2;
}

bool	bsp (Point const a, Point const b, Point const c, Point const point)
{
	return (orientation(a, b, point) == orientation(b, c, point) && orientation(b, c, point) == orientation(c, a, point));
}