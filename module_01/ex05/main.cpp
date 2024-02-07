#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
    Harl harl;
    
    harl.complain("error");
    harl.complain("debug");
    harl.complain("warning");
    harl.complain("info");
	return 0;
}