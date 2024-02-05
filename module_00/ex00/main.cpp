#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    int j;
    
    argv++;
    if (!(*argv))
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(*argv)
    {
        j = 0;
        while (**argv)
        {
            std::cout << (char) std::toupper(**argv);
            (*argv)++;        
        }
        argv++;
    }
    std::cout << std::endl;
    return 0;
}

