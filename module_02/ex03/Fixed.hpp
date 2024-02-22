#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int number;
    static const int    fractional;

public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& ref);
    ~Fixed();
    Fixed&  operator=(const Fixed& ref);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    //Arithmetic operators
    float   operator+(const Fixed& other) const;
    float   operator-(const Fixed& other) const;
    float   operator*(const Fixed& other) const;
    float   operator/(const Fixed& other) const;

    //Comparision operators
    bool operator>(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    //Increment operators
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    //Max min functions
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
