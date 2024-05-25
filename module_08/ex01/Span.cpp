#include "Span.hpp"

unsigned int Span::MINSIZE = 2;

Span::Span()
{
}

Span::Span(unsigned int size) : maxSize(size)
{
}

Span::Span(const Span &ref) : maxSize(ref.maxSize)
{
	this->numbers = ref.numbers;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (numbers.size() >= maxSize)
		throw FullOfSpam();
	numbers.push_back(n);
}

int Span::shortestSpan(void)
{
    if (numbers.size() < MINSIZE)
        throw NotEnoughSpam();
    std::sort(numbers.begin(), numbers.end());
    int minSpan = numbers[1] - numbers[0];
    for (size_t i = 2; i < numbers.size(); i++) {
        if (numbers[i] - numbers[i - 1] < minSpan)
            minSpan = numbers[i] - numbers[i - 1];
    }
	return (minSpan);
}

int Span::longestSpan(void)
{
	if (numbers.size() < MINSIZE)
        throw NotEnoughSpam();
    return (*std::max_element(numbers.begin(), numbers.end())
		- *std::min_element(numbers.begin(), numbers.end()));
}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		this->maxSize = ref.maxSize;
		this->numbers = ref.numbers;
	}
	return (*this);
}

const char *Span::FullOfSpam::what() const throw()
{
	return ("I am already full");
}

const char *Span::NotEnoughSpam::what() const throw()
{
	return ("I do not have enough numbers");
}
