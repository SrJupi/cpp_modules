#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : number(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int num) : number(num * (1 << Fixed::fractional))
{
    std::cout << "Integer Constructor Called" << std::endl;
}

Fixed::Fixed(const float num) : number(roundf(num * (1 << Fixed::fractional)))
{
    std::cout << "Float Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
    std::cout << "Copy Constructor Called" << std::endl;
    number = ref.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref)
{
    std::cout << "Copy Assignment Constructor Called" << std::endl;
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
