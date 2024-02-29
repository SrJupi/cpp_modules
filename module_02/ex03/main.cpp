#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
	Point A (0, 0);
	Point B (4, 0);
	Point C (2, 4);
	Point testPoint1 (2, 2);

	// Test case 1: Point inside the triangle
	if (bsp(A, B, C, testPoint1))
		std::cout << "Test 1 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 1 Failed: Point is outside the triangle." << std::endl;

	if (bsp(A, C, B, testPoint1))
		std::cout << "Test 2 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 2 Failed: Point is outside the triangle." << std::endl;

	if (bsp(B, A, C, testPoint1))
		std::cout << "Test 3 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 3 Failed: Point is outside the triangle." << std::endl;

	if (bsp(B, C, A, testPoint1))
		std::cout << "Test 4 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 4 Failed: Point is outside the triangle." << std::endl;

	if (bsp(C, A, B, testPoint1))
		std::cout << "Test 5 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 5 Failed: Point is outside the triangle." << std::endl;

	if (bsp(C, B, A, testPoint1))
		std::cout << "Test 6 Passed: Point is inside the triangle." << std::endl;
	else
		std::cout << "Test 6 Failed: Point is outside the triangle." << std::endl;

	// Test case 2: Point outside the triangle
	Point testPoint2 (5, 5);
	if (!bsp(A, B, C, testPoint2))
		std::cout << "Test 7 Passed: Point is outside the triangle." << std::endl;
	else
		std::cout << "Test 7 Failed: Point is inside the triangle." << std::endl;

	// Test case 3: Point lies on the edge of the triangle
	Point testPoint3 (2, 0);
	if (!bsp(A, B, C, testPoint3))
		std::cout << "Test 8 Passed: Point is outside the triangle." << std::endl;
	else
		std::cout << "Test 8 Failed: Point is inside the triangle." << std::endl;

	// Test case 4: Point lies on the vertice of the triangle
	if (!bsp(A, B, C, A))
		std::cout << "Test 9 Passed: Point is outside the triangle." << std::endl;
	else
		std::cout << "Test 9 Failed: Point is inside the triangle." << std::endl;

	// Test case 5: Points do not form a triangle
	Point D (0, 0);
	Point E (0, 2);
	Point F (0, 4);

	if (!bsp(D, E, F, testPoint1))
		std::cout << "Test 10 Passed: Triangle is not a triangle." << std::endl;
	else
		std::cout << "Test 10 Failed: Triangle is a triangle." << std::endl;

	return 0;
}
