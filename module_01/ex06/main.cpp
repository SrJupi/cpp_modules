#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
    Harl harl;
    
    std::cout << "~~~~~~ Harl with error input ~~~~~~\n";
    harl.complain("error");
    std::cout << "\n~~~~~~ Harl with debug input ~~~~~~\n";
    harl.complain("debug");
    std::cout << "\n~~~~~~ Harl with warning input ~~~~~~\n";
    harl.complain("warning");
    std::cout << "\n~~~~~~ Harl with info input ~~~~~~\n";
    harl.complain("info");
	return 0;
}