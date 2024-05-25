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
    template <typename it>
    void addNumbers(it begin, it end);

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


template <typename it>
void Span::addNumbers(it begin, it end) {
    if (static_cast<unsigned int>(std::distance(begin, end)) > maxSize - numbers.size()) {
        throw Span::FullOfSpam();
    }
    numbers.insert(numbers.end(), begin, end);
}

#endif
