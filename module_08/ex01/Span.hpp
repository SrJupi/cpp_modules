#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
    static unsigned int MINSIZE;
    std::vector<int> numbers;
    unsigned int    maxSize;
    Span();

public:
    Span(unsigned int size);
    Span(const Span& ref);
    ~Span();
    void addNumber(int n);
    int shortestSpan(void);
    int longestSpan(void);

    Span&	operator=(const Span& ref);
	class FullOfSpam : public std::exception {
	public:
        const char* what() const throw();
    };

    class NotEnoughSpam : public std::exception {
	public:
        const char* what() const throw();
    };
};

#endif
