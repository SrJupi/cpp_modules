#include <string>
#include <iostream>
#include <fstream>

int ft_replace(std::string filename, std::string s1, std::string s2);

int main(void)
{
	std::string errors[3] = {"Ok!\n", "Error opening infile!\n", "Error opening outfile!\n"};

    std::cout << errors[ft_replace("infile.txt", "in", "out")];
	std::cout << errors[ft_replace("not_exist.txt", "in", "out")];
	std::cout << errors[ft_replace("in.txt", "in", "out")];

}