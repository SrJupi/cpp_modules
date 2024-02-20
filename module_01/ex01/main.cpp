#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

static int getInput(int argc, char **argv);

int main(int argc, char **argv)
{
    Zombie *z;
    int i;
    int N;
    
    N = getInput(argc, argv);
    if (N <= 0)
        return EXIT_FAILURE;
    z = zombieHorde(N, "Horde Zombie");
    i = 0;
    while (i < N)
    {
        z[i].announce();
        i++;
    }
    delete [] z;
    return EXIT_SUCCESS;
}

static int getInput(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            return std::atoi(argv[1]);
        }
        catch (...)
        {
            std::cout << "Your argument is not a number. Setting N to 4!" << std::endl;
            return 4;
        }
    }
    else
    {
        std::cout << "Invalid number of arguments. Setting N to 4!" << std::endl;
        return 4;
    }
}
