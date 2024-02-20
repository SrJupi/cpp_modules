#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;
    
    std::cout<< "String:    " << &s << " -> " << s << std::endl;
    std::cout<< "StringPtr: " << &stringPTR << " -> " << *stringPTR <<std::endl;
    std::cout<< "StringRef: " << &stringREF << " -> " << stringREF <<std::endl;
    return 0;
}
