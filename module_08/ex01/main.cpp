#include <iostream>
#include "Span.hpp"

int main() {

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

    return 0;
}