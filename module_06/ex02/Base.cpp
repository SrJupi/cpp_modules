#include "Base.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	std::srand(std::time(NULL));
    std::cout << "Generating: ";
	switch (std::rand() % 3)
	{
	case 0:
        std::cout << "A class" << std::endl;
		return (new A());
	case 1:
        std::cout << "B class" << std::endl;
		return (new B());
	case 2:
        std::cout << "C class" << std::endl;
		return (new C());
	default:
		return (NULL);
	}
}

void identify(Base *p)
{
	std::cout << "Pointer: ";
    A* pa = dynamic_cast<A*>(p);
    if (pa) {
        std::cout << "It is A" << std::endl;
        return;
    }
    B* pb = dynamic_cast<B*>(p);
    if (pb) {
        std::cout << "It is B" << std::endl;
        return;
    }
    C* pc = dynamic_cast<C*>(p);
    if (pc) {
        std::cout << "It is C" << std::endl;
        return;
    }
    std::cout << "I don't know what you are!" << std::endl;
}

void identify(Base &p)
{
    std::cout << "Reference: ";
    try {
        A& pa = dynamic_cast<A&>(p);
        (void)pa;
        std::cout << "It is A" << std::endl;
        return ;
    }
    catch (const std::exception& e){
        (void)e;
    }

    try {
        B& pb = dynamic_cast<B&>(p);
        (void)pb;
        std::cout << "It is B" << std::endl;
        return ;
    }
    catch (const std::exception& e){
        (void)e;
    }

    try {
        C& pc = dynamic_cast<C&>(p);
        (void)pc;
        std::cout << "It is C" << std::endl;
        return ;
    }
    catch (const std::exception& e){
        (void)e;
    }
    std::cout << "I don't know what you are!" << std::endl;
}
