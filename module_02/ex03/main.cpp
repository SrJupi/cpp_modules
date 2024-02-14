#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
    // Test case 1: Point inside the triangle
    Point p1 (0, 0);
    Point p2 (4, 0);
    Point p3 (2, 4);
    Point point1 (2, 2);

    if (bsp(p1, p2, p3, point1))
        std::cout << "Test 1 Passed: Point is inside the triangle." << std::endl;
    else
        std::cout << "Test 1 Failed: Point is outside the triangle." << std::endl;

    // Test case 2: Point outside the triangle
    Point point2 (5, 5);
    if (!bsp(p1, p2, p3, point2))
        std::cout << "Test 2 Passed: Point is outside the triangle." << std::endl;
    else
        std::cout << "Test 2 Failed: Point is inside the triangle." << std::endl;

    // Test case 3: Point lies on the edge of the triangle
    Point point3 (2, 0);
    if (!bsp(p1, p2, p3, point3))
        std::cout << "Test 3 Passed: Point is outside the triangle." << std::endl;
    else
        std::cout << "Test 3 Failed: Point is inside the triangle." << std::endl;

    // Test case 4: Point lies on the vertice of the triangle
    if (!bsp(p1, p2, p3, p1))
        std::cout << "Test 4 Passed: Point is outside the triangle." << std::endl;
    else
        std::cout << "Test 4 Failed: Point is inside the triangle." << std::endl;

    return 0;
}
