#include "Base.hpp"

#include <unistd.h>

int main (int argc, char *argv[]) {
    
    int times = 3;
    if (argc == 2){
        times = std::atoi(argv[1]);
    }
    for (int i = 0; i < times; i++){
        std::cout << "Testing " << i + 1 << "/" << times << std::endl;
        Base *p = generate();
        identify(p);
        identify(*p);
        delete p;
        std::cout << std::endl;
        sleep(1);
    }
 
    return (0);
}
