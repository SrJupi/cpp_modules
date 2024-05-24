#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vecIt << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::list<int>::iterator lstIt = easyfind(lst, 30);
        std::cout << "Found in list: " << *lstIt << std::endl;

        // Testing with an element not in the container
        easyfind(vec, 6);
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}