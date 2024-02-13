#include <string>
#include <iostream>

int main(int argc, char **argv)
{
    (void)argc;
    argv++;
    if (!(*argv))
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(*argv)
    {
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

