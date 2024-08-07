#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {

    //Normal span, subject test
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;


    //Normal Span, no exception
    try { 
        Span span(10);

        for (int i = 0; i < 10; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Add more numbers than size, FullOfSpam exception
    try { 
        Span span(10);

        for (int i = 0; i < 15; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    //Not enough number to calculate shortest spam, NotEnoughSpam exception
    try { 
        Span span(1);

        for (int i = 0; i < 1; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    //Not enough number to calculate longest spam, NotEnoughSpam exception
    try { 
        Span span(1);

        for (int i = 0; i < 1; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Longest Span: " << longest << std::endl;
        std::cout << "Shortest Span: " << shortest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    //Normal Span, no exception, 50000 elements
    try { 
        Span span(50000);

        for (int i = 0; i < 50000; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();
        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    //Normal Span, test addNumbers with iterator and random numbers
    try {
        Span span(10000);
        std::srand(std::time(NULL));

        std::vector<int> randomNumbers;
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(rand() % 100000);
        }
        span.addNumbers(randomNumbers.begin(), randomNumbers.end());

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
