#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    MutantStack();
    MutantStack(const MutantStack& ref);
    ~MutantStack();

    MutantStack&	operator=(const MutantStack& ref);

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();

};

#include "MutantStack.tpp"

#endif
