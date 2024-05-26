#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Mutant stack size: " << mstack.size() << " -> top: " << mstack.top() << std::endl;
    std::cout << "Popping: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Mutant stack size: " << mstack.size() << " -> top: " << mstack.top() << std::endl << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Forward iteration:\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "\n\nRerverse iteration:\n";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++) {
        std::cout << *it << std::endl;
    }
    std::stack<int> s(mstack);

    std::cout << "ɅɅɅɅɅɅ END OF MUTANT ɅɅɅɅɅɅ\n\nVVVVVV START OF LIST VVVVVV\n";
    //List testing:
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "List size: " << lst.size() << " -> top: " << lst.back() <<std::endl;
    std::cout << "Popping: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "List size: " << lst.size() << " -> top: " << lst.back() <<std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Forward iteration:\n";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "\n\nRerverse iteration:\n";
    for (std::list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;
}