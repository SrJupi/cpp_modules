#include <string>
#include <iostream>
#include <fstream>

static void do_replace(std::string& str, std::string old_str, std::string new_str)
{
    size_t index = 0;
    while (true) {
         index = str.find(old_str, index);
         if (index == std::string::npos) break;
         str = str.substr(0, index) + new_str + str.substr(index + old_str.length());
         index += new_str.length();
    }
}


int ft_replace(std::string filename, std::string s1, std::string s2)
{
    std::string inText;
    std::ifstream inFile(filename.c_str());
    if (inFile.fail())
        return 1;
    std::string outText (filename + ".replace");
    std::ofstream ofFile(outText.c_str());
    if (ofFile.fail())
        return 2;
    while (getline (inFile, inText)) {
        do_replace(inText, s1, s2);
        ofFile << inText << std::endl;
    }
    inFile.close();
    ofFile.close();
    return 0;
}