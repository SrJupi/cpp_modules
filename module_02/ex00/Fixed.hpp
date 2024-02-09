#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
    int number;
    static const int    fractional;

public:
    Fixed();
    Fixed(const Fixed& ref);
    ~Fixed();

    Fixed&	operator=(const Fixed& ref);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
