#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : number(0)
{
}

Fixed::Fixed(const int num) : number(num * (1 << Fixed::fractional))
{
}

Fixed::Fixed(const float num) : number(roundf(num * (1 << Fixed::fractional)))
{
}

Fixed::Fixed(const Fixed &ref)
{
	number = ref.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &ref)
{
	if (this != &ref)
	{
		number = ref.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return number;
}

void Fixed::setRawBits(int const raw)
{
	number = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(getRawBits()) / static_cast<float>(1 << fractional);
}

int Fixed::toInt(void) const
{
	return getRawBits() / (1 << fractional);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.toFloat() == 0.0)
		throw std::invalid_argument("Cannot divide by zero!");
	return Fixed(toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
	return toFloat() > other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return toFloat() >= other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
	return toFloat() < other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
	return toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return toFloat() != other.toFloat();
}

Fixed &Fixed::operator++()
{
	++number;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	--number;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? const_cast<Fixed &>(a) : const_cast<Fixed &>(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? const_cast<Fixed &>(a) : const_cast<Fixed &>(b);
}
