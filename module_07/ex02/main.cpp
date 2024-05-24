#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> emptyArray;
    std::cout << "Empty Array size: " << emptyArray.size() << std::endl;

    Array<double> doubleArray(5);
    std::cout << "Double Array size: " << doubleArray.size() << std::endl;

    std::cout << "double array: ";
    for (unsigned int i = 0; i < doubleArray.size(); ++i) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    const Array<int> constArray (5);
    std::cout << "const array: ";
    for (unsigned int i = 0; i < constArray.size(); ++i) {
        std::cout << constArray[i] << " ";
    }
    std::cout << std::endl;
    //constArray[0] = 1; compilation error, trying to modify const array

    Array<char> charArray(3);
    charArray[0] = 'a';
    charArray[1] = 'b';
    charArray[2] = 'c';

    Array<char> copiedArray = charArray;
    copiedArray[1] = 'd';

    std::cout << "Original Array: ";
    for (unsigned int i = 0; i < charArray.size(); ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Array: ";
    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << charArray[5] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
