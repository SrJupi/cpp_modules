#include <string>
#include <iostream>
#include <fstream>

static void ft_replace(std::string& str, std::string old_str, std::string new_str)
{
    size_t index = 0;
    while (true) {
         index = str.find(old_str, index);
         if (index == std::string::npos) break;
         str = str.substr(0, index) + new_str + str.substr(index + old_str.length());
         index += new_str.length();
    }
}


int main(int argc, char *argv[])
{
	std::string inText;
    if (argc != 4)
    {
        std::cout << "Usage: ./ft_replace <infile name> <string to replace> <new string>\n";
        return 1;
    }
    std::ifstream inFile(argv[1]);
    if (inFile.fail())
    {
        std::cout << "Cannot open: " << argv[1] << "\n";
        return 1;
    }
    std::string outText = std::string(argv[1]) + ".replace";
    std::ofstream ofFile(outText.c_str());
    if (ofFile.fail())
    {
        std::cout << "Cannot open " << outText << "\n";
        return 1;
    }
	if (inFile.peek() == std::ifstream::traits_type::eof())
		std::cout << "Input file is empty... generating new empty file: " << outText << "\n";
    while (getline (inFile, inText)) {
        ft_replace(inText, argv[2], argv[3]);
        ofFile << inText << std::endl;
    }
    inFile.close();
    ofFile.close();
	std::cout << "New file created: " << outText << "\n";
    return 0;
}
