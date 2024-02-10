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

    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
